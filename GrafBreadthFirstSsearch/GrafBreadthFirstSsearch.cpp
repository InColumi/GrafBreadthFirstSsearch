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
		std::cout << "������� ��� ����� � ���������� txt\n";
		std::cout << "������ ������� ����� � �����������: input.txt\n";
		std::cin >> input;

		if(IsCorrectExtention(input))
		{
			outFile.open(input);
			if(outFile.is_open())
			{
				system("cls");
				std::cout << "�����!\n";
			}
			else
			{
				std::cout << "������ ����� �� ���������!\n";
			}
		}
		else
		{
			std::cout << "�������� ����������!\n";
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
		std::cout << "������� ����� ������ �����!\n\n";
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
		std::cout << "�������� �����\n";
		std::cout << "\t 1 - ���� �� �����.\n";
		std::cout << "\t 2 - ���� � ����������.\n";
		std::cout << "\t 3 - ����� �� ���������.\n";
		if(TryParseToInt(numberOfCommand) == false)
		{
			continue;
		}
		switch(numberOfCommand)
		{
			case 1:
			{
				system("cls");
				std::cout << "�� ������� ���� �� �����!\n";
				ReadFromFile();
				break;
			}
			case 2:
			{
				system("cls");
				std::cout << "�� ������� ���� � ����������!\n";
				ReadFromKeyboard();
				break;
			}
			case 3:
			{
				isExit = true;
				std::cout << "��������� ��������� ���� ������!\n";
				break;
			}

			default:
				std::cout << "����������� �������!\n";
				break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	ShowMenu();
}