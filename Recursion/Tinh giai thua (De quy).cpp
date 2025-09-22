#include<iostream>
using namespace std;

int giai_thua(int x){
	if(x == 0 || x == 1) return 1;
	else return x * giai_thua(x - 1);
}

int main(){
	int x; cin >> x;
	cout << x << "! = " << giai_thua(x);
	return 0;
}
