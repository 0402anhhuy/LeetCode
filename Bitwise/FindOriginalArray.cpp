#include<bits/stdc++.h>
using namespace std;

vector<int> findArray(vector<int>& pref){
        vector<int> ans;
        ans.push_back(pref[0]);

        for(int i = 1; i < pref.size(); i++){
            ans.push_back(pref[i] ^ pref[i - 1]);
        }
        return ans;
    }

int main(){
    int n; cin >> n;
    vector<int> pref(n);
    for(int i = 0; i < n; i++){
        cin >> pref[i];
    }
    vector<int> ans = findArray(pref);
    for(int num : ans){
        cout << num << " ";
    }
    return 0;
}