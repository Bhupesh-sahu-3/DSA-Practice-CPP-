#include <bits/stdc++.h>
using namespace std;

// Average and worst case -> o(n^2)
// Best case -> o(n), outer loop runs n times while inner loop runs 1 time for each i value (already sorted)
// space-> o(1)

void insertionSort(int arr[], int n)
{
    int flag=0;
    for (int i = 0; i < n; ++i)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}

int main()
{
    int arr[] = {7, 3, 9, 1, 5, 3, 8, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}