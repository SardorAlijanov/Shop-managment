#pragma once
#include <Windows.h> 
#include "1st_Page.h"
class Welcome:public Client,public Exist
{
public:
	void Authorization()
	{
		system("cls");
		do
		{
			cout << "*****" << " Welcome to T-Shirt shop " << "*****" << '\n';
			cout << "***********************************" << '\n';
			cout << "Identify yourself: " << endl;
			cout << "1. - Admin" << " ***** " << "2. - Client" << endl;
			while (!(cin>>choise)) 
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "Wrong input, only digits accepted: ";
			}
			system("cls");
			switch (choise)
			{
			case 1:
			{
					  ::Admin a;
					  a.Show();
					  system("cls");
					  a.Action();
					  break;
			}
			case 2:
			{
					  for (int q = 5; q != 0 ; q--)
					  {
						  Show();
						  cout << endl << "                ***** Loaded files " <<( 100 / q) << " % *****" << endl;
						  Sleep(650);
						  system("cls");
					  }					 
					  ::Admin a;
					  a.ShowQuantity();
					  Ask();
					  while (!(cin>>answer)||answer<=0||answer>2)
					  {
						  cin.clear();
						  while (cin.get() != '\n');
						  cout << "Wrong input, only digits from 1-2 accepted, re - enter: ";
					  }
					  Purchace(answer);
					  _getch();
					  break;
			}
			case 0:
			{
					  cout << "Goodbye!" << endl;
					  break;
			}
			default:
				cout << "*****Wrong input!*****" << endl;
				break;
			}
		} while (choise != 0);
	}
private:
	int choise, answer;
};
int main()
{
	Welcome w;
	w.Authorization();
	_getch();
}