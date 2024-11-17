//
// Created by Oleksandr Vinichenko on 08.11.2024.
//

#ifndef DBMODEL_H
#define DBMODEL_H

#include <iostream>
#include <vector>

static std::string emptyString;
namespace DB {

    class DBModel {

    public:
        //Constructor
        DBModel(std::string &name, Database* db, std::string &tableCode = emptyString);

        //checks whether table with the same name exists
        bool isInitialized();

        //Executes 'INSERT' sql query with specified fields and condition, returns nothing
        void insert(std::string &fields, std::string values);
        //Executes 'SELECT' sql query with specified fields and condition, returns ResultSet
        sql::ResultSet* select(std::string &fields, std::string &condition=emptyString);

    private:
        std::string name;
        Database* db;
    };
}





#endif //DBMODEL_H
