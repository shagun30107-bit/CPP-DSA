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


// Method-1
// We will take stack data structure (LIFO)
// keep the temp variable at head move it and push into the stack [1st iteration]
// Again take temp variable at head and replace it's value from the stack [2nd iteration]
// U'll get reverse SLL in terms of Data

// TC-O(2*N)
// SC-O(N)
Node* reverseDLL1(Node* head){
    Node* temp = head;
    stack<int> st;
    while(temp != NULL){
        st.push(temp->data);
        temp=temp->next;
    }

    Node* temp= head;
    while(temp != NULL){
        temp->data = st.top();
        st.pop();
        temp=temp->next;   
    }
    return head;
}

// Method-2
// Reverse DLL in the terms of links

// Same as swapping of two numbers 
// let;s say swap a and b-->
// temp = a
// a=b;
// b= temp;

// TC-O(N) & SC-O(1)
Node* reverseDLL2(Node* head){
    if(head==NULL || head->next == NULL){
        return NULL;
    }
    Node* prev= NULL;
    Node* current = head;
    while(current != NULL){
        prev = current -> back;
        current->back = current->next;
        current->next = prev;
        current = current -> back;
    }
    return prev->back; //it's now our new head
}

