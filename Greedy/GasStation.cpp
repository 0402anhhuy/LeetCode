#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode: 134. Gas Station
    Ý tưởng:
        - Ta duyệt qua mảng gas, với mỗi phần tử gas[i] ta cộng vào current_tank và cập nhật total_tank.
        - Nếu current_tank < 0 thì ta cập nhật current_tank = 0 và cập nhật starting_station = i + 1.
        - Nếu total_tank >= 0 thì ta trả về starting_station.
        - Nếu không ta trả về -1.
*/

int canCompleteCircuit(vector<int> gas, vector<int> cost){
    int n = 0;
    int current_tank = 0, starting_station = 0, total_tank = 0;
    for(int i = 0; i < n; i++){
        current_tank += gas[i] - cost[i];
        total_tank += gas[i] - cost[i];
        if(current_tank < 0){
            current_tank = 0;
            starting_station = i + 1;
        }
    }
    if(total_tank >= 0) return starting_station;
    else return -1;
}

int main(){
    int n; cin >> n;
    vector<int> gas(n), cost(n);
    for(int i = 0; i < n; i++){
        cin >> gas[i];
    }

    for(int i = 0; i < n; i++){
        cin >> cost[i];
    }
    return 0;
}