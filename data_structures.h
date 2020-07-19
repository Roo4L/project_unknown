#ifndef DATA_STRUCTURES
#define DATA_STRUCTURES

#include <fstream>
#include <QString>
#include <QUrl>

#define SPIRIT_INIT true
#define SPIRIT_CREATE false

#define ELEM_NOT_FOUND -1
#define OK 0

namespace fs = std:filesystem;

/*
 * Project main class for interaction with all project components.
 * Initialized with path to project folder and existence flag.
 * Constucted during openning project.
 * Destructed during closing.
 */
class spirit
{
private:
	fs::path project_folder;
	std::vector<fs:path> blog_files;
	bool git_exists;
	QString git_origin;
public:
	spirit(const fs::path project_folder, const bool exist);
	fs::path path() { return project_folder };
	~spirit();
}
/*
 * Types for basic information blocks.
 */
class link
{
private:
	QString name;
	QUrl addr;
public:
	link(const QString& name, const QUrl& addr):
	  name(name)
	, addr(addr){};
	QString& name();
	QUrl& addr();
	//bool operator=(link& x);
	~link() {};
}

class command
{
private:
	QString name;
	QString com;
public:
	command(const QString& name, const QString& com): name(name), com(com) {};
	//bool operator=(command& x);
	~command() {};
}
/*
 * Main information container for most data widjects. Stores objects grouped in user defined unions.
 * Constructed during widjet openning.
 * Destructed during widject closing.
 */
template<typename Content>
class group_table
{
	using value_type = Content;
private:
	list<group<Content>> table;
	fs::path db;
	spirit project;
public:
	explicit group_table(spirit project);
 	int size() const;
	void push_back(QString& group_name);
	int remove(QString& group_name);
	void move(QString& old_pos, QString& new_pos);
	list<group<Content>>& list() const;
	void save() const;
	~group_table();
}
/*
 * Logic container for objects united in user defined group.
 * Constructed with parent table constructor.
 * Destructed with parent destructor.
 */
template<typename Content>
class group
{
	using value_type = Content;
private:
	list<Content> data;
	QString name;
public:
	group(const QString& name): name(name), data(){}; 
	group(const std::ofstream& src, char16_t* buf);
	QString& name();
	group<Content>& operator=(group<Content>& x);
	void push_back(Content elem);
	int remove(const QString& name);
	void move(QString& old_pos, QString& new_pos);
	list<Content>& list() const;
	int size() const;
	~group() {};
}
/*
 * Interface for file synchonizing with Google Drive.
 * Constructed
 * Destructed
 */
class sync_files
{
private:
	std::vector<fs::path> syncFiles;
public:
	sync_files(fs::path f);
	sync_files(const fs::path f, const std::vector<fs::path>& files_to_sync);
	std::vector<fs::path>& list();
	void add(const fs::path f);
	void add(const std::vector<fs::path>& farr);
	void remove(const fs::path f);
	void remove(const std::vector<fs::path>& f);
}

#endif