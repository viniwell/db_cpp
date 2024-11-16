//
// Created by Oleksandr Vinichenko on 08.11.2024.
//

#ifndef DBMODEL_H
#define DBMODEL_H

#include <iostream>
#include <vector>

static std::string defaultTableCode;
namespace DB {

    class DBModel {

    public:
        //Constructor
        DBModel(std::string &name, DB::Database* db, std::string &tableCode = defaultTableCode);

        //returns whether table with specifies name exists
        bool isInitialized();
        //void init();


        void insert(std::string &fields, std::string values);

    private:
        std::string name;
        DB::Database* db;
        //std::vector<std::string> fields;
    };
}





#endif //DBMODEL_H
