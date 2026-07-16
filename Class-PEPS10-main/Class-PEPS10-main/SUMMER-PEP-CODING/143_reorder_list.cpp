#include <bits/stdc++.h>
using namespace std;
struct ListNode { int val; ListNode *next; ListNode(int x): val(x), next(nullptr) {} };
class Solution {
public:
    void reorderList(ListNode* head){
        if(!head || !head->next) return;
        ListNode *slow=head, *fast=head;
        while(fast->next && fast->next->next){ slow=slow->next; fast=fast->next->next; }
        ListNode* second=slow->next;
        slow->next=nullptr;
        ListNode* prev=nullptr;
        while(second){ ListNode* nxt=second->next; second->next=prev; prev=second; second=nxt; }
        ListNode* first=head;
        second=prev;
        while(second){
            ListNode* n1=first->next, *n2=second->next;
            first->next=second;
            second->next=n1;
            first=n1; second=n2;
        }
    }
};
