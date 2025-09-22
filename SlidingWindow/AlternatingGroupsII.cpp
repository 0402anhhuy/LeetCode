#include<bits/stdc++.h>
using namespace std;

/*
    Leetcode - 3208. Alternating Groups II
    Ý tưởng:
        - Thêm k - 1 phần tử đầu vào cuối mảng
        - Duyệt mảng, nếu màu tại vị trí i giống màu tại vị trí i - 1 thì cập nhật left = i
        - Nếu right - left + 1 >= k thì tăng biến đếm cnt
        - Trả về cnt
*/

int numberOfAlternatingGroups(vector<int>& colors, int k){
    colors.insert(colors.end(), colors.begin(), colors.begin() + (k - 1));
    int cnt = 0, left = 0;
    for(int right = 1; right < colors.size(); right++){
        if(colors[right - 1] == colors[right]){
            left = right;
        }
        if(right - left + 1 >= k){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    int n, k; cin >> n;
    vector<int> colors(n);
    for(int i = 0; i < n; i++){
        cin >> colors[i];
    }
    cin >> k;
    int res = numberOfAlternatingGroups(colors, k);
    cout << res;
    return 0;
}