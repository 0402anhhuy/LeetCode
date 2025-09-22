// Sap xep tang dan
// Do phuc tap O(n^2)
#include<bits/stdc++.h>
using namespace std;

void BubbleSort(vector<int> &a, int n){
	for(int i = 0; i < n - 1; i++){
		// Duyet tu dau mang den phan tu cuoi chua duoc sap xep
		// n - i - 1 la phan tu cuoi chua duoc sap xep
		// j < n - i - 1 la phan tu ke cuoi chua duoc sap xep
		for(int j = 0; j < n - i - 1; j++){
			if(a[j] > a[j + 1]){
				swap(a[j], a[j + 1]);
			}
		}
	}
	/*
	i = 0
		a[0] -> a[n - 1]: so sanh a[j] va a[j + 1], swap;
	i = 1
		a[0] -> a[n - 2]: so sanh a[j] va a[j + 1], swap; (Vi GTNN da duoc dua len dau)
		...
	i = n - 3
		a[0] -> a[2]: so sanh a[j] va a[j + 1], swap;
	i = n - 2
		a[0] -> a[1]: so sanh va swap
	*/
}

int main(){
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	BubbleSort(a, n);
	for(auto x : a) cout << x << " ";
	return 0;
}
