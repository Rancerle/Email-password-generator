//Created by: Reilly Q. Curran	
//last edited: 11/25/16
//last compiled:

#include<iostream>
#include<string>
#include<fstream>
#include <time.h>
#include<stdlib.h>

struct email
{
	std::string emailAdress;
	std::string passW;
};

email employees[50] = { " " };
std::string adress[50] = { " " };
std::string pWords[50] = { " " };

int main()
{
	srand(time(NULL));
	int i = 0;
	int randChecker = 0;
	int randomNumber = -1;
	int unique;
	std::ifstream inData;
	std::ifstream passWords;
	std::ofstream fullAdress;
	std::string firstName;
	std::string	lastName;
	std::string word;
	inData.open("names.txt");
	passWords.open("passwords.txt");
	inData >> firstName >> lastName;
	passWords >> word;
	while (!inData.eof() && !passWords.eof())
	{
		adress[i] = firstName.substr(0, 1) + lastName.substr(0, 7) + "@company.com";
		pWords[i] = word;
		inData >> firstName >> lastName;
		passWords >> word;
		i++;
	}
	inData.close();
	i = 0;

	for (int j = 0; j < 50; j++)
	{
		while (unique = 0)
		{
			randomNumber = rand() % 49;
			for (int k = 0; k < 50; k++)
			{
				if (pWords[j] == employees[k].passW)
				{
					randChecker++;
					break;
				}
			}
			if (randChecker == 0)
			{
				unique++;
			}
		}
		employees[j].emailAdress = adress[j];
		employees[j].passW = pWords[randomNumber];
		unique = 0;
	}

	fullAdress.open("employeeEmails.txt");

	while (i < 50)
	{
		fullAdress << employees[i].emailAdress + " " + employees[i].passW << std::endl;
		i++;
	}

	fullAdress.close();
	
	return 0;
}