#include<bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n);

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i = 2; i < n; i++){
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[n - 1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    int ans = rob(nums);
    cout << ans;
    return 0;
}