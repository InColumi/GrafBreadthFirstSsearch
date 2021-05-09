#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Matrix
{
private:
	bool** _matrix;
	size_t _size;

	void MemoryAllocation()
	{
		_matrix = new bool* [_size];
		for(size_t i = 0; i < _size; i++)
		{
			_matrix[i] = new bool[_size];
		}
	}

	void Parse(std::vector<std::string>& matrixInStrings)
	{
		_size = matrixInStrings.size();
		MemoryAllocation();
		size_t sizeRow;
		std::string line;
		size_t countColumn = 0;
		for(size_t i = 0; i < _size; i++)
		{
			line = matrixInStrings[i];
			sizeRow = line.size();
			for(size_t j = 0; j < sizeRow; j++)
			{
				if(line[j] != ' ')
				{
					if(line[j] == '0')
					{
						_matrix[i][countColumn++] = 0;
					}
					else if(line[j] == '1')
					{
						_matrix[i][countColumn++] = 1;
					}
					else
					{
						std::cout << "В файле некорретные данные!\n";
						exit(-1);
					}
				}
			}
			countColumn = 0;
		}
	}

	bool IsCorrect(size_t index)
	{
		return index >= 0 && index < _size;
	}

public:
	Matrix(): _matrix(NULL), _size(0)
	{}

	Matrix(std::vector<std::string>& matrixInStrings)
	{
		Parse(matrixInStrings);
	}

	const bool& operator()(size_t row, size_t col)
	{
		if(IsCorrect(row) && IsCorrect(col))
		{
			return _matrix[row][col];
		}
		else
		{
			std::cout << "Неверный индекс!\n";
			exit(-1);
		}
	}

	~Matrix()
	{
		for(size_t i = 0; i < _size; i++)
		{
			delete[]_matrix[i];
		}
		delete[] _matrix;
		_size = 0;
	}

	size_t GetSize()
	{
		return _size;
	}

	template<typename T>
	void ShowMatrix(T& stream)
	{
		for(size_t i = 0; i < _size; i++)
		{
			for(size_t j = 0; j < _size; j++)
			{
				stream << _matrix[i][j] << "\t";
			}
			stream << "\n";
		}
	}
};

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

void CheckInputData(Matrix& matrix, size_t startVertex)
{
	size_t size = matrix.GetSize();
	if(startVertex < 0 || startVertex >= size)
	{
		std::cout << "Недопустимая вершина в файле!\n";
		exit(-1);
	}
}

void ShowVertex(std::vector<size_t>& vertexes, int countSteps)
{
	size_t size = vertexes.size();
	std::cout << "За " << countSteps << " шагов ";
	if(size == 1)
	{
		std::cout << "из вершины " << vertexes[0] + 1 << " нелья никуда попасть!\n";
	}
	else
	{
		std::cout << "Из вершины " << vertexes[0] + 1 << " можно попасть в:\n";
		for(size_t i = 1; i < size; i++)
		{
			std::cout << '\t' << vertexes[i] + 1 << " вершину.\n";
		}
	}
}

std::vector<size_t> GetVertexes(Matrix& matrix, int startVertex, size_t countSteps)
{
	startVertex--;
	CheckInputData(matrix, startVertex);
	std::vector<size_t> vertexes;
	vertexes.push_back(startVertex);
	size_t size = matrix.GetSize();
	bool isExistPath = false;
	bool isVertexInVector = false;
	size_t indexCurrentVertex = vertexes.back();
	for(size_t i = 0; i < countSteps; i++)
	{
		for(size_t j = 0; j < size; j++)
		{
			if(matrix(j, indexCurrentVertex) == 1)
			{
				isExistPath = true;
				for(size_t k = 0; k < vertexes.size(); k++)
				{
					if(vertexes[k] == j)
					{
						isVertexInVector = true;
						break;
					}
				}
				if(isVertexInVector == false)
				{
					vertexes.push_back(j);
				}
				isVertexInVector = false;
			}
		}
		if(isExistPath == false)
		{
			break;
		}
		indexCurrentVertex = vertexes.back();
	}

	return vertexes;
}

void ReadFromFile()
{
	std::string input;
	bool isCorrect = false;
	std::ifstream outFile;
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

				std::string line;
				std::vector<std::string> textFromFile;
				int startVertex;
				int countSteps;
				try
				{
					std::getline(outFile, line);
					startVertex = std::stoi(line);
					std::getline(outFile, line);
					countSteps = std::stoi(line);
					while(std::getline(outFile, line))
					{
						textFromFile.push_back(line);
					}
					outFile.close();

					Matrix matrix(textFromFile);
					std::vector<size_t> vertexes = GetVertexes(matrix, startVertex, countSteps);
					ShowVertex(vertexes, countSteps);
				}
				catch(const std::exception&)
				{
					std::cout << "Что-то с файлом не так!\n";
				}
				isCorrect = true;
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