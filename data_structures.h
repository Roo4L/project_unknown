 class link
 {
 private:
 	string name;
 	string addr;
 public:
 	link(const string& name, const string& addr):
 	  name(name)
 	, addr(addr){};
 	link(const FILE* f, )
 }

class command
{
private:
	string name;
	string com;
public:
	command(const string& name, const string& com): name(name), com(com) {}
}
/*
	Container for groups of objects
*/
template<typename Content>
class group_table
{
	using value_type = Content;
private:
	group<Content>* table = nullptr;
	uint32_t sz = 0;
	spirit project;
public:
	explicit content_table(spirit project);
	content_table();
	group<Content>& operator[](string& group_name);
	group<Content>& operator[](int i);
	const group<Content>& operator[](int i) const;
 	int size();
	void add_group(string& group_name);
	void remove_group(string& group_name);
	void save();
	~content_table();
}

template<typename Content>
Content* begin(group_table<Content>& x);

template<typename Content>
Content* end(group_table<Content>& x);

/*
	Container for arbitrary content (links, commands, required software and etc)
*/
template<typename Content>
class group
{
	using value_type = Content;
private:
	Content* arr = nullptr;
	uint32_t sz = 0;
public:
	string name;
	group(const string& name): name(name){}; 
	group(const FILE* src, const size_t offset);
	void add(Content elem);
	void remove(const string& name);
	int size();
	Content& operator[](int i);
	const Content& operator[](int i) const;
	~group();
}

template<typename Content>
Content* begin(group<Content>& x);

template<typename Content>
Content* end(group<Content>& x);