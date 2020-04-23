#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;	
class Node
{
    public:
        int data;
        Node *next;
        Node(int d){
            data=d;
            next=NULL;
        }
};
class Solution{
public:
	Node* removeDuplicates(Node *head){
		#if 0
		if(!head){
			return head;
		}

		Node *node = head;
		while(node->next){
			if(node->data == node->next->data){
				delete node->next;
				node->next = node->next->next;
			}
			else{
				node = node->next;
			}
		}
		return head;
		#endif
		
		Node *temp = head, *prevNode = head;
		vector<int> v;
		vector<int>::iterator itr = v.begin();
		
		if(NULL == head){return head;}

		while(NULL != temp){
			itr = find(v.begin(), v.end(), temp->data);
			if(itr != v.end()){//Found.
				prevNode->next = temp->next;
				delete temp;
				temp = prevNode->next;
			}
			else{
				v.push_back(temp->data);
				prevNode = temp;
				temp = temp->next;
			}
		}
		return head;
	}

	Node* insert(Node *head,int data)
	{
		Node* p=new Node(data);
		if(head==NULL){
			head=p;  
		}
		else if(head->next==NULL){
			head->next=p;
		}
		else{
			Node *start=head;
			while(start->next!=NULL){
				start=start->next;
			}
			start->next=p;
		}
		return head;
	}

	void display(Node *head)
	{
		Node *start=head;
		while(start)
		{
			cout<<start->data<<" ";
			start=start->next;
		}
	}
};

int main()
{
	Node* head=NULL;
  	Solution mylist;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        head=mylist.insert(head,data);
    }	
    head=mylist.removeDuplicates(head);

	mylist.display(head);		
}