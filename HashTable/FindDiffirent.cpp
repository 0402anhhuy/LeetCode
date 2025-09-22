#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode: 2215. Find the Difference of Two Arrays
    Ý tưởng:
        - Ta tạo 2 unordered_set set1 và set2 để lưu các phần tử của nums1 và nums2.
        - Ta tạo 2 mảng diff1 và diff2 để lưu các phần tử khác nhau của nums1 và nums2.
        - Ta duyệt qua set1, với mỗi phần tử num ta kiểm tra num có trong set2 không, nếu không thì ta thêm num vào diff1.
        - Ta duyệt qua set2, với mỗi phần tử num ta kiểm tra num có trong set1 không, nếu không thì ta thêm num vào diff2.
        - Cuối cùng ta trả về {diff1, diff2}.
*/

vector<vector<int>> findDifference(vector<int> nums1, vector<int> nums2){
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());
    vector<int> diff1, diff2;

    for(int num : set1){
        if(set2.find(num) == set2.end()){
            diff1.push_back(num);
        }
    }

    for(int num : set2){
        if(set1.find(num) == set1.end()){
            diff2.push_back(num);
        }
    }
    return {diff1, diff2};
}

int main(){
    int m, n; cin >> m >> n;
    vector<int> nums1(m), nums2(n);
    for(int i = 0; i < m; i++) cin >> nums1[i];
    for(int i = 0; i < n; i++) cin >> nums2[i];
    vector<vector<int>> res = findDifference(nums1, nums2);
    for(int num : res[0]) cout << num << " ";
    cout << endl;
    for(int num : res[1]) cout << num << " ";
    return 0;
}