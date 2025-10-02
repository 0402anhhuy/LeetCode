#include<bits/stdc++.h>
using namespace std;

int maxBottlesDrunk(int numBottles, int numExchange){
    int ans = numBottles;
    for(int empty = numBottles; empty >= numExchange; numExchange++){
        ans++;
        empty -= numExchange - 1;
    }
    return ans;
}

int main(){
    int numBottles, numExchange;
    cin >> numBottles >> numExchange;
    int ans = maxBottlesDrunk(numBottles, numExchange);
    cout << ans;
    return 0;
}