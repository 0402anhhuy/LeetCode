// Sap xep tang dan
// Phan hoach Hoare
/* Do phuc tap
	Average case: O(nlgn)
	Bad case: O(n^2)
*/
	
#include<iostream>
using namespace std;

void Nhap(int a[], int n){
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
}

// Chon pivot la phan tu ngoai cung ben trai a[l]
int partition(int a[], int l, int r){
	int pivot = a[l];
	int i = l - 1;
	int j = r + 1;
	while(true){
		do{
			i++;
		}while(a[i] < pivot);
		do{
			j--;
		}while(a[j] > pivot);
		if(i < j){
			swap(a[i], a[j]);     // Dao gia tri de co a[i] <= pivot <= a[j]
		}
		else return j;
	}
}

void quickSort(int a[], int l, int r){
	if(l >= r) return;
	int p = partition(a, l, r);
	quickSort(a, l, p);
	quickSort(a, p + 1, r);
}


int main(){
	int n; cin >> n;
	int a[n];
	Nhap(a, n);
	quickSort(a, 0, n - 1);
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	return 0;
}
