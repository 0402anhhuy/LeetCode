#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode: 328. Odd Even Linked List
    Ý tưởng:
        - Sử dụng 2 con trỏ odd và even để lưu trữ các node lẻ và chẵn.
        - Duyệt qua danh sách liên kết, cập nhật next của odd và even.
        - Cuối cùng gán next của odd bằng evenHead.
        - Trả về head.
*/

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

ListNode* oddEvenList(ListNode* head){
    if(!head || !head->next) return head;

    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = even;

    while(even && even->next){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
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
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* res = oddEvenList(head);
    printList(res);
    return 0;
}