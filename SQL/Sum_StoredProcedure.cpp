#include<bits/stdc++.h>
using namespace std;

void Tong(int a, int b, int &tong){
    tong = a + b;
}

int main(){
    int a = 5, b = 6, kq = 0;
    Tong(a, b, kq);
    cout << "Tổng = " << kq << endl;
    return 0;
}