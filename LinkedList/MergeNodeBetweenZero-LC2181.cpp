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
    LeetCode 2181. Merge Nodes in Between Zeros

    Đề bài:  
    Cho một danh sách liên kết (linked list) bắt đầu và kết thúc bằng các node có giá trị 0
    Giữa mỗi cặp 0 liên tiếp là một nhóm các số nguyên dương

    Yêu cầu:  
    → Với mỗi cặp 0 liên tiếp, cộng tổng các node nằm giữa chúng
    và thay chúng bằng một node duy nhất có giá trị bằng tổng đó
    → Kết quả cuối cùng không chứa node có giá trị 0

    Ví dụ:  
        Input:  [0, 3, 1, 0, 4, 5, 2, 0]  
        → Giữa hai số 0 đầu tiên: 3 + 1 = 4  
        → Giữa hai số 0 tiếp theo: 4 + 5 + 2 = 11  
        → Output: [4, 11]
*/

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

ListNode* mergeNodes(ListNode* head){
    int sum = 0;
    ListNode* ans = new ListNode();
    ListNode* result = ans;

    while(head){
        if(head->val == 0 && sum != 0){
            ans->next = new ListNode(sum);
            ans = ans->next;
            sum = 0;
        }
        else{
            sum += head->val;
        }
        head = head->next;
    }
    return result->next;
}

int main(){
    FAST_IO;

    ListNode* head = new ListNode(0);
    head->next = new ListNode(3);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(0);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next->next = new ListNode(0);

    ListNode* ans = mergeNodes(head);
    while(ans != nullptr){
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}