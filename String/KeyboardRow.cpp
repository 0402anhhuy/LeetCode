#include <bits/stdc++.h>
using namespace std;

vector<string> findWords(vector<string> &words)
{
    map<char, int> row;
    string first = "qwertyuiop";
    string second = "asdfghjkl";
    string third = "zxcvbnm";

    for (char c : first)
        row[tolower(c)] = 1;
    for (char c : second)
        row[tolower(c)] = 2;
    for (char c : third)
        row[tolower(c)] = 3;

    vector<string> ans;
    for (string word : words)
    {
        int check = row[tolower(word[0])];
        bool flag = true;
        for (char c : word)
        {
            if (row[tolower(c)] != check)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            ans.push_back(word);
    }
    return ans;
}

int main()
{
    int n; cin >> n;
    vector<string> words(n);
    for(int i = 0; i < n; i++){
        cin >> words[i];
    }

    vector<string> ans = findWords(words);
    for(string word : ans){
        cout << word << endl;
    }
    return 0;
}