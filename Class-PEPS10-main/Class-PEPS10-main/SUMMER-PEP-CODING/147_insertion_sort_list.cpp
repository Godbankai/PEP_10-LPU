#include <bits/stdc++.h>
using namespace std;
struct ListNode { int val; ListNode *next; ListNode(int x): val(x), next(nullptr) {} };
class Solution {
public:
    ListNode* insertionSortList(ListNode* head){
        ListNode dummy(0);
        ListNode* cur=head;
        while(cur){
            ListNode* next=cur->next;
            ListNode* p=&dummy;
            while(p->next && p->next->val<cur->val) p=p->next;
            cur->next=p->next; p->next=cur;
            cur=next;
        }
        return dummy.next;
    }
};
