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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1 != temp2){
            if(temp1!=NULL) temp1=temp1->next;
            else temp1=headB;
            if(temp2!=NULL) temp2=temp2->next;
            else temp2=headA;
        }
        return temp1;
    }
};