using namespace std;
#include <iostream>
#include "CTable.h"
static const int ADDITION_NUMBER = 5;
static const int MAX_TAB_LENGTH = 100000;

bool vAllocTableAdd5(int iSize) {
    if (iSize > 0 && iSize <= MAX_TAB_LENGTH) {
        int* table;
        table = new int[iSize];
        for (int i = 0; i < iSize; i++)
            table[i] = i + ADDITION_NUMBER;
        for (int i = 0; i < iSize; i++)
            cout << "table[" << i << "] = " << table[i] << endl;
        delete table;
        return true;
    }
    else 
        return false;
    
}

bool bAllocTable2Dim(int*** piTable, int iSizeX, int iSizeY) {
    if (iSizeX >= 1 && iSizeY >= 1 && iSizeX <= MAX_TAB_LENGTH && iSizeY <= MAX_TAB_LENGTH) {
        *piTable = new int* [iSizeX];
        for (int i = 0; i < iSizeX; i++)
            (*piTable)[i] = new int[iSizeY];
        return true;
    }
    else
        return false;
}

bool bDeallocTable2Dim(int** piTable, int iSizeX) {
    //zakładam, że zapamiętałem długość tablicy i wpisuje ją do procedury (tak zrozumiałem na labolatoriach)
    if (iSizeX > 0) {
        for (int i = 0; i < iSizeX; i++)
            delete piTable[i];
        delete piTable;
        return true;
    }
    else
        return false;
}


bool vModTab(CTable* pcTab, int iNewSize) {
    return pcTab->bSetNewSize(iNewSize);
}

bool vModTab(CTable pcTab, int iNewSize) {
    return pcTab.bSetNewSize(iNewSize);
}




int main()
{
    //testy zadan 1-3
    cout << "zadania 1-3:" << endl << "vAllocTableAdd5(10):" << endl;
    vAllocTableAdd5(10);
    int** piTable;
    cout << "czy udalo sie zaalokowac tablice: " << bAllocTable2Dim(&piTable, 4, 1) << endl;
    piTable[3][0] = 3;
    cout << "piTable[3][0] = " << piTable[3][0] << endl;
    bDeallocTable2Dim(piTable, 4);
    //cout << piTable[3][0] << endl;   //linijka wywołująca błąd w celu sprawdzenia czy tablica została zdealokowana

    cout << "\n\n\n";

    //zadanie 4
    cout << "zadanie 4: " << endl;
    CTable tabToCopy("tabToCopy", 1);
    CTable* copy;
    copy = new CTable(tabToCopy);
    copy->bSetNewSize(2);
    copy->vSetName("newName");
    cout << "Wielkosc tablicy copy po ustawieniu na 2: " << copy->getTabLength() << "\nNazwa tablicy copy po ustawieniu na 'newName': " << copy->getSName() << endl;
    cout << "test metody pcClone: " << endl;
    CTable c_tab;
    CTable* pc_new_tab;
    pc_new_tab = c_tab.pcClone();
    delete pc_new_tab;


    cout << "\n\n\n";

    //testy procedur    
    cout << "test procedur" << endl;
    vModTab(copy, 3);
    cout << "przekazanie przez wskaznik, dlugosc tablicy bo wywolaniu procedury vModTab(copy, 3): " << copy->getTabLength() << endl;
    CTable tabToMod("tabToMod", 1);
    vModTab(tabToMod, 2);
    cout << "przekazanie przez wartosc, dlugosc tablicy bo wywolaniu procedury vModTab(tab1, 2): " << tabToMod.getTabLength() << endl;

    cout << "\n\n\n";

    cout << "test alokacji statycznej i dynamicznej obiekow CTable" << endl;
    CTable tabStatic("tabStatic", 3);
    CTable* tabDynamic;
    tabDynamic = new CTable("tabDynamic", 3);
    CTable tabOfTabsStatic[5];
    CTable* tabOfTabsDynamic;
    tabOfTabsDynamic = new CTable[5];

    cout << "\n\n\n";

    cout << "test modyfikacji" << endl;
    CTable modTest("mod", 1);
    modTest.vPush(2);
    cout << "przekazanie przez wartosc, dlugosc tablicy bo wywolaniu metody vPush(2): " << modTest.getTabLength() << endl;

    
    cout << "\n\n\n";

    cout << "usuniecie obiektow zaalokowanych dynamicznie" << endl;
    //usuniecie dynamicznie zaalokowanych obiektow
    delete copy;
    delete tabDynamic;
    //aby usunac elementy tablicy zaalokowanej dynamicznie musze wykonac taka operacje
    cout << "delete[] tabOfTabsDynamic" << endl;
    delete[] tabOfTabsDynamic;
    cout << "koniec maina" << endl;
    

    

    


}

