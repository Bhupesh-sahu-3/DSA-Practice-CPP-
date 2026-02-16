#include <bits/stdc++.h>
using namespace std;

// o(n^2) time
// o(1) space
void selectionSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}

int main()
{
    int arr[] = {7, 3, 9, 1, 5, 3, 8, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}