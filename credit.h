#pragma once

#include "account.h"
#include <cmath>


class Credit: public Account{
private:
    int credit_card_number;
    double doubt;
    double interest_rate;
    int period;
    double monthly_payment;
public:
    Credit(Fio fio, int credit_card_number, double doubt, double interest_rate, int period): Account(fio){
        this -> credit_card_number = credit_card_number;
        this -> doubt = doubt;
        this -> interest_rate = interest_rate;
        this -> period = period;
        double r = interest_rate / 12;
        this -> monthly_payment = doubt * r * pow(1 + r, period) / (pow(1 + r, period) - 1);
    }

    Credit(){
        this -> credit_card_number = 0;
        this -> doubt = 0;
        this -> interest_rate = 0;
        this -> period = 0;
        this -> monthly_payment = 0; 
    }

    Credit(const Credit& otherCredit): Account(otherCredit){
        this -> credit_card_number = otherCredit.credit_card_number;
        this -> doubt = otherCredit.doubt;
        this -> interest_rate = otherCredit.interest_rate;
        this -> period = otherCredit.period;
        this -> monthly_payment = otherCredit.monthly_payment;
    }

    ~Credit() override {
        std::cout << "~Credit\n";
    }


    int get_credit_card_number(){
        return this -> credit_card_number;
    }

    double get_doubt(){
        return this -> doubt;
    }

    double get_interest_rate(){
        return this -> interest_rate;
    }

    void init() override {
        fio.init_fio();
        std::cout << "enter credit card number: ";
        credit_card_number = cin<int>();
        std::cout << "enter doubt: ";
        doubt = cin_only_positive<double>();
        std::cout << "enter interest rate: ";
        interest_rate = cin_in_range<double>(0.0, 100.0);
        std::cout << "enter period: ";
        period = cin_in_range<int>(0, 100 * 12);
        double r = interest_rate / 12 / 100;
        monthly_payment = doubt * r * pow(1 + r, period) / (pow(1 + r, period) - 1);
    }

    void credit_payment() {
        std::cout << "how much do you want to pay?\n";
        double payment = cin_in_range<double>(0, doubt + doubt * interest_rate / 12);
        doubt -= payment;
        printf("you have paid %d. The remaining doubt: %d\n", payment, doubt);
    }
    

    std::ostream& print(std::ostream& os) const override {
        // int credit_card_number = consumer.credit_card_number;
        // double doubt = consumer.doubt;
        // double interest_rate = consumer.interest_rate;
        os << "Credit: " << '\n';
        os << fio << "credit card number: " << credit_card_number << '\n' << "doubt: " << doubt << '\n' << "interest rate: " << interest_rate << "\nperiod: " << period << "\nmonthly payment: " << monthly_payment << "\n\n";
        return os; 
    }

    Credit operator+(double sum_to_add){
        Credit new_credit = *this;
        new_credit.doubt += sum_to_add;
        return new_credit;
    } 

};

