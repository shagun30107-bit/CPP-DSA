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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || left==right) return head;

        ListNode* dummy = new ListNode (0); //connet it with head
        dummy->next=head;
        ListNode* prenode= dummy;

        for(int i=1 ; i<left; i++){ //stop just before left
            prenode=prenode->next;
        }
        ListNode* prev= NULL; //same as reverse
        ListNode* cur= prenode->next;
        ListNode* subhead= cur;
        for(int i=0; i<= right-left ; i++){
            ListNode* front= subhead->next;
            subhead->next=prev;
            prev=subhead;
            subhead=front;
        }
        prenode->next=prev;
        cur->next = subhead;
        return dummy->next;
    }
};