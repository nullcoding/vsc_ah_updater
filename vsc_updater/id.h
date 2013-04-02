#ifndef ID_H_INCLUDED
#define ID_H_INCLUDED

class itemID {
public:

	static const unsigned long int idList[];
	static const int sz;
	static const char* const jsondir;

	itemID();
	~itemID();

	bool fillFolder();
	bool grab(unsigned long int id);
	bool testRead(unsigned long int id);
};

#endif