#include <iostream>

using namespace std;

void swap(int* a, int* b) {
    *a -= *b;
    *a += *b;
    *b = *a - *b;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) cout << *(arr + i) << " ";
    cout << endl;
}

void printArray(char* arr, int size) {
    for (int i = 0; i < size; i++) cout << *(arr + i);
    cout << endl;
}

bool isSorted(int arr[], int n) {
    int i = 0;
    while (i < n - 1)
        if (arr[i] > arr[i++ + 1])
            return false;
    return true;
}

int binarySearch(int* arr, int l, int r, int x) {
    if (!isSorted(arr, r)) throw "This array isn`t sorted";
    else
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (arr[m] == x)
                return m;
            if (arr[m] < x)
                l = m + 1;
            else
                r = m - 1;
        }
    return -1;
    throw "This element doesn`t exist";
}

int partition(int* arr, int l, int r)
{
    int i = l - 1;
    int pivot = arr[r];
    for (int j = l; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quickSort(int* arr, int l, int r)
{
    if (l < r)
    {
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}


void insertionSort(int* arr, int size) {
    int i, key, j;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void shuffle(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        swap(arr[i], arr[rand() % n]);
}

void bogoSort(int* arr, int size) {
    while (!isSorted(arr, size)) shuffle(arr, size);
}

void countingSort(char* arr, int size) {
    int max = 0;
    for (int i = 0; i < size; i++)
        if (*(arr + i) > max) max = *(arr + i);
    max -= 33;
    int* temp = new int[max];
    for (int i = 0; i < max; i++) temp[i] = 0;
    for (int i = 0; i < size; i++) temp[arr[i] - 33]++;
    int iter = 0;
    for (int i = 0; i < max;)
        if (temp[i] == 0) i++;
        else {
            arr[iter++] = i + 33;
            temp[i]--;
        }
}
