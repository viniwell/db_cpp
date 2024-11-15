#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
//#include <cppconn/resultset.h>
#include "database.h"


DB::Database::Database(const std::string &url, const std::string &username, const std::string &password, const std::string &schema) {
    sql::mysql::MySQL_Driver *driver = sql::mysql::get_mysql_driver_instance();
    this->driver = driver;
    std::cout << "Created driver instance\n";

    //create Connection instance
    this->connection =  driver->connect(url, username, password);


    if (connection->isValid()) {
        std::cout << "Connected to Azure MySQL database successfully!\n";
    } else {
        std::cerr << "Connection failed.\n";
    }

    connection->setSchema(schema);
    std::cout << "Connection valid: " << connection->isValid() << "\n";


    statement = connection->createStatement();
    std::cout << "Create Statement instance\n";
}







DB::Database::~Database() {
    connection->close();
    delete connection;
    delete driver;
}


