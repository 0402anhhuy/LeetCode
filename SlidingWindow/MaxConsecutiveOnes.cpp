#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 1004. Max Consecutive Ones III
    Ý tưởng:
        - Nếu gặp số 0, tăng biến đếm zeroCount
        - Nếu số lượng 0 vượt quá k, dịch biên left về phía phải để giảm số 0 trong cửa sổ
        - Cập nhật độ dài dãy con dài nhất
*/

int longestOnes(vector<int> nums, int k){
    int maxLength = 0, left = 0, zeroCount = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 0){
            zeroCount++;
        }
        while(zeroCount > k){
            if(nums[left] == 0){
                zeroCount--;
            }
            left++;
        }
        maxLength = max(maxLength, i - left + 1);
    }
    return maxLength;
}

int main(){
    int n, k; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    cin >> k;
    int res = longestOnes(nums, k);
    cout << res;
    return 0;
}