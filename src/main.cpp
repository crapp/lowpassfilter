#include <iostream>
#include <memory>
#include <string>
#include "DBConnector.h"
#include "SimpleLowPass.h"


using namespace std;


int main()
{
    string dbFile = "/Users/chrwr/bkt20130525.db";
    shared_ptr<DBConnector> dbCon(new DBConnector(dbFile));
    unique_ptr<SimpleLowPass> slp (new SimpleLowPass(dbCon->query()));
    slp->applySLP();
    return 0;
}

