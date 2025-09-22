#include<bits/stdc++.h>
using namespace std;

void ShellSort(vector<int> &a, int n){
	int h, i, j, tmp;
	for(h = n / 2; h > 0; h /= 2){
		for(i = h; i < n; i++){
			tmp = a[i];
			for(j = i; j >= h && a[j - h] > tmp; j -= h){
				a[j] = a[j - h];				
			}
			a[j] = tmp;
		}
    }
}

int main(){
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	ShellSort(a, n);
	for(auto x : a) cout << x << " ";
	return 0;
}
