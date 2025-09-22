#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode: 1207. Unique Number of Occurrences
    Ý tưởng:
        - Ta tạo một unordered_multiset arr1 để lưu các phần tử của mảng arr.
        - Ta tạo một unordered_set arr2 để lưu các phần tử của mảng arr.
        - Ta tạo một set res để lưu số lần xuất hiện của các phần tử của mảng arr2.
        - Ta duyệt qua mảng arr2, với mỗi phần tử num ta kiểm tra số lần xuất hiện của num trong arr1.
        - Nếu res đã có num thì ta trả về false.
        - Nếu không ta thêm số lần xuất hiện của num vào res.
        - Cuối cùng ta trả về true.
*/

bool uniqueOccurrences(vector<int> arr){
    unordered_multiset<int> arr1(arr.begin(), arr.end());
    unordered_set<int> arr2(arr.begin(), arr.end());
    set<int> res;
    for(int num : arr2){
        int tmp = arr1.count(num);
        if(res.find(tmp) != res.end()){
            return false;
        }
        res.insert(tmp);
    }
    return true;
}

int main(){
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    bool res = uniqueOccurrences(nums);
    cout << boolalpha << res;
    return 0;
}