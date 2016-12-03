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
	bool randChecker = 0;
	int randomNumber = -1;
	int check = 0;
	int unique = 0;
	int listLength = 0;
	int breaker = false;
	int indexes[50] = { 0 };
	std::ifstream inData;
	std::ifstream passWords;
	std::ofstream fullAdress;
	std::string firstName;
	std::string	lastName;
	std::string word;
	srand(time(NULL));
	/*******************************************************************/
	//opens the provided data files
	inData.open("names.txt");
	passWords.open("passwords.txt");
	//stores the first and last name at the top of the list of names
	inData >> firstName >> lastName;
	//stores the first password
	passWords >> word;
	
	//Initializes the index array to -1
	for (int f = 0; f < 50; f++)
	{
		indexes[f] = -1;
	}

	//Assigns random numbers to the index array
	for (int h = 0; h < 50; h++)
	{
		//sets the checking variable to false
		breaker = false;
		//loops until a number that has not already been assigned is generated
		while (!breaker)
			{
				randomNumber = rand() % 50;
				breaker = true;
				//loops through all assigned indexes and prevents matching indexes to pass
				for (int g = 0; g < h+1; g++)
				{
					if (randomNumber == indexes[g])
					{
						breaker = false;
					}
				}

			}
		indexes[h] = randomNumber;
		std::cout << indexes[h] << std::endl;
	}

	//runs the loop until both files have stored all their info in the two starting arrays
	while (!inData.eof() && !passWords.eof())
	{
		//saves an email adress given the guidelines provided in the assignment
		employees[i].emailAdress = firstName.substr(0, 1) + lastName.substr(0, 7) + "@company.com";
		//stores a password in the array of possible passwords
		employees[i].passW = word;
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

	//opens the new file to save the data to
	fullAdress.open("employeeEmails.txt");

	//saves the data to the file line by line
	while (i < 50)
	{

		//assigns the adress and the random password
		fullAdress << employees[i].emailAdress + " " + employees[indexes[i]].passW << std::endl;
		i++;
	}
	//closes the file
	fullAdress.close();
	//ends the program
	return 0;
}