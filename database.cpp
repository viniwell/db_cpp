#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
//#include <cppconn/resultset.h>
#include "database.h"
#include <typeinfo>
#include <vector>

//prints specified fields of ResultSet object
void DB::printResultSet(sql::ResultSet *resultSet, std::vector<std::string> &columnNames) {
    int count = 1;
    if (resultSet == nullptr) {
        throw std::exception("ResultSet pointer is null\n");
    }
    while (resultSet->next()) {
        std::cout << "____________________________________\n";
        std::cout << "Element #" + std::to_string(count) + " of result set: " + "\n";
        for (const std::string& columnName : columnNames) {
            std:: cout << "Property '" << columnName << "' : " << resultSet->getString(columnName) << "\n";
        }
        std::cout << "____________________________________\n";
        count++;
    }

}




DB::Database::Database(const std::string &url, const std::string &username, const std::string &password, const std::string &schema, bool debugMode) {
    this->debugMode = debugMode;

    sql::mysql::MySQL_Driver *driver = sql::mysql::get_mysql_driver_instance();
    this->driver = driver;
    if (debugMode){std::cout << "Created driver instance\n";};

    //create Connection instance
    this->connection =  driver->connect(url, username, password);


    if (connection->isValid()) {
        if (debugMode){std::cout << "Connected to Azure MySQL database successfully!\n";};
    } else {
        //if (debugMode){std::cerr << "Connection failed.\n";};
        throw std::exception("Connection failed.\n");
    }

    connection->setSchema(schema);

    statement = connection->createStatement();
    if (debugMode){std::cout << "Create Statement instance\n";};

}


//Executes query and tries to return a ResultSet. If impossible, return nullptr
sql::ResultSet *DB::Database::execute(std::string &query) {
    statement->execute(sql::SQLString(query));
    try {
        return statement->getResultSet();
    } catch (...) {
        return nullptr;
    }
}





DB::Database::~Database() {
    delete statement;
    connection->close();
    delete connection;
    delete driver;
}


