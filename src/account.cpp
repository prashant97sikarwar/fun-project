#include "account.h"
#include <string>
using namespace std;

Account::Account()
{
    //ctor
}

Account::~Account()
{
    //dtor
}

string to_string(int x) {
    std::ostringstream stream;
    stream << x;
    std::string x_str = stream.str();
    return x_str;
}

bool Account::create_account()
{
	system("CLS");
	cout << "\n\n\t\t\t\t======================\n";
	cout << "\t\t\t\tENTER ACCOUNT DETAILS";
	cout << "\n\t\t\t\t======================\n";
	cout << "\n\t\t\tEnter the Account No. : ";
	int acnoTemp,pinTemp;
	char typeTemp;
	cin >> acnoTemp;

	string check = to_string(acnoTemp);
	if (check.length() <= 7 || check.length() >= 16)
	{
		system("CLS");
		cout << "\n\t\t\tTry again with a valid Account number!!!";
		return 0;
	}

	Account ac;
	ifstream inFile;
	inFile.open("account.dat", ios::binary | ios::in | ios::out);
	if (!inFile)
	{
		system("CLS");
		cout << "\n\t\t\tError Occurred. Try again!!";
		return 0;
	}
	while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(Account)))
	{

		if (ac.ret_ac_no() == acnoTemp)
		{
			system("CLS");
			cout << "\n\t\t\tAccount already Exists";
			return 0;
		}
	}

	inFile.close();

	cout << "\n\t\t\tEnter the 4 digit PIN: ";
	cin >> pinTemp;
	int p = pinTemp;

	string c = to_string(p);
	if (c.length() != 4)
	{
		system("CLS");
		cout << "\n\t\t\tTry again with a valid PIN!!!";
		return 0;
	}

	cout << "\n\n\t\t\tEnter the Name of the Account holder : ";
	cin.ignore();
	cin.getline(name, 50);
	cout << "\n\t\t\tEnter Type of the Account (C/S) : ";
	cin >> typeTemp;
	type = toupper(typeTemp);

	if (type != 'S' && type != 'C')
	{
		system("CLS");
		cout << "\n\t\t\tTry again with a valid Account Type!!!";
		return 0;
	}

	acno = acnoTemp;
	pin = pinTemp;
	type = typeTemp;
	cout << "\n\t\t\tEnter The Initial amount : ";
	cin >> deposit;
	return 1;
}

void Account::show_account() const
{
	cout << "\n\n\t\t\t\t======================\n";
	cout << "\t\t\t\tACCOUNT DETAILS";
	cout << "\n\t\t\t\t======================\n";
	cout << "\n\t\t\tAccount No. : " << acno;
	cout << "\n\t\t\tAccount Holder Name : ";
	cout << name;
	cout << "\n\t\t\tType of Account : " << type;
	cout << "\n\t\t\tBalance amount : " << deposit;
}

void Account::modify()
{
	cout << "\n\t\t\tEnter New PIN : ";
	cin >> pin;
}

void Account::deposit_money(int x)
{
	deposit += x;
}

void Account::withdraw(int x)
{
	deposit -= x;
}

void Account::report() const
{
	//cout << acno << setw(10) << " " << name << setw(10) << " " << type << setw(6) << deposit << endl;
	cout << "|   " << acno << setw(5) << "   |   " << setw(5) << name << setw(5) << "   |   "
		 << setw(5) << type << setw(5) << "   |   " << setw(5) << deposit << setw(5) << "  |" << endl;
}

int Account::ret_ac_no() const
{
	return acno;
}
char *Account::ret_name()
{

	return name;
}
int Account::ret_pin() const
{
	return pin;
}

int Account::ret_deposit() const
{
	return deposit;
}

char Account::ret_type() const
{
	return type;
}

