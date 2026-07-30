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
    // TC-> O((N1+N2)+(N1+N2+N3)+(N1+N2+N3+N4)+....) => ROUGHLY O(N^3)
    // SC-> O(1)
    ListNode* merge2Lists(ListNode* head1, ListNode* head2){
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;
        ListNode* dNode = new ListNode (0);
        ListNode* temp=dNode;
        while(temp1!=NULL && temp2 != NULL){
            if(temp1->val < temp2->val){
                temp->next=temp1;
                temp=temp1;
                temp1=temp1->next;
            }
            else{
                temp->next = temp2;
                temp=temp2;
                temp2=temp2->next;
            }
        }
        if(temp1 != NULL) temp->next=temp1;
        else temp->next=temp2;
        return dNode->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return {};
        ListNode* head = lists[0];
        for(int i=1 ; i< lists.size() ; i++){
            head= merge2Lists(head,lists[i]);
        }
        return head;
    }
};
    // METHOD-2
    // Min-heap -> it's data structure store the values and return the minimum
     // Create dummy Node->-1 assign as temp
    // I'll store <int,node> in the priority queue firstly store starting
    // node and value of all lists in queue then serch who is minimun then attach it to with temp
    // move temp and change the value which u used as next of this in list in the queue

    ListNode* mergeKLists1(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,
        vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for(int i=0 ; i< lists.size() ; i++){
            if(lists[i]){
                pq.push({lists[i]->val, lists[i]});
            }
        }
        ListNode* dNode= new ListNode (0);
        ListNode* temp = dNode;
        while(!pq.empty()){
            auto it=pq.top(); //mini one
            pq.pop();
            if(it.second ->next){
                pq.push({it.second->next->val, it.second->next});
            }
            temp->next= it.second;
            temp=temp->next;
        }
        return dNode->next;
    }
