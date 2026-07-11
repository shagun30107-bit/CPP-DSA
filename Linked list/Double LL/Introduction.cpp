// In DLL u can move both the direction 
// We have node in which has data which point to next node as well as back node

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

Node* convertArr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1 ; i<arr.size();i++){
        Node* temp = new Node(arr[i] , nullptr , prev);
        prev->next = temp ;
        prev = temp;
    }
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

Node* deleteHead(Node* head){
    // To remove head from DLL
    // prev = head
    // head = head->next
    // head -> back = nullptr
    // prev-> next = nullptr
    // delete prev
    if(head==NULL || head -> next == NULL){
        return NULL;
    }
    Node* prev=head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
}

Node* deleteTail(Node* head){
    if(head==NULL || head -> next == NULL){
        return NULL;
    }
    Node* prev = head;
    while (prev->next->next != NULL){
        prev=prev->next;
    }
    Node* temp=prev->next;
    prev->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}

// prev->temp->front
Node* removeKthElement(Node* head, int k){
    if(head==NULL) return NULL;

    int cnt=0;
    Node* kNode = head;
    while(kNode != NULL){
        cnt++;
        if(cnt == k) break;
        kNode = kNode->next;
    }
    Node* prev = kNode->back;
    Node* front = kNode->next;

    if(prev==NULL && front == NULL){ //Means it has single element
        return NULL;
    }
    else if(prev == NULL) return deleteHead(head); //i.e ,it's head
    else if(front == NULL) return deleteHead(head); // delete tail

    prev->next = front;
    front->back = prev;

    kNode->next = nullptr;
    kNode->back = nullptr;
    delete kNode;
    return head;
}

//Delete the node of the DLL (constraint it never be head)
void deleteNode(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;

    if(front == NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return;
    }
    prev->next = front;
    front->back = prev;

    temp->next = temp->back = nullptr;
    free(temp);
}

//Insertion of Node
// Before the head, tail, kth, Node
Node* Insertbeforehead(Node* head, int val){
    Node* temp = new Node(val,head,nullptr);
    head->back = temp;
    return temp;
}

Node* Insertbeforetail(Node* head , int val){
    if(head->next == NULL){
        return Insertbeforehead(head, val);
    }
    Node* temp = head;
    while(temp->next->next != NULL){
        temp= temp->next;
    }
    Node* newtail = new Node(val,temp->next,temp);
    temp->next = newtail;
    return head;
}

//Insert before the kth element
Node* InsertKthelement(Node* head, int k, int val){
    if(head==NULL){
        if (k==1){
            return Insertbeforehead(head,val);
        }
        else return head;
    }
    if(k==1) return Insertbeforehead(head,val);
    int cnt=0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* newNode = new Node(val, temp , prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

//Insertion of Node (node never be head)
void insertbeforenode(Node* node , int val){
    Node* prev = node->back;
    Node* newNode = new Node(val, node , prev);
    prev->next = newNode;
    node->back = newNode;
}

int main(){
    vector<int> arr = {12,5,8,7};
    Node* head = convertArr2DLL(arr);
    
    print(Insertbeforetail(head,122));
    return 0;
}