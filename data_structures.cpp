#include "data_structures.h"

using namespace std;
namespace fs = std::filesystem;

const QString LIST_END = "";

template <typename Content>
group::group(const std::ifstream& src, char16_t* buf) {
	name(fromUtf16(title + 7));
	while (!src.eof() && (getline(src, buf), !title(buf))) {
		QString name (fromUtf16(buf));
		getline(src, buf);
		QString addr (fromUtf16(buf));
		data.push_back({name, addr});
	}
}

template<typename Content>
int group::size() {
	return data.size();
}

template<typename Content>
QString& group::name() {
	return name;
}

template<typename Content>
void group::push_back(Content elem) {
	data.push_back(elem);
}

template<typename Content>
int group::remove(const QString& name) {
	auto& it = data.begin();
	while (it != data.end() && it->name() != name) {
		++it;
	}
	if (it != data.end()) {
		data.erase(it);
		return OK;
	}
	else {
		return ELEM_NOT_FOUND;
	}
}

template<typename Content>
void group::move(QString& old_pos, QString& new_pos) {
	std::list<Content>::iterator i = data.end();
	std::list<Content>::iterator j = data.end();

	for (auto& it : data) {
		if (it->name() == old_pos):
			i = it;
		if (it->name() == new_pos):
			j = it;
		if (i != data.end() and j != data.end()) {
			break;
		}
	}

	const Content tmp = *i;
	data.erase(i);
	data.insert(j, tmp);
}

template<typename Content>
list<Content>& group::list() {
	return data;
}

template<typename Content>
explicit group_table::group_table(spirit project) {
	if (std::is_same<Content, link>::value){
		db = project.path() / ".workdog" / "links.txt";
	}
	else  if(std::is_same<Content, command>::value) {
		db = project.path() / ".workdog" / "commands.txt";
	}
	if (fs::exists(db)) {
		ifstream f (db, ios::trunc);
		char16_t buf[2048];
		getline(f, buf);
		while (f.eof()) {
			if (title(buf)) {
				group<Content> g(f, buf);
				table.push_back(g);
			}
			else {
				//raise exception
			}
		}
		f.close();
	}
}

template<typename Content>
int group_table::size() const {
	return table.size();
}

template<typename Content>
list<group<Content>>& group_table::list() const {
	return table;
}

template<typename Content>
void group_table::push_back(QString& group_name){
	group<Content> g(group_name);
	table.push_back(g);
}

template<typename Content>
int group_table::remove(QString& group_name) {
	for (auto& it : table) {
		if (it->name() == group_name) {
			table.erase(it);
			return OK;
		}
	}
	return ELEM_NOT_FOUND;
}

template<typename Content>
void group_table::move(QString& old_pos, QString& new_pos) {
	std::list<group<Content>::iterator i = table.end();
	std::list<group<Content>::iterator j = table.end();

	for (auto& it : table) {
		if (it->name() == old_pos) :
			i = it;
		if (it->name() == new_pos) :
			j = it;
		if (i != table.end() && j != table.end()) :
			break;
	}

	const group<Content> tmp = *i;
	table.erase(i);
	table.insert(j, tmp);
}

template<typename Content>
void group_table::save() const {
	ifstream f (db);
	if (f.is_open()) {
		for (auto& g : table) {
			f << L"[group]" << g->name().unicode() << endl;
			for (auto& elem : g) {
				f << elem->name() << endl;
				f << elem->addr().toString().unicode() << endl;
			}
		}
	}
}