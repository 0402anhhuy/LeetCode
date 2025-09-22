#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 394. Decode String
    Ý tưởng:
        - Duyệt qua từng ký tự của chuỗi s
        - Nếu gặp chữ số, tính toán giá trị số lặp num (vì có thể có nhiều chữ số liền nhau, ví dụ 23[a])
        - Nếu gặp dấu mở ngoặc [, lưu giá trị của num vào numStack và chuỗi res vào strStack, sau đó reset lại num và res
        - Nếu gặp dấu đóng ngoặc ], lấy số lặp repeat từ numStack và chuỗi trước đó từ strStack, sau đó nhân bản res rồi nối vào chuỗi trước đó
        - Nếu gặp chữ cái, nối vào res
*/

string decodeString(string s){
    stack<int> numStack;
    stack<string> strStack;  
    string res = "";      
    int num = 0;             

    for(int i = 0; i < s.size(); i++){
        if(isdigit(s[i])){
            num = num * 10 + (s[i] - '0');
        } 
        else if(s[i] == '['){
            numStack.push(num);
            strStack.push(res);
            num = 0;
            res = "";
        } 
        else if(s[i] == ']'){
            string temp = res;
            res = strStack.top(); strStack.pop();
            int repeat = numStack.top(); numStack.pop();
            while(repeat--) res += temp;
        } 
        else{
            res += s[i];
        }
    }
    return res;
}

int main(){
    string s; cin >> s;
    string res = decodeString(s);
    cout << res;
    return 0;
}