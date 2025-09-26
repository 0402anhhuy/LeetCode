#include<bits/stdc++.h>
using namespace std;

vector<int> minSubsequence(vector<int>& nums){
    sort(nums.begin(), nums.end(), greater<int>());
    
    int sumFirst = 0, sumSecond = 0;
    for(int i = 0; i < nums.size(); i++){
        sumFirst += nums[i];
    }

    vector<int> ans;
    for(int i = 0; i < nums.size(); i++){
        sumFirst -= nums[i];
        sumSecond += nums[i];
        ans.push_back(nums[i]);

        if(sumSecond > sumFirst){
            break;
        }
    }
    return ans;
}


int main(){
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    vector<int> ans = minSubsequence(nums);
    for(int num : ans){
        cout << num << " ";
    }
    return 0;
}