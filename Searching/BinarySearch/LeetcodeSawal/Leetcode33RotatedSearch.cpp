#include <bits/stdc++.h>
using namespace std;
int binSearch(vector<int> &a, int low, int high, int tgt)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (mid == tgt)
            return mid;
        if (a[mid] > tgt)
            high = mid - 1;
        else
            low = mid + 1;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int tgt;
    cin >> tgt;
    int lo = 0, hi = n - 1;
    int pivot = -1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (a[mid] < a[mid + 1] && a[mid] < a[mid - 1])
        {
            pivot = mid;
            break;
        }
        else if (a[mid] > a[mid + 1] && a[mid] > a[mid - 1])
        {
            pivot = mid + 1;
            break;
        }
        else if (a[mid] > a[hi])
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    if (tgt >= a[0] && tgt <= a[pivot - 1])
        cout << binSearch(a, 0, pivot - 1, tgt);
    else
        cout << binSearch(a, pivot, n, tgt);
}