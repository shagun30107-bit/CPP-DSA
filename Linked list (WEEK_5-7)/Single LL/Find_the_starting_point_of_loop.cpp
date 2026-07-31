#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// By Hashing
//TC-O(2*N*logN)
//SC-O(N)
ListNode* METHOD1(ListNode* head){
    ListNode* temp = head;
    map<ListNode*,int> mpp;
    while(temp!= NULL){
        if ( mpp.find(temp) != mpp.end()) return temp;
        mpp[temp]=1;
        temp=temp->next;
    }
    return NULL;
}

//Tortoise and Hare
//TC-O(N) & SC-O(1)
ListNode* METHOD2(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast != NULL && fast->next != NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow == fast) {
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    return NULL;
}