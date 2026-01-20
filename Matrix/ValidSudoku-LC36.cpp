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
    LeetCode 36. Valid Sudoku

    Đề bài:
    Xác định xem một bảng Sudoku kích thước 9 x 9 có hợp lệ hay không
    Lưu ý: Bạn chỉ cần kiểm tra các ô đã được điền số, các ô trống (ký hiệu là '.') thì bỏ qua

    Quy tắc hợp lệ:
    1. Mỗi hàng: Phải chứa các chữ số từ 1-9 mà không được lặp lại
    2. Mỗi cột: Phải chứa các chữ số từ 1-9 mà không được lặp lại
    3. Mỗi khối 3 x 3: Trong số 9 khối con của bảng, mỗi khối phải chứa các chữ số từ 1-9 mà không được lặp lại

    Lưu ý quan trọng:
    → Một bảng Sudoku hợp lệ không nhất thiết phải giải được
    → Bạn chỉ cần kiểm tra tính hợp lệ của các con số hiện có trên bảng dựa trên 3 quy tắc trên

    Ví dụ:
        Input: board = [
          ["5","3",".",".","7",".",".",".","."],
          ["6",".",".","1","9","5",".",".","."],
          ...
        ]
        → Kiểm tra từng hàng, từng cột và từng khối 3x3 xem có con số nào xuất hiện 2 lần không
        → Output: true
*/

bool isValidHertical(vector<vector<char>>& board){
    for(int i = 0; i < 9; i++){
        map<int, int> numFreq;
        for(int j = 0; j < 9; j++){
            if(isdigit(board[i][j])){
                numFreq[board[i][j] - '0']++;
                if(numFreq[board[i][j] - '0'] > 1){
                    return false;
                }
            }
        }
    }

    return true;
}

bool isValidVertical(vector<vector<char>>& board){
    for(int i = 0; i < 9; i++){
        map<int, int> numFreq;
        for(int j = 0; j < 9; j++){
            if(isdigit(board[j][i])){
                numFreq[board[j][i] - '0']++;
                if(numFreq[board[j][i] - '0'] > 1){
                    return false;
                }
            }
        }
    }

    return true;
}

bool isValidBoard(vector<vector<char>>& board){
    for(int i = 2; i < 9; i += 3){
        for(int j = 2; j < 9; j += 3){
            map<int, int> numFreq;
            for(int k = i - 2; k <= i; k++){
                for(int l = j - 2; l <= j; l++){
                    if(isdigit(board[k][l])){
                        numFreq[board[k][l] - '0']++;
                        if(numFreq[board[k][l] - '0'] > 1){
                            return false;
                        }
                    }
                }
            }
        }
    }

    return true;
}

bool isValidSudoku(vector<vector<char>>& board){
    bool validHertical = isValidHertical(board);
    bool validVertical = isValidVertical(board);
    bool validBoard = isValidBoard(board);

    return validHertical && validVertical && validBoard;
}

int main(){
    FAST_IO;

    vector<vector<char>> board(9, vector<char>(9));
    FORI(i, 9){
        FORI(j, 9){
            cin >> board[i][j];
        }
    }

    cout << boolalpha << isValidSudoku(board);
    return 0;
}