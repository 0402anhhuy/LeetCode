#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode: 1657. Determine if Two Strings Are Close
    Ý tưởng:
        - Ta tạo 2 mảng countWord1 và countWord2 với 26 phần tử ban đầu bằng 0.
        - Ta duyệt qua chuỗi word1, với mỗi ký tự c ta tăng countWord1[c - 97] lên 1.
        - Ta duyệt qua chuỗi word2, với mỗi ký tự c ta tăng countWord2[c - 97] lên 1.
        - Ta duyệt qua 26 phần tử, nếu countWord1[i] == 0 và countWord2[i] != 0 hoặc countWord1[i] != 0 và countWord2[i] == 0 thì ta trả về false.
        - Ta sắp xếp countWord1 và countWord2.
        - Nếu countWord1 == countWord2 thì ta trả về true.
        - Ngược lại ta trả về false.
*/

bool closeStrings(string word1, string word2){
    vector<int> countWord1(26, 0);
    vector<int> countWord2(26, 0);
    for(char c : word1){
        countWord1[c - 97]++;
    }
    for(char c : word2){
        countWord2[c - 97]++;
    }
    for(int i = 0; i < 26; i++){
        if((countWord1[i] == 0 && countWord2[i] != 0) || (countWord1[i] != 0 && countWord2[i] == 0)){
            return false;
        }
    }
    sort(countWord1.begin(), countWord1.end());
    sort(countWord2.begin(), countWord2.end());
    return countWord1 == countWord2;
}

int main(){
    string word1, word2; cin >> word1 >> word2;
    bool res = closeStrings(word1, word2);
    cout << boolalpha << res;
    return 0;
}