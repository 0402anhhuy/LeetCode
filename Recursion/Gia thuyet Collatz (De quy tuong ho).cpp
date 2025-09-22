#include<iostream>
using namespace std;

void Solve(int x);

void SolveOdd(int x){
	Solve(x * 3 + 1);
	cout << " / 3";
}

void SolveEven(int x){
	Solve(x / 2);
	cout << " * 2";
}

void Solve(int x){
	if(x == 1) cout << x;
	else{
		if(x % 2 == 0) SolveEven(x);
		else SolveOdd(x);
	}
}

int main(){
	int x; cin >> x;
	Solve(x);
	return 0;
}
