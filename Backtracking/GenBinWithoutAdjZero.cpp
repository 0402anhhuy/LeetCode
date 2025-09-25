#include<bits/stdc++.h>
using namespace std;

vector<string> result;

void backtrack(string &cur, int n){
    if(cur.length() == n){
        result.push_back(cur);
        return;
    }

    if(!cur.empty() && cur.back() == '0'){
        cur.push_back('1');
        backtrack(cur, n);
        cur.pop_back();
    }
    else{
        // Nếu ký tự cuối cùng không phải '0' -> thử cả hai trường hợp '0' và '1'
        for(char i = '0'; i <= '1'; i++){
            cur.push_back(i);
            backtrack(cur, n);
            cur.pop_back();
        }
    }
}

vector<string> validStrings(int n){
    string cur = "";
    backtrack(cur, n);
    return result;
}

int main(){
    int n; cin >> n;
    vector<string> ans = validStrings(n);
    for(string s : ans){
        cout << s << " ";
    }
    return 0;
}