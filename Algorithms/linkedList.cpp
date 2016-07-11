#include<bits/stdc++.h>
using namespace std;
struct node
{
	/* data */
	node* prev;
	int key;
	node* next;
};

void insert(node* head,node* newNode, int value){
	cout<<head<<endl;
	cout<<newNode<<endl;
	newNode->next = head;
	newNode->key = value;
	head->prev = newNode;
	head = newNode;
}
int main(){
	struct node* head;
	struct node* newNode;
	cout<<&head<<endl;
	insert(head, newNode,7);
	cout<<head->prev<<endl;
	// insert()
}