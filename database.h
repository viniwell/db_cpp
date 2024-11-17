//
// Created by Oleksandr Vinichenko on 06.11.2024.
//

#ifndef DB_H
#define DB_H

#include <iostream>
#include <vector>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>


namespace DB {

    class Database {


    public:

        Database(const std::string& url, const std::string& username, const std::string& password, const std::string& schema, bool debugMode = false);

        //Executes query and tries to return a ResultSet. If impossible, return nullptr
        sql::ResultSet* execute(std::string &query);


        sql::Connection* getConnection(){ return connection; };
        sql::mysql::MySQL_Driver* getDriver(){ return driver; };

        bool getDebugMode(){ return debugMode; };

        ~Database();

    private:
        sql::mysql::MySQL_Driver* driver;
        sql::Connection* connection;
        sql::Statement* statement;
        bool debugMode = false;
    };


    //prints specified fields of ResultSet object
    void printResultSet(sql::ResultSet* resultSet, std::vector<std::string> &columnNames);
}
#endif //DB_H
