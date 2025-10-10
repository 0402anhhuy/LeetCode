#include<bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)

using ll  = long long;
using ull = unsigned long long;
using ld  = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = vector<int>;
using vll = vector<ll>;
using vii = vector<pii>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define F first
#define S second

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define FORI(i, n) for (int i = 0; i < (n); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPD(i, n) for (int i = (n)-1; i >= 0; --i)

const int INF = 1e9 + 7;
const ll  LINF = 4e18;
const ld  EPS = 1e-9;
const int MOD = 1e9 + 7;

vector<vector<int>> findMatrix(vector<int>& nums){
    vector<vector<int>> ans;
    map<int, vector<int>> numFreq;
    int n = nums.size();

    multiset<int> freq;
    for(int i = 0; i < n; i++){
        numFreq[freq.count(nums[i])].push_back(nums[i]);
        freq.insert(nums[i]);
    }

    for(auto &[f, v] : numFreq){
        ans.push_back(v);
    }
    return ans;
}

int main(){
    FAST_IO;

    int n; cin >> n;
    vector<int> nums(n);
    FORI(i, n) cin >> nums[i];

    vector<vector<int>> results = findMatrix(nums);
    for(auto result : results){
        for(int ans : result){
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}