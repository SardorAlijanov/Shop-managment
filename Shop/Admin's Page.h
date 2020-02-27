#pragma once
#include "1st_Page.h"
namespace AddProd
{
	void SetName(string name);
	void SetQuantity(string name);
	void AddPreOrdered();
}

class Admin;

class Checker
{
public:
	ifstream in, in1;
	ofstream out, out1;
	bool Checking(string login, string password)
	{
		advancer = 0, checking_number  =  0;
		in.open("Admins.txt");
		while (!in.eof())
		{
			in >> Admins[temp];
			temp++;
			counter = temp;
		}
		in.close();
		in1.open("Passwords.txt");
		for (int w = 0; w < counter; w++)
		{
			in1 >> Passwords[w];
		}
		in1.close();
		while (checking_number != counter)
		{
			if (login == Admins[checking_number] && password == Passwords[checking_number])
			{
				checking_number =  counter;
				advancer = 1;
			}
			else
			{
				checking_number++;
				if (checking_number == counter)
				{
					return false;
				}
			}
		}
		return  true;
	}
	int Getadvancer()
		{
			return advancer;
		}
private:
	int temp = 0, checking_number, advancer, counter;
	string Admins[5], Passwords[5];
};

class Admin
{
public:
	ifstream in, in1, in2;
	ofstream out, out1;
	Checker c;
	void Show()
	{
		string p, l;
		cout << "***********************************" << '\n';
		cout << "Enter login and password" << endl;
		cin >> l >> p;
		c.Checking(l, p);
		if (c.Getadvancer()!=1)
		{
			cout << "Autharization error" << endl;
			cout << "Re - enter again!" << endl;
			Show();
		}
		cout << "Welcome, admin" << endl;
	}
	void ShowQuantity()
	{
		system("cls");
		in.open("White_Goods_Name.txt");
		temp = 0;
		while (!in.eof())
		{
			in >> Names[temp];
			temp++;
			nmsize =  temp;
		}
		in.close();
		in1.open("White_Goods_Number.txt");
		for (int q = 0; q < nmsize; q++)
		{
			in1 >> number[q];  
		}
		in1.close();
		in2.open("White_Goods_Prizes.txt");
		for (int w = 0; w < nmsize; w++)
		{
			in2 >> prize[w];
		}
		in2.close();
		for (int e = 0; e < nmsize; e++)
		{
			cout << endl << e + 1 << ". " << Names[e] << " - " << number[e] << " left - " << prize[e] << " soums" << endl;
		}
	}
	void AddQuantity()
	{
		system("cls");
		ShowQuantity();
		cout << "Enter number of product: ";
		while (!(cin >> prod_num) || prod_num<1 || prod_num>nmsize)
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << endl << "*****No such product, re-enter: *****" << endl;
		}
		cout << "Enter quantity on which you want to add/reduce: ";
		while (!(cin >> quant) || number[prod_num - 1] + quant < 0)
		{
			cin.clear();
			while (cin.get() != '\n');
			cout<<endl << "*****Impossible to reduce on such value, re-enter: *****";
		}
		system("cls");
		number[prod_num - 1] = number[prod_num - 1] + quant;
			out.open("White_Goods_Number.txt");
			cout << "Data successfully changed" << endl;
			for (int r = 0; r < nmsize; r++)
			{
				out << number[r] << endl;
			}
			out.close();
	}
	void ChangePrize()
	{
		temp = 0;
		cout << "This is current prices" << endl;
		cout << "************************" << endl;
		in.open("White_Goods_Name.txt");
		while (!in.eof())
		{
			in >> Names[temp];
			temp++;
			nmsize =  temp;
		}
		in.close();
		in1.open("White_Goods_Prizes.txt");
		for (int t = 0; t < nmsize; t++)
		{
			in1 >> prize[t];
		}
		in1.close();
		for (int y = 0; y < nmsize; y++)
		{
			cout << y + 1 << ". " << Names[y] << " - " << prize[y] << endl;
		}
		cout << "Enter number of product that you want to change: " << endl;
		while (!(cin >> prod_num) || prod_num<0 || prod_num>nmsize)
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "No such product, re-enter: ";
		}
		cout << "Enter value that you want the price to be increased/decreased: " << endl;
		while (!(cin >> price) || prize[prod_num - 1] + price < 0)
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Impossible to reduce on such price,enter again: ";
		}
		prize[prod_num - 1] = prize[prod_num - 1] + price;
		out.open("White_Goods_Prizes.txt");
		cout << "Data successfully changed" << endl;
		for (int i = 0; i < nmsize; i++)
		{
			out << prize[i] << endl;
		}
		out.close();
	}
	void AddAdmin()
	{
		temp = 0;
		in.open("Admins.txt");
		while (!in.eof())
		{
			in>>Admins[temp];
			temp++;
		}
		in.close();
		if (5-temp<=0)
		{
			cout << "The limit of 5 admins is reached! Cannot add any new!" << endl;
		}
		else
		{
			cout << "Available number out of 5 users is " << 5 - temp << endl;
			cout << "************************" << endl;
			cout << "Enter login for new user: " << endl;
			cin >> Admins[5 - temp];
			out.open("Admins.txt",ios::app);
			out << endl << Admins[5 - temp];
			out.close();
			cout << "Enter password for new user: " << endl;
			cin >> Passwords[5 - temp];
			out1.open("Passwords.txt", ios::app);
			out1 << endl << Passwords[5 - temp];
			out1.close();
			temp++;

		}
	}
	void Action()
	{
		do
		{
			cout << "What would you like to do: " << endl;	cout << "1. See white goods" << endl;cout << "2. Add/Reduce white goods(quantity)" << endl;
			cout << "3. Change the price" << endl;
			cout << "4. See profit" << endl;
			cout << "5. Add new product" << endl;
			cout << "6. Add new admin" << endl;
			cout << "7. See pre - orders" << endl;
			cout << "8. Quit" << endl;
			while (!(cin>>wish))
			{
				cin.clear();
				while (cin.get() != '\n.');
				cout << "Wrong input, only digits are accepted, enter once again:" << endl;
			}
			system("cls");
			switch (wish)
			{
			case 1:
			{
					  ShowQuantity();
					  break;
			}
			case 2:
			{
					  AddQuantity();
					  break;
			}
			case 3:
			{
					  ChangePrize();
					  break;
			}
			case 4:
			{
					  ifstream in;
					  in.open("Profit.txt");
					  in >> profit;
					  cout <<"So far profit is: " <<profit <<" soums"<<endl;
					  in.close();
					  break;
			}
			case 5:
			{
					  ShowQuantity();
					  cout << "Enter name for a new product: ";
					  cin >> product;
					  AddProd::SetName(product);
					  AddProd::SetQuantity(product);
					  cout << "These changes will be added from the next session!" << endl;
					  break;
			}
			case 6:
			{
					  AddAdmin();
					  break;
			}
			case 7:
			{
					  AddProd::AddPreOrdered();
					  break;
			}
			case 8:
			{
					  break;
			}
			default:
			{
					   cout << "Wrong input! Re-enter!";
			}
				break;
			}
			cout << "***** Press any bottom... *****";
			_getch();
			system("cls");
		} while (wish!=8);
	}
	int Get()	{ return nmsize; }
	string GetProd(int q)	{return Names[q - 1];	}
	int GetPrise(int q)	{ return prize[q - 1];}
private:
	string Names[150], Admins[5], Passwords[5], product;
	int prod_num, temp = 0,profit, number[150], prize[150], nmsize, wish, quant, price;
};