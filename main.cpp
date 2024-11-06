//
// Created by Oleksandr Vinichenko on 06.11.2024.
//

#include <iostream>
#include "database.h"


int main() {
    std::string path = "path";
    auto* db = new DB::Database(path);

    std::cout << "DB path: " << db->getPath() << std::endl;

    delete db;
}