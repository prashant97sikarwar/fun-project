#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <fstream>
#include <cctype>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

class Account
{
    public:
        int acno;
        int pin;
        char name[50];
        int deposit;
        char type;
        Account();
        virtual ~Account();



        bool create_account();
        void show_account() const;
        void modify();
        void deposit_money(int);
        void withdraw(int);
        void report() const;
        int ret_ac_no() const;
        int ret_pin() const;
        int ret_deposit() const;
        char ret_type() const;
        char *ret_name();

};

#endif // ACCOUNT_H
