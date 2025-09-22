#include<iostream>
#include<vector>
using namespace std;

long long int mergeAndCountInversions(vector<int> &a, int l, int m, int r){
    long long int count = 0;
    int len_left = m - l + 1;
    int len_right = r - m;
    vector<int> L(a.begin() + l, a.begin() + m + 1), R(a.begin() + m + 1, a.begin() + r + 1);
    int i = 0, j = 0;
    while(i < len_left && j < len_right){
        if(L[i] <= R[j]){
            a[l++] = L[i++];
        } 
		else{
            a[l++] = R[j++];
            count += len_left - i;
        }
    }
    while(i < len_left){
    	a[l++] = L[i++];
	}
    while(j < len_right){
    	a[l++] = R[j++];
	}
    return count;
}

long long int mergeSortAndCountInversions(vector<int> &a, int l, int r){
    long long int count = 0;
    if(l < r){
        int m = l + (r - l) / 2;
        count += mergeSortAndCountInversions(a, l, m);
        count += mergeSortAndCountInversions(a, m + 1, r);
        count += mergeAndCountInversions(a, l, m, r);
    }
    return count;
}

int main(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
	}
    long long int inversions = mergeSortAndCountInversions(a, 0, n - 1);
    cout << inversions;
    return 0;
}

