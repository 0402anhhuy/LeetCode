#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 268. Missing Number
    Ý tưởng:
        - XOR các số từ [0, n]
        - XOR các số trong mảng nums
        - XOR hai kết quả sẽ trả về số còn thiếu
*/

int missingNumber(vector<int>& nums){
    int xorArr = 0, xorAll = 0;
    for(int i = 1; i <= nums.size(); i++){
        xorAll ^= i;
    }

    for(int i = 0; i < nums.size(); i++){
        xorArr ^= nums[i];
    }
    return xorAll ^ xorArr;
}

int main(){
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    int res = missingNumber(nums);
    cout << res;
    return 0;
}