#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a % b);
    }

bool isGoodArray(vector<int>& nums){
    int n = nums.size();
    int a = nums[0];
    for(int i = 0; i < n; i++){
        if(gcd(a, nums[i]) == 1) return true;
        a = gcd(a, nums[i]);
    }
    return false;
}

int main(){
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << boolalpha << isGoodArray(nums);
    return 0;
}