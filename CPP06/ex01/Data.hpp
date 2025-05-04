#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data {
    int number;
    std::string text;

    Data();                             
    Data(const Data& copy);               
    Data& operator=(const Data& copy);    
    ~Data();                               
};

#endif
