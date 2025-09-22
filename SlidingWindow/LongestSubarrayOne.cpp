#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 1493. Longest Subarray of 1's After Deleting One Element
    Ý tưởng:
        - Duyệt mảng và mở rộng cửa sổ để chứa nhiều số 1 nhất có thể
        - Giới hạn số 0 trong cửa sổ: chỉ được có tối đa một số 0
        - Nếu số 0 vượt quá 1, thu hẹp cửa sổ bằng cách di chuyển left
*/

int longestSubarray(vector<int> nums){
    int zeroCount = 0, left = 0, maxLength = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 0){
            zeroCount++;
        }
        while(zeroCount > 1){
            if(nums[left] == 0){
                zeroCount--;
            }
            left++;
        }
        maxLength = max(maxLength, i - left);
    }
    return maxLength;
}

int main(){
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    int res = longestSubarray(nums);
    cout << res;
    return 0;
}