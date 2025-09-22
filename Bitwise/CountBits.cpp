#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 338. Counting Bits
    Ý tưởng:
        - Duyệt qua mảng [0, n], num = i (i = 0, 1, 2,..., n)
        - Đếm số bit 1 của num
        - Dùng (num & 1) để lấy bit cuối
        - Dịch bit sang phải 1 (n = n >> 1)
*/

vector<int> countBits(int n){
    vector<int> res;
    for(int i = 0; i <= n; i++){
        int cnt = 0, num = i;
        while(num != 0){
            cnt += (num & 1);
            num >>= 1;
        }
        res.push_back(cnt);
    }
    return res;
}

int main(){
    int n; cin >> n;
    vector<int> nums = countBits(n);
    for(int num : nums){
        cout << num << " ";
    }
    return 0;
}