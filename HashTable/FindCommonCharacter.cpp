#include <bits/stdc++.h>
using namespace std;

vector<string> commonChars(vector<string> &words)
{
    vector<int> commonCharacter(26), currentCharacter(26);
    vector<string> result;

    for (char ch : words[0])
    {
        commonCharacter[ch - 'a']++;
    }

    for (int i = 1; i < words.size(); i++)
    {
        fill(currentCharacter.begin(), currentCharacter.end(), 0);

        for (char ch : words[i])
        {
            currentCharacter[ch - 'a']++;
        }

        for (int letter = 0; letter < 26; letter++)
        {
            commonCharacter[letter] = min(commonCharacter[letter], currentCharacter[letter]);
        }
    }

    for (int letter = 0; letter < 26; letter++)
    {
        for (int common = 0; common < commonCharacter[letter]; common++)
        {
            result.push_back(string(1, letter + 'a'));
        }
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    vector<string> result = commonChars(words);
    for (string str : result)
    {
        cout << str << " ";
    }
    return 0;
}