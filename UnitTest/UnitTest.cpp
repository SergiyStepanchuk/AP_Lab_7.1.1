#include "pch.h"
#include "CppUnitTest.h"
#include "../Program/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(met_get_sum_count)
		{
			const int size[2] = { 4, 4 };
			int** matrix = new int* [] {
					new int[] {1, 6, 3, 4},
					new int[] {1, 2, 3, 4},
					new int[] {1, 2, 3, 4},
					new int[] {1, 2, 3, 6}
			}, count, sum;
			get_sum_count(matrix, size, sum, count);
			Assert::AreEqual(sum, 12);
			Assert::AreEqual(count, 2);
		}
	};
}
