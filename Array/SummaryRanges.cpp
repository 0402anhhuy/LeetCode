#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode: 228. Summary Ranges
    Ý tưởng:
        - Ta duyệt qua mảng nums, với mỗi phần tử nums[i] ta duyệt qua mảng nums từ i đến hết mảng hoặc phần tử nums[i] + 1 khác phần tử nums[i].
        - Nếu i == j thì ta thêm phần tử nums[i] vào mảng res.
        - Nếu không thì ta thêm phần tử nums[i] + "->" + nums[j] vào mảng res.
        - Cuối cùng ta trả về mảng res.
*/

vector<string> summaryRanges(vector<int>& nums){
    vector<string> res;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        int j = i;
        while(i + 1 < n && nums[i] + 1 == nums[i + 1]){
            i++;
        }
        if(i == j){
            res.push_back(to_string(nums[j]));
        } 
        else{
            res.push_back(to_string(nums[j]) + "->" + to_string(nums[i])); // Range
        }
    }
    return res;
}

int main(){
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    vector<string> res = summaryRanges(nums);
    for(string result : res){
        cout << result << " ";
    }
    return 0;
}