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
// METHOD-1 TC-O(2N) & SC-O(N)
    ListNode* reverseList1(ListNode* head) {
        if(head==NULL || head->next == NULL) return head;
        ListNode* temp = head;
        stack<int> st;
        while(temp != NULL){
            st.push(temp->val);
            temp=temp->next;
        }

        ListNode* temp1 = head;
        while(temp1 != NULL){
            temp1->val = st.top();
            st.pop();
            temp1=temp1->next;
        }
        return head;
    }

// METHOD-2
// TC-O(N) & SC-O(1)
    ListNode* reverseList2(ListNode* head) {
        if(head == NULL || head->next == NULL ) return head;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }

// METHOD-3
//TC-O(N) & SC-O(1) -->Recursive and iteration
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL ) return head;
        ListNode* temp = head;
        ListNode* newHead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }

};