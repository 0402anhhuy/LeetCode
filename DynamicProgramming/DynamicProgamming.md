# 🧭 TỔNG QUAN VỀ DYNAMIC PROGRAMMING (DP)

> “Bài toán lớn có thể chia thành các bài toán con nhỏ hơn có cấu trúc giống nhau.”

Ta lưu lời giải của bài toán con → dùng lại để tính nhanh bài toán lớn (tránh lặp).

---

# ⚙️ 1️⃣ DẠNG 1: DP TUYẾN TÍNH (1 CHIỀU)

### 💡 Mô hình:

Kết quả ở vị trí `i` chỉ phụ thuộc vào vài vị trí trước đó (`i-1`, `i-2`, …).

### 🔹 Mẫu công thức:

[
dp[i] = f(dp[i-1], dp[i-2], ..., input[i])
]

### 🔹 Ví dụ:

| Bài                              | Ý tưởng                     | Công thức                                 |
| -------------------------------- | --------------------------- | ----------------------------------------- |
| 🪜 **Climbing Stairs**           | Leo 1 hoặc 2 bậc            | `dp[i] = dp[i-1] + dp[i-2]`               |
| 💰 **Min Cost Climbing Stairs**  | Leo với chi phí nhỏ nhất    | `dp[i] = cost[i] + min(dp[i-1], dp[i-2])` |
| 🏠 **House Robber I**            | Không chọn 2 nhà kề nhau    | `dp[i] = max(dp[i-1], dp[i-2] + nums[i])` |
| 📈 **Maximum Subarray (Kadane)** | Tổng con liên tiếp lớn nhất | `dp[i] = max(nums[i], nums[i] + dp[i-1])` |

👉 **Nhận biết:** có chuỗi 1 chiều, mỗi bước phụ thuộc 1–2 phần tử trước.

---

# 🧩 2️⃣ DẠNG 2: DP 2 CHIỀU (GRID / TABLE)

### 💡 Mô hình:

Mỗi trạng thái phụ thuộc vào **2 chỉ số** (thường là `i, j` → dòng, cột).

### 🔹 Mẫu công thức:

[
dp[i][j] = f(dp[i-1][j], dp[i][j-1], ..., input[i][j])
]

### 🔹 Ví dụ:

| Bài                                     | Ý tưởng                   | Công thức                                                                |
| --------------------------------------- | ------------------------- | ------------------------------------------------------------------------ |
| 🗺️ **Unique Paths**                    | Đếm số đường đi trên lưới | `dp[i][j] = dp[i-1][j] + dp[i][j-1]`                                     |
| 💎 **Minimum Path Sum**                 | Tổng chi phí nhỏ nhất     | `dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])`                    |
| 🔠 **Edit Distance**                    | Sửa chuỗi A thành B       | `dp[i][j] = min(ins, del, rep)`                                          |
| 💬 **Longest Common Subsequence (LCS)** | Dãy con chung dài nhất    | `dp[i][j] = (a[i]==b[j]) ? dp[i-1][j-1]+1 : max(dp[i-1][j], dp[i][j-1])` |

👉 **Nhận biết:** đề có dạng “chuỗi / ma trận / 2 chiều / so sánh 2 chuỗi”.

---

# 🎒 3️⃣ DẠNG 3: KNAPSACK (BALO)

### 💡 Mô hình:

Chọn một tập con phần tử sao cho **đạt mục tiêu tối đa** mà **không vượt giới hạn**.

### 🔹 Mẫu công thức:

[
dp[i][w] = \max(dp[i-1][w],\ dp[i-1][w-w_i] + v_i)
]
(`w_i` là trọng lượng, `v_i` là giá trị của vật i)

### 🔹 Ví dụ:

| Bài                                        | Ý tưởng                 | Công thức                                        |   |                       |
| ------------------------------------------ | ----------------------- | ------------------------------------------------ | - | --------------------- |
| 🎒 **0/1 Knapsack**                        | Chọn hoặc không chọn đồ | `dp[i][w] = max(dp[i-1][w], dp[i-1][w-wi] + vi)` |   |                       |
| 💵 **Subset Sum / Partition Equal Subset** | Có thể tạo tổng S không | `dp[i][s] = dp[i-1][s]                           |   | dp[i-1][s - nums[i]]` |
| 🧩 **Coin Change**                         | Cách tạo ra tổng tiền   | `dp[i] = min(dp[i], dp[i - coin] + 1)`           |   |                       |

👉 **Nhận biết:** có “giới hạn tài nguyên” (trọng lượng, số tiền, ký tự, thời gian…).

---

# 🌳 4️⃣ DẠNG 4: DP TRÊN CÂY (Tree DP)

### 💡 Mô hình:

Tính giá trị dựa trên các **con** trong cây.

### 🔹 Ý tưởng:

Sử dụng **DFS** để tính kết quả cho mỗi nút dựa trên kết quả các nút con.

### 🔹 Ví dụ:

| Bài                     | Ý tưởng                     | Công thức                             |
| ----------------------- | --------------------------- | ------------------------------------- |
| 🌲 **House Robber III** | Không chọn cha-con cùng lúc | `rob = root->val + sum(child.notRob)` |
| 🔁 **Diameter of Tree** | Độ dài đường đi dài nhất    | `res = max(res, left+right)`          |
| 📈 **Maximum Path Sum** | Đường đi có tổng lớn nhất   | `dp[node] = max(left,right)+val`      |

👉 **Nhận biết:** đề có cấu trúc “cây” hoặc “đồ thị có hướng không chu trình (DAG)”.

---

# 🧠 5️⃣ DẠNG 5: BITMASK / SUBSET DP

### 💡 Mô hình:

Trạng thái là **tập con các phần tử** (biểu diễn bằng bitmask).

### 🔹 Ví dụ:

| Bài                               | Ý tưởng                         | Công thức                                                         |                                               |
| --------------------------------- | ------------------------------- | ----------------------------------------------------------------- | --------------------------------------------- |
| 🔤 **Word Score (LeetCode 1255)** | Chọn tập con từ để đạt điểm cao | `dp[mask                                                          | (1<<i)] = max(dp[mask], dp[mask] + score[i])` |
| 🧮 **Travelling Salesman (TSP)**  | Đường đi ngắn nhất qua mọi điểm | `dp[mask][i] = min(dp[mask][i], dp[mask^(1<<i)][j] + cost[j][i])` |                                               |

👉 **Nhận biết:** đề nói về “chọn tập con tối ưu” hoặc “thử tất cả tổ hợp”.

---

# 🔁 6️⃣ DẠNG 6: INTERVAL DP (DP trên đoạn)

### 💡 Mô hình:

Kết quả của một đoạn `[i, j]` phụ thuộc các đoạn con `[i, k]` và `[k+1, j]`.

### 🔹 Ví dụ:

| Bài                                | Ý tưởng                  | Công thức                                                    |
| ---------------------------------- | ------------------------ | ------------------------------------------------------------ |
| 💣 **Burst Balloons**              | Chọn bóng nổ tối ưu      | `dp[i][j] = max(dp[i][k] + dp[k][j] + val[i]*val[k]*val[j])` |
| 🧮 **Matrix Chain Multiplication** | Tối ưu phép nhân ma trận | `dp[i][j] = min(dp[i][k] + dp[k+1][j] + cost)`               |

👉 **Nhận biết:** đề có đoạn `[i, j]`, yêu cầu chia đôi hoặc ghép dần các đoạn.

---

# 🌀 7️⃣ DẠNG 7: STATE MACHINE DP (trạng thái phức hợp)

### 💡 Mô hình:

Một biến `i` (thời điểm) + nhiều trạng thái phụ (`holding`, `sold`, `cooldown`, …).

### 🔹 Ví dụ:

| Bài                                                        | Ý tưởng                    | Công thức                                      |
| ---------------------------------------------------------- | -------------------------- | ---------------------------------------------- |
| 💹 **Best Time to Buy and Sell Stock II / III / Cooldown** | Giao dịch cổ phiếu tối ưu  | `dp[i][state] = max(... trạng thái trước ...)` |
| 🚶 **Dungeon Game / Minimum Falling Path Sum**             | Mỗi bước có nhiều hướng rẽ | DP 2D hoặc State Machine                       |

👉 **Nhận biết:** đề có “trạng thái hành động” (mua/bán/đợi…).

---

# ✅ TỔNG KẾT

| Dạng              | Đặc điểm nhận diện                    | Cách giải                        |
| ----------------- | ------------------------------------- | -------------------------------- |
| 1️⃣ Tuyến tính    | Chuỗi 1D, phụ thuộc vài phần tử trước | Duyệt từ trái sang phải, 1D DP   |
| 2️⃣ 2 Chiều       | Ma trận, chuỗi đôi                    | DP 2D (bảng)                     |
| 3️⃣ Knapsack      | Giới hạn tài nguyên                   | DP 2D hoặc 1D đảo ngược          |
| 4️⃣ Trên cây      | Cấu trúc cha–con                      | DFS + DP trả về nhiều giá trị    |
| 5️⃣ Bitmask       | Chọn tập con                          | Duyệt mask, dùng bit để đánh dấu |
| 6️⃣ Interval      | Chia đoạn, hợp đoạn                   | DP theo độ dài đoạn              |
| 7️⃣ State machine | Nhiều trạng thái logic                | DP đa chiều (i + state)          |

