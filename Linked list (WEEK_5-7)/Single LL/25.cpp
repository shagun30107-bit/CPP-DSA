#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Intuition- First find the kth node , & then store it's next node and point it's next node to null so that
//u can reverse it easily
// LL head should be the your kth node so write condition for that as well then
// point all the nodes into correct position prev node ,temp ,nextnode when kthnode==NULL
// your function should be break...
class Solution {
public:
//TC-O(2N)
    void Reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev=temp;
            temp=front;
        }
    }

    ListNode* getKthNode(ListNode* head, int k){
        k-=1;
        ListNode* temp = head;
        while(temp != NULL && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp!=NULL){
            ListNode* KthNode = getKthNode(temp,k);
            if(KthNode==NULL){
                if(prev) prev->next=temp;
                break;
            }

            ListNode* Next = KthNode->next;
            KthNode->next = NULL;
            Reverse(temp);
            if(temp==head) head=KthNode;
            else{
                prev->next = KthNode;
            }

            prev = temp;
            temp = Next;
        }
        return head;
    }
};