#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 167. Two Sum II - Input Array Is Sorted
    Ý tưởng:
        - Dùng 2 con trỏ l = 0, r = n - 1
        - Tính tổng của numbers[l] + numbers[r]
            + Nếu bằng target -> thêm vào kết quả
            + Nếu lớn hơn target -> giảm r (Cần số nhỏ hơn)
            + nếu nhỏ hơn target -> tăng l (Cần số lớn hơn)
*/

vector<int> twoSum(vector<int> numbers, int target){
    vector<int> res;
    int n = numbers.size();
    int l = 0, r = n - 1;
    while(l < r){
        int tmp = numbers[l] + numbers[r];
        if(tmp == target){
            res.push_back(l + 1);
            res.push_back(r + 1);
            break;
        }
        else{
            if(tmp > target) r--;
            else l++;
        }
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
    vector<int> res;
    res = twoSum(nums, target);
    for(auto result : res){
        cout << result << " ";
    }
    return 0;
}