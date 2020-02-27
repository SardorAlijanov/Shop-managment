#pragma once
#include "1st_Page.h"
namespace Counter
{
	void TempPriceTaker(int price, int index)
	{
		ofstream out;
		if (index == 0)
		{
			out.open("TempStorage.txt");
		}
		else
		{
			out.open("TempStorage.txt", ios::app);
		}
		out << price << endl;
		out.close();
	}

	bool Allower = false;

	class Money
	{
	public:
		Money()
		{
			money = 0;
		}
		Money(int money)
		{
			this->money = money;
		}
		Money operator+(Money other)
		{
			Money temp;
			temp.money = money + other.money;
			return temp;
		}
		Money operator-(Money other)
		{
			Money temp;
			temp.money = money - other.money;
			return temp;
		}
		int GetMoney()
		{
			return money;
		}
	private:
		int money;
	};
	void Processor(int type)
	{
		int curr, prime, overall = 0, value, limit = 0;
		string temp;
		ifstream in; ofstream out;
		string path[2] = { "Profit.txt", "Expences.txt" };
		in.open("CurrentMoney.txt");
		in >> curr;
		Money m(curr);
		in.close();
		if (type == 1)
		{
			in.open(path[0]);
			in >> prime;
			Money m1(prime);
			in.close();
			Money m2 = m + m1;
			overall = m2.GetMoney();
			Allower = true;
		}
		else
		{
			in.open(path[1]);
			in >> prime;
			Money m1(prime);
			in.close();
			Money m2 = m - m1;
			overall = m2.GetMoney();
			if (overall<0)
			{
				Allower = false;
			}
			else
			{
				Allower = true;
				in.open("Pre-ordert.txt", ios::binary);
				out.open("White_Goods_Name.txt", ios::app);
				while (!(in.eof()))
				{
					in >> temp;
					limit++;
				}
				in.close();
				in.open("Pre-ordert.txt", ios::binary);
				for (int i(1); i<limit; i++)
				{
					in >> temp;
					for (int i = 0; temp[i]!='\0'; i++)
					{
						if (isdigit(temp[i])!=0)
						{
							temp[i] = ' ';
						}
					}
					out << endl << temp;
				}
				in.close();
				out.close();
				in.open("Temp.txt", ios::binary);
				out.open("White_Goods_Number.txt", ios::app);
				for (int i(1); i<limit; i++)
				{
					in >> value;
					out << endl << value;
				}
				in.close();
				out.close();
			}
		}
		if (Allower)
		{
			int tempinter;
			out.open("CurrentMoney.txt",ios::binary);
			out << overall;
			out.close();
			out.open("Pre_ordert.txt", ios::binary);
			out << " ";
			out.close();
			in.open("TempStorage.txt", ios::binary);
			out.open("White_Goods_Prizes.txt", ios::app);
			for (int i(0); i<limit-1; i++)
			{
				in >> tempinter;
				out << endl << tempinter;
			}
			in.close();
			out.close();
		}
		else
		{
			cout << "No enough money to purchase!" << endl;
		}
	}
}