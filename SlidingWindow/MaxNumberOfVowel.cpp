#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 1456. Maximum Number of Vowels in a Substring of Given Length
    Ý tưởng:
        - Đếm số lượng nguyên âm từ đầu đến k
        - Duyệt từ k đến hết chuỗi
        - Cập nhật số lượng nguyên âm = (vowel.count(s[i]) - vowel.count(s[i - k]))
        - Cập nhật res
*/

int maxVowels(string s, int k){
    set<char> vowel = {'u', 'e', 'o', 'a', 'i'};
    int maxNumberVowel = 0;
    for(int i = 0; i < k; i++){
        maxNumberVowel += vowel.count(s[i]);
    }
    int res = maxNumberVowel;
    for(int i = k; i < s.length(); i++){
        maxNumberVowel += (vowel.count(s[i]) - vowel.count(s[i - k]));
        res = max(res, maxNumberVowel);
    }
    return res;
}

int main(){
    string s; cin >> s;
    int k; cin >> k;
    int res = maxVowels(s, k);
    cout << res;
    return 0;
}