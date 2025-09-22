#include<iostream>
using namespace std;

void Solve(int x){
	if(x == 1) cout << x;
	else{
		if(x % 2 == 0){
			Solve(x / 2);
			cout << " * 2";
		}
		else{
			Solve(x * 3 + 1);
			cout << " / 3"; // Chia lay phan nguyen
		}
	}
}

int main(){
	int x; cin >> x;
	Solve(x);
	return 0;
}
