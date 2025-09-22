// Do phuc tap: O(lgn)
#include<iostream>
using namespace std;

int luy_thua(int a, int n){
	if(n == 1) return a;
	else{
		int s = luy_thua(a, n / 2);
		if(n % 2 == 0){
			return s * s;
		}
		else return s * s * a;
	}
}

int main(){
	int a, n;
	cin >> a >> n;
	cout << luy_thua(a, n);
	return 0;
}
