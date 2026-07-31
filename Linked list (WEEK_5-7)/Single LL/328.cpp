// Odd & even LL
// Method - 1
// By using list 
// 1->3->4->2->5->6
// assign temp = head and jump by one place adn store the vslue in a list 
// L=[1,4,5]
// Again iterate as temp = head->next adn just put in a list
// L=[1,4,5,2,5,6]
// Final step iterate over LL and list at the same time and replace the data

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//TC-O(2N) & SC-O(N)
ListNode* Oddeven(ListNode* head){
    //edge cases
    if(head == NULL || head->next == NULL) return head;
    vector<int> arr;
    ListNode* temp = head;
    while(temp != NULL && temp->next ==NULL){
        arr.push_back(temp->val);
        temp = temp->next->next;
    }
    if(temp) arr.push_back(temp->val);

    ListNode* temp = head->next;
    while(temp != NULL && temp->next ==NULL){
        arr.push_back(temp->val);
        temp = temp->next->next;
    }
    if(temp) arr.push_back(temp->val);

    int i=0;
    ListNode* temp = head;
    while(temp != NULL){
        temp->val = arr[i];
        i++;
        temp = temp-> next;
    }
    return head;
}

// Method-2(By changing Linkedlist)
// Remember evenHead in the memory to point in the last with odd
// TC-O(N/2)*2--> You r doing 2 steps in while loop & SC-O()

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next == NULL) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenhead = head->next;
        while(even != NULL && even-> next != NULL){
            odd->next = odd->next->next;
            even->next = even->next-> next;

            odd = odd->next;
            even= even->next;
        }
        odd->next= evenhead;
        return head;
    }
};