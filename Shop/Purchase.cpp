#pragma once
#include "1st_Page.h"
ostream &Name(ostream &nque)
{
	cout << "Enter name of product to pre-order: ";
	return nque;
}
ostream &Number(ostream &numb)
{
	cout << "Enter quantity of product to pre-order: ";
	return numb;
}
namespace Purch
{
	void Buy_Existing(int steps)
	{
		ifstream in;
		::Admin a; int num, sum = 0, quant = 1, quants[150], counter = 0, limit = 0;
		a.ShowQuantity();
		cout << "Enter the number of product: ";
		while (!(cin >> num) || num <= 0 || num > a.Get())
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Wrong input, only digits from 1 to " << a.Get() << " are accepted, re - enter: ";
		}
		in.open("White_Goods_Number.txt");
		while (!(in.eof()))
		{
			in >> quants[counter];
			counter++;
			limit = counter;
		}
		in.close();
		cout << "Enter how many of " << a.GetProd(num)<<" you want to purchase: ";
		while (!(cin >> quant) || quant <= 0||quants[num-1]<quant)
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Wrong input, only digits are accepted, or given value is more than existing quantity of product, re - enter: ";
		}
		ofstream out1;
		out1.open("Quantity.txt",ios::app);
		out1 << quant << endl;
		out1.close();
		quants[num - 1] -= quant;
		main(num, quant, steps);
		ofstream out;
		out.open("White_Goods_Number.txt");
		counter = 0;
		while (counter!=limit)
		{
			out << quants[counter] << endl;
			counter++;
		}
		out.close();
		if (steps==0)
		{
			out.open("Temp_Products.txt");
		}
		else
		{
			out.open("Temp_Products.txt",ios::app);
		}
		out << a.GetProd(num) <<a.GetPrise(num) <<endl;
		out.close();
	}
	class Buy
	{
	public:
		Buy(int prodnumber,int prodquant,int steps)
		{
			ifstream in;
			in.open("White_Goods_Prizes.txt");
			while (counter!=prodnumber)
			{
				int money;
				in >> money;
				this->money = money;
				counter++;
			}
			in.close();
			this->sum = prodquant * this->money;
			cout <<"Current price: "<< GetSum(steps) << endl;
			GetProfit();
		}
		int GetSum(int steps)
		{
			ofstream out;
			ifstream in;
			if (steps==0)
			{
				out.open("Temp.txt");
				out << 0;
				out.close();
			}
			in.open("Temp.txt");
			in >> temp;
			in.close();
			sum += temp;
			out.open("Temp.txt");
			out << sum;
			out.close();
			profit = sum;
			return sum;
		}
		void GetProfit()
		{
			ifstream in;
			in.open("Profit.txt");
			in >> temp1;
			in.close();
			profit += temp1;
			ofstream out;
			out.open("Profit.txt");
			out << profit;
			out.close();
		}
	private:
		int temp, temp1, money, counter = 0, profit = 0, sum = 0;
	};
	void main(int q, int w, int e)
	{
		Buy b(q, w, e);
	}
	void getBill(int type)
	{
		string product, cardnumber;
		int value, *ptrvalue, limit = 0, q;
		system("cls");
		cout << "\tJan Shop\n";
		ifstream in,in1;
		if (type==1)
		{
			in.open("Temp_Products.txt");
			while (!(in.eof()))
			{
				in >> product;
				limit++;
			}
			in.close();
			in.open("Temp_Products.txt");
			in1.open("Quantity.txt");
			cout << "Name(s)\t" << "\tvalue(s)" << endl;
			for (int j = 1; j!=limit; j++)
			{
				in >> product;
				for (int i = 0; product[i] != '\0'; i++)
				{
					if (isalpha(product[i]) != 0)
					{
						cout << product[i];
					}
				}
				cout << setw(12) << setfill('.');
				for (int i = 0; product[i] != '\0'; i++)
				{
					if (isdigit(product[i]) != 0)
					{
						cout << product[i];
					}
				}
				cout << " X ";
				in1 >> q;
				cout << q;
				cout << endl;
			}
			in1.close();
			in.close();
		}
		else if (type == 2)
		{
		point:;
			cout << "Enter number of your card: ";
			while (!(cin>>cardnumber)||cardnumber.length()!=15)
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "Wrong input of card number, enter once again: ";
			}
			for (int i = 0; i < 15; i++)
			{
				if (int(cardnumber[i])<48 || int(cardnumber[i])>57)
				{
					cout << "Wrong input of card number, enter once again: ";
					goto point;
				}
			}
			cout << "Card :" << cardnumber << endl;
		}
		ofstream out;
		out.open("Quantity.txt");
		out << "";
		out.close();
		in.open("Temp.txt");
		in >> value;
		ptrvalue = &value;
		cout << "Total value: " << *ptrvalue << endl;
		in.close();
		cout << "\n\n\tThank you\n\tfor your choice!" << endl;
	}
	void LeaveOrder(int bills_order)
	{
		ofstream out;	string productforpreorder; int quant;
		if (bills_order == 0)
		{
			out.open("Pre-ordert.txt", ios::binary);
			cout << Name;
			cin >> productforpreorder;
			out << productforpreorder;
			out.close();
		}
		else
		{
			out.open("Pre-ordert.txt", ios::app | ios::binary);
			cout << Name;
			cin >> productforpreorder;
	 		out << productforpreorder;
			out.close();
		}
		out.open("Pre-ordert.txt", ios::app | ios::binary);
		cout << Number;
		while (!(cin>>quant)||quant<=0)
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Wrong input, it is possible to enter only digits that are greater than 0, enter once again: ";
		}
		out << quant << endl;
		out.close();
	}
}