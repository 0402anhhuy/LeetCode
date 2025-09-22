#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode: 83. Remove Duplicates from Sorted List
    Ý tưởng:
        - Duyệt qua danh sách liên kết, nếu giá trị của node hiện tại bằng giá trị của node tiếp theo thì gán node tiếp theo cho node tiếp theo của node hiện tại.
        - Nếu không thì gán node hiện tại cho node tiếp theo của node hiện tại.
        - Trả về node đầu tiên của danh sách liên kết.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

void printList(ListNode *head){
    ListNode *current = head;
    while(current){
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

ListNode* deleteDuplicates(ListNode* head){
    ListNode* current = head;
    while(head && head->next){
        if(head->val == head->next->val){
            head->next = head->next->next;
        }
        else head = head->next;
    }
    return current;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    ListNode* res = deleteDuplicates(head);
    printList(res);
    return 0;
}
