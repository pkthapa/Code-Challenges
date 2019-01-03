#include <iostream>
 
class Node{
        int data;
        Node *next;
    public:
        Node(){}//!! Default constructor.
        Node(int data){ //!! Parametrized constructor.
            this->data = data;
            next = NULL;
        }
        Node *CreateNode(int);
        void InsertNode(int);
        void ViewNodes();
        void DeleteNode(int);
        Node *head = NULL;
};
 
//!! Deleting a node.
void Node :: DeleteNode(int nodeOffset /*Node offset to be delete*/){
    Node *temp1 = head, *temp2 = NULL;
    int ListLen = 0;
     
    if(NULL == head){
        std::cout<<"List empty."<<std::endl;
        return;
    }
     
    while(NULL != temp1){
        temp1 = temp1->next;
        ListLen++; //!! Length of the linked-list.
    }
     
    if(ListLen < nodeOffset){ //!! Check if the nodeoffset to be deleted is less than the length of the linked-list.
        std::cout<<"Error: Illegal deletion."<<std::endl;
        return;
    }
     
    temp1 = head; //!! Resetting.
    if(1 == nodeOffset){ //!! Deleting 1st node.
        head = head->next;
        delete temp1;
        return;
    }
     
    while(nodeOffset-- > 1){
        temp2 = temp1;
        temp1 = temp1->next;//!! This will contain the address to be deleted.
    }
    temp2->next = temp1->next;
    delete temp1;
}
 
//!! Creating a new node.
Node *Node :: CreateNode(int data){
    return new Node(data); //!! Parametrized constructor called.
}
 
//!! Insert a new node.
void Node :: InsertNode(int data){
    Node *newNode = CreateNode(data), *temp = head;
     
    if(NULL == head){
        head = newNode;
        return;
    }
     
    while(NULL != temp->next){
        temp = temp->next;
    }
    temp->next = newNode;
}
 
void Node :: ViewNodes(){
    Node *temp = head;
    if(NULL == head){
        std::cout<<"List empty"<<std::endl;
        return;
    }
    while(NULL != temp){
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
}
 
//!! Driver code to run the above implementation.
int main(){
    Node n, m; //!! Default constructors called.

    m.ViewNodes(); //!! This will give "List empty" output.

    n.InsertNode(1);
    n.InsertNode(2);
    n.InsertNode(3);
    n.InsertNode(4);
    n.ViewNodes(); //!! This will print "1 2 3 4" in output.
    
    std::cout<<std::endl;
    n.DeleteNode(2);
    n.ViewNodes(); //!! This will print "1 3 4" in output.
    return 0;
}
