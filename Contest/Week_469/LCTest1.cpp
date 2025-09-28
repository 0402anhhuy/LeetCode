#include<bits/stdc++.h>
using namespace std;

vector<int> decimalRepresentation(int n) {
    vector<int> ans;
    int multiple = 0;

    while(n > 0){
        int digit = n % 10;
        if(digit != 0){
            ans.push_back(digit * pow(10, multiple));
        }
        multiple++;
        n /= 10;
    }
    sort(ans.begin(), ans.end(), greater<int>());
    return ans;
}

int main(){
    int n; cin >> n;
    vector<int> ans = decimalRepresentation(n);
    for(int num : ans){
        cout << num << " ";
    }
    return 0;
}