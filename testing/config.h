//
// Created by Oleksandr Vinichenko on 09.11.2024.
//

#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>

class Config {
public:
    Config() = default;

    /*const std::string url = "tcp://dbcppserver.database.windows.net:3306/dbcppdatabase";
    const std::string username = "dbcpp";//"vooleksandrov22@codingburgas.bg";//dbcpp
    const std::string password = "pW12345678!";//pW12345678!*/

    const std::string url = "tcp://127.0.0.1:3306";
    const std::string username = "root";//"vooleksandrov22@codingburgas.bg";//dbcpp
    const std::string password = "07282009IIIi$";//pW12345678!
};
#endif //CONFIG_H
