#include <bits/stdc++.h>
using namespace std;

/*
    LeetCode - 67. Add Binary
    Ý tưởng:
        - Làm cho 2 chuỗi a, b bằng nhau
        - Duyệt từ cuối lên rồi cộng như bình thường
*/

string addBinary(string a, string b){
    int len_a = a.length(), len_b = b.length();

    while (len_a < len_b){
        a = "0" + a;
        len_a++;
    }

    while (len_b < len_a){
        b = "0" + b;
        len_b++;
    }

    string res = "";
    int carry = 0;
    for(int i = len_a - 1; i >= 0; i--){
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        res += (sum % 2) + '0';
        carry = sum / 2;
    }
    if(carry) res += '1';
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    string a, b;
    cin >> a >> b;
    cout << addBinary(a, b);
    return 0;
}
