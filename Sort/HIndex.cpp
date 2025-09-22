#include<bits/stdc++.h>
using namespace std;

int hIndex(vector<int> citations){
    int n = citations.size();
    sort(citations.begin(), citations.end(), greater<int>());
    int news = 1, res = 0;
    for(int i = 0; i < n; i++){
        if(citations[i] >= news){
            res++;
            news++;
        }
    }
    return res;
}

int main(){
    int n; cin >> n;
    vector<int> citations(n);
    for(int i = 0; i < n; i++){
        cin >> citations[i];
    }
    int res = hIndex(citations);
    cout << res;
    return 0;
}