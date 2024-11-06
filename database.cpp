#include <iostream>
#include "database.h"

DB::Database::Database(std::string &path) {
    std::cout << "Initialised database with path " << path << std::endl;
    this->path = path;
}
