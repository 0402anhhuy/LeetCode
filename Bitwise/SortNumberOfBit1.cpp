#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 1356. Sort Integers by The Number of 1 Bits
    Ý tưởng:
        - Đếm số lượng bit của nums[i]
        - Nếu số lượng bằng nhau thì xếp theo (a < b)
        - Xếp theo số lượng bit 1
*/

bool compare(int a, int b){
    int cnt_a = 0, cnt_b = 0, tmp_a = a, tmp_b = b;
    for(int i = 0; i < 32; i++){
        if(a & 1) cnt_a++;
        if(b & 1) cnt_b++;
        a >>= 1;
        b >>= 1;
    }
    if(cnt_a == cnt_b) return tmp_a < tmp_b;
    return cnt_a < cnt_b;
}

vector<int> sortByBits(vector<int>& arr){
    sort(arr.begin(), arr.end(), compare);
    return arr;
}

int main(){
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    vector<int> res = sortByBits(nums);
    for(int num : nums){
        cout << num << " ";
    }
    return 0;
}