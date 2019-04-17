#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

struct PERSON {
	char  Name[20];
	float Balance;
};

PERSON* readData(int &N)
{
	ifstream theFile;
	theFile.open("data.txt");
	string inLine;
	// Determine number of records.
	N = 0;
	while (theFile)
	{
		if (getline(theFile, inLine))
		{
			N++;
		}
	}
	theFile.close();

	// Define array of person
	PERSON* P = new PERSON[N];

	//Populate array of PERSONS
	string fname, lname;
	string pname;
	int ix = 0;
	theFile.open("data.txt");
	while (theFile)
	{
		theFile >> fname >> lname;
		pname = fname + " " + lname;
		strcpy(P[ix].Name, pname.c_str());
		//theFile >> P[ix].Name >> P[ix].Name;
		theFile >> P[ix].Balance;
		ix++;
	}

	return P;
}

void Display(PERSON* &a, int N)
{
	cout << "\tName\t\tBalance" << endl;
	cout << "\t--------------------------" << endl;
	// for loop to traverse through the array
	cout << fixed << setprecision(2);
	for (int i = 0; i < N; i++) {
		cout << "\t" << a[i].Name << " " << a[i].Balance << endl;
	}
}

void FindRichest(PERSON* &a, int N)
{
	cout << endl;
	// for loop
	int ix = 0;
	float balance = a[0].Balance;
	for (int i = 1; i < N; i++)
	{
		if (a[i].Balance > balance)
		{
			ix = i;
			balance = a[i].Balance;
		}
	}
	cout << "\tThe customer with maximum balance is " << a[ix].Name << endl;
	cout << endl;
}

void Deposit(PERSON* &a, int N, string CustName, float deposit)
{
	for (int i = 0; i < N; i++)
	{
		cout << fixed << setprecision(2);
		if (CustName == a[i].Name) {
			a[i].Balance += deposit;
			cout << "Now your new balance is " << a[i].Balance << endl;
			break;
		}
	}
}

void NewCopy(string fileName, PERSON* &a, int N)
{
	ofstream theFile;
	theFile.open(fileName.c_str());
	cout << fixed << setprecision(2);
	for (int i = 0; i < N; i++)
	{
		theFile << a[i].Name << " " << a[i].Balance << endl;
	}

	theFile.close();
}


int main()
{
  int N = 0;
	PERSON* P = readData(N);
  string ename;
	float deposit;
	int choice = 0;
	while (choice != 9)
	{
		//system("clear");
		cout << "	--------------MENU--------------" << endl;
		cout << "	1.  Display" << endl;
		cout << "	2.  Find Richest" << endl;
		cout << "	3.  Deposit" << endl;
		cout << "	4.  New Copy" << endl;
		cout << "	9.  Exit" << endl;
		cout << endl;
		cout << "	Type a number for any command from the menu above: ";
		cin >> choice;
		cin.ignore();

		switch (choice)
		{
			case 1:
      Display(P, N);
			break;

			case 2:
			FindRichest(P, N);
			break;

			case 3:
			cout << "Enter name: ";
			getline(cin, ename);
			cout << endl;
			cout << "Amount: ";
			cin >> deposit;
			cout << endl;
			Deposit(P, N, ename, deposit);
			break;

			case 4:
			break;

			default:
			break;
		}

	}

	//FindRichest(P, N);

	//string ename;
	//cout << "Enter your full name to deposit money: ";
	//getline(cin, ename);
	//Deposit(ename, P, N);

	//NewCopy("data.txt", P, N);

	return 0;
}
