#include <bits/stdc++.h>
using namespace std;

int pivotInteger(int n)
{
    if (n == 1)
        return 1;

    vector<int> prefix(n);
    prefix[0] = 1;

    for (int i = 1; i < n; i++)
    {
        prefix[i] = (i + 1) + prefix[i - 1];
    }

    for (int i = 1; i < n - 1; i++)
    {
        if ((prefix[n - 1] - prefix[i - 1]) == prefix[i])
        {
            return i + 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int ans = pivotInteger(n);
    cout << ans;
    return 0;
}