#include<bits/stdc++.h>
using namespace std;

int numWaterBottles(int numBottles, int numExchange){
    int result = (numBottles / numExchange);
    int success = result, rest = (numBottles % numExchange);
    while((success + rest) >= numExchange){
        result += (success + rest) / numExchange;
        int temp = success;
        success = (success + rest) / numExchange;
        rest = (temp + rest) % numExchange;
    }
    return result + numBottles;
}

int main(){
    int numBottles, numExchange;
    cin >> numBottles >> numExchange;
    int ans = numWaterBottles(numBottles, numExchange);
    cout << ans;
    return 0;
}