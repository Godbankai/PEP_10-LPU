#include <bits/stdc++.h>
using namespace std;
struct ListNode { int val; ListNode *next; ListNode(int x): val(x), next(nullptr) {} };
class Solution {
public:
    ListNode *detectCycle(ListNode *head){
        ListNode *slow=head, *fast=head;
        while(fast && fast->next){
            slow=slow->next; fast=fast->next->next;
            if(slow==fast){
                ListNode* ptr=head;
                while(ptr!=slow){ ptr=ptr->next; slow=slow->next; }
                return ptr;
            }
        }
        return nullptr;
    }
};
