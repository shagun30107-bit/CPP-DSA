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

// METHOD-1(TC-O(2*N) & SC-O(N))
    bool isPalindrome(ListNode* head) {
        if(head==NULL && head->next ==NULL) return true;
        stack<int>st;
        ListNode* temp = head;
        while(temp != NULL){
            st.push(temp->val);
            temp=temp->next;
        }
        ListNode* tem = head;
        while(tem !=NULL){
            if(st.top() != tem->val) return false;
            st.pop();
            tem = tem->next;
        }
        return true;   
    }

// METHOD-2
// TC-O(2*N) & SC-O(1)
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next == NULL) return head;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev=temp;
            temp = front;
        }
        return prev;
    }

    ListNode* mid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        ListNode* midH = reverse( mid(head));
        while(midH != NULL){
            if(temp->val != midH->val) return false;
            temp=temp->next;
            midH=midH->next;
        }
        return true;
    }

};