#include<bits/stdc++.h>
using namespace std;

vector<int> getNoZeroIntegers(int n){
    int a, b, temp_a, temp_b;
    for(int i = 0; i < n; i++){
        a = i, b = n - i, temp_a = a, temp_b = b;
        bool valid = true;

        while(temp_a != 0){
            if(temp_a % 10 == 0){
                valid = false;
                break;
            }
            temp_a /= 10;
        }

        while(valid && temp_b != 0){
            if(temp_b % 10 == 0){
                valid = false;
                break;
            }
            temp_b /= 10;
        }

        if(valid) return {a, b};
    }
    return {1, n - 1};
}

int main(){
    int n; cin >> n;
    vector<int> ans = getNoZeroIntegers(n);
    for(auto &num : ans){
        cout << num << " ";
    }
    return 0;
}