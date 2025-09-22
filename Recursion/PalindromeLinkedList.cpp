#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode -  234. Palindrome Linked List
    Ý tưởng:
        + Duyệt đến cuối danh sách liên kết bằng cách gọi đệ quy
        + So sánh từng cặp phần tử đối xứng
        + Khi quay lui từ lời gọi đệ quy cuối cùng, so sánh từng nút đầu với nút cuối tương ứng
        + Dùng một con trỏ toàn cục curr để duyệt từ đầu danh sách
        + Cập nhật con trỏ curr để di chuyển lên trong quá trình quay lui
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

ListNode* curr;

bool solve(ListNode* head){
    if(head == nullptr) return true;
    bool res = solve(head->next) && head->val == curr->val;
    curr = curr->next;
    return res;
}

bool isPalindrome(ListNode* head){
    curr = head;
    return solve(head);
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    bool res = isPalindrome(head);
    cout << boolalpha << res;
    return 0;
}
