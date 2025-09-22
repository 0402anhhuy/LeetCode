#include<bits/stdc++.h>
using namespace std;

/*
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        while (current) {
            next = current->next; // Lưu node tiếp theo
            current->next = prev; // Đảo ngược liên kết
            prev = current;       // Di chuyển prev lên
            current = next;       // Di chuyển current lên
        }
        return prev;
    }
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

ListNode* reverseList(ListNode* head){
    stack<ListNode*> st;
    if(!head) return nullptr;
    while(head){
        st.push(head);
        head = head->next;
    }

    ListNode* newHead = st.top();
    ListNode* current = newHead;
    st.pop();

    while(!st.empty()){
        ListNode* tmp = st.top();
        current->next = tmp;
        current = current->next;
        st.pop();
    }
    current->next = nullptr;
    return newHead;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    ListNode* res = reverseList(head);
    printList(res);
    return 0;
}
