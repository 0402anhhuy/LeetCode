#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 541. Reverse String II
    Ý tưởng:
        - Duyệt qua từng ký tự của chuỗi
        - Nếu i % (2 * k) == 0 thì đảo ngược chuỗi từ i đến min(i + k, n)
*/

string reverseStr(string s, int k){
    int n = s.size();
    for(int i = 0; i < n; i += 2 * k){
        int l = i, r = min(i + k, n) - 1;
        while(l < r){
            swap(s[l++], s[r--]);
        }
    }
    return s;       
}

int main(){
    string s; cin >> s;
    int k; cin >> k;
    return 0;
}