#include<iostream>
using namespace std;

int k, n;
int a[100];

void Xuat(){
	for(int i = 1; i <= k; i++){
		cout << a[i];
	}
	cout << "\n";
}

void Try(int i){
	/*
		Duyet cac kha nang co the cua a[i]
		Gia tri max cua a[i] = n - k + i
		Gia tri min cua a[i] = a[i - 1] + 1
		--> Duyet tu a[i - 1] + 1 den n - k + i
	*/
	for(int j = a[i - 1] + 1; j <= n - k + i; j++){
		a[i] = j;
		if(i == k){
			Xuat();
		}
		else{
			Try(i + 1);
		}
	}
}

int main(){
	cin >> k >> n;
	Try(1);
	return 0;
}
