#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 137. Single Number II
    Ý tưởng:
        - Nếu một số num xuất hiện lần thứ nhất, nó sẽ được thêm vào ones
        - Nếu xuất hiện lần thứ hai, nó sẽ chuyển từ ones sang twos
        - Nếu xuất hiện lần thứ ba, nó sẽ bị loại khỏi cả ones và twos (bị reset về 0)
*/

int singleNumber(vector<int> nums){
    int ones = 0, twos = 0;
    for(int num : nums){
        ones = (ones ^ num) & ~twos;
        twos = (twos ^ num) & ~ones;
    }
    return ones;
}

int main(){
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int res = singleNumber(nums);
    cout << res;
    return 0;
}