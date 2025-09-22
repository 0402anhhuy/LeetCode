#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode: 1. Two Sum
    Ý tưởng:
        - Ta tạo một map findIndex để lưu vị trí của phần tử nums[i].
        - Ta duyệt qua mảng nums, nếu phần tử target - nums[i] đã có trong findIndex thì ta trả về vị trí của phần tử target - nums[i] và i.
        - Nếu không ta cập nhật findIndex[nums[i]] = i.
        - Cuối cùng ta trả về mảng res.
*/

vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> findIndex;
    vector<int> res;

    for(int i = 0; i < nums.size(); i++){
        int current = target - nums[i];
        if(findIndex.find(current) != findIndex.end()){
            res.push_back(findIndex[current]);
            res.push_back(i);
            return res;
        }
        findIndex[nums[i]] = i;
    }
    return res;
}

int main(){
    int n, target; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cin >> target;
    vector<int> res = twoSum(nums, target);
    for(int tmp : res){
        cout << tmp << " ";
    }
    return 0;
}