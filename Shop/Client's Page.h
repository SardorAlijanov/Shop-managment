#pragma once
#include <iomanip>
namespace Purch
{
	void Buy_Existing(int steps);
	void main(int q, int w, int e);
	class Buy;
	void getBill(int type);
	void LeaveOrder(int bills_order);
}

namespace Counter
{
	class Money;
	void Processor(int type);
}

class Exist
{
public:
	void Purchace(int q)
	{
		if (q==1)
		{
			int steps = 0;
			do
			{
				Purch::Buy_Existing(steps);
				cout << "Do you want to buy something else? (y/n)";
				cin >> answer;
				steps++;
			} while (answer!='n');
			cout << "How would you like to cover bill: " << endl;
			cout << setw(34) << setfill('*') << "\n";
			cout << setw(14) << "1. Cash " << setw(11) << setfill('X') << " 2.Card";
			while (!(cin>>type)||type<1||type>2)
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "Wrong input, enter again: " << endl;
			}
			Purch::getBill(type);
			Counter::Processor(1);
		}
		else if (q==2)
		{
			cout <<"So if you have not seen the wished product, then you may pre-order it, but it will cost you 15%: (y/n) " ;
			cin >> answer;
			if (answer=='n')
			{
				cout << "Okay, have a nice day!";
			}
			else if (answer == 'y')
			{
				int bills_order = 0;
				do
				{
					system("cls");
					Purch::LeaveOrder(bills_order);
					cout << "Do you want to add something to pre-orders?(y/n)";
					cin >> ans;
					bills_order++;
				} while (ans!='n');
			}
		}
	}
private:
	char answer,ans;
	int type;
};

class Client
{
public:
	void Show()
	{
		cout << "***** Here will be a list of avaliable things to purchase! *****" << endl;
	}

	void Ask()
	{
		cout << endl << "This is a list of avaliable things" << endl;
		cout << "Do we have product that you want: " << endl;
		cout << "***** 1. - Yes ***** 2. - No ****" << endl;
	}

private:
	string name, sname;
	int ans;
};