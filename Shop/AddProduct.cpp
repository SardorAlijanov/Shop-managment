#include "1st_Page.h"
#include <cstdlib>
ofstream fout, fout1, fout2;
ifstream in, in1;
namespace Counter
{
	class Money;
	void Processor(int type);
	void TempPriceTaker(int price,int index);
}
namespace AddProd
{
	void SetName(string name)
	{
		fout.open("White_Goods_Name.txt",ios::app);
		fout << endl << name;
		fout.close();
	}
	void SetQuantity(string name)
	{
		int quantity;
		string path[2] = { "White_Goods_Number.txt", "White_Goods_Prizes.txt" }, names[2] = { "quantity","prize"};
		for (int i = 0; i < 2; i++)
		{
			cout << "Enter "<<names[i]<<" for " << name << ": ";
			while (!(cin >> quantity))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "Wrong input,re-enter: ";
			}
			if (i==0)
			{
				fout1.open(path[i], ios::app);
				fout1 << endl << quantity;
				fout1.close();
			}
			else
			{
				fout2.open(path[i], ios::app);
				fout2 << endl << quantity;
				fout2.close();
			}
		}
	}
	void AddPreOrdered()
	{
		char answer;
		string prodname;
		bool goodexist = false;
		int limit = 0, prices[150], value[150], temp = 0, num, tot_value = 0, possym;
		fout.open("Temp.txt");
		fout << 0;
		fout.close();
		srand(static_cast<unsigned int>(time(0)));
		in.open("Pre-ordert.txt", ios::in|ios::binary);
		for (int i = 1; !in.eof(); i++)
		{
			in >> prodname;
			limit++;
		}
		in.close();
		in.open("Pre-ordert.txt", ios::app | ios::binary);
		cout << "Product" << "\t\t quantity"<<"\t\t price" << endl;
		for (int i = 1; i < limit; i++)
		{
		in >> prodname;
		int price = ((rand() % 10) + 1) * 10000, tempquan = 0;
		for (int j(0); prodname[j] != '\0';j++)
			{
				if (isalpha(prodname[j])!=0)
				{
					cout << prodname[j];
					goodexist = true;
					possym = j;
				}
			}
			cout << setw(18) << setfill('-');
			int k = 0, l = 0;
			for (; prodname[k]!='\0';k++)//null statement
			{
				if (isdigit(prodname[k])!=0)
				{
					cout << prodname[k];
					prices[l] = char(prodname[k] - 48);
					temp++;
					l++;
				}
			}
			prodname.erase(possym+1);
			num = 1, temp;
			for (; temp != 0; temp--, num *= 10)
			{
				tempquan += char(prices[temp-1]) * num;
			}
			value[i-1] = tempquan;
			fout2.open("Temp.txt", ios::app | ios::binary);
			fout2 << value[i-1] << endl;
			fout2.close();
			if (goodexist)
			{
				cout << setw(24) << setfill('-');
				cout << price;
				Counter::TempPriceTaker(price,i-1);
				value[i-1] *= price;
			}
			cout << endl;
		}
		for (int i(0); i < limit-1; i++)
		{
			tot_value += value[i];
		}
		in.close();
		if (goodexist)
		{
		point1:;
			cout << "Would you like the program to add them all?" << endl;
			cout << "y - Yes" << endl;
			cout << "n - No" << endl;
			cin >> answer;
			if (answer == 'y')
			{
				fout2.open("Expences.txt", ios::binary);
				fout2 << tot_value;
				fout2.close();
				Counter::Processor(2);
			}
			else if (answer == 'n')
			{
				cout << "Ok, maybe later!" << endl;
			}
			else
			{
				cout << "Wrong input, enter again: " << endl;
				goto point1;
			}
		}
	}
}