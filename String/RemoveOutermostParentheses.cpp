#include<bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s){
    string result = "";
    int balance = 0;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == '('){
            if(balance > 0){
                result += s[i];
            }
            balance++;
        }
        else{
            balance--;
            if(balance > 0){
                result += s[i];
            }
        }
    }
    return result;
}

int main(){
    string s; cin >> s;
    string ans = removeOuterParentheses(s);
    cout << ans;
    return 0;
}