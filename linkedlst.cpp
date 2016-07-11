#include<iostream>
#include<malloc.h>
using namespace std; 
struct Node{
	int info;
	Node* link;
}start;
//Node* Start = (Node*)malloc(sizeof(Node*));
void creatList(){
	int n,item,i; Node* ptr ;
	Node* tmp = (Node*)malloc(sizeof(Node*));
	   
	cin>>n;
	for(i = 0; i < n; i ++)
	{
		cin>>item;
		Node* tmp = (Node*)malloc(sizeof(Node*));
		ptr->link = tmp;
		tmp->info = item;
		ptr = tmp;
	}
}
int main()
{
	creatList();
	return 0;
}
