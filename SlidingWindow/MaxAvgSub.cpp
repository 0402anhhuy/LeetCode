#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 643. Maximum Average Subarray I
    Ý tưởng:
        - Tính windowSum đầu tiên tới vị trí thứ k
        - Duyệt từ vị trí k tới hết mảng
        - Cập nhật windowSum += (nums[i] - nums[i - k])
        - Cập nhật res
*/

double findMaxAverage(vector<int>& nums, int k){
    double windowSum = 0;
    for(int i = 0; i < k; i++){
        windowSum += nums[i];
    }

    double res = windowSum / k;
    for(int i = k; i < nums.size(); i++){
        windowSum += (nums[i] - nums[i - k]);
        res = max(res, (windowSum / k));
    }
    return round(res * 10000) / 100000;
}

int main(){
    int n, k; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    cin >> k;
    double res = findMaxAverage(nums, k);
    cout << res;
    return 0;
}