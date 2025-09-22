#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 415. Add Strings
*/

string addStrings(string num1, string num2){
    string res = "";
    while(num1.length() < num2.length()){
        num1 = '0' + num1;
    }

    while(num2.length() < num1.length()){
        num2 = '0' + num2;
    }

    int carry = 0;
    for(int i = num1.length() - 1; i >= 0; i--){
        int x = (num1[i] - '0') + (num2[i] - '0') + carry;
        res += (x % 10) + '0';
        carry = x / 10;
    }
    if(carry != 0) res += carry + '0';
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    string num1, num2; cin >> num1 >> num2;
    string res = addStrings(num1, num2);
    cout << res;
    return 0;
}