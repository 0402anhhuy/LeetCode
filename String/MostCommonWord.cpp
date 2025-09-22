#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 819. Most Common Word
    Ý tưởng:
        - Chuẩn hóa văn bản
            + Chuyển tất cả các ký tự về chữ thường
            + Thay thế dấu câu (!?',;.) bằng dấu cách " "
            + Tách các từ bằng khoảng trắng
        - Đếm số lần xuất hiện của từ
            + Sử dụng unordered_map<string, int> để lưu số lần xuất hiện của từng từ hợp lệ
            + Bỏ qua các từ trong danh sách banned
        - Tìm từ xuất hiện nhiều nhất
            + Duyệt qua unordered_map, tìm từ có tần suất lớn nhất
*/

string mostCommonWord(string paragraph, vector<string>& banned){
    unordered_set<string> bannedSet(banned.begin(), banned.end());
    unordered_map<string, int> wordCount;
    string word, result;
    int maxCount = 0;
    
    for(char& c : paragraph){
        c = isalpha(c) ? tolower(c) : ' ';
    }
    
    stringstream ss(paragraph);
    while(ss >> word){
        if(!bannedSet.count(word)){
            wordCount[word]++;
            if(wordCount[word] > maxCount){
                maxCount = wordCount[word];
                result = word;
            }
        }
    }
    return result;
}

int main(){
    string s; cin >> s;
    int n; cin >> n;
    vector<string> banned(n);
    for(int i = 0; i < n; i++){
        cin >> banned[i];
    }
    return 0;
}