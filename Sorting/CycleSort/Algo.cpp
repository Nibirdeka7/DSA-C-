#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {5, 6, 3, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    while (i < n)
    {
        int correctIdx = arr[i] - 1;
        if (i == correctIdx)
            i++;
        else
            swap(arr[i], arr[correctIdx]);
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}