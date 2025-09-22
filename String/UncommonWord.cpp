#include <bits/stdc++.h>
using namespace std;

vector<string> uncommonFromSentences(string s1, string s2)
{
    map<string, int> sentenceFreq;

    string sentence = "";
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] != ' ')
        {
            sentence += s1[i];
        }
        else
        {
            sentenceFreq[sentence]++;
            sentence = "";
        }
    }

    sentenceFreq[sentence]++;
    sentence = "";

    for (int i = 0; i < s2.length(); i++)
    {
        if (s2[i] != ' ')
        {
            sentence += s2[i];
        }
        else
        {
            sentenceFreq[sentence]++;
            sentence = "";
        }
    }

    sentenceFreq[sentence]++;

    vector<string> ans;
    for (auto &[s, f] : sentenceFreq)
    {
        ans.push_back(s);
    }
    return ans;
}

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    vector<string> ans = uncommonFromSentences(s1, s2);
    for (string s : ans)
    {
        cout << s << endl;
    }
    return 0;
}