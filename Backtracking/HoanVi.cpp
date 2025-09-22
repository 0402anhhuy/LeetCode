#include<iostream>
#include<string.h>
using namespace std;

int n;
int a[100], used[100];

void Xuat(){
	for(int i = 1; i <= n; i++) cout << a[i];
	cout << "\n";
}

void Try(int i){
	// Duyet tu kha nang 1 --> M
	for(int j = 1; j <= n; j++){
		// Neu chap nhan kha nang j (chua su dung)
		if(used[j] == 0){
			a[i] = j;
			used[j] = 1;
			if(i == n) Xuat();
			else{
				Try(i + 1);
			}
			used[j] = 0;
		}
	}
}

int main(){
	cin >> n;
	Try(1);
	memset(used, 0, sizeof(used));
	return 0;
}
