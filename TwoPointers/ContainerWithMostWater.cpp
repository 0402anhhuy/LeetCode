#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 11. Container With Most Water
    Ý tưởng:
        - Dùng 2 con trỏ duyệt 2 đầu của mảng
        - Diện tích chứa được nước là chiều cao nhỏ hơn (giữa 2 cột) và khoảng cách từ l đến r
        - Hoặc là diện tích giữa 2 cột lớn và khoảng cách l đến r
*/

int maxArea(vector<int> height){
    int n = height.size();
    int l = 0, r = n - 1, res = 0;
    while(l < r){
        res = max(res, ((r - l) * min(height[l], height[r])));
        if(height[l] < height[r]){
            l++;
        }
        else r--;
    }
    return res;
}

int main(){
    int n; cin >> n;
    vector<int> height(n);
    for(int i = 0; i < n; i++){
        cin >> height[i];
    }
    int res = maxArea(height);
    cout << res;
    return 0;
}