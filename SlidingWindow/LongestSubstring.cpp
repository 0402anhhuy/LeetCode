#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 3. Longest Substring Without Repeating Characters
    Ý tưởng:
        - Dùng unordered_set để lưu các ký tự duy nhất
        - Nếu chưa tìm thấy trong set thì thêm kí tự vào
        - Cập nhật maxLength (right - left + 1)
        - Nếu tìm thấy ký tự thì xóa từ trái sang đến khi ký tự đó được xóa khỏi set
*/

int lengthOfLongestSubstring(string s){
    unordered_set<char> window;
    int left = 0, maxLength = 0;

    for(int right = 0; right < s.length(); right++){
        while(window.find(s[right]) != window.end()){
            window.erase(s[left]);
            left++;
        }
        window.insert(s[right]);
        maxLength = max(maxLength, right - left + 1);
    }
    return maxLength;
}

int main(){
    string s; cin >> s;
    int res = lengthOfLongestSubstring(s);
    cout << res;
    return 0;
}