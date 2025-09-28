#include<bits/stdc++.h>
using namespace std;

long long splitArray(vector<int>& nums){
    int n = nums.size();

    vector<long long> prefix(n + 1, 0);
    for(int i = 0; i < n; i++){
        prefix[i + 1] = prefix[i] + nums[i];
    }

    vector<bool> inc(n, false);
    inc[0] = true;
    for(int i = 1; i < n; i++){
        if(nums[i] > nums[i - 1] && inc[i - 1]) inc[i] = true;
    }

    vector<bool> dec(n, false);
    dec[n - 1] = true;
    for(int i = n - 2; i >= 0; i--){
        if(nums[i] > nums[i + 1] && dec[i + 1]) dec[i] = true;
    }

    long long ans = LLONG_MAX;
    bool found = false;

    for (int i = 1; i < n; i++) {
        if (inc[i - 1] && dec[i]) {
            long long sumLeft = prefix[i];
            long long sumRight = prefix[n] - prefix[i];
            ans = min(ans, abs(sumLeft - sumRight));
            found = true;
        }
    }

    return (found) ? ans : -1;
}

int main(){
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    long long ans = splitArray(nums);
    cout << ans;
    return 0;
}