#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode: 56. Merge Intervals
    Ý tưởng:
        - Ta sắp xếp mảng intervals theo thứ tự tăng dần của phần tử đầu tiên của mỗi phần tử.
        - Ta duyệt qua mảng intervals, nếu mảng res rỗng hoặc phần tử cuối cùng của mảng res nhỏ hơn phần tử đầu tiên của phần tử hiện tại thì ta thêm phần tử hiện tại vào mảng res.
        - Nếu không thì ta cập nhật phần tử cuối cùng của mảng res bằng max của phần tử cuối cùng của mảng res và phần tử cuối cùng của phần tử hiện tại.
        - Cuối cùng ta trả về mảng res.
*/

vector<vector<int>> merge(vector<vector<int>>& intervals){
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    for(auto interval : intervals){
        if(res.empty() || res.back()[1] < interval[0]){
            res.push_back(interval);
        }
        else{
            res.back()[1] = max(res.back()[1], interval[1]);
        }
    }
    return res;
}

int main(){
    int n; cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            cin >> intervals[i][j];
        }
    }
    vector<vector<int>> mergedIntervals = merge(intervals);
    for(auto interval : mergedIntervals){
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    return 0;
}