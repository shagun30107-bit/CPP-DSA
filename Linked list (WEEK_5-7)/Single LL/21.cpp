#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
//brute solution
class Solution {
public:
    ListNode* convertArr2LL(vector<int> &arr){
    ListNode* head = new ListNode(arr[0]);
    ListNode* mover = head;
    for(int i=1; i<arr.size() ; i++){
        ListNode* temp = new ListNode(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL && list2 == NULL) return NULL;

        vector<int> arr;
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        while (temp1 != NULL) {
            arr.push_back(temp1->val);
            temp1=temp1->next;
        }
        while(temp2 != NULL){
            arr.push_back(temp2->val);
            temp2=temp2->next;
        }
        sort(arr.begin(),arr.end());
        ListNode* head= convertArr2LL(arr);
        return head;
    }
};
//Optimal solution
    ListNode* mergeTwoLists2(ListNode* list1, ListNode* list2) {
        //TC-O(N1+N2)--TWO POINTERS APPROACH
        ListNode* temp1= list1;
        ListNode* temp2= list2;
        ListNode* dNode = new ListNode (-1);
        ListNode* temp = dNode;
        while(temp1 != NULL && temp2 != NULL){
            if(temp1->val < temp2->val) {
            temp->next = temp1;
            temp=temp1;
            temp1 = temp1->next;
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