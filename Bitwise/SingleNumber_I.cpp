#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 136.Single Number
    Ý tưởng:
        + Dùng XOR -> các số giống nhau sẽ cho kết quả bằng 0
        + a ^ a = 0
        + a ^ 0 = a
*/

int singleNumber(vector<int> nums){
    int res = 0;
    for(int num : nums){
        res ^= num;
    }
    return res;
}

int main(){
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int res = singleNumber(nums);
    cout << res;
    return 0;
}