// Array has fixed size it cannot increase or decrease the size
// that's why Linked list come
// Linked list is similar data structure as array but it can inc or dec it's size
// LL not in contigous location
// Starting element of LL is head of the LL
// Last element called tail of the LL
// Head point to the next element , next element point to the next and so on and the tail elemnt points to the null element

// Where is it used ?
//Browser,reels

//struct uses public inheritance by default, while class uses private inheritance by default.
// Here struct and class works same 
// but good habit to use class

// Difference between node and node*
// Node is an object & Access members using the . operator.(x.data or x.next)
// Node* is a pointer that stores the address of a Node.
// Access members using the -> operator.
// We always use Node* because nodes are connected by pointers, and the head of the list is also a pointer

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

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size() ; i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int lengthOfLL(Node* head){
    int cnt=0;
    Node* temp = head;
    while(temp){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int checkIfpresent(Node* head , int val){
    Node* temp = head;
    while(temp){
        if(temp->data == val) return 1;
        temp = temp->next;
    }
    return 0;
}

int main(){
    vector<int> arr = {2,5,8,7};
    // Node* y = new Node(arr[0] , nullptr);
    // cout << y->data ; 
    Node* head = convertArr2LL(arr);
    // cout << head->data;
    // Traverse
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
