#include <bits/stdc++.h>
using namespace std;

long long numOfSubsequences(string s)
{
    map<char, int> charFreq;
    for (char c : s)
    {
        charFreq[c]++;
    }

    int ans1 = (charFreq['L'] + 1) * charFreq['C'] * charFreq['T'];
    int ans2 = charFreq['L'] * (charFreq['C'] + 1) * charFreq['T'];
    int ans3 = charFreq['L'] * charFreq['C'] * (charFreq['T'] + 1);
    return max({ans1, ans2, ans3});
}

int main()
{
    string s;
    cin >> s;
    long long ans = numOfSubsequences(s);
    cout << ans;
    return 0;
}