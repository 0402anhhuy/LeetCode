#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 2390. Removing Stars From a String
    Ý tưởng:
        - Duyệt từng ký tự c trong s
        - Nếu c khác *, đẩy vào stack
        - Nếu c là *, lấy phần tử trên cùng ra (pop()), nghĩa là xoá ký tự trước đó
        - Sau khi duyệt xong, kết quả nằm trong stack, nhưng theo thứ tự ngược
        - Lấy ra từng phần tử, ghép vào chuỗi res
        - Đảo ngược res để có chuỗi đúng thứ tự
*/

string removeStars(string s){
    stack<char> st;
    for(char c : s){
        if(c != '*'){
            st.push(c);
        }
        else st.pop();
    } 
    string res = "";
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    string s; cin >> s;
    string res = removeStars(s);
    cout << res;
    return 0;
}