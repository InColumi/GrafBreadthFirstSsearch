#include <iostream>
#include <string>



void ReadFromFile()
{

}

void ReadFromKeyboard()
{

}

bool TryParseToInt(int &number)
{
	std::string input;
	std::cin >> input;
	try
	{
		number = std::stoi(input);
		return true;
	}
	catch(const std::exception&)
	{
		std::cout << "Вводить можно только цыфры!\n\n";
		return false;
	}
	
}

void ShowMenu()
{
	std::string input;
	bool isExit = false;
	int numberOfCommand;
	while(isExit == false)
	{
		std::cout << "Выберете режим\n";
		std::cout << "\t 1 - Ввод из файла.\n";
		std::cout << "\t 2 - Ввод с клавиатуры.\n";
		std::cout << "\t 3 - Выход из программы.\n";
		if(TryParseToInt(numberOfCommand) == false)
		{
			continue;
		}
		switch(numberOfCommand)
		{
			case 1:
			{
				system("cls");
				std::cout << "Вы выбрали ввод из файла!\n";
				ReadFromFile();
				break;
			}
			case 2:
			{
				system("cls");
				std::cout << "Вы выбрали ввод с клавиатуры!\n";
				ReadFromKeyboard();
				break;
			}
			case 3:
			{
				isExit = true;
				std::cout << "Программа закончила свою работу!\n";
				break;
			}
				
			default:
				std::cout << "Неизвестная команда!\n";
				break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	ShowMenu();
}