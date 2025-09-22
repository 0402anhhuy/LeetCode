#include <bits/stdc++.h>
using namespace std;

/*
    LeetCode: 290. Word Pattern
    Ý tưởng:
        - Ta tạo 2 unordered_map mapPatternS và mapSPattern.
        - Ta tạo 2 biến l = 0, r = 0, wordCount = 0.
        - Ta duyệt qua pattern, với mỗi ký tự pattern[i] ta duyệt qua chuỗi s từ l đến r.
        - Nếu l >= s.length() thì ta trả về false.
        - Ta tăng r cho đến khi r < s.length() và s[r] != ' '.
        - Ta tăng wordCount lên 1.
        - Ta tạo một chuỗi tmp = s.substr(l, r - l).
        - Tăng r lên 1 và cập nhật l = r.
        - Nếu mapPatternS.find(pattern[i]) != mapPatternS.end() thì ta kiểm tra mapPatternS[pattern[i]] có bằng tmp không, nếu không trả về false.
        - Nếu không ta thêm pattern[i] và tmp vào mapPatternS.
        - Nếu mapSPattern.find(tmp) != mapSPattern.end() thì ta kiểm tra mapSPattern[tmp] có bằng pattern[i] không, nếu không trả về false.
        - Nếu không ta thêm tmp và pattern[i] vào mapSPattern.
        - Nếu r < s.length() hoặc wordCount != pattern.length() thì ta trả về false.
        - Cuối cùng ta trả về true.
*/

bool wordPattern(string pattern, string s){
    unordered_map<char, string> mapPatternS;
    unordered_map<string, char> mapSPattern;

    int l = 0, r = 0, wordCount = 0;

    for(int i = 0; i < pattern.length(); i++){
        while(r < s.length() && s[r] != ' '){
            r++;
        }

        if(l >= s.length()){
            return false;
        }

        wordCount++;
        string tmp = s.substr(l, r - l);
        r++;
        l = r;
        if(mapPatternS.find(pattern[i]) != mapPatternS.end()){
            if(mapPatternS[pattern[i]] != tmp){
                return false;
            }
        }
        else{
            mapPatternS[pattern[i]] = tmp;
        }

        if(mapSPattern.find(tmp) != mapSPattern.end()){
            if(mapSPattern[tmp] != pattern[i]){
                return false;
            }
        }
        else{
            mapSPattern[tmp] = pattern[i];
        }
    }
    if(r < s.length() || wordCount != pattern.length()){
        return false;
    }
    return true;
}

int main(){
    string pattern, s;
    cin >> pattern;
    cin.ignore();
    getline(cin, s);
    bool res = wordPattern(pattern, s);
    cout << boolalpha << res;
    return 0;
}