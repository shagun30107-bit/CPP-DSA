#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast = head;
        if(head == NULL || head->next == NULL) return NULL;
        if(head->next->next == NULL) {
            ListNode* delN = head->next;
            head->next = NULL;
            delete delN;
            return head;
        }
        while(fast->next->next !=NULL && fast->next->next->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* delN = slow->next;
        slow->next = delN->next;
        delete delN;
        return head;
    }
};