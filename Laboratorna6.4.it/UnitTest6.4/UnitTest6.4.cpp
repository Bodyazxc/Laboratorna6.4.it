#include "pch.h"
#include "CppUnitTest.h"
#include "../Laboratorna6.4.it/Laboratorna6.4.it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64
{
	TEST_CLASS(UnitTest64)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int SIZE = 20;
			int arr[SIZE]{};
			int MIN = -15;
			int MAX = 25;
			create(arr, SIZE, MIN, MAX);
			Assert::AreEqual(165, sum(arr, SIZE), 0.00001);
		}
	};
}
