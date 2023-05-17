#pragma once
#include "database.h"
#include "deposit.h"
#include "credit.h"
#include "fio.h"
#include <cstring>


int switch_tree(Database& database, int func_num);
int choose_func(Database& database);


void start() {
    char buffer[] = "deposit.txt";
    char* deposit_filename = (char*)std::malloc(sizeof(buffer));
    strcpy(deposit_filename, buffer);
    char buffer2[] = "credit.txt";
    char* credit_filename = (char*)std::malloc(sizeof(buffer2));
    strcpy(credit_filename, buffer2);
    Database database_credit(credit_filename);
    Database database_deposit(deposit_filename);
    std::cout << "choose database\n";
    std::cout << "1 - deposit\n" << "2 - credit\n";
    int database_num = cin_in_range<int>(1, 2);
    if (database_num == 1) { 
        while (true) {
            if (choose_func(database_deposit) == 1) {
                break;
            }
        }
    }
    else {
        while (true) {
            if (choose_func(database_credit) == 1) {
                break;
            }
        }
    }
}


int choose_func(Database& database) {
    std::cout << "choose function\n";
    std::cout << "1 - add element\n2 - fio search\n3 - exit\n";
    int func_num = cin_in_range<int>(1, 3);
    return switch_tree(database, func_num);
}


int switch_tree(Database& database, int func_num) {
    if (func_num == 1) {
        if (!strcmp(database.filename, "deposit.txt")) {
            Deposit* profile = new Deposit();
            database.append(profile);
        }
        else {
            Credit* profile = new Credit();
            database.append(profile);
        }
    }   
    else {
        if (func_num == 2){
            database.fio_search();
        }
        else {
            database.exit_program();
            return 1;
        }
    }
    return 0;
}  