#include<bits/stdc++.h>
using namespace std;

/*
    Ý tưởng:
        + Nếu phần tử ở 2 đầu, chỉ cần kiếm tra xem có lớn hơn 1 phần tử bên cạnh
        + Kiếm tra phần tử i nếu bé hơn i + 1 -> Mảng đang tăng -> Peak có thể nằm bên phải (kiểm tra mảng con phải - low = mid + 1)
        + Kiểm tra phần tử i nếu bé hơn i - 1 -> Mảng đang tăng -> Peak có thể nằm bên trái (kiếm tra mảng con trái - high = mid - 1)
*/

int findPeakElement(vector<int> nums){
    int low = 0, high = nums.size() - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if((mid == 0 || nums[mid - 1] < nums[mid]) && (mid == nums.size() - 1 || nums[mid] > nums[mid + 1])){
            return mid;
        }
        else if(nums[mid] < nums[mid + 1]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}

int main(){
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int res = findPeakElement(nums);
    cout << res;
    return 0;
}