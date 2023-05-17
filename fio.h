#pragma once

#include "d:/c++/utils/safe_input_exceptions.h"

class Fio {
public:
    std::string first_name;
    std::string middle_name;
    std::string last_name;

    Fio(){
        this -> first_name = "first name";
        this -> middle_name = "middle name";
        this -> last_name = "last name";
    }
    
    Fio(std::string first_name, std::string middle_name, std::string last_name){
        this -> first_name = first_name;
        this -> middle_name = middle_name;
        this -> last_name = last_name;
    }

    Fio(const Fio& otherFio){
        this -> first_name = otherFio.first_name;
        this -> middle_name = otherFio.middle_name;
        this -> last_name = otherFio.last_name;
    }

    ~Fio() {};

    friend std::ostream& operator<<(std::ostream& os, const Fio& fio){
        os << fio.last_name << ' ' << fio.first_name << ' ' << fio.middle_name << '\n';
        return os;
    }

    friend bool operator==(const Fio& lfio, const Fio& rfio){
        if (lfio.first_name == rfio.first_name && lfio.middle_name == rfio.middle_name && lfio.last_name == rfio.last_name) {
            return true;
        }
        return false;
    }

    void init_fio(){
        std::cout << "enter last name: ";
        std::string last_name = cin_string_symbol_only();
        std::cout << "enter first name: ";
        std::string first_name = cin_string_symbol_only();
        std::cout << "enter middle name: ";
        std::string middle_name = cin_string_symbol_only();
        this -> first_name = first_name;
        this -> last_name = last_name;
        this -> middle_name = middle_name;
    }
};