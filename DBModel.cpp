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


DB::DBModel::DBModel(std::string &name, Database *db, std::string &tableCode) {
    //assign properties
    this->name = std::move(name);
    this->db = db;

    //create table, if does not exists
    if (!isInitialized()) {
        const char* message = ("Table with name '" + this->name + "' is not initialized. Creating a new one.").c_str();
        std::wcerr << message;

        //check if SQL code is valid
        if (tableCode.empty()) {
            const char* message = ("Table with name '" + this->name + "' is not yet created and tableCode is not valid.").c_str();
            throw std::exception(message);
        }

        //create table
        std::string query = "CREATE TABLE " + this->name + "(" +
                            tableCode+
                            ");";
        db->execute(query);
    }
}


//checks whether table with the same name exists
bool DB::DBModel::isInitialized() {
    std::string query = "SHOW TABLES LIKE '" + this->name + "'";
    sql::ResultSet* res = db->execute(query);
    try {
        //checks if ResultSet contains something, true means it returned table info
        return res->next();
    } catch(...) {
        return false;
    }

}


//Executes 'INSERT' sql query with specified fields and condition, returns nothing
void DB::DBModel::insert(std::string &fields, std::string values) {
    std::string query = "INSERT INTO " + name + " ( " + fields + " ) values ( " + values + " );";
    db->execute(query);
}

//Executes 'SELECT' sql query with specified fields and condition, returns ResultSet
sql::ResultSet* DB::DBModel::select(std::string &fields, std::string &condition) {
    std::string query = "SELECT " + fields + " FROM " + name + (!condition.empty() ? (" WHERE "+condition) : "") + ";";
    return db->execute(query);
}

//Executes 'DELETE' sql query with specified condition, returns nothing
void DB::DBModel::sqlDelete(std::string &condition) {
    std::string query = "delete from " + name + (!condition.empty() ? (" where " + condition) : "") + ";";
    db->execute(query);
}



