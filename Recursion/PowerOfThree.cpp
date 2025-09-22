#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 326. Power of Three
    Ý tưởng:
        - Nếu n <= 0 -> trả về false
        - Dùng đệ quy xác định xem số đó khi chia đến hết thì bằng 1 hay không (Vì nếu bằng 1 thì số cuối cùng khi chia là 3)
*/

bool isPowerOfThree(int n){
    if(n <= 0) return false;
    if(n == 1) return true;
    else if (n % 3 != 0) return false;
    return isPowerOfThree(n / 3);
}

int main(){
    int n; cin >> n;
    bool res = isPowerOfThree(n);
    cout << res;
    return 0;
}