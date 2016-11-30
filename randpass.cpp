//Created by: Reilly Q. Curran	
//last edited: 11/29/16
//last compiled: 11/29/16

#include<iostream>
#include<string>
#include<fstream>
//couldn't decide which randomizer was better
#include <time.h>
#include<stdlib.h>

struct email //allows for the complete user info to be stored in a single array 
{
	std::string emailAdress;
	std::string passW;
};

email employees[50] = { " ", " " }; //initializes an empty array of employees
std::string adress[50] = { " " }; //empty array that will store the email adresses
std::string pWords[50] = { " " }; //empty array that will temporari;y store paswords

int main()
{
	/******************************************************************/
	int i = 0;
	int randChecker = 0;
	int randomNumber = -1;
	int unique = 0;
	int listLength = 0;
	std::ifstream inData;
	std::ifstream passWords;
	std::ofstream fullAdress;
	std::string firstName;
	std::string	lastName;
	std::string word;
	/*******************************************************************/
	//opens the provided data files
	inData.open("names.txt");
	passWords.open("passwords.txt");
	//stores the first and last name at the top of the list of names
	inData >> firstName >> lastName;
	//stores the first password
	passWords >> word;
	//runs the loop until both files have stored all their info in the two starting arrays
	while (!inData.eof() && !passWords.eof())
	{
		//saves an email adress given the guidelines provided in the assignment
		adress[i] = firstName.substr(0, 1) + lastName.substr(0, 7) + "@company.com";
		//stores a password in the array of possible passwords
		pWords[i] = word;
		//starts the next line of both files
		inData >> firstName >> lastName;
		passWords >> word;
		//raises the index
		i++;
	}
	//closes the opened files and resets the index for later use
	inData.close();
	passWords.close();
	i = 0;

	//runs a loop that checks each password against the list of already randomly assigned passwords
	//if one has already been assigned it will iterate a variable that breaks the loop so it can draw another 
	//random number and start over.  Only a unique password will iterate through the loop completely.
	for (int j = 0; j < 50; j++)
	{
		std::cout << j << std::endl;
		randChecker = 0;
		while (unique == 0)								//COMMENTS: unique = 0 is incorrect as you are checking if unique has been set to 0
		{
			randomNumber = rand() % 49;
			if (listLength > 0)
			{		for (int k = 0; k < 50; k++)
				{
					if (pWords[randomNumber] == employees[k].passW)	//COMMENTS: employees[k].PassW is empty, can you explain your logic here?
					{
						randChecker++;
						break;
					}
				}
			}
			if (randChecker == 0)
			{
				unique++;
			}
		}
		//stores the email adress and the randomly assigned password to the index in the struct array.
		employees[j].emailAdress = adress[j];
		employees[j].passW = pWords[randomNumber];
		unique = 0;
		listLength++;
		//COMMENTS: randChecker needs to be reset for each loop run
	}

	//opens the new file to save the data to
	fullAdress.open("employeeEmails.txt");

	//saves the data to the file line by line
	while (i < 50)
	{
		fullAdress << employees[i].emailAdress + " " + employees[i].passW << std::endl;
		i++;
	}
	//closes the file
	fullAdress.close();
	//ends the program
	return 0;
}