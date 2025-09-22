#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 209. Minimum Size Subarray Sum
    Ý tưởng:
        - Tính windowSum đầu tiên lớn hơn bằng target
        - Lặp khi vẫn còn lớn hơn bằng
            + Cập nhật minLength = end - start + 1
            + Trừ windowSum cho nums[start]
            + Nếu vẫn lớn hơn thì tiếp tục cập nhật minLength

*/

int minSubArrayLen(int target, vector<int> nums){
    int n = nums.size();
    int start = 0, windowSum = 0, minLength = INT_MAX;

    for(int end = 0; end < n; end++){
        windowSum += nums[end];

        while(windowSum >= target){
            minLength = min(minLength, end - start + 1);
            windowSum -= nums[start];
            start++;
        }
    }
    return (minLength == INT_MAX) ? 0 : minLength;
}

int main(){
    int n, target; cin >> n >> target;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int res = minSubArrayLen(target, nums);
    cout << res;
    return 0;
}