#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

struct Person
{
	string firstName;
	string lastName;
	unsigned short int age; // unsigned because age can not be a negative number
	string phoneNumber;
};

short int howManyPersons;

Person persons[100];

void AskForEnter();
void AddNewPerson();
void ShowData();
void SaveData();
void LoadData();
void SearchData();
void RemovePerson();

int main()
{
    char test;

    do
    {
    	cout << "-------------------------" << endl;
		cout << "|                       |" << endl;
		cout << "|   DATABASE v. 1.0     |" << endl;
    	cout << "|   by Jakub Sadecki    |" << endl;
    	cout << "|                       |" << endl;
    	cout << "-------------------------" << endl << endl;
    
        cout << "Number of people in database: " << howManyPersons << endl << endl;
		
		cout << "MENU: " << endl << endl;
        
		cout << "1. Add new person to database " << endl;
        cout << "2. Show all people in database " << endl;
        cout << "3. Save data to an external file " << endl;
        cout << "4. Load data from file " << endl;
        cout << "5. Search a person in database " << endl;
        cout << "6. Remove a person from database " << endl << endl;
        
        cout << "Press ESC to exit..." << endl << endl;

        test = getch();

        switch(test)
        {
        case '1':
            AddNewPerson();
            break;
        case '2':
			ShowData();
            break;
        case '3':
        	SaveData();
        	break;
        case '4':
        	LoadData();
        	break;
        case '5':
        	SearchData();
        	break;
        case '6':
        	RemovePerson();
        	break;
        }

        AskForEnter();
		system("cls");

    } while(test != 27); // 27 is ASCII Code for 'ESC' button

    return 0;
}

void AskForEnter()
{
    cout << "Press ENTER to continue..." << endl;
    while(getch() != 13); // 13 is ASCII Code for 'ENTER' button
}

void AddNewPerson()
{
	cout << "Enter person's FIRST NAME (no spaces allowed): " << endl;
	cin >> persons[howManyPersons].firstName;
	
	cout << "Enter person's LAST NAME (no spaces allowed): " << endl;
	cin >> persons[howManyPersons].lastName;
	
	cout << "Enter person's AGE (no spaces allowed): " << endl;
	cin >> persons[howManyPersons].age;
	
	cout << "Enter person's PHONE NUMBER (no spaces allowed): " << endl;
	cin >> persons[howManyPersons].phoneNumber;
	
	howManyPersons++;
}

void ShowData()
{
	if (howManyPersons > 0)
	{
		for (int j = 0; j < howManyPersons; j++)
		{
			cout << endl;
			cout << "Person number: " << (j+1) << endl;
			cout << "First name: " << persons[j].firstName << endl;
			cout << "Last name: " << persons[j].lastName << endl;
			cout << "Age: " << persons[j].age << endl;
			cout << "Phone number: " << persons[j].phoneNumber << endl << endl;
		}	
	}
	else
		cout << "Database is EMPTY. " << endl;
}

void SaveData()
{
	ofstream file("database.txt");
	
	if (file.is_open())
	{
		file << howManyPersons << endl;
		for (int j = 0; j < howManyPersons; j++)
		{
			file << persons[j].firstName << endl;
			file << persons[j].lastName << endl;
			file << persons[j].age << endl;
			file << persons[j].phoneNumber << endl;
		}
		
		file.close();
	}
	else
		cout << "Opening the file FAILED!" << endl;
	
}

void LoadData()
{
	ifstream file("database.txt");
	
	if (file.is_open())
	{
		file >> howManyPersons;
		
		int i = 0;
		
		do
		{
			file >> persons[i].firstName;
			file >> persons[i].lastName;
			file >> persons[i].age;
			file >> persons[i].phoneNumber;
			i++;
		} while(!file.eof());
		
		file.close();
	}
	else
		cout << "Opening the file FAILED!" << endl;
}

void SearchData()
{
	if (howManyPersons != 0)
	{
		string lastName;
		cout << "Enter LAST NAME of person you are looking for: " << endl;
		cin >> lastName;
		
		for (int j = 0; j < howManyPersons; j++)
		{
			if (lastName == persons[j].lastName)
			{
				cout << endl;
				cout << "Person number: " << (j+1) << endl;
				cout << "First name: " << persons[j].firstName << endl;
				cout << "Last name: " << persons[j].lastName << endl;
				cout << "Age: " << persons[j].age << endl;
				cout << "Phone number: " << persons[j].phoneNumber << endl << endl;
			}
		}
	}
	else
		cout << "Database is EMPTY. " << endl;
}

void RemovePerson()
{
	if (howManyPersons != 0)
	{
		short int index;
		
		cout << "Enter NUMBER of person to REMOVE from database: " << endl;
		cin >> index;
		
		for (short int k = index; k < howManyPersons; k++)
		{
			persons[k-1].firstName = persons[k].firstName;
			persons[k-1].lastName = persons[k].lastName;
			persons[k-1].age = persons[k].age;
			persons[k-1].phoneNumber = persons[k].phoneNumber;
		}
		
		howManyPersons--;
		
		cout << "Person number " << index << " has been removed from the database. " << endl;
	}
	else
		cout << "Database is EMPTY. " << endl;
}
