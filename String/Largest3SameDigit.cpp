#include<bits/stdc++.h>
using namespace std;

string largestGoodInteger(string num) {
    string temp = "", ans = "";
    for(int i = 0; i + 2 < num.length(); i++){
        if(num[i] == num[i + 1] && num[i] == num[i + 2]){
            temp = num.substr(i, 3);
            ans = max(ans, temp);
        }
    }
    return ans;
}

int main(){
    string num; cin >> num;
    string ans = largestGoodInteger(num);
    cout << ans;
    return 0;
}