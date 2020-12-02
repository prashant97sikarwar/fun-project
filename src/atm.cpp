#include "Atm.h"
#define ATM_MAX 100000

Atm::Atm()
{
    //ctor
}

Atm::~Atm()
{
    //dtor
}

int Atm::ret_amount()
{
	return money;
}

void Atm::draw_from_atm(int amt)
{
	money -= amt;
}

void Atm::deposit_in_atm(int amt)
{
	money += amt;
}

int Atm::ret_id()
{
	return id;
}

int Atm::cash_replenish(int check)
{
    Atm am;

    cout << "\n\n\n\t\t\t\tENTER AMOUNT:";
    cin >> money;

    fstream inFile;
    system("CLS");
    inFile.open("atm.dat", ios::binary | ios::in | ios::out);
    if (!inFile)
    {
        if(am.ret_amount()+money > ATM_MAX)
	   {
                cout<<"\n\n\n\n\t\t\t\tLIMIT EXCEEDED";
                return 0;
            }
        return 1;
    }
    while (!inFile.eof())
    {
        inFile.read(reinterpret_cast<char *>(&am), sizeof(Atm));
        if (am.ret_id() == 1 && check==1){
            if(am.ret_amount()+money > ATM_MAX)
	   {
                cout<<"\n\n\n\n\t\t\t\tLIMIT EXCEEDED";
                return 0;
            }
            am.deposit_in_atm(money);
            int pos = (-1) * static_cast<int>(sizeof(Atm));
            inFile.seekp(pos, ios::cur); //fncallat1353
            inFile.write(reinterpret_cast<char *>(&am), sizeof(Atm));
            cout<<"\n\n\n\n\t\t\t\tAMOUNT DEPOSITED";
            inFile.close();
            return 0;
        }
        if (am.ret_id() == 1 && check==2){
            if(am.ret_amount()-money<0){
                cout<<"\n\n\n\n\t\t\t\tINSUFFICIENT BALANCE";
                break;
            }
            am.draw_from_atm(money);
            int pos = (-1) * static_cast<int>(sizeof(Atm));
            inFile.seekp(pos, ios::cur); //fncallat1353
            inFile.write(reinterpret_cast<char *>(&am), sizeof(Atm));
            cout<<"\n\n\n\n\t\t\t\tWITHDRAWAL COMPLETED";
            inFile.close();
            return 0;
        }
    }
    return 1;
}
