#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode: 55. Jump Game
    Ý tưởng:
        - Ta duyệt qua mảng nums, với mỗi phần tử nums[i] ta cập nhật maxReach = max(maxReach, i + nums[i]).
        - Nếu i > maxReach thì ta trả về false.
        - Nếu maxReach >= n - 1 thì ta trả về true.
        - Cuối cùng ta trả về false.
*/

bool canJump(vector<int> nums){
    int n = nums.size(), maxReach = 0;
    for(int i = 0; i < n; i++){
        if(i > maxReach){
            return false;
        }
        maxReach = max(maxReach, i + nums[i]);
        if(maxReach >= n - 1){
            return true;
        }
    }
    return false;
}

int main(){
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    bool res = canJump(nums);
    cout << boolalpha << res;
    return 0;
}