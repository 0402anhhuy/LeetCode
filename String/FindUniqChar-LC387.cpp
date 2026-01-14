#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 387. First Unique Character in a String
    Ý tưởng:
        - Tạo mảng gồm 26 ký tự, duyệt chuỗi lưu tần suất xuất hiện (c - 'a')
        - Duyệt lại chuỗi, nếu gặp ký tự đầu tiên có tần suất là 1 thì trả về chỉ số
*/

int firstUniqChar(string s){
    vector<int> character(26, 0);
    for(char c : s){
        character[c - 'a']++;
    }

    for(int i = 0; i < s.length(); i++){
        if(character[s[i] - 'a'] == 1) return i;
    }
    return -1;
}

int main(){
    string s; cin >> s;
    int res = firstUniqChar(s);
    cout << res;
    return 0;
}