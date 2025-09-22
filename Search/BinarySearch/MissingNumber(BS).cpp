#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums){
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.size();
    while(left < right){
        int mid = left + (right - left) / 2;
        // Số bị thiếu sẽ nằm bên trái
        if(nums[mid] > mid){
            right = mid;
        }
        
        // Số bị thiếu sẽ nằm bên phải
        else{
            left = mid + 1;
        }
    }
    return left;
}

int main(){
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    int res = missingNumber(nums);
    cout << res;
    return 0;
}