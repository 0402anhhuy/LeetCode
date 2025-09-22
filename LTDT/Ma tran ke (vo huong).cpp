#include<iostream>
#include<vector>
using namespace std;

int adj[1001][1001];
int n;

/*
	4
	0 1 0 0
	1 0 2 0
	0 2 1 0
	0 0 0 0
*/

int main(){
	cout << "Nhap so dinh: "; cin >> n;
	vector<int> res;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> adj[i][j];
		}
	}
	
	for(int i = 1; i <= n; i++){
		int sum = 0;
		for(int j = 1; j <= n; j++){
			sum += adj[i][j];
			if(adj[i][j] == adj[j][i] && i < j && adj[i][j] >= 1){
				cout << "e" << i << " va e" << j << " la canh song song\n";
			}
			if(adj[i][j] == 1 && i == j) cout << "e" << i << " la vong\n";
		}
		res.push_back(sum);
		if(sum == 1){
			cout << i << " la dinh treo\n";
		}
		else if(sum == 0){
			cout << i << " la dinh co lap\n";
		}
	}
	for(int i = 0; i < n; i++){
		cout << "d(" << i + 1 << "): " << res[i] << endl;
	}
	return 0;
}
