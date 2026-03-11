#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {-2, -1, 0, -2, 4, 3};

    int cn = 0, cz = 0, cp = 0; // cn=count of -ve, cz= count of 0
    int prod_pos = 1;
    int prod_neg = 1;
    int largestNeg = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 0)
            cz++;
        if (v[i] < 0)
        {
            cn++;
            prod_neg *= v[i];
            largestNeg = max(v[i], largestNeg);
        }
        if (v[i] > 0)
        {
            cp++;
            prod_pos *= v[i];
        }
    }

    if (cn == 0)
    {
        if (cz > 0)
            cout << 0;
        else
        {
            auto it = min_element(v.begin(), v.end());
            cout << *it;
        }
    }
    else
    {
        if (cn % 2 == 0)
        {
            if (largestNeg != 0)
                cout << (prod_neg / largestNeg) * prod_pos;
            else
                cout << 0; // Handle the case where largestNeg is zero
        }
        else
        {
            cout << prod_pos * prod_neg;
        }
    }
}