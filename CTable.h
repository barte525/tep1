using namespace std;
#include <iostream>




class CTable {
public:
	static const string defaultName;// = "default";
	static const int dafaultTabLength = 10;

	CTable();
	CTable(string sName, int tabLength);
	CTable(const CTable& pcOther);
	~CTable();

private:
	string sName;
	int tabLength;
	int* table;

public:
	void vSetName(string sName);
	bool bSetNewSize(int tableLength);
	CTable* pcClone();
	int getTabLength();
	string getSName();// { return tabLength; };
	void vPush(int iNewVal);
};

