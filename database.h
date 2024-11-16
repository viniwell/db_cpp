//
// Created by Oleksandr Vinichenko on 06.11.2024.
//

#ifndef DB_H
#define DB_H

#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>

namespace DB {

    class Database {
    public:
        Database(const std::string& url, const std::string& username, const std::string& password, const std::string& schema);

        sql::ResultSet* execute(std::string &query) { return statement->executeQuery(sql::SQLString(query)); }



        sql::Connection* getConnection(){ return connection; };
        sql::mysql::MySQL_Driver* getDriver(){ return driver; };


        ~Database();

    private:
        sql::mysql::MySQL_Driver* driver;
        sql::Connection* connection;
        sql::Statement* statement;
    };
}
#endif //DB_H
