Dưới đây là **kiến thức tổng quan và chuyên sâu** về **Heap trong C++**, bao gồm lý thuyết, cách dùng với `vector` và `priority_queue`, cũng như so sánh hai cách triển khai.

---

## 🔷 I. HEAP là gì?

**Heap** là một **cấu trúc dữ liệu dạng cây** thỏa mãn tính chất sau:

- **Max-heap**: Node cha ≥ node con (phần tử lớn nhất ở root).
- **Min-heap**: Node cha ≤ node con (phần tử nhỏ nhất ở root).

Heap thường được dùng để:

- Lấy phần tử lớn nhất/nhỏ nhất nhanh chóng.
- Tối ưu các bài toán như top-k, k smallest/largest, hoặc Dijkstra’s algorithm.

---

## 🔷 II. Triển khai Heap trong C++

C++ hỗ trợ 2 cách làm việc với heap:

---

### 🟢 1. Sử dụng `priority_queue` (container adapter)

```cpp
#include <queue>
priority_queue<int> maxHeap;                    // Max-heap mặc định
priority_queue<int, vector<int>, greater<>> minHeap; // Min-heap
```

#### ✅ Ưu điểm:

- Dễ dùng, quản lý nội bộ.
- Tự động duy trì tính chất heap.

#### ✅ Các thao tác:

| Hàm       | Mô tả                              |
| --------- | ---------------------------------- |
| `push(x)` | Thêm phần tử `x`                   |
| `pop()`   | Loại bỏ phần tử lớn nhất/nhỏ nhất  |
| `top()`   | Truy cập phần tử lớn nhất/nhỏ nhất |
| `empty()` | Kiểm tra rỗng                      |

---

### 🟢 2. Sử dụng `vector` + các hàm `<algorithm>`

C++ cung cấp các hàm để quản lý **heap trong vector**:

| Hàm                     | Mô tả                     |
| ----------------------- | ------------------------- |
| `make_heap(begin, end)` | Biến dãy thành max-heap   |
| `push_heap(begin, end)` | Thêm phần tử mới vào heap |
| `pop_heap(begin, end)`  | Di chuyển root ra cuối    |
| `sort_heap(begin, end)` | Sắp xếp heap tăng dần     |

#### 🔧 Ví dụ:

```cpp
vector<int> v = {3, 1, 4, 2};
make_heap(v.begin(), v.end());        // v[0] = 4 (max-heap)

v.push_back(5);
push_heap(v.begin(), v.end());        // Thêm phần tử và duy trì heap

pop_heap(v.begin(), v.end());         // Đưa max ra cuối
v.pop_back();                         // Xóa max ra khỏi heap
```

#### ⚠ Lưu ý:

- Theo mặc định là **max-heap**.
- Muốn dùng min-heap thì truyền `greater<>()`.

---

## 🔷 III. Min-heap & Max-heap với comparator

### Max-heap (mặc định):

```cpp
priority_queue<int> pq;
```

### Min-heap:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

### Với cặp giá trị:

```cpp
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
```

---

## 🔷 IV. So sánh `priority_queue` vs `heap + vector`

| Tiêu chí              | `priority_queue`        | `vector + heap API`        |
| --------------------- | ----------------------- | -------------------------- |
| Dễ dùng               | ✅ Rất dễ               | ❌ Cần thao tác thủ công   |
| Cập nhật phần tử giữa | ❌ Không hỗ trợ         | ✅ Có thể làm thủ công     |
| Kiểm soát thứ tự heap | ❌ Không tùy chỉnh được | ✅ Có thể sắp xếp thủ công |
| Tính linh hoạt        | ❌ Hạn chế              | ✅ Linh hoạt               |

---

## 🔷 V. Ứng dụng phổ biến của heap

- **Top K Largest/Smallest**
- **Dijkstra's Algorithm**
- **Huffman Encoding**
- **Lập lịch CPU**
- **Bộ nhớ ưu tiên**

---

## ✅ Tóm tắt

| Kiến thức chính  | Ghi nhớ                                  |
| ---------------- | ---------------------------------------- |
| `make_heap`      | Xây dựng heap từ vector                  |
| `push_heap`      | Thêm phần tử vào heap                    |
| `pop_heap`       | Đẩy root ra cuối, cần `pop_back()` tiếp  |
| `priority_queue` | Dùng tiện lợi nhưng khó cập nhật phần tử |
| `greater<>`      | Dùng để tạo min-heap                     |

---

Bạn muốn mình minh họa bằng ví dụ cụ thể về `priority_queue`, `heap` với cặp giá trị (`pair<int, int>`), hoặc so sánh hiệu năng giữa 2 cách này không?
