//
//  DBConnector.h
//  dbManipulator
//
//  Created by Christian Rapp on 26.05.13.
//
//

#ifndef __dbManipulator__DBConnector__
#define __dbManipulator__DBConnector__

#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>
#include <sys/time.h>
#include <memory>
#include "Node.h"

class DBConnector {
private:
    sqlite3 *db;
    sqlite3_stmt *preparedStmt;
    std::string dbName;
    
    
public:
    DBConnector(std::string dbName);
    ~DBConnector();
    std::vector< std::shared_ptr<Node> > query();
};

#endif /* defined(__dbManipulator__DBConnector__) */
