#include <bits/stdc++.h>
using namespace std;

// Average and worst case -> o(n^2)
// Best case -> o(n), outer loop runs 1 time and inner loop runs n times
// space-> o(1)

void bubbleSort(int arr[], int n)
{
    int flag = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j + 1] < arr[j])
            {
                flag = 1;
                swap(arr[j + 1], arr[j]);
            }
        }
        if (flag == 0) // already sorted
            break;     // no further need of comparisons
    }
}

int main()
{
    int arr[] = {7, 3, 9, 1, 5, 3, 8, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}