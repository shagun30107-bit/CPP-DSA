#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
// Method-1
// TC-O(2*len)

int length(ListNode* head){
    ListNode* temp= head;
    int len=0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=length(head);
        if(len == n){
            ListNode* newhead = head->next;
            delete head;
            return newhead;
        }

        ListNode* temp= head;
        int rem = len-n;
        while(rem > 1){
            temp = temp->next;
            rem--;
        }
        ListNode* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
        return head;
    }
};

// Method-2
// fast & slow approach
// TC- O(len)

ListNode* M2(ListNode* head,int n){
    ListNode* fast= head;
    while(n){
        fast=fast->next;
        n--;
    }
    if(fast == NULL) {
        ListNode* newhead = head->next;
        delete head;
        return newhead;
    }
    ListNode* slow = head;
    while(fast->next != NULL){
        slow=slow->next;
        fast=fast->next;
    }
    ListNode* delNode = slow->next;
    slow->next = delNode->next;
    delete delNode;
    return head;
}
