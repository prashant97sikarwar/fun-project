#define _WIN32_WINNT 0x0502
#include<windows.h>
#include <iostream>
#include <fstream>
#include <graphics.h>
#include <cctype>
#include <iomanip>
#include <bits/stdc++.h>
#include "account.h"
#include "atm.h"
#define ATM_MAX 100000

using namespace std;

void graphic_start(void);
void graphic_end(void);
void already_exists();
void write_account();
void display_sp(int, int);
void modify_account(int, int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int);
void admin_account();
void transfer_money(int);
void cash_add();
void available_amount_atm();
void cash_draw();

int main()
{
    system("Color 70");

    graphic_start();
	char ch;
	int num, p;
	while (true) {
		system("CLS");
		cout << "\n\n\t\t\t\t======================\n";
		cout << "\t\t\t\tBANK MANAGEMENT SYSTEM";
		cout << "\n\t\t\t\t======================\n";
		cout << "\t\t\t\t    ::MAIN MENU::\n";
		cout << "\n\t\t\t\t1. NEW ACCOUNT";
		cout << "\n\t\t\t\t2. PRE-EXISTING ACCOUNT";
		cout << "\n\t\t\t\t3. ADMIN ACCOUNT";
		cout << "\n\t\t\t\t4. EXIT";
		cout << "\n\n\t\t\t\tSelect Your Option (1-4): ";
		cin >> ch;
		switch (ch)
		{
		case '2':
			already_exists();
			break;
		case '1':
			write_account();
			break;
		case '3':
			admin_account();
			break;
		case '4':
			system("CLS");
			graphic_end();
			return 0;
		default:
			cout << "\a";
		}

		cin.ignore();
		cin.get();
	}

	return 0;
}

void graphic_start()
{
    int gd=5, gm, errorcode;
    int col,i=0,j;
    initgraph(&gd, &gm, "");

    while(5*i<=700)
    {
        setbkcolor(10);
        setcolor(3);
        rectangle(0+10*i,0+10*i,getmaxx()-10*i,getmaxy()-10*i);
        i++;
    }

    i=0;
    setcolor(4);
    settextstyle(1,0,6);

    Sleep(5);
    cleardevice();
    while(5*i<=700)
    {
        setbkcolor(15);
        setcolor(3);
        circle(getmaxx()/2,getmaxy()/2,i*5);
        i++;
    }

    setcolor(1);
    settextstyle(10,0,7);
    outtextxy(170 ,getmaxy()/2-85,"Welcome");
    outtextxy(280,getmaxy()/2-25,"To");
    outtextxy(120,getmaxy()/2+25,"MIT2020 Bank");

    Sleep(3);
    i=0;
    while(i<=130)
    {
        setbkcolor(1);
        setcolor(3);
        line(i*3,0,i*3,getmaxy());
        line(getmaxx()-i*3,0,getmaxx()-i*3,getmaxy());
        i++;
    }
    Sleep(1);
    i=getmaxy();
    while(i>0)
   {
        line(getmaxx()/2,getmaxy(),getmaxx(),i-=10);
        delay(10);
   }
      i=getmaxx();
    while(i>0)
   {
        line(getmaxx()/2,getmaxy(),i-=10,0);
        delay(10);
   }
     i=0;

     while(i<getmaxy())
    {
        line(getmaxx()/2,getmaxy(),0,i+=10);
        delay(10);
    }

    closegraph();
    int c;
    do c = getchar(); while (c != EOF && c != '\n');
 }

 void graphic_end()
{
    int gd=5, gm, errorcode;
    int col,i=0,j;
    initgraph(&gd, &gm, "");

    while(5*i<=700)
    {
        setbkcolor(10);
        setcolor(3);
        rectangle(0+10*i,0+10*i,getmaxx()-10*i,getmaxy()-10*i);
        i++;
    }

    i=0;
    setcolor(4);
    settextstyle(1,0,6);

    Sleep(5);
    cleardevice();
    while(5*i<=700)
    {
        setbkcolor(15);
        setcolor(3);
        circle(getmaxx()/2,getmaxy()/2,i*5);
        i++;
    }

    setcolor(1);
    settextstyle(10,0,6);
    outtextxy(180 ,getmaxy()/2-85,"Thank You");
    outtextxy(260,getmaxy()/2-25,"For");
    outtextxy(110,getmaxy()/2+25,"Banking With Us");

    Sleep(3);
    i=0;
    while(i<=130)
    {
        setbkcolor(1);
        setcolor(3);
        line(i*3,0,i*3,getmaxy());
        line(getmaxx()-i*3,0,getmaxx()-i*3,getmaxy());
        i++;
    }
    Sleep(1);
    i=getmaxy();
    while(i>0)
   {
        line(getmaxx()/2,getmaxy(),getmaxx(),i-=10);
        delay(10);
   }
      i=getmaxx();
    while(i>0)
   {
        line(getmaxx()/2,getmaxy(),i-=10,0);
        delay(10);
   }
     i=0;

     while(i<getmaxy())
    {
        line(getmaxx()/2,getmaxy(),0,i+=10);
        delay(10);
    }

    closegraph();
    int c;
    do c = getchar(); while (c != EOF && c != '\n');
 }

void admin_account()
{
    int num, p;
    char ch;
    Account ac;
    system("CLS");
    cout << "\n\n\t\t\t\t======================\n";
    cout << "\t\t\t\tENTER ACCOUNT DETAILS";
    cout << "\n\t\t\t\t======================\n";
    cout << "\n\t\t\t\tEnter Account No:";
    cin >> num;
    cout << "\n\t\t\t\tEnter PIN:";
    cin >> p;
    bool flag = false;
    bool check = false;
    Atm at;

    Account admin;
    ofstream outFile;
    outFile.open("admin.dat", ios::binary | ios::app);
    admin.acno = 9999;
    admin.pin = 1111;
    admin.deposit = 0;
    outFile.write(reinterpret_cast<char *>(&admin), sizeof(Account));
    outFile.close();

    ifstream inFile;
    system("CLS");
    inFile.open("admin.dat", ios::binary);
    if (!inFile)
    {
        cout << "\n\n\t\t\tError Occurred.";
        return;
    }

    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(Account)))
    {

        if (ac.ret_ac_no() == num && ac.ret_pin() == p)
        {
            do
            {
                system("CLS");
                cout << "\n\n\t\t\t\t===========================\n";
                cout << "\t\t\t\t\tADMIN PORTAL";
                cout << "\n\t\t\t\t===========================\n";
                cout << "\n\t\t\t\t1. COMPLETE ACCOUNT HOLDERS LIST";
                cout << "\n\t\t\t\t2. DEPOSIT CASH";
                cout << "\n\t\t\t\t3. WITHDRAW CASH";
                cout << "\n\t\t\t\t4. CHECK AVAILABLE BALANCE";
                cout << "\n\t\t\t\t5. Exit";
                cout << "\n\n\t\t\t\tSelect Your Option (1-5): ";
                cin >> ch;
                switch (ch)
                {
                case '1':
                    system("CLS");
                    display_all();
                    break;
                case '2':
                    system("CLS");
                    cash_add();
                    break;
                case '3':
                    system("CLS");
                    cash_draw();
                    break;
                case '4':
                    system("CLS");
                    available_amount_atm();
                    break;
                case '5':
                    return;

                default:
                    cout << "\a";
                }

                cin.ignore();
                cin.get();
            } while (ch != '5');
        }
    }
}

void available_amount_atm()
{
	Atm ac;

	ifstream inFile;
	system("CLS");
	inFile.open("atm.dat", ios::binary);
	if (!inFile)
	{
		cout << "\n\n\t\t\tError Occurred.";
		return;
	}

	while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(Atm)))
	{
		if(ac.ret_id()==1){
			cout<<"\n\n\t\t\tAVAILABLE AMOUNT:"<<ac.ret_amount();
		}
	}

	inFile.close();
}

void cash_add()
{
    Atm ac;
    ofstream outFile;

    if (ac.cash_replenish(1))
    {
        remove("atm.dat");
        outFile.open("atm.dat", ios::binary | ios::app);
        outFile.write(reinterpret_cast<char *>(&ac), sizeof(Account));
        cout<<"\n\t\t\t\tAMOUNT DEPOSITED";
        outFile.close();
    }
}

void already_exists()
{
	int num, p, num1, amount;
	char ch;
	Account ac;
	system("CLS");
	cout << "\n\n\t\t\t\t======================\n";
	cout << "\t\t\t\tENTER ACCOUNT DETAILS";
	cout << "\n\t\t\t\t======================\n";
	cout << "\n\t\t\t\tEnter Account No:";
	cin >> num;
	cout << "\n\t\t\t\tEnter PIN:";
	cin >> p;
	bool flag = false;
	bool check = false;
	bool del = false;
	ifstream inFile;
	system("CLS");
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "\n\n\t\t\tError Occurred.";
		return;
	}

	while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(Account)))
	{
		if (ac.ret_ac_no() == num && ac.ret_pin() == p)
		{

			check = true;
			inFile.close();
			do
			{
				system("CLS");

				cout << "\n\n\t\t\t\t======================\n";
				cout << "\t\t\t\tWELCOME " << ac.ret_name();
				cout << "\n\t\t\t\t======================\n";

				cout << "\t\t\t\t    ::MAIN MENU::\n";
				cout << "\n\t\t\t\t1. DEPOSIT AMOUNT";
				cout << "\n\t\t\t\t2. WITHDRAW AMOUNT";
				cout << "\n\t\t\t\t3. BALANCE ENQUIRY";
				cout << "\n\t\t\t\t4. CLOSE AN ACCOUNT";
				cout << "\n\t\t\t\t5. PIN CHANGE";
				cout << "\n\t\t\t\t6. TRANSFER AMOUNT";
				cout << "\n\t\t\t\t7. EXIT";
				cout << "\n\n\t\t\t\tSelect Your Option (1-7): ";
				cin >> ch;

				switch (ch)
				{

				case '1':
					system("CLS");
					deposit_withdraw(num, 1);
					break;
				case '2':
					system("CLS");
					deposit_withdraw(num, 2);
					break;
				case '3':
					system("CLS");
					display_sp(num, p);
					break;
				case '4':
					system("CLS");
					del = true;
					delete_account(num);
					return;
				case '5':
					system("CLS");
					modify_account(num, p);
					break;
				case '6':
					system("CLS");
					transfer_money(num);
					break;
				case '7':
                    return;

				default:
					cout << "\a";
				}
				cin.ignore();
				cin.get();
			} while (ch != '7');
			break;
		}
	}
	if (check == false)
	{

		cout << "\n\t\t\t\tEntered wrong account number or password";
	}
}

void transfer_money(int ac1)
{

	bool found = false, NB = false;
	Account act1, act2;
	fstream File;
	int ac2, n;
	cout << "\n\t\t\t\tEnter Payee Account No:";
	cin >> ac2;
	cout << "\n\t\t\t\tEnter Amount To be Transferred:";
	cin >> n;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "\n\n\t\t\tError Occurred.";
		return;
	}
	while (!File.eof())
	{
		File.read(reinterpret_cast<char *>(&act1), sizeof(Account));
		if (act1.ret_ac_no() == ac1)
		{
			int bal = act1.ret_deposit() - n;
			if (bal < 0)
			{
				cout << "\n\n\t\t\tInsufficient Balance!";
				NB = true;
			}
			break;
		}
	}
	File.close();

	if (!NB)
	{
		File.open("account.dat", ios::binary | ios::in | ios::out);
		while (!File.eof())
		{
			File.read(reinterpret_cast<char *>(&act2), sizeof(Account));

			if (act2.ret_ac_no() == ac2)
			{
				act2.deposit_money(n);
				int pos = (-1) * static_cast<int>(sizeof(act2));
				File.seekp(pos, ios::cur); //fncallat1353
				File.write(reinterpret_cast<char *>(&act2), sizeof(Account));
				cout << "\n\n\t\t\t\t\t\tAmount Deposited to" << ac2;
				found = true;
				break;
			}
		}
		File.close();
		if(found)
		{
		    File.open("account.dat", ios::binary | ios::in | ios::out);
            while (!File.eof())
            {
			File.read(reinterpret_cast<char *>(&act1), sizeof(Account));
                if (act1.ret_ac_no() == ac1)
                {
                    act1.withdraw(n);
                    act1.show_account();
                    int pos = (-1) * static_cast<int>(sizeof(act1));
                    File.seekp(pos, ios::cur);
                    File.write(reinterpret_cast<char *>(&act1), sizeof(Account));
                    break;
                }
            }
            File.close();
		}
	}

	File.close();
	if (!NB && found == false)
	{
		cout << "\n\n\t\t\tAccount Not Found ";
	}
}

void write_account()
{
	Account ac;
	ofstream outFile;
    outFile.open("account.dat", ios::binary | ios::app);
    outFile.close();

	if (ac.create_account())
	{
		outFile.open("account.dat", ios::binary | ios::app);
		outFile.write(reinterpret_cast<char *>(&ac), sizeof(Account));
		outFile.close();
		cout << "\n\n\t\t\tAccount Created!!!";
	}

}

void display_sp(int n, int p)
{
	Account ac;
	bool flag = false;
	ifstream inFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "\n\n\t\t\tError Occurred.";
		return;
	}
	cout << "\n\t\t\tBALANCE DETAILS\n";
	while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(Account)))
	{
		if (ac.ret_ac_no() == n)
		{
			ac.show_account();
			flag = true;
		}
	}
	inFile.close();
	if (flag == false)
	{
		cout << "\n\t\t\tAccount does not exist!!";
	}
}

void modify_account(int n, int p)
{
	bool found = false;
	Account ac;
	fstream File;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "\n\n\t\t\tError Occurred.";
		return;
	}
	while (!File.eof() && found == false)
	{
		File.read(reinterpret_cast<char *>(&ac), sizeof(Account));
		if (ac.ret_ac_no() == n && ac.ret_pin() == p)
		{
			ac.show_account();
			ac.modify();
			int pos = (-1) * static_cast<int>(sizeof(Account));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char *>(&ac), sizeof(Account));
			cout << "\n\n\t\t\tPIN changed";
			found = true;
		}
	}
	File.close();
	if (found == false)
		cout << "\n\n\t\t\tRecord Not Found ";
}

void delete_account(int n)
{
	Account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat", ios::in |ios::binary);
	if (!inFile)
	{
		cout << "\n\n\t\t\tError Occurred.";
		return;
	}
	outFile.open("Temp.dat", ios::out |ios::binary);
	inFile.seekg(0, ios::beg);
	while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(Account)))
	{
		if (ac.ret_ac_no() != n)
		{
			outFile.write(reinterpret_cast<char *>(&ac), sizeof(Account));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat", "account.dat");
	cout << "\n\n\t\t\tRecord Deleted ..";
//	display_all();
}

void display_all()
{
	system("CLS");
	Account ac;
	ifstream inFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "\n\n\t\t\tError Occurred.";
		return;
	}
	cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout << "====================================================\n";
	//cout << "A/c no.      NAME           Type    Balance\n";
	cout << "   A/c no.  " << setw(15) << "   Name   " << setw(15)
		 << "   Type   " << setw(15) << "   Balance   " << setw(15) << endl;
	cout << "====================================================\n";
	while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(Account)))
	{
		ac.report();
	}
	inFile.close();
}

void deposit_withdraw(int n, int option)
{
	int amt;
	bool found = false;
	Account ac;
	Atm at;
	fstream File, atFile;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	atFile.open("atm.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "\n\n\t\t\tError Occurred.";
		return;
	}
	while (!File.eof() && found == false)
	{
		File.read(reinterpret_cast<char *>(&ac), sizeof(Account));

		if (ac.ret_ac_no() == n)
		{
			ac.show_account();
			if (option == 1)
			{
				cout << "\n\n\t\t\tTO DEPOSITSS AMOUNT";
				cout << "\n\n\t\t\tEnter The amount to be deposited: ";
				cin >> amt;

				while (!atFile.eof())
					{
						atFile.read(reinterpret_cast<char *>(&at), sizeof(Atm));
						if (at.ret_id() == 1 && at.ret_amount()+amt > 100000)
						{
							cout << "\n\n\t\t\tCAN'T DEPOSIT!!";
							found = true;
							break;
						}
						else
						{

							if (at.ret_id() == 1)
							{
								at.deposit_in_atm(amt);
								ac.deposit_money(amt);
								break;
							}
						}
					}
					if (found == true)
						break;
			}

			if (option == 2)
			{
				cout << "\n\n\t\t\tTO WITHDRAW AMOUNT";
				cout << "\n\n\t\t\tEnter the Amount to be Withdrawn: ";
				cin >> amt;
				int bal = ac.ret_deposit() - amt;
				if (bal < 0)
				{
					cout << "\n\n\t\t\tInsufficient Balance!";
					found = true;
					break;
				}
				else
				{
					while (!atFile.eof())
					{
						atFile.read(reinterpret_cast<char *>(&at), sizeof(Atm));
						if (at.ret_id() == 1 && at.ret_amount() < amt)
						{
							cout << "\n\n\t\t\tCash Not Available!!";
							found = true;
							break;
						}
						else
						{

							if (at.ret_id() == 1)
							{
								at.draw_from_atm(amt);
								ac.withdraw(amt);
								break;
							}
						}
					}
					if (found == true)
						break;
				}
			}
			int pos = (-1) * static_cast<int>(sizeof(ac));
			File.seekp(pos, ios::cur); //fn1353
			File.write(reinterpret_cast<char *>(&ac), sizeof(Account));
			int post = (-1) * static_cast<int>(sizeof(at));
			atFile.seekp(post, ios::cur); //fn1353
			atFile.write(reinterpret_cast<char *>(&at), sizeof(Atm));
			cout << "\n\n\t\t\tRecord Updated";
			found = true;
		}
	}
	File.close();
	atFile.close();
	if (found == false)
		cout << "\n\n\t\t\tRecord Not Found ";
}

void cash_draw()
{
    Atm ac;
    ofstream outFile;

    ac.cash_replenish(2);

}

