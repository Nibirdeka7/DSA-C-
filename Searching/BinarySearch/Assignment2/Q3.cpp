/* You are given an m x n integer matrix matrix with the following two properties:
Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target , return true if target is in matrix or false otherwise.
You must write a solution in O(log(m * n)) time complexity.
Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false */
#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &a, int tgt)
{
    int n = a.size();
    int m = a[0].size();
    int lo = 0;
    int hi = n * m - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        int row = mid / m;
        int col = mid % m;
        if (a[row][col] == tgt)
            return true;
        else if (a[row][col] < tgt)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return false;
}
int main()
{
    vector<vector<int>> a = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int tgt = 30;
    bool res = searchMatrix(a, tgt);
    cout << res;
}