#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1){
        data= data1;
        next=nullptr;
    }
};

//Method-1
//count the 0s,1s,and 2s
//then replace data with that
//TC-O(2N) & SC-O(1)

Node* mwthod1(Node* head){
    Node* temp = head;
    int cnt0=0;
    int cnt1=0;
    int cnt2=0;
    while(temp!=NULL){
        if(temp->data == 0) cnt0++;
        else if(temp->data == 1) cnt1++;
        else cnt2++;
        temp=temp->next;
    }
    Node* temp = head;
    while(temp != NULL){
        if(cnt0) {
            temp->data=0;
            cnt0--;
        }
        else if(cnt1) {
            temp->data=1;
            cnt1--;
        }
        else {
            temp->data=2;
            cnt2--;
        }
        temp=temp->next;
    }
    return head;
}


// TC=O(N) & SC-O(1)
Node* method2(Node* head){
    if(head == NULL || head->next == NULL) return head;

    Node* zerohead = new Node(-1);
    Node* onehead = new Node(-1);
    Node* twohead = new Node(-1);

    Node* zero = zerohead;
    Node* one= onehead;
    Node* two = twohead;
    Node* temp = head;

    while(temp != NULL){
        if(temp->data == 0){
            zero->next = temp;
            zero = zero->next;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = one->next;
        }
        else{
            two->next = two;
            two = two->next;
        }
        temp=temp->next;
    }
    // if(onehead->next){
    //     zero->next = onehead->next;
    // }
    // else zero->next = twohead->next;
    zero->next = (onehead->next) ? (onehead->next) : (twohead->next);
    one->next = twohead->next;
    two->next=NULL;

    Node* newhead= zerohead->next;

    delete zerohead;
    delete onehead;
    delete twohead;
    return newhead;
}
