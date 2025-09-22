#include<iostream>
using namespace std;

int gcd(int m, int n){
    if(n == 0) return m;
    else return gcd(n, m % n);
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b);
    return 0;
}
