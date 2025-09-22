#include<bits/stdc++.h>
using namespace std;

/*
	Đếm số lần xuất hiện của phần tử x trong mảng a.
	Ý tưởng:
		- Nếu l == r thì ta kiểm tra x có bằng a[l] không, nếu có thì trả về 1, ngược lại trả về 0.
		- Nếu l < r thì ta tính m = (l + r) / 2.
		- Ta đệ quy đến khi l == r.
*/

int count(vector<int> a, int l, int r, int x){
	if(l == r){
		if(a[l] == x) return 1;
		else return 0;
	} 
	else{
		int m = (l + r) / 2;
		return count(a, l, m, x) + count(a, m + 1, r, x);
	}
}
int main(){
	int n, x; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	cin >> x;
	cout << count(a, 0, n - 1, x);
	return 0;
}
