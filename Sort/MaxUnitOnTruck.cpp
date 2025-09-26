#include<bits/stdc++.h>
using namespace std;

int compare(const vector<int> a, const vector<int> b){
    if(a[1] == b[1]){
        return a[0] > b[0];
    }
    return a[1] > b[1];
}

int maximumUnits(vector<vector<int>>& boxTypes, int truckSize){
    sort(boxTypes.begin(), boxTypes.end(), compare);

    int n = boxTypes.size(), ans = 0;
    for(int i = 0; i < n; i++){
        truckSize -= boxTypes[i][0];
        if(truckSize <= 0){
            ans += (boxTypes[i][1] * abs(truckSize));
            return ans;
        }

        ans += (boxTypes[i][1] * boxTypes[i][0]);
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