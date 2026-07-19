#include<bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
// METHOD-1
// TC-O(N*2*LOGN) & SC-O(N)
    bool hasCycle(ListNode *head) {
        map<ListNode* , int> mpp;
        ListNode* temp = head;
        while(temp != NULL){
            if(mpp.find(temp) != mpp.end()) return true;
            mpp[temp]=1;
            temp=temp->next;
        }
        return false;
    }

// Method-2
// Tortoise and Hare
// Move slow 1 step and fast 2 steps
// And at one time they overlap means (slow==fast) that ensures that their is a loop if it does not then not a Loop
// But why they overlap bcoz whenever u move slow anf fast pointer , distance b/w them reduces fast->slow
//So we are sure that it their is loop then slow and fast pointer must be overlap
    bool hasCycle1(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast != NULL && fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};