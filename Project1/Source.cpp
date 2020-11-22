#include <iostream>
#include "SortFunc.h"
#include <time.h>

using namespace std;

int main() {
	const int cnt = 10;
	char* chararr = new char[cnt];
	int* arr = new int[cnt];
	double* res = new double[10];
	srand(time(0));
	/*for (int j = 0; j < 10; j++) {
		for (int i = 0; i < cnt; i++)
			*(arr + i) = rand() % (cnt * 10);
		clock_t start = clock();
		insertionSort(arr, cnt);
		clock_t stop = clock();
		clock_t itog = stop - start;
		res[j] = ((double)itog * 1000 / CLOCKS_PER_SEC);
	}*/
	for (int i = 0; i < cnt; i++)
		*(arr + i) = rand() % (cnt * 10);
	for (int i = 0; i < cnt; i++)
		*(chararr + i) = rand() % 93 + 33;
	printArray(arr, cnt);
	quickSort(arr, 0, cnt - 1);
	//insertionSort(arr, cnt);
	//bogoSort(arr, cnt);
	printArray(arr, cnt);
	cout << binarySearch(arr, 0, cnt - 1, *(arr + 2)) << endl;
	printArray(chararr, cnt);
	countingSort(chararr, cnt);
	printArray(chararr, cnt);
	return 0;
}