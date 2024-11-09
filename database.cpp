#include <iostream>
#include "database.h"

DB::Database::Database(sql::Connection* connection) {
   std::cout << "Create Database instance. Connection valid: " << connection->isValid();
   this->connection = connection;
}

