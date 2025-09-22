#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 2379. Minimum Recolors to Get K Consecutive Black Blocks
    Ý tưởng:
        - Đếm số lượng block màu trắng trong k block đầu tiên.
        - Duyệt từ k đến hết chuỗi:
            + Nếu block thứ i màu trắng thì tăng biến wBlock lên 1.
            + Nếu block thứ i - k màu trắng thì giảm biến wBlock đi 1.
            + Cập nhật res = min(res, wBlock).
*/

int minimumRecolors(string blocks, int k){
    int wBlock = 0, res = INT_MAX;
    for(int i = 0; i < k; i++){
        if(blocks[i] == 'W'){
            wBlock++;
        } 
    }
    res = min(res, wBlock);
    for(int i = k; i < blocks.size(); i++){
        if(blocks[i] == 'W'){
            wBlock++;
        } 
        if(blocks[i - k] == 'W'){
            wBlock--;
        }
        res = min(res, wBlock);
    }
    return res;
}

int main(){
    string blocks; cin >> blocks;
    int k; cin >> k;
    int res = minimumRecolors(blocks, k);
    cout << res;
    return 0;
}