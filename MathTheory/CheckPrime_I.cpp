/*
    Dùng vòng lặp duyệt từ 3 -> √x
*/

#include<bits/stdc++.h>
using namespace std;

bool isPrime(int x){
    if(x == 2) return true;
    if(x < 2 || x % 2 == 0) return false;
    for(int i = 3; i * i <= x; i += 2){
        if(x % i == 0) return false;
    }
    return true;
}

int main(){
    int x; cin >> x;
    bool ans = isPrime(x);
    cout << boolalpha << ans;
}