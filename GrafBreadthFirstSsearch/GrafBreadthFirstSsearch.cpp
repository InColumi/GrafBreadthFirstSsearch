#include <iostream>
#include <string>
#include <fstream>

bool IsCorrectExtention(std::string& filename, std::string  extention = ".txt")
{
	try
	{
		for(int i = extention.size() - 1, j = filename.size() - 1; i >= 0; i--, j--)
		{
			if(extention[i] != filename[j])
			{
				return false;
			}
		}
	}
	catch(const std::exception&)
	{
		return false;
	}

	return true;
}

void ReadFromFile()
{
	std::string input;
	bool isCorrect = false;
	std::fstream outFile;
	while(isCorrect == false)
	{
		std::cout << "Введите имя файла с раширением txt\n";
		std::cout << "Пример верного файла с расширением: input.txt\n";
		std::cin >> input;

		if(IsCorrectExtention(input))
		{
			outFile.open(input);
			if(outFile.is_open())
			{
				system("cls");
				std::cout << "Нашел!\n";
			}
			else
			{
				std::cout << "Такого файла не сущестует!\n";
			}
		}
		else
		{
			std::cout << "Неверное расширение!\n";
		}
	}
}

void ReadFromKeyboard()
{

}

bool TryParseToInt(int& number)
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