// Sap xep tang dan
// Do phuc tap O(nlogn)
#include<bits/stdc++.h>
using namespace std;

//Tron hai day con da sap xep: day 1 [l, m], day 2 [m + 1, r]
/*
	l: left
	m: middle
	r: right
*/
void merge(vector<int> &a, int l, int m, int r){
	int len_left = m - l + 1;    //Bên trái: left -> middle
	int len_right = r - m;	     //Bên phải: middle + 1 -> right
	
	//Tạo mảng lưu trữ hai mảng con
	vector<int> a_left(len_left), a_right(len_right);
	for(int i = 0; i < len_left; i++){
		a_left[i] = a[l + i];
	}
	for(int i = 0; i < len_right; i++){
		a_right[i] = a[m + 1 + i];
	}
	
	//Gộp hai mảng con đã sắp xếp (phần tử nhỏ thì vào trước)
	int i = 0, j = 0;
	while(i < len_left && j < len_right){
		if(a_left[i] <= a_right[j]){
			a[l] = a_left[i];
			i++;
		}
		else{
			a[l] = a_right[j];
			j++;
		}
		l++;
	}
	//Nếu một trong hai mảng con còn phần tử thì thêm vào mảng a
	while(i < len_left){
		a[l++] = a_left[i++];
	}
	while(j < len_right){
		a[l++] = a_right[j++];
	}
}

// Use stack to explain
void mergeSort(vector<int> &a, int l, int r){
	if(l >= r) return;
	int m = (l + r) / 2;
	//Gọi đệ quy đến khi mảng còn 1 phần tử
	mergeSort(a, l, m);
	mergeSort(a, m + 1, r);
	
	//Gộp hai mảng con đã sắp xếp
	merge(a, l, m, r);
}

int main(){
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	mergeSort(a, 0, n - 1);
	for(auto x : a) cout << x << " ";
	return 0;
}
