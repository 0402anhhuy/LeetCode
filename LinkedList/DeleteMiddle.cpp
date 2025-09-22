#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode: 876. Middle of the Linked List
    Ý tưởng:
        + ListNode* slow chạy n
        + ListNode* fast chạy 2n -> Nếu fast tới cuối thì slow sẽ là phần tử chính giữa
        + Dùng prev để lưu node trước node slow
*/

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

ListNode* deleteMiddle(ListNode* head){
    if(!head || !head->next) return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;
    while(fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    return head;
}

void printList(ListNode *head){
    ListNode *current = head;
    while(current){
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(7);
    head->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(6);

    ListNode* res = deleteMiddle(head);
    printList(res);
    return 0;
}