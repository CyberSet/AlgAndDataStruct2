#include "pch.h"
#include "CppUnitTest.h"
#include "..\Project1\SortFunc.cpp"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortTests
{
	TEST_CLASS(SortTests)
	{
	public:
		int arr[10] = { 8, 9, 7, 6, 1, 3, 2, 5, 10, 4 };
		int sorted[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		char chararr[10] = {'h', 'a', 'v', 's', 'd', 'e', 'k', 'l', 'i', 'b'};

		TEST_METHOD(isSortedTest1)
		{
			Assert::IsTrue(isSorted(sorted, 10));
		}

		TEST_METHOD(isSortedTest2)
		{
			Assert::IsTrue(!isSorted(arr, 10));
		}

		TEST_METHOD(binarySearchTest1)
		{
			Assert::IsTrue(binarySearch(sorted, 0, 10, 4) == 3);
		}

		TEST_METHOD(binarySearchTest2) 
		{
			try
			{
				int res = binarySearch(arr, 0, 9, 4);
			}
			catch (const char* warning)
			{
				Assert::AreEqual(warning, "This array isn`t sorted");
			}
		}

		TEST_METHOD(binarySearchTest3)
		{
			try
			{
				int res = binarySearch(sorted, 0, 9, 0);
			}
			catch (const char* warning)
			{
				Assert::AreEqual(warning, "This element doesn`t exist");
			}
		}

		TEST_METHOD(quickSortTest1)
		{
			quickSort(arr, 0, 9);
			Assert::IsTrue(isSorted(arr, 10));
		}

		TEST_METHOD(quickSortTest2)
		{
			quickSort(sorted, 0, 9);
			Assert::IsTrue(isSorted(sorted, 10));
		}

		TEST_METHOD(insertionSortTest1)
		{
			insertionSort(arr, 10);
			Assert::IsTrue(isSorted(arr, 10));
		}

		TEST_METHOD(insertionSortTest2)
		{
			insertionSort(sorted, 10);
			Assert::IsTrue(isSorted(sorted, 10));
		}

		TEST_METHOD(bogoSortTest1)
		{
			bogoSort(arr, 10);
			Assert::IsTrue(isSorted(arr, 10));
		}

		TEST_METHOD(bogoSortTest2)
		{
			bogoSort(sorted, 10);
			Assert::IsTrue(isSorted(sorted, 10));
		}

		TEST_METHOD(countingSortTest1)
		{
			countingSort(chararr, 10);
			Assert::IsTrue(chararr[0] == 'a' && chararr[9] == 'v');
		}
	};
}
