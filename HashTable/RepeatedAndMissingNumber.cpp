#include<bits/stdc++.h>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid){
    unordered_set<int> tmp;
    vector<int> res;
    int n = grid.size(), sum = 0, tmpSum = 0;
    for(int i = 1; i <= n * n; i++) tmpSum += i;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int num = grid[i][j];
            if(tmp.find(num) != tmp.end()){
                res.push_back(num);
            }
            else{
                tmp.insert(num);
                sum += num;
            }
        }
    }
    res.push_back(tmpSum - sum);
    return res;
}

int main(){
    int n; cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    vector<int> res = findMissingAndRepeatedValues(grid);
    for(int num : res){
        cout << num << " ";
    }
    return 0;
}