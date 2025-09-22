#include<bits/stdc++.h>
using namespace std;

string toBinary(int num) {
    if (num == 0) return "0";
    string res = "";
    while (num > 0) {
        res.push_back((num % 2) + '0');
        num /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

string convertDateToBinary(string date) {
    stringstream ss(date);
    string token;
    vector<string> parts;

    while (getline(ss, token, '-')) {
        int num = stoi(token);
        parts.push_back(toBinary(num));
    }

    return parts[0] + "-" + parts[1] + "-" + parts[2];
}


int main(){
    string date; cin >> date;
    string ans = convertDateToBinary(date);
    cout << ans;
    return 0;
}