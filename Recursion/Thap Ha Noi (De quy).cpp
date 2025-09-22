#include<iostream>
using namespace std;

void chuyen(int n, char x, char y){
	cout << "\nChuyển đĩa thứ " << n << " từ cọc " << x << " sang cọc " << y;
}

void thapHaNoi(int n, char x, char y, char z){
	if(n == 1) chuyen(1, x, z);
	else{
		thapHaNoi(n - 1, x, z, y);
		chuyen(n, x, z);
		thapHaNoi(n - 1, y, x, z);
	}
}

int main(){
	int n; cin >> n; 
	char a = 'A', b = 'B', c = 'C';
	thapHaNoi(n, a, b, c);
	return 0;
}
