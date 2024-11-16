//
// Created by Oleksandr Vinichenko on 08.11.2024.
//

#include <iostream>
#include <utility>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>

#include "database.h"
#include "dbModel.h"


DB::DBModel::DBModel(std::string &name, DB::Database *db, std::string &tableCode) {
    //assign properties
    this->name = std::move(name);
    this->db = db;

    //create table, if does not exists
    if (!isInitialized()) {
        const char* message = ("Table with name '" + this->name + "' is not initialized. Creating a new one.").c_str();
        std::wcerr << message;

        //check if SQL code is valid
        if (tableCode.empty()) {
            const char* message = ("Table with name '" + this->name + "' is not yet created and tableCode is not specified.").c_str();
            throw std::exception(message);
        }

        //create table
        std::string query = "CREATE TABLE " + this->name + "(" +
                            tableCode+
                            ");";
        db->execute(query);
    }
}


bool DB::DBModel::isInitialized() {
    std::string query = "SHOW TABLES LIKE '" + this->name + "'";
    sql::ResultSet* res = db->execute(query);

    //checks if ResultSet contains something, true means it returned table info
    return res->next();
}



void DB::DBModel::insert(std::string &fields, std::string values) {
    std::string query = "INSERT INTO " + name + " ( " + fields + " ) values ( " + values + " )";
    db->execute(query);
}



/*bool DB::DBModel::create(std::string data) {
    return true;
}*/


