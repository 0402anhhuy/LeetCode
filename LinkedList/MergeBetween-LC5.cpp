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
    LeetCode 5. Merge In Between Linked Lists

    Đề bài:  
    Cho hai danh sách liên kết (linked list) `list1` và `list2`
    Hãy xóa các node trong `list1` từ vị trí `a` đến `b` (tính từ 0),  
    sau đó chèn toàn bộ list2 vào vị trí đó

    Yêu cầu:  
    → Trả về head của danh sách liên kết mới sau khi đã ghép

    Ví dụ:  
        Input: list1 = [10, 1, 13, 6, 9, 5], a = 3, b = 4, list2 = [1000000, 1000001, 1000002]  
        → Xóa các node vị trí 3, 4 (tức là [6, 9])  
        → Ghép list2 vào giữa  
        → Output: [10, 1, 13, 1000000, 1000001, 1000002, 5]
*/

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2){
    ListNode* start = nullptr;
    ListNode* end = list1;

    for(int i = 0; i < b; i++){
        if(i == a - 1){
            start = end;
        }
        end = end->next;
    }

    start->next = list2;

    ListNode* tail = list2;
    while(tail->next != nullptr){
        tail = tail->next;
    }

    tail->next = end->next;
    end->next = nullptr;
    
    return list1;
}

int main(){
    FAST_IO;

    ListNode* list1 = new ListNode(10);
    list1->next = new ListNode(1);
    list1->next->next = new ListNode(13);
    list1->next->next->next = new ListNode(6);
    list1->next->next->next->next = new ListNode(9);
    list1->next->next->next->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(1000000);
    list2->next = new ListNode(1000001);
    list2->next->next = new ListNode(1000002);

    int a = 3, b = 4;

    ListNode* ans = mergeInBetween(list1, a, b, list2);
    while(ans != nullptr){
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}