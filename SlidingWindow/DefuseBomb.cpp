// LeetCode 1652

#include<bits/stdc++.h>
using namespace std;

vector<int> decrypt(vector<int>& code, int k){
    int n = code.size(), sliding = 0;
    vector<int> ans(n, 0);
    if(k == 0) return ans;

    int step = abs(k);
    int sum = 0;
    int start = (k > 0 ? 1 : n - step);
    int end = (k > 0 ? k : n - 1);

    for(int i = start; i <= end; i++){
        sum += code[i];
    }

    for(int i = 0; i < n; i++){
        ans[i] = sum;
        sum -= code[(start + i) % n];
        sum += code[(end + 1 + i) % n];
    }
    return ans;
}

int main(){
    int n, k; cin >> n;
    vector<int> code(n);
    for(int i = 0; i < n; i++) cin >> code[i];
    cin >> k;

    vector<int> ans = decrypt(code, k);
    for(auto &num : ans){
        cout << num << " ";
    }
    return 0;
}