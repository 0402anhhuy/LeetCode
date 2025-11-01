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
    LeetCode 3217. Delete Nodes From Linked List Present in Array

    Đề bài:
    Cho một mảng các số nguyên (array of integers) nums và head của một danh sách liên kết (linked list)

    Yêu cầu:
    → Trả về head của danh sách liên kết đã được chỉnh sửa
    → Danh sách liên kết phải được xóa bỏ tất cả các node có giá trị tồn tại (xuất hiện) trong mảng nums

    Ví dụ:
        Input: nums = [1,2,3], head = [1,2,3,4,5]
        → Các node có giá trị 1, 2, 3 bị xóa vì chúng nằm trong mảng nums
        → Output: [4,5]
*/

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

ListNode* modifiedList(vector<int>& nums, ListNode* head){
    unordered_set<int> numSet(nums.begin(), nums.end());

    while(head && numSet.count(head->val)){
        head = head->next;
    }

    if(!head) return nullptr;

    ListNode* cur = head;
    while(cur && cur->next){
        if(numSet.count(cur->next->val)){
            cur->next = cur->next->next;
        }
        else{
            cur = cur->next;
        }
    }
    return head;
}

int main(){
    FAST_IO;

    int n; cin >> n;
    vector<int> nums(n);
    FORI(i, n) cin >> nums[i];

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    ListNode* ans = modifiedList(nums, head);
    while(ans){
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}