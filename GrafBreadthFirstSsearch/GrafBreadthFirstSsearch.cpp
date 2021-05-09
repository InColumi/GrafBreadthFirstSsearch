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