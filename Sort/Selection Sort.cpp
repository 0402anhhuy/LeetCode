// Sap xep tang dan
// Do phuc tap O(n^2)
#include<bits/stdc++.h>
using namespace std;

void SelectionSort(vector<int> &a, int n){
	for(int i = 0; i < n - 1; i++){
		// Dung 1 bien de luu index cua phan tu nho nhat
		int min_index = i;
		// So sanh cac gia tri cua i
		//Duyet tat ca cac phan tu sau phan tu hien tai va cap nhat index cua phan tu nho nhat
		for(int j = i + 1; j < n; j++){
			if(a[j] < a[min_index]){
				min_index = j;       // Cap nhat
			}
		}
		swap(a[i], a[min_index]);
	}
	/*
	i = 0
		a[0] -- a[1 -> n - 1]: So sanh tim ra GTNN va swap(a[0], x);
	i = 1
		a[1] -- a[2 -> n - 1]: So sanh tim ra GTNN va swap(a[1], x);
	...
	i = n - 3
		a[n - 3] -- a[n - 2 -> n - 1]: So sanh tim ra GTNN va swap(a[n - 3], x);
	i = n - 2
		a[n - 2] -- a[n - 1]: So sanh va swap(a[n - 2], a[n - 1]);
	i = n - 1 -> Thoat
	*/
}

int main(){
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	SelectionSort(a, n);
	for(auto x : a) cout << x << " ";
	return 0;
}
