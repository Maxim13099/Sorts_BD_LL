
#include "base_sqlite.h"
#include "LinkedList.h"
#include "realize.h"
#include <iostream>
#include <string>
using namespace std;
static sqlite3 *bd; //handle of BD


void testBd() {
    int sizeT = 10000;
    OneLinkedList first;
    first.push_first(BubbleSortTime(sizeT));
    first.push_back(SelectionSortTime(sizeT));
    first.push_back(InsertionSortTime(sizeT));
    first.push_back(CountingSortTime(sizeT));
    first.push_back(MergeSortTime(sizeT));
    Node* nodeq = first.getAt(0);
        double a1 = nodeq->data;
    Node* nodew = first.getAt(1);
        double a2 = nodew->data;
    Node* nodee = first.getAt(2);
        double a3 = nodee->data;
    Node* noder = first.getAt(3);
        double a4 = noder->data;
    Node* nodet = first.getAt(4);
        double a5 = nodet->data;
    string Time = "INSERT INTO ressorts (idSort,idsizeAr,`dursortMs`) VALUES('BubbleSort', "+to_string(sizeT)+" , "+to_string(a1)+"), ('SelectionSort', "+to_string(sizeT)+", "+to_string(a2)+"), ('InsertionSort', "+to_string(sizeT)+", "+to_string(a3)+"), ('CountingSort', "+to_string(sizeT)+", "+to_string(a4)+"), ('MergeSort', "+to_string(sizeT)+", "+to_string(a5)+");";
    openBd("test.bd\0");
    request_insert_create("CREATE TABLE IF NOT EXISTS temp(id integer primary key, name varchar(32));");
    request_insert_create("CREATE TABLE IF NOT EXISTS sorts(id integer primary key,nameSort varchar(32));");
    request_insert_create("CREATE TABLE IF NOT EXISTS  sizears(id integer primary key autoincrement,sizeAr integer);");
    request_insert_create("CREATE TABLE IF NOT EXISTS  ressorts(id integer primary key autoincrement, `dursortMs` varchar(32), idSort varchar(32),idsizeAr varchar(32),FOREIGN KEY(idSort) REFERENCES sorts(id), FOREIGN KEY(idsizeAr) REFERENCES sizears(id));");
    request_insert_create("INSERT INTO SizeArs VALUES(1,30000), (2,30000),(3,30000),(4,30000),(5,30000);");
    request_insert_create("INSERT INTO Sorts VALUES(1,'BubbleSort'),(2,'SelectionSort'),(3,'InsertionSort'),(4,'CountingSort'),(5,'MergeSort');");
    request_insert_create(Time.c_str());
    request_select("SELECT * FROM ressorts");

    closeBd();
}

bool openBd(const char* bdName) {
    int status = sqlite3_open(bdName, &bd);
    assert(status == SQLITE_OK);

    return status;
}

bool closeBd() {
    int status = sqlite3_close(bd);
    assert(status == SQLITE_OK);
    return status;
}

bool request_insert_create(const char* sqlString) {
    char* errMsg;
    int er = sqlite3_exec(bd, sqlString, nullptr, nullptr, &errMsg);
    if (er) {
        std::cerr << "error request " << sqlString << " : " << errMsg << std::endl;   //std::cout
    }

    return er;
}
int getLastRowId() {
    int last_id = sqlite3_last_insert_rowid(bd);
    return last_id;
}

int callback(void* outputStruct, int countRec, char** argv, char** colName) {
    //void* -- c-style
    //outputStructure allow to return back the data for processing....
    for (int i = 0; i < countRec; i++) {
        std::cout << "\t" << colName[i] << " '" << argv[i] << "'";
    }
    std::cout << std::endl;
    return 0;
}

bool request_select(const char* sqlString) {
    char* errMsg;
    int er = sqlite3_exec(bd, sqlString, callback, nullptr /*input arguments*/, &errMsg);

    if (er != SQLITE_OK) {
        std::cerr << "error request " << sqlString << " : " << errMsg << std::endl;
    }
    assert(er == SQLITE_OK);

    return er;
}
