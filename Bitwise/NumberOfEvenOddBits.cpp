#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 2595. Number of Even and Odd Bits
    Ý tưởng:
        - Cho 1 biến index tương ứng vị trí của bit
        - Lấy bit cuối và xét giá trị index
            + Nếu là 1 và index chẵn -> chẵn++
            + Nếu là 1 và index lẻ -> lẻ++
*/

vector<int> evenOddBit(int n){
    vector<int> res;
    int index = 0, even = 0, odd = 0;
    while(n != 0){
        if(n & 1){
            if(index % 2 == 0){
                even++;
            }
            else odd++;
        }
        n >>= 1;
        index++;
    }
    res.push_back(even);
    res.push_back(odd);
    return res;
}

int main(){
    int n; cin >> n;
    vector<int> nums = evenOddBit(n);
    for(int num : nums){
        cout << num << " ";
    }
    return 0;
}