#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 344. Reverse String
    Ý tưởng:
        - Dùng 2 con trỏ để hoán đổi ký tự
*/

void reverseString(vector<char>& s){
    int l = 0, r = s.size() - 1;
    while(l < r){
        char tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        l++;
        r--;
    }
}

int main(){
    string s; cin >> s;
    vector<char> arrS(s.length());
    for(int i = 0; i < s.length(); i++){
        arrS[i] = s[i];
    }
    reverseString(arrS);
    for(char c : arrS){
        cout << c << " ";
    }
    return 0;
}