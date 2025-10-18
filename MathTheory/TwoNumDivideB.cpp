#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, a, b; cin >> t;
    while(t){
        cin >> a >> b;
        int index = 2, minValue = b;
        while(minValue < a){
            minValue = b * index;
            index++;
        }

        cout << b * (index - 2) << " " << b * (index - 1);
        t--;
    }
    return 0;
}