#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7.2(2)/Lab_7.2(2).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab722
{
	TEST_CLASS(UnitTestLab722)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int const line = 3;
			int const column = 3;
			int** matriz = new int* [line];
			for (int index = 0; index < line; index++)
				matriz[index] = new int[column];
			matriz[0][0] = 9; matriz[0][1] = 1;matriz[0][2] = 2;matriz[1][0] = 3;matriz[1][1] = 4;matriz[1][2] = 5;matriz[2][0] = 6;matriz[2][1] = 7;matriz[2][2] = 8;
			int* max = new int[line];
			for (int i = 0; i < line; i++)
			{
				max[i] = matriz[i][0];
				for (int j = 1; j < column; j++)
					if (matriz[i][j] > max[i])
						max[i] = matriz[i][j];
			}
			int min = min_max(matriz, max, line, 0, max[0]);
			Assert::AreEqual(min, 5);
			delete[] max;
			delete[] matriz;
		}
	};
}
