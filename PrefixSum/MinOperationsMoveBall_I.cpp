#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity: O(n²)
*/

vector<int> minOperations(string boxes) {
    int n = boxes.size();
    vector<int> ans(n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(boxes[j] == '1'){
                ans[i] += abs(j - i);
            }
        }
    }
    return ans;
}

int main(){
    string boxes; cin >> boxes;
    vector<int> operations = minOperations(boxes);
    for(auto &operation : operations){
        cout << operation << " ";
    }
    return 0;
}