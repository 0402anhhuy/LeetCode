#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode: 66. Plus One
    Ý tưởng:
        - Ta duyệt từ cuối mảng về đầu mảng, cứ mỗi phần tử ta cộng thêm 1 vào phần tử đó.
        - Nếu phần tử đó là phần tử cuối cùng thì ta cộng thêm 1 vào phần tử đó.
        - Nếu phần tử đó không phải là phần tử cuối cùng thì ta cộng thêm carry vào phần tử đó.
        - Sau đó ta lưu phần tử đó vào mảng kết quả và cập nhật carry.
        - Nếu carry khác 0 thì ta lưu carry vào mảng kết quả.
        - Cuối cùng ta đảo ngược mảng kết quả và trả về mảng kết quả.
*/

vector<int> plusOne(vector<int> digits){
    vector<int> res;
    int n = digits.size(), carry = 0, sum = 0;
    for(int i = n - 1; i >= 0; i--){
        if(i == n - 1){
            sum = digits[i] + 1;
        }
        else sum = digits[i] + carry;
        res.push_back(sum % 10);
        carry = sum / 10;
    }
    if(carry != 0) res.push_back(carry);
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    int n; cin >> n;
    vector<int> digits(n);
    for(int i = 0; i < n; i++){
        cin >> digits[i];
    }
    vector<int> res = plusOne(digits);
    for(int result : res){
        cout << result << " ";
    }
    return 0;
}