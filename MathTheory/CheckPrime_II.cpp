/*
    Dùng sàng Eratosthenes để lọc số nguyên tố
*/

#include<bits/stdc++.h>
using namespace std;

vector<bool> sieveOfEratosthenes(int n){
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i * i <= n; i++){
        if(isPrime[i]){
            for(int j = i * i; j <= n; j += i){
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

int main(){
    int n = 100;
    vector<bool> prime = sieveOfEratosthenes(n);

    cout << "Các số nguyên tố từ 1 đến " << n << " là:\n";
    for(int i = 2; i <= n; i++){
        if (prime[i]) cout << i << " ";
    }
    return 0;
}
