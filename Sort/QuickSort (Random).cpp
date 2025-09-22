#include<iostream>
#include<cstdlib>
using namespace std;

int partition(int a[], int l, int r){
    int pivot = a[r];
    int i = l - 1;
    for(int j = l; j < r; j++){
        if(a[j] <= pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    i++;
    swap(a[i], a[r]);
    return i;
}

void quickSort(int a[], int l, int r){
	if(l >= r) return;
    int pivotIndex = l + rand() % (r - l + 1);
    swap(a[pivotIndex], a[r]);  // Dua pivot ra vi tri cuoi
    int p = partition(a, l, r);
    quickSort(a, l, p - 1);
    quickSort(a, p + 1, r);
}

int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    quickSort(a, 0, n - 1);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}

