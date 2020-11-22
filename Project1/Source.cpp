#include <iostream>
#include "SortFunc.h"
#include <time.h>

using namespace std;

int main() {
	const int cnt = 10;
	char* chararr = new char[cnt];
	int* arr = new int[cnt];
	//arr = (int*)realloc(arr, cnt * sizeof(int));
	srand(time(0));
	for (int i = 0; i < cnt; i++)
		*(arr + i) = rand() %  100;
	for (int i = 0; i < cnt; i++)
		*(chararr + i) = rand() % 93 + 33;
	printArray(arr, cnt);
	cout << binarySearch(arr, 0, cnt - 1, 2) << endl;
	quickSort(arr, 0, cnt - 1);
	//insertionSort(arr, cnt);
	//bogoSort(arr, cnt);
	printArray(arr, cnt);
	printArray(chararr, cnt);
	countingSort(chararr, cnt);
	printArray(chararr, cnt);
	return 0;
}