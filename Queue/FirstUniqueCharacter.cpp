#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 387. First Unique Character in a String
    Ý tưởng:
        - Duyệt chuỗi và lưu các ký tự xuất hiện vào hàng đợi (queue)
        - Dùng unordered_map để theo dõi tần suất xuất hiện của từng ký tự
        - Duyệt hàng đợi để tìm ký tự đầu tiên không lặp lại (Dùng while lặp khi gặp kí tự cần tìm)
*/

int firstUniqChar(string s){
    unordered_map<char, int> mp;
    queue<int> q;

    for(int i = 0; i < s.length(); i++){
        mp[s[i]]++;
        q.push(i);

        while(!q.empty() && mp[s[q.front()]] > 1){
            q.pop();
        }
    }
    return q.empty() ? -1 : q.front();
}

int main(){
    string s; cin >> s;
    int res = firstUniqChar(s);
    cout << res;
    return 0;
}