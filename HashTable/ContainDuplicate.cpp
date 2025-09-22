#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode: 219. Contains Duplicate II
    Ý tưởng:
        - Ta tạo một unordered_map findIndex để lưu vị trí của phần tử nums[i].
        - Ta duyệt qua mảng nums, nếu phần tử nums[i] đã có trong findIndex và i - findIndex[nums[i]] <= k thì ta trả về true.
        - Nếu không ta cập nhật findIndex[nums[i]] = i.
        - Cuối cùng ta trả về false.
*/

bool containsNearbyDuplicate(vector<int>& nums, int k){
    unordered_map<int, int> findIndex;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(findIndex.find(nums[i]) != findIndex.end()){
            if(i - findIndex[nums[i]] <= k){
                return true;
            }
        }
        findIndex[nums[i]] = i;
    }
    return false;
}

int main(){
    int n, k; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cin >> k;
    bool res = containsNearbyDuplicate(nums, k);
    cout << boolalpha << res;
    return 0;
}