#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode: 349. Intersection of Two Arrays
    Ý tưởng:
        - Sắp xếp 2 mảng
        - Duyệt 2 mảng với 2 biến i, j
        - Nếu nums1[i] == nums2[j] thì thêm vào res
        - Nếu nums1[i] < nums2[j] thì tăng i
        - Nếu nums1[i] > nums2[j] thì tăng j
        - Đảm bảo res không chứa phần tử trùng lặp
*/

vector<int> intersection(vector<int> nums1, vector<int> nums2){
    vector<int> res;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i = 0, j = 0;
    while(i < nums1.size() && j < nums2.size()){
        if(nums1[i] == nums2[j]){
            if(res.empty() || res.back() != nums1[i]){
                res.push_back(nums1[i]);
            }
            i++;
            j++;
        }
        else if(nums1[i] < nums2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    return res;
}

int main(){
    int m, n; cin >> m >> n;
    vector<int> nums1(m), nums2(n);
    for(int i = 0; i < m; i++) cin >> nums1[i];
    for(int i = 0; i < n; i++) cin >> nums2[i];
    vector<int> res = intersection(nums1, nums2);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    return 0;
}