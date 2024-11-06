//
// Created by Oleksandr Vinichenko on 06.11.2024.
//

#ifndef DB_H
#define DB_H

#include <iostream>

namespace DB {
    class Database {
    public:
        Database(std::string &path);
        std::string getPath(){ return path; };


    private:
        std::string path;
    };
}
#endif //DB_H
