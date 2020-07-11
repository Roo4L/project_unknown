 class link
 {
 public:
 	link(string name, sring addr, string family = 0):
 	  this->name = name
 	, this->addr = addr
 	, this->family = family;

 private:
 	string name;
 	string addr;
 	string family;
 }

 class content_table
 {
 public:
 	content_table(spirit project);
 	add();
 	listall();
 	delete();
 	update();
 	save();
 	~content_table();
 private:
 	vector<group<>> group_table;
 	spirit project;
 }

 class group
 {
 public:
 	string name;
 	group(string name): this->name = name, 

 	add();
 	listall();
 	delete();
 	update();
 private:
 	vector<> table;
 }