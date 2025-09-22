#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 735. Asteroid Collision
    Ý tưởng:
        - Duyệt từng tiểu hành tinh trong asteroids
        - Nếu res đang có số dương (res.back() > 0) và tiểu hành tinh hiện tại là âm (asteroid < 0), thì có thể xảy ra va chạm
        - Nếu res.back() < |asteroid|, tiểu hành tinh dương trước đó bị phá hủy → pop_back(), tiếp tục kiểm tra
        - Nếu res.back() == |asteroid|, cả hai bị phá hủy
        - Nếu res.back() > |asteroid|, tiểu hành tinh âm bị phá hủy, không thêm vào res
        - Nếu không có va chạm, thêm asteroid vào res
*/

vector<int> asteroidCollision(vector<int> asteroids){
    vector<int> res;
    for(int asteroid : asteroids){
        while(!res.empty() && res.back() > 0 && asteroid < 0){
            int last = res.back();
            if(last < -asteroid){
                res.pop_back();
                continue;
            }
            else if(last == -asteroid){
                res.pop_back();
            }
            asteroid = 0;
        }
        if(asteroid != 0){
            res.push_back(asteroid);
        }
    }
    return res;
}

int main(){
    int n; cin >> n;
    vector<int> asteroids(n);
    for(int i = 0; i < n; i++){
        cin >> asteroids[i];
    }
    vector<int> res = asteroidCollision(asteroids);
    for(int asteroid : res){
        cout << asteroid << " ";
    }
    return 0;
}