#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    int l = 0;
    for (int i = 0; i < s.length(); i++)
    {
        while (i < s.length() && s[i] != ' ')
        {
            i++;
        }
        int r = i - 1;
        while (l < r)
        {
            swap(s[l], s[r]);
            l++;
            r--;
        }
        l = i + 1;
    }
    return s;
}

int main()
{
    string s;
    getline(cin, s);
    string ans = reverseWords(s);
    cout << ans;
    return 0;
}