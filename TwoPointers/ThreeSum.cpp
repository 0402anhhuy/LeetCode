#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 15. 3Sum
    Ý tưởng:
        - Đưa bài toán về 2Sum
        - Sắp xếp mảng, nếu phần tử đầu tiên > 0 -> Không có tổng bằng 0
        - Duyệt từng phần tử nums[i] làm số đầu tiên của bộ ba
        - Tìm hai số còn lại (nums[l] và nums[r]) sao cho:
                    nums[i] + nums[l] + nums[r] = 0
        - Dùng 2 con trỏ l = i + 1, r = n - 1
            + Nếu tổng bằng 0, thêm vào kết quả
            + Nếu tổng nhỏ hơn 0, tăng l (cần số lớn hơn)
            + Nếu tổng lớn hơn 0, giảm r (cần số nhỏ hơn)
        - Loại bỏ trùng lặp
            + Sau khi tìm được bộ ba hợp lệ, bỏ qua các số trùng nhau bằng cách tăng l hoặc giảm r
            + nums[l] == nums[l + 1] hoặc nums[r] == nums[r - 1]
            + Sau khi xét nums[i], cũng cần bỏ qua nums[i] trùng nhau
*/

vector<vector<int>> threeSum(vector<int> nums){
    vector<vector<int>> res;
    int n = nums.size();
    int i = 0, target = 0, index = 0;
    sort(nums.begin(), nums.end());
    while(i < n - 1){
        if(nums[i] > 0) break;
        target = -nums[i];
        int l = i + 1, r = n - 1;
        while(l < r){
            if(nums[l] + nums[r] == target){
                res.push_back({-target, nums[l], nums[r]});

                // Loại bỏ trùng lặp
                while(l < r && nums[l] == nums[l + 1]) l++;
                while(l < r && nums[r] == nums[r - 1]) r--;
                l++;
                r--;
            }
            else{
                if(nums[l] + nums[r] < target) l++;
                else r--;
            }
        }
        while(i < n - 1 && nums[i] == nums[i + 1]) i++;
        i++;
    }
    return res;
}

int main(){
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    vector<vector<int>> res = threeSum(nums);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}