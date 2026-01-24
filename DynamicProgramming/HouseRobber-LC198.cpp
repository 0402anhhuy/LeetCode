#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode 198. House Robber

    Đề bài:  
    Bạn là một tên trộm chuyên nghiệp đang lập kế hoạch đi trộm các ngôi nhà dọc theo một con phố
    Mỗi ngôi nhà có một số tiền nhất định (nums[i])

    Yêu cầu:  
    → Bạn cần chọn các ngôi nhà để trộm sao cho tổng số tiền thu được là lớn nhất
    → Ràng buộc: Không được trộm hai ngôi nhà liền kề nhau trong cùng một đêm, vì hệ thống an ninh sẽ tự động báo cảnh sát
    → Trả về tổng số tiền tối đa có thể trộm được mà không làm báo động kêu

    Ví dụ:  
        Input: nums = [1, 2, 3, 1]  
        → Cách 1: Trộm nhà 1 (1) và nhà 3 (3) => Tổng = 1 + 3 = 4
        → Cách 2: Trộm nhà 2 (2) và nhà 4 (1) => Tổng = 2 + 1 = 3
        → Output: 4
*/

int rob(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n);

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i = 2; i < n; i++){
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[n - 1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    int ans = rob(nums);
    cout << ans;
    return 0;
}