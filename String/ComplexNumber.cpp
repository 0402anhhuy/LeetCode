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

string complexNumberMultiply(string num1, string num2){
    string real1 = "", imaginary1 = "", real2 = "", imaginary2 = "";
    for(int i = 0; i < num1.length(); i++){
        if(num1[i] == '+'){
            imaginary1 = num1.substr(i + 1, num1.size() - i - 2);
            break;
        }
        else{
            real1 += num1[i];
        }
    }

    for(int i = 0; i < num2.length(); i++){
        if(num2[i] == '+'){
            imaginary2 = num2.substr(i + 1, num2.size() - i - 2);
            break;
        }
        else{
            real2 += num2[i];
        }
    }

    int real = (stoi(real1) * stoi(real2)) + (stoi(imaginary1) * stoi(imaginary2)) * -1;
    int imaginary = (stoi(real1) * stoi(imaginary2)) + (stoi(real2) * stoi(imaginary1));
    
    return to_string(real) + '+' + to_string(imaginary) + 'i';
}

int main(){
    FAST_IO;

    string num1, num2; cin >> num1 >> num2;
    string ans = complexNumberMultiply(num1, num2);
    cout << ans;
    return 0;
}