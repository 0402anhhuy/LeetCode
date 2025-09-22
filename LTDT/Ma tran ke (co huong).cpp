#include<bits/stdc++.h>
using namespace std;

int n;
int adj[1001][1001];

/*
	4
	0 2 0 0 
	0 0 1 0
	0 1 1 0
	0 0 0 0
*/

int main(){
	cout << "Nhap so dinh: "; cin >> n;
	vector<pair<int, int>> res;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> adj[i][j];
		}
	}
	
	for(int i = 1; i <= n; i++){
		int sum_row = 0, sum_col = 0;
		for(int j = 1; j <= n; j++){
			sum_row += adj[i][j];
			sum_col += adj[j][i];
			if(adj[i][j] > 1){
				cout << "Dinh " << i << ", " << j << " co canh // cung huong\n";
			}
			if(adj[i][j] == adj[j][i] && i < j && adj[i][j] >= 1){
				cout << "Dinh " << i << ", " << j << " co canh // nguoc huong\n"; 
			}
		}
		res.push_back({sum_row, sum_col});
	}
	for(int i = 0; i < n; i++){
		cout << "Dinh " << i + 1 << endl;
		cout << "  Ban bac trong: " << res[i].second << endl;
		cout << "  Ban bac ngoai: " << res[i].first << endl;
	}
	return 0;
}
