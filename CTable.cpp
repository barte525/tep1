#include "CTable.h"
#include <iostream>
using namespace std;


const string CTable::defaultName = "default";

CTable::CTable() {
	sName = defaultName;
	tabLength = dafaultTabLength;
	table = new int[tabLength];
	cout << "bezp: " + sName << endl;
}


CTable::CTable(string _sName, int _tabLength) {
	sName = _sName;
	tabLength = _tabLength;
	cout << "parametr: " + sName << endl;
	table = new int[tabLength];
}


CTable::CTable(const CTable& pcOther) {
	sName = pcOther.sName + "_copy";
	tabLength = pcOther.tabLength;
	cout << "kopiuj: " + sName << endl;
	table = new int[tabLength];
	for (int i = 0; i < tabLength; i++) {
		table[i] = pcOther.table[i];
	}
	
}

CTable :: ~CTable() {
	delete table;
	cout << "usuwam: " + sName << endl;
}


void CTable::vSetName(string _sName) {
	sName = _sName;
}



bool CTable::bSetNewSize(int _tabLength) {
	if (_tabLength < 0)
		return false;
	else {
		int* tmpTable;
		tmpTable = new int[_tabLength];
		if (tabLength < _tabLength) {
			for (int i = 0; i < tabLength; i++)
				tmpTable[i] = table[i];
		}
		else {
			for (int i = 0; i < _tabLength; i++)
				tmpTable[i] = table[i];
		}
		tabLength = _tabLength;
		delete[] table;
		table = tmpTable;
		return true;
	}
}

//funckja pomocnicza do testow
int CTable::getTabLength() {
	return tabLength;
}

//funkcja pomoznicza do testow
string CTable::getSName() {
	return sName;
}

CTable* CTable::pcClone() {
	CTable* objClone;
	objClone = new CTable(*this);
	return objClone;
}

void CTable :: vPush(int iNewVal) {
	this->bSetNewSize(tabLength + 1);
	this->table[tabLength - 1] = iNewVal;
}
