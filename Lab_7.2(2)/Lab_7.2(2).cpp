// 1 Спосіб --- "Рекурсивний"
#include <iostream>
#include <Windows.h>
#include <iomanip>

void matriz_create(int** matriz, const int line, const int column, const int Low, const int High, int index, int index_j);
void matriz_print(int** matriz, const int line, const int column, int index, int index_j);
void matriz_print1(int* matriz, const int line, int index);
int min_max(int** matriz, int* max, const int line, int index, int min);

int main(void)
{
	srand((unsigned)time(NULL));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	using std::cout;
	using std::endl;
	using std::cin;

	int line;
	int column;

	cout << "Задайте розмір матриці: " << endl;
	cout << endl;
	cout << "Кількість рядків: ";
	cin >> line;
	cout << endl;
	cout << "Кількість стовпців: ";
	cin >> column;
	cout << endl;

	int** matriz = new int* [line];
	for (int index = 0; index < line; index++)
		matriz[index] = new int[column];

	int High = 40;
	int Low = -40;
	matriz_create(matriz, line, column, Low, High, 0, 0);
	cout << "Сформований масив: " << endl << endl;
	matriz_print(matriz, line, column, 0, 0);
	cout << std::endl;

	int* max = new int[line];
	for (int i = 0; i < line; i++)
	{
		max[i] = matriz[i][0];
		for (int j = 1; j < column; j++)
			if (matriz[i][j] > max[i])
				max[i] = matriz[i][j];
	}
	cout << std::endl;
	cout << "Сформований масив: " << endl;
	cout << std::endl;
	matriz_print1(max, line, 0);

	cout << std::endl;
	int min = min_max(matriz, max, line, 0, max[0]);
	cout << endl;
	cout << "Найменший з максимальних елементів по всіх рядках матриці (4x4) становить: " << min << endl;

	delete[] max;
	delete[] matriz;

	return 0;
}

void matriz_create(int** matriz, const int line, const int column, const int Low, const int High, int index, int index_j)
{
	matriz[index][index_j] = Low + rand() % (High - Low + 1);
	if (index_j < column - 1)
		matriz_create(matriz, line, column, Low, High, index, index_j + 1);
	else
		if (index < line - 1)
			matriz_create(matriz, line, column, Low, High, index + 1, 0);
}

void matriz_print(int** matriz, const int line, const int column, int index, int index_j)
{
	using std::cout;
	using std::endl;
	cout << std::setw(4) << matriz[index][index_j];
	if (index_j < column - 1)
		matriz_print(matriz, line, column, index, index_j + 1);
	else
		if (index < line - 1)
		{
			cout << endl;
			matriz_print(matriz, line, column, index + 1, 0);
		}
}

void matriz_print1(int* matriz, const int line, int index)
{
	using std::cout;
	using std::endl;
	std::cout << std::setw(5) << matriz[index];
	if (index < line - 1)
		matriz_print1(matriz, line, index + 1);
	else;
}


int min_max(int** matriz, int* max, const int line, int index, int min)
{
	if (max[index] < min)
		min = max[index];
	if (index < line - 1)
		min_max(matriz, max, line, index + 1, min);
	else
		return min;
}
