// Sap xep tang dan
// Do phuc tap O(n^2)
#include<bits/stdc++.h>
using namespace std;

void InsertionSort(vector<int> &a, int n){
	for(int i = 1; i < n; i++){
		// Lay phan tu o chi so i
		long long int key = a[i];
		int j = i - 1;
		while(j >= 0 && key < a[j]){
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
	/*
	key = a[1] -> j = 0 -> so sanh key voi a[j] ( j >= 0, j -= 1);
		True:
			a[1] = a[0]; (Day cac gia tri lui ra sau tao o trong tai vi tri j)
		False:
			a[0] = key; (Gan gia tri tai vi tri j = key) -> Do j -= 1 -> a[j + 1]
	key = a[2] -> j = 1 -> so sanh key voi a[j] ( j >= 0, j -= 1);
		True:
			a[2] = a[1];
			a[1] = a[0];
		False:
			a[0] = key;
	...
	key = a[n - 1] -> j = n -> so sanh key voi a[j] ( j >= 0, j -= 1);
		True:
			a[j + 1] = a[j]; (Day cac gia tri lui ra sau tao o trong tai vi tri j)
			...
		False:
			a[j + 1] = key;
	*/
}

int main(){
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	InsertionSort(a, n);
	for(auto x : a) cout << x << " ";
	return 0;
}
