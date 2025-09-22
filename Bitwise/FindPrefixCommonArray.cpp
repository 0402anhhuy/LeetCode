#include<bits/stdc++.h>
using namespace std;

vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B){
    int n = A.size();
    vector<int> ans(n);

    bitset<51> x = 0, y = 0;
    for(int i = 0; i < n; i++){
        int a = A[i], b = B[i];

        x[a] = 1;
        y[b] = 1;
        
        /*
            Thực hiện phép AND (&)
                - Những bit 1 ở vị trí giống nhau sẽ được giữ nguyên (bit không giống sẽ thành 0)
                - Dùng count() để đếm số bit 1
        */
        ans[i] = (x & y).count();
    }
    return ans;
}

int main(){
    int n; cin >> n;
    vector<int> A(n), B(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    for(int i = 0; i < n; i++){
        cin >> B[i];
    }

    vector<int> ans = findThePrefixCommonArray(A, B);
    for(auto &num : ans){
        cout << num << " ";
    }
    return 0;
}