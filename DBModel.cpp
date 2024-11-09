//
// Created by Oleksandr Vinichenko on 08.11.2024.
//

#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include "dbModel.h"



DB::DBModel::DBModel(std::string tableName, std::string modelSqlCode) {
    name = tableName;
    modelSqlCode;
}

bool DB::DBModel::create(std::string data) {
    return true;
}


