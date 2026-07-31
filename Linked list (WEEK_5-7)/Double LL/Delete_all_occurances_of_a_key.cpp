#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

//TC-O(N) & SC-O(1)
Node* Delete(Node* head, int key){
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == key){
            //if this is the  head of the DLL
            //Then post deletion the head will be updated
            if(temp==head) head=temp->next;
            Node* front = temp->next;
            Node* prev = temp->back;
            
            if(front != NULL)front->back = prev;
            if(prev != NULL) prev->next = front;
            delete temp;
            temp = front;
        }
        else {
            temp=temp->next;
        }
    }
    return head;
}