//
// Created by Oleksandr Vinichenko on 06.11.2024.
//

#ifndef DB_H
#define DB_H

//#include <iostream>
#include <mysql_connection.h>

namespace DB {
    class Database {
    public:
        Database(sql::Connection* connection);
        sql::Connection* getConnection(){ return connection; };


    private:
        sql::Connection* connection;
    };
}
#endif //DB_H
