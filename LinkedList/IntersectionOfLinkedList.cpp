#include<bits/stdc++.h>
using namespace std;

/*
*/

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    ListNode *pA = headA;
    ListNode *pB = headB;

    while(pA != pB){
        pA = (pA != nullptr) ? pA->next : headB;
        pB = (pB != nullptr) ? pB->next : headA;
    }
    return pA;
}

int main(){
    ListNode* common = new ListNode(2, new ListNode(4));
    ListNode* headA = new ListNode(1, new ListNode(9, new ListNode(1, common)));
    ListNode* headB = new ListNode(3, common);

    int res = getIntersectionNode(headA, headB)->val;
    cout << res;
    return 0;
}