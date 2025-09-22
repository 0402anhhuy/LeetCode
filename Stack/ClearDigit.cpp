#include <bits/stdc++.h>
using namespace std;

string clearDigits(string s)
{
    stack<char> characters;
    for (char c : s)
    {
        if (isdigit(c))
        {
            characters.pop();
        }
        else
        {
            characters.push(c);
        }
    }

    string ans = "";
    while (!characters.empty())
    {
        char c = characters.top();
        ans += c;
        characters.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s;
    cin >> s;
    string ans = clearDigits(s);
    cout << ans;
    return 0;
}