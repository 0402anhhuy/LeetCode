#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 203. Remove Linked List Elements
    Ý tưởng:
        - Tìm phần curr tại node mà giá trị không trùng giá trị cần xóa
        - Duyệt danh sách nếu phần tử bằng val thì head->next = head->next->next
        - Nếu không thì chỉ di chuyển lên head = head->next
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

ListNode* removeElements(ListNode* head, int val){
    if(!head) return nullptr;
    ListNode* curr = nullptr;
    while(head){
        if(head->val != val){
            curr = head;
            break;
        }
        head = head->next;
    }

    while(head && head->next){
        if(head->next->val == val){
            head->next = head->next->next;
        }
        else head = head->next;
    }
    return curr;

}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);
    int val = 6;
    ListNode* res = removeElements(head, val);
    printList(res);
    return 0;
}
