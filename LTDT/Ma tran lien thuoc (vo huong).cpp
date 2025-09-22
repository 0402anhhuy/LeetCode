#include<iostream>
#include<vector>
using namespace std;

int inc[1001][1001];
vector<int> res;
int n, m;

int main(){
	cout << "Nhap so dinh: "; cin >> n;
	cout << "Nhap so canh: "; cin >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> inc[i][j];
		}
	}
	
	for(int i = 1; i <= n; i++){
		int sum_row = 0, sum_col = 0;
		for(int j = 1; j <= m; j++){
			sum_row += inc[i][j];
			sum_col += inc[j][i];
			if(inc[i][j] == inc[j][i] && i < j && inc[i][j] == 1){
				cout << "e" << i << " va e" << j << " la canh song song\n";
			}
		}
		res.push_back(sum_row);
		if(sum_col == 1){
			for(int j = 1; j <= n; j++){
				if(inc[j][i] == 1){
					cout << "Dinh " << j << " la vong\n";
					break;
				}
			}
		}
		if(sum_row == 0){
			cout << i << " la dinh co lap\n";
		}
		else if(sum_row == 1){
			cout << i << " la dinh treo\n";
		}
	}
	for(int i = 0; i < n; i++){
		cout << "d(" << i + 1 << "): " << res[i] << endl;
	}
	return 0;
}
