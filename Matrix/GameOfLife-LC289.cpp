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

/*
    LeetCode 289. Game of Life

    Đề bài:
    Cho một bảng kích thước m x n đại diện cho các tế bào, trong đó mỗi tế bào có trạng thái: sống (1) hoặc chết (0)
    Mỗi tế bào sẽ tương tác với 8 hàng xóm xung quanh nó (ngang, dọc, chéo) để quyết định trạng thái ở thế hệ tiếp theo

    Quy tắc cập nhật (áp dụng đồng thời cho tất cả tế bào):
    1. Sống → Chết: Nếu tế bào sống có ít hơn 2 hàng xóm sống (do thiếu hụt quần thể)
    2. Sống → Sống: Nếu tế bào sống có 2 hoặc 3 hàng xóm sống
    3. Sống → Chết: Nếu tế bào sống có nhiều hơn 3 hàng xóm sống (do quá tải quần thể)
    4. Chết → Sống: Nếu tế bào chết có đúng 3 hàng xóm sống (do sự sinh sản)

    Yêu cầu:
    → Cập nhật trực tiếp trên bảng board để phản ánh trạng thái ở thế hệ tiếp theo
    → Lưu ý: Tất cả các thay đổi phải diễn ra đồng thời, nghĩa là trạng thái mới của một tế bào không được ảnh hưởng đến việc tính toán của các tế bào khác trong cùng một lượt cập nhật

    Ví dụ:
        Input: board = [
          [0, 1, 0],
          [0, 0, 1],
          [1, 1, 1],
          [0, 0, 0]
        ]
        → Sau khi áp dụng 4 quy tắc cho từng ô:
        Output: [
          [0, 0, 0],
          [1, 0, 1],
          [0, 1, 1],
          [0, 1, 0]
        ]
*/

int dx[8] = {-1, -1, 1, 0, 0, -1, 1, 1};
int dy[8] = {-1, 0, -1, -1, 1, 1, 0, 1};

void gameOfLife(vector<vector<int>>& board){
    int m = board.size();
    int n = board[0].size();
    vector<vector<int>> old = board;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int live = 0;
            for(int k = 0; k < 8; k++){
                int x = i + dx[k], y = j + dy[k];
                if(0 <= x && x < m && 0 <= y && y < n){
                    live += old[x][y];
                }
            }

            if(old[i][j] == 1){
                if(live < 2 || live > 3){
                    board[i][j] = 0;
                }
            } 
            else{
                if(live == 3){
                    board[i][j] = 1;
                }
            }
        }
    }
}


int main(){
    FAST_IO;

    int m, n; cin >> m >> n;
    vector<vector<int>> board(m, vector<int>(n));
    FORI(i, m){
        FORI(j, n){
            cin >> board[i][j];
        }
    }

    gameOfLife(board);

    FORI(i, m){
        FORI(j, n){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}