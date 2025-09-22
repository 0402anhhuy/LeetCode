#include<iostream>
using namespace std;

int chinh_hop(int n, int k){
    if(k == 0 || k == n) return 1;
    else return chinh_hop(n - 1, k - 1) + chinh_hop(n - 1, k);
}

int main(){
    int n, k;
    cin >> n >> k;
    if(n < k) return 0;
    else cout << chinh_hop(n, k);
    return 0;
}
