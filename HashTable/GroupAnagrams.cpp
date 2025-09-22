#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode: 49. Group Anagrams
    Ý tưởng:
        - Ta tạo một unordered_map anagramGroups để lưu các nhóm anagram.
        - Ta duyệt qua mảng strs, với mỗi chuỗi str ta sắp xếp str và thêm str vào anagramGroups.
        - Ta tạo một mảng res để lưu kết quả.
        - Ta duyệt qua anagramGroups, với mỗi anagramGroup ta thêm anagramGroup.second vào res.
        - Cuối cùng ta trả về res.
*/

vector<vector<string>> groupAnagrams(vector<string>& strs){
    unordered_map<string, vector<string>> anagramGroups;
    for(string str : strs){
        sort(str.begin(), str.end());
        anagramGroups[str].push_back(str);
    }

    vector<vector<string>> res;
    for(auto anagramGroup : anagramGroups){
        res.push_back(anagramGroup.second);
    }
    return res;
}

int main(){
    int n; cin >> n;
    vector<string> strs(n);
    for(int i = 0; i < n; i++){
        cin >> strs[i];
    }
    vector<vector<string>> res = groupAnagrams(strs);
    return 0;
}