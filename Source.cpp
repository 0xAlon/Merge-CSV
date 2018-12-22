#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main()
{

	std::ofstream  mainFile("PF Data.csv", std::ios::app);
	if (!mainFile.is_open())
	{
		std::exit(EXIT_FAILURE);
	}

	std::string fileName;

	std::cout << "Please, enter file name: ";
	std::getline(std::cin, fileName);
	fileName.append(".CSV");

	std::ifstream data(fileName);
	if (!data.is_open())
	{
		std::exit(EXIT_FAILURE);
	}

	std::cout << "Wait..." << std::endl;
	std::string str;
	std::string tmp;
	std::getline(data, str); // Skip the first line
	while (std::getline(data, str))
	{
		std::istringstream iss(str);
		std::string token;
		while (std::getline(iss, token, ','))
		{
			// Process each token
			//std::cout << token << ","; //Print Debag
			tmp.append(token);
			tmp.append(",");
		}
		tmp = tmp.substr(0, tmp.size() - 1); // Delete the last ','
		tmp.append("\n");
		mainFile << tmp;
		tmp.clear();
	}

	std::cout << "Done." << std::endl;
	std::cin.ignore();

}
