#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode: 724. Find Pivot Index
    Ý tưởng:
        - Ta tạo 2 mảng leftSum và rightSum.
        - leftSum[i] là tổng của các phần tử từ 0 đến i.
        - rightSum[i] là tổng của các phần tử từ i đến n - 1.
        - Ta duyệt qua mảng nums, nếu leftSum[i] == rightSum[i] thì ta trả về i.
        - Nếu không tìm thấy thì ta trả về -1.
*/

int pivotIndex(vector<int> nums){
    int n = nums.size();
    vector<int> leftSum(n, 0), rightSum(n, 0);
    leftSum[0] = nums[0];
    rightSum[n - 1] = nums[n - 1];
    for(int i = 1; i < n; i++){
        leftSum[i] = leftSum[i - 1] + nums[i];
        rightSum[n - i - 1] = rightSum[n - i] + nums[n - i - 1];
    }
    for(int i = 0; i < n; i++){
        if(leftSum[i] == rightSum[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    int res = pivotIndex(nums);
    cout << res;
    return 0;
}