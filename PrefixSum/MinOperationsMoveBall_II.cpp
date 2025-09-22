#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity: O(n)
*/

vector<int> minOperations(string boxes) {
    int n = boxes.size();
    vector<int> ans(n, 0);

    int countLeft = 0, moveLeft = 0;
    for(int i = 0; i < n; i++){
        ans[i] += moveLeft;
        if(boxes[i] == '1'){
            countLeft++;
        }
        moveLeft += countLeft;
    }

    int countRight = 0, moveRight = 0;
    for(int i = n - 1; i >= 0; i--){
        ans[i] += moveRight;
        if(boxes[i] == '1'){
            countRight++;
        }
        moveRight += countRight;
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