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

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
};

Node* removesHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;

}

Node* removesTail(Node* head){
    Node* temp =head;
    if(head == NULL || head->next == NULL) return NULL ;
    while(temp->next->next != NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

void print(Node* head){
    while(head != NULL){
    cout << head->data << " ";
    head = head -> next;
    }
    cout << endl;
}

Node* deleteK(Node* head , int k){
    if(head==NULL) return head; // Edge case
    if(k==1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int cnt=0;
    Node* temp= head;
    Node* prev = NULL;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}

Node* deleteel(Node* head , int el){
    if(head==NULL) return head; // Edge case
    if(head->data == el){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp= head;
    Node* prev = NULL;
    while(temp != NULL){ 
        if(temp->data == el){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}

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

Node* Inserthead(Node* head , int el){
    Node* temp = new Node(el,head);
    return temp;
}

Node* Inserttail(Node* head , int el){
    if(head == NULL){
        return new Node(el);
    }
    Node* temp = head;
    while(temp-> next != NULL){
        temp=temp->next;
    }
    Node* newNode = new Node(el);
    temp->next = newNode;
    return head;
}

Node* insertPosition(Node* head , int el , int k){
    if(head == NULL){
        if(k==1) return new Node(el);
        else return head;
    }
    if(k==1){
        Node*temp = new Node (el,head);
        return temp;
    }
    int cnt=0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k-1){
            Node* x= new Node(el,temp->next);
            // Node* x= new Node(el);
            // x-> next = temp->next;
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node* insertBeforeValue(Node* head , int el , int val){
    if(head == NULL){
        return NULL;
    }
    if(head->data == val){
        Node*temp = new Node (el,head);
        return temp;
    }
    Node* temp = head;
    while(temp->next != NULL){
        if(temp->next->data == val){
            Node* x= new Node(el,temp->next);
            // Node* x= new Node(el);
            // x-> next = temp->next;
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {2,5,8,7};
    Node* head = convertArr2LL(arr);
    head = Inserthead(head,8);
    print(head);
}
