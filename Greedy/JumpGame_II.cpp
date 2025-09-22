#include<bits/stdc++.h>
using namespace std;

/*
	LeetCode: 45. Jump Game II
	Ý tưởng:
		- Ta duyệt qua mảng nums, với mỗi phần tử nums[i] ta cập nhật maxReach = max(maxReach, i + nums[i]).
		- Nếu i == currentEnd thì ta cập nhật jumps++ và cập nhật currentEnd = maxReach.
		- Nếu currentEnd >= n - 1 thì ta trả về jumps.
		- Cuối cùng ta trả về jumps.
*/

int jump(vector<int> nums){
	int n = nums.size();
	int maxReach = 0, jumps = 0, currentEnd = 0;
	for(int i = 0; i < n; i++){
        maxReach = max(maxReach, i + nums[i]);
        if(i == currentEnd){
            jumps++;
			currentEnd = maxReach;
        }

		if(currentEnd >= n - 1){
			return jumps;
		}
	}
    return jumps;
}

int main(){
	int n; cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; i++){
		cin >> nums[i];
	}
	int res = jump(nums);
	cout << res;
	return 0;
}