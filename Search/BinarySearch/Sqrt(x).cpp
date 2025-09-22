#include<bits/stdc++.h>
using namespace std;

int mySqrt(int x){
    if(x == 0 || x == 1) return x;
    int low = 1, high = x, ans = 0;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(mid == x / mid) return mid;
        if(mid < x / mid){
            low = mid + 1;
            ans = mid;
        } 
        else{
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    int n; cin >> n;
    int res = mySqrt(n);
    cout << res;
    return 0;
}