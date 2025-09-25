## 🔍 Backtracking là gì?

**Backtracking** (quay lui) là một kỹ thuật giải thuật dùng để giải các bài toán bằng cách thử nghiệm tất cả các khả năng có thể xảy ra. Khi phát hiện một hướng đi không dẫn đến kết quả, thuật toán sẽ "quay lui" lại và thử hướng khác

## ⚡ Nguyên lý hoạt động

Backtracking hoạt động theo nguyên tắc **"Thử và Sai"**:
1. Thử một lựa chọn
2. Nếu lựa chọn này dẫn đến giải pháp → thành công
3. Nếu không → quay lui và thử lựa chọn khác

## 📝 Cấu trúc cơ bản

```cpp
void backtrack(parameters) {
    if (điều_kiện_dừng) {
        // Xử lý kết quả
        return;
    }
    
    for (mỗi lựa chọn có thể) {
        if (lựa_chọn_hợp_lệ) {
            // Thử lựa chọn này
            thực_hiện_lựa_chọn();
            
            // Gọi đệ quy để thử tiếp
            backtrack(parameters_updated);
            
            // Quay lui (undo)
            hủy_lựa_chọn();
        }
    }
}
```

## 💡 Ví dụ minh họa
### 🥞 Bài toán Tổ hợp (Combinations)

#### Tìm tất cả tổ hợp chập k của n phần tử

```cpp
#include <iostream>
#include <vector>
using namespace std;

void backtrack(int start, int n, int k, vector<int>& current, vector<vector<int>>& result) {
    // Điều kiện dừng: đã chọn đủ k phần tử
    if (current.size() == k) {
        result.push_back(current);
        return;
    }
    
    // Thử các lựa chọn từ start đến n
    for (int i = start; i <= n; i++) {
        // Thử chọn i
        current.push_back(i);
        
        // Gọi đệ quy với start = i + 1 (tránh trùng lặp)
        backtrack(i + 1, n, k, current, result);
        
        // Quay lui: bỏ phần tử vừa chọn
        current.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> current;
    backtrack(1, n, k, current, result);
    return result;
}

int main() {
    int n = 4, k = 2;
    vector<vector<int>> combinations = combine(n, k);
    
    cout << "Tổ hợp chập " << k << " của " << n << " phần tử:\n";
    for (auto& comb : combinations) {
        for (int num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
```

**Kết quả:**
```
1 2
1 3
1 4
2 3
2 4
3 4
```

### 2. Bài toán N-Queens

Xếp n quân hậu trên bàn cờ n×n sao cho không có 2 quân nào ăn nhau:

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isValid(vector<string>& board, int row, int col, int n) {
    // Kiểm tra cột
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
    }
    
    // Kiểm tra đường chéo trái trên
    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }
    
    // Kiểm tra đường chéo phải trên
    for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }
    
    return true;
}

void solveNQueens(int n, int row, vector<string>& board, vector<vector<string>>& solutions) {
    if (row == n) {
        solutions.push_back(board);
        return;
    }
    
    for (int col = 0; col < n; col++) {
        if (isValid(board, row, col, n)) {
            // Thử đặt hậu
            board[row][col] = 'Q';
            
            // Gọi đệ quy cho hàng tiếp theo
            solveNQueens(n, row + 1, board, solutions);
            
            // Quay lui
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    solveNQueens(n, 0, board, solutions);
    return solutions;
}

int main() {
    int n = 4;
    vector<vector<string>> solutions = solveNQueens(n);
    
    cout << "Số giải pháp cho " << n << "-Queens: " << solutions.size() << endl;
    for (int i = 0; i < solutions.size(); i++) {
        cout << "Giải pháp " << i + 1 << ":\n";
        for (string row : solutions[i]) {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}
```

## 🎯 Các bài toán phù hợp với Backtracking

Backtracking thường được dùng cho:
- **Bài toán liệt kê**: Tổ hợp, chỉnh hợp, hoán vị
- **Bài toán xếp hạng**: N-Queens, Sudoku
- **Bài toán tìm đường**: Maze solving
- **Bài toán phân chia**: Subset sum, Partition problem

## ⚡ Tối ưu hóa Backtracking

### 1. Cắt tỉa (Pruning)
```cpp
void backtrack(int n, int k, int start, vector<int>& current, vector<vector<int>>& result) {
    if (current.size() == k) {
        result.push_back(current);
        return;
    }
    
    // Cắt tỉa: nếu số phần tử còn lại không đủ để chọn
    if (k - current.size() > n - start + 1) {
        return;
    }
    
    for (int i = start; i <= n; i++) {
        current.push_back(i);
        backtrack(n, k, i + 1, current, result);
        current.pop_back();
    }
}
```

### 2. Memoization (ghi nhớ)
```cpp
unordered_map<string, bool> memo;

bool canPartition(vector<int>& nums, int index, int sum, int target) {
    string key = to_string(index) + "-" + to_string(sum);
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }
    
    // ... backtracking logic ...
    
    memo[key] = result;
    return result;
}
```

## 📊 Độ phức tạp

- **Thời gian**: Thường là hàm mũ O(2ⁿ) hoặc O(n!)
- **Không gian**: O(n) cho stack đệ quy