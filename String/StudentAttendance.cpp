#include <bits/stdc++.h>
using namespace std;

bool checkRecord(string s)
{
    int absent = 0, late = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'A') absent++;
        if(s[i] == 'L') late++;
        else late = 0;

        if(absent == 2 || late == 3){
            return false;
        }
    }
    return true;
}

int main()
{
    string s; cin >> s;
    cout << boolalpha << checkRecord(s);
    return 0;
}