#include<bits/stdc++.h>
using namespace std;

int calPoints(vector<string>& operations){
    vector<int> ans;
    for(string operation : operations){
        int n = ans.size();
        if(operation != "D" && operation != "C" && operation != "+"){
            int num = stoi(operation);
            ans.push_back(num);
        }
        else if(operation == "D"){
            ans.push_back(ans.back() * 2);
        }
        else if(operation == "+"){
            ans.push_back(ans[n - 2] + ans[n - 1]);
        }
        else{
            ans.pop_back();
        }
    }

    return accumulate(ans.begin(), ans.end(), 0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    int n; cin >> n;
    vector<string>  operations(n);
    for(int i = 0; i < n; i++){
        cin >> operations[i];
    }

    int ans = calPoints(operations);
    cout << ans;
    return 0;
}