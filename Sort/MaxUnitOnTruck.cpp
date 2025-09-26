#include<bits/stdc++.h>
using namespace std;

bool compare(const vector<int> a, const vector<int> b){
    return a[1] > b[1];
}

int maximumUnits(vector<vector<int>>& boxTypes, int truckSize){
    sort(boxTypes.begin(), boxTypes.end(), compare);

    int ans = 0;
    for(auto box : boxTypes){
        if(truckSize == 0) break;

        int take = min(truckSize, box[0]);
        ans += (box[1] * take);
        truckSize -= take;
    }
    return ans;
}

int main(){
    int n, a, b, truckSize; cin >> n;
    vector<vector<int>> boxes;

    for(int i = 0; i < n; i++){
        cin >> a >> b;
        boxes.push_back({a, b});
    }
    cin >> truckSize;
    int ans = maximumUnits(boxes, truckSize);
    cout << ans;
    return 0;
}