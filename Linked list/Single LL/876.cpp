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

    int length(ListNode* head){
        ListNode* temp = head;
        int cnt=0;
        while(temp != NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
// METHOD-1(TC-O(N+N/2) & SC-O(N)) 
    ListNode* middleNode(ListNode* head) {
        int mid= length(head)/2 ;
        ListNode* temp= head;
        while(mid--){
            temp=temp->next;
        }
        return temp;
    }

// METHOD-2(TORTOISE AND HARE)
//slow pointer moves one step while fast pointer moves 2 step
// for even length fast is equal to NULL in the last
// and for odd length fast points to last element

    ListNode* middleNode1(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast != NULL && fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
};