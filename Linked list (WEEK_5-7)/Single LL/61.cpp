#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || head == NULL) return head;
        ListNode* tail = head;
        int len=1;
        while(tail->next != NULL){
            len++;
            tail=tail->next;
        }
        if( k%len == 0) return head;
        k=k%len;
        tail->next=head;
        ListNode* last=head;
        int n=len-k-1;
        for(int i=0 ; i<n ; i++){
            last=last->next;
        }
        head=last->next;
        last->next=NULL;
        return head;
    }