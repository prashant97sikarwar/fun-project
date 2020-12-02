#ifndef ATM_H
#define ATM_H
#include <fstream>
#include <cctype>
#include <iomanip>
#include <bits/stdc++.h>
#define ATM_MAX 100000
using namespace std;


class Atm
{
public:
	int id = 1;
        int money;    
        Atm();
        virtual ~Atm();
        

        int ret_amount();
        int cash_replenish(int);
        void draw_from_atm(int);
        void deposit_in_atm(int);
        int ret_id();
};

#endif // ATM_H
