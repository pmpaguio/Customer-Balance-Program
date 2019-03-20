#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

struct PERSON {
	char  Name[20];
	float Balance;
};

void Display(PERSON a[], int N)
{
	cout << "\tName\t\tBalance" << endl;
	cout << "\t--------------------------" << endl;
	// for loop to traverse through the array
	cout << fixed << setprecision(2);
	for (int i = 0; i < N; i++) {
		cout << "\t" << a[i].Name << " " << a[i].Balance << endl;
	}
}

void FindRichest(PERSON a[], int N)
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

void Deposit(string CustName, PERSON a[], int N)
{
	float deposit;
	cout << CustName << ", how much would you like to deposit? ";
	cin >> deposit;

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

void NewCopy(string fileName, PERSON a[], int N)
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
	ifstream theFile;
	theFile.open("data.txt");
	string inLine;
	// Determine number of records.
	int N = 0;
	while (theFile)
	{
		if (getline(theFile, inLine))
		{
			N++;
		}
	}
	theFile.close();

	// Define array of person
	PERSON P[N];

	//Populate array of PERSONS
	string fname, lname;
	string pname;
	float money;
	int ix = 0;
	theFile.open("data.txt");
	while (theFile)
	{
		theFile >> fname >> lname;
		theFile >> money;
		pname = fname + " " + lname;
		strcpy(P[ix].Name, pname.c_str());
		P[ix].Balance = money;
		ix++;
	}

	Display(P, N);
	FindRichest(P, N);

	string ename;
	cout << "Enter your full name to deposit money: ";
	getline(cin, ename);
	Deposit(ename, P, N);

	NewCopy("data.txt", P, N);

	return 0;
}
