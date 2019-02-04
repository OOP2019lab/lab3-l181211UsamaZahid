#include <iostream>
#include "q1_181211_header.h"
#include <fstream>
#include <stdio.h>
using namespace std;

//Reads data from file to input in users array
void readDataFromFile(gitHubUser*&users, string filepath, int &size)
{
	ifstream readfile;
	readfile.open(filepath);
	string empty;
	if (!readfile)
	{
		cout << "No file exists";
	}
	else
	{
		readfile >> size;
		users = new gitHubUser[size];

		for (int i = 0; i < size; i++)
		{
			readfile >> users[i].firstName;
			readfile >> users[i].userName;
			readfile >> users[i].email;
			readfile >> users[i].folderCount;

			users[i].gitHubFolders = new string[users[i].folderCount];
			getline(readfile, empty);
			for (int j = 0; j < users[i].folderCount; j++)
			{
				getline(readfile, users[i].gitHubFolders[j]);
			}
		}
	}
}

//inputs name of institute and qualification level for the current user
void setEduBckGrnd(gitHubUser &user)
{
	//skips institute name input on Visual Studio 2015 Compilier
	cout << endl << user.firstName << " enter your institution name: ";
	user.institute_name = new string;
	getline(cin, *user.institute_name);
	
	cout << endl << user.firstName << " enter your level of qualification: ";
	user.qualification_level = new string;
	getline(cin,*user.qualification_level);
}

//prints information of the current user
void print(gitHubUser &user)
{
	cout << "First Name: " << user.firstName << endl;
	cout << "User Name: " << user.userName << endl;
	cout << "Password: " << user.password << endl;
	cout << "Email: " << user.email << endl;
	cout << "Folder Count: " << user.folderCount << endl;
	for (int i = 0; i < user.folderCount; i++)
	{
		cout << "   " << i << ") " << user.gitHubFolders[i] << endl;
	}
	if (user.institute_name != '\0')
		cout << "Institute Name: " << *user.institute_name << endl;
	if (user.qualification_level != '\0')
		cout << "Qualification Level: " << *user.qualification_level << endl;
}

//removes information of institute and qualification levelf or current user
void remove(gitHubUser &user)
{
	user.institute_name = '\0';
	user.qualification_level = '\0';
}

//creates a backup array by copying information
void backup(gitHubUser *originalArry, gitHubUser*backupArry, int userCount)
{
	backupArry = new gitHubUser[userCount];
	for (int i = 0; i < userCount; i++)
	{
		backupArry[i].firstName = originalArry[i].firstName;
		backupArry[i].userName = originalArry[i].userName;
		backupArry[i].email = originalArry[i].email;
		backupArry[i].folderCount = originalArry[i].folderCount;

		backupArry[i].gitHubFolders = new string[originalArry[i].folderCount];
		for (int j = 0; j < originalArry[i].folderCount; j++)
		{
			backupArry[i].gitHubFolders[j] = originalArry[i].gitHubFolders[j];
		}
	}
	cout << "Backup array has been created\n";
}

//menu system
int main()
{
	gitHubUser*users = nullptr;
	gitHubUser*backupuser = nullptr;
	string path = "q1_181211_in.txt";
	int size;
	readDataFromFile(users, path, size);

	//user must enter his position in array where his data is stored
	cout << "Enter your user position in array: ";
	int pos;
	cin >> pos;
	users[pos].institute_name = '\0';
	users[pos].qualification_level = '\0';

	int choice = 0;
	while (choice != 5)
	{
		cout << "------------------------------------Menu---------------------------------\n";
		cout << "1) Input Institute name and Education Level\n";
		cout << "2) Print User Information\n";
		cout << "3) Remove Institute and Education Information\n";
		cout << "4) Create Backup of User Array\n";
		cout << "5) End Program\n";

		cout << "\nSelect one of the choices\n";
		cin >> choice;
		if (choice == 1)
			setEduBckGrnd(users[pos]);
		else if (choice == 2)
			print(users[pos]);
		else if (choice == 3)
			remove(users[pos]);
		else if (choice == 4)
			backup(users, backupuser, size);
		else if (choice == 5)
			cout << "You are now exiting the program\n";
		else
			cout << "This choice does not exist\n";

		system("pause");
		system("cls");
	}

	//deletion of pointers
	for (int i = 0; i < size; i++)
	{
		users[i].gitHubFolders = nullptr;
		users[i].institute_name = nullptr;
		users[i].qualification_level = nullptr;
		if (backupuser != nullptr)
		{
			backupuser[i].gitHubFolders = nullptr;
			backupuser[i].institute_name = nullptr;
			backupuser[i].qualification_level = nullptr;
		}
	}
	delete[]users;
	delete[]backupuser;
}