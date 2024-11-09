//
// Created by Oleksandr Vinichenko on 08.11.2024.
//

#ifndef DBMODEL_H
#define DBMODEL_H

#include <iostream>
#include <vector>

namespace DB {
    class DBModel {
    public:
        DBModel(std::string tableName, std::string modelSqlCode);

        bool create(std::string data);

    private:
        std::string name;
        std::vector<std::string> fields;
    };
}





#endif //DBMODEL_H
