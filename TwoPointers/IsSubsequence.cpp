#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 392. Is Subsequence
    Ý tưởng:
        - Dùng 2 con trỏ (l duyệt chuỗi s, r duyệt chuỗi t)
        - Nếu s[l] = t[r] -> tăng l lên
        - So sánh l là độ dài của s
*/

bool isSubsequence(string s, string t){
    int l = 0, r = 0;
    while(l < s.size() && r < t.size()){
        if(s[l] == t[r]){
            l++;
        }
        r++;
    }
    return l == s.size();
}

int main(){
    string s, t; cin >> s >> t;
    bool res = isSubsequence(s, t);
    cout << boolalpha << res;
    return 0;
}