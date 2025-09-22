#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 389. Find the Difference
    Ý tưởng:
        - XOR các ký tự của chuỗi s (Dùng XOR int(char))
        - XOR các ký tự của chuỗi t (Dùng XOR int(char))
        - XOR 2 kết quả trên sẽ trả về ký tự khác biệt
*/

char findTheDifference(string s, string t){
    int xorS = 0, xorT = 0;
    for(int i = 0; i < s.length(); i++){
        xorS ^= (s[i] - 'a');
    }

    for(int i = 0; i < t.length(); i++){
        xorT ^= (t[i] - 'a');
    }
    int res = xorS ^ xorT;
    return (res + 'a');
}

int main(){
    string s, t; cin >> s >> t;
    char res = findTheDifference(s, t);
    cout << res;
    return 0;
}