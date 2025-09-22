#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode: 205. Isomorphic Strings
    Ý tưởng:
        - Ta tạo 2 unordered_map mapST và mapTS để ánh xạ từ s -> t và từ t -> s.
        - Ta duyệt qua chuỗi s, với mỗi ký tự s[i] ta kiểm tra xem ký tự s[i] đã xuất hiện trong mapST chưa, nếu có thì ta kiểm tra xem mapST[s[i]] có bằng t[i] không, nếu không thì trả về false.
        - Nếu không thì ta thêm s[i] vào mapST[s[i]] = t[i].
        - Ta làm tương tự với mapTS.
        - Cuối cùng ta trả về true.
*/

bool isIsomorphic(string s, string t){
    unordered_map<char, char> mapST, mapTS;
    for(int i = 0; i < s.length(); i++){

        // Ánh xạ từ s -> t
        if(mapST.find(s[i]) != mapST.end()){
            if(mapST[s[i]] != t[i]){
                return false;
            }
        }
        else{
            mapST[s[i]] = t[i];
        }

        // Ánh xạ từ t -> s
        if(mapTS.find(t[i]) != mapTS.end()){
            if(mapTS[t[i]] != s[i]){
                return false;
            }
        }
        else{
            mapTS[t[i]] = s[i];
        }
    }
    return true;
}

int main(){
    string s, t; cin >> s >> t;
    bool res = isIsomorphic(s, t);
    cout << boolalpha << res;
    return 0;
}