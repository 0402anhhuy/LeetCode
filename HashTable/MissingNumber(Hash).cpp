#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode: 268. Missing Number
    Ý tưởng:
        - Ta tạo một unordered_map arr để lưu các phần tử của mảng nums.
        - Ta duyệt qua mảng nums, với mỗi phần tử num ta thêm num vào arr.
        - Ta duyệt từ 0 đến nums.size(), nếu i không có trong arr thì ta trả về i.
        - Cuối cùng ta trả về -1.
*/

int missingNumber(vector<int> nums) {
    unordered_map<int, bool> arr;
    for(int num : nums){
        arr[num] = true;
    }

    for(int i = 0; i <= nums.size(); i++){
        if(arr.find(i) == arr.end()){
            return i;
        }
    }
    return -1;
}

int main(){
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    int res = missingNumber(nums);
    cout << res;
    return 0;
}