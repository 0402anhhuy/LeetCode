#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode 2375. Construct Smallest Number From DI String
    - Dùng Stack
*/

string smallestNumber(string pattern){
    string ans = "";
    stack<int> result;

    for(int i = 0; i <= pattern.length(); i++){
        result.push(i + 1);

        if(i == pattern.length() || pattern[i] == 'I'){
            while(!result.empty()){
                ans += to_string(result.top());
                result.pop();
            }
        }
    }
    return ans;
}

int main(){
    string pattern; cin >> pattern;
    string ans = smallestNumber(pattern);
    cout << ans;
    return 0;
}