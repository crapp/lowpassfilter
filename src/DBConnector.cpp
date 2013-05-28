//
//  DBConnector.cpp
//  dbManipulator
//
//  Created by Christian Rapp on 26.05.13.
//
//

#include "DBConnector.h"

DBConnector::DBConnector(std::string dbName) : dbName(dbName)
{
    this->db = NULL;
    this->preparedStmt = NULL;
}

DBConnector::~DBConnector()
{
    //make sure database will be closed
    sqlite3_close(this->db);
}

std::vector< std::shared_ptr<Node> > DBConnector::query()
{
    std::vector< std::shared_ptr<Node> > nodeList;
    int rc = sqlite3_open(this->dbName.c_str(), &this->db);
    if (rc > 0)
    {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return nodeList;
    }
    
    std::string sqlQuery = "SELECT * FROM NODES";
    
    rc = sqlite3_prepare(this->db, sqlQuery.c_str(), sqlQuery.length(), &this->preparedStmt, NULL);
    if (rc > 0)
    {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return nodeList;
    }
    
    while (sqlite3_step(this->preparedStmt) == SQLITE_ROW)
    {
        double alti = 0;
        double altiup = 0;
        double altidown = 0;
        std::string datetime = "";
        long ts = 0;
        struct tm tm;
        alti = sqlite3_column_double(this->preparedStmt, 3);
        altiup = sqlite3_column_double(this->preparedStmt, 4);
        altidown = sqlite3_column_double(this->preparedStmt, 5);
        //fancy cast to get the datetime string from the db
        datetime = std::string(reinterpret_cast<const char*>(sqlite3_column_text(this->preparedStmt, 12)));
        strptime(datetime.c_str(), "%Y-%m-%d %H:%M:%S", &tm);
        ts = mktime(&tm);
        std::shared_ptr<Node> n(new Node(0, alti, altiup, altidown, 0, 0, ts));
        nodeList.push_back(n);
    }
    
    sqlite3_finalize(this->preparedStmt);
    
    return nodeList;
}

