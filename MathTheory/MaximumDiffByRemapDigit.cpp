#include <bits/stdc++.h>
using namespace std;

int minMaxDifference(int num)
{
    string maxNum = to_string(num);
    for (int i = 0; i < maxNum.size(); i++)
    {
        if (maxNum[i] != '9')
        {
            char firstDigit = maxNum[i];
            for (int j = i; j < maxNum.size(); j++)
            {
                if (maxNum[j] == firstDigit)
                {
                    maxNum[j] = '9';
                }
            }
            break;
        }
    }

    string minNum = to_string(num);
    for (int i = 0; i < minNum.size(); i++)
    {
        char firstDigit = minNum[i];
        minNum[i] = '0';
        for (int j = i + 1; j < minNum.size(); j++)
        {
            if (minNum[j] == firstDigit)
            {
                minNum[j] = '0';
            }
        }
        break;
    }

    int maxNumAns = 0;
    for (int i = maxNum.size(); i >= 1; i--)
    {
        maxNumAns += (maxNum[maxNum.size() - i] - '0') * pow(10, i - 1);
    }

    int minNumAns = 0;
    for (int i = minNum.size(); i >= 1; i--)
    {
        minNumAns += (minNum[minNum.size() - i] - '0') * pow(10, i - 1);
    }

    return maxNumAns - minNumAns;
}

int main()
{
    int n;
    cin >> n;
    int ans = minMaxDifference(n);
    cout << ans;
    return 0;
}