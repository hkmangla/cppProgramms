#include<iostream>
using namespace std;
#define mod 1000000007
long long int fib[200000];
void build_fibonaci()
{
	fib[0]=1;fib[1]=1;fib[2]=1;
	for(int i=3;i<200000-2;i++)
	{
	fib[i]=fib[i-1]+fib[i-2];
	fib[i]%=mod;
	}
}
// A C Program to demonstrate adjacency list representation of graphs
 
#include <stdio.h>
#include <stdlib.h>
 
// A structure to represent an adjacency list node
struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};
 
// A structure to represent an adjacency list
struct AdjList
{
    struct AdjListNode *head;  // pointer to head node of list
};
 
// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
struct Graph
{
    int V;
    struct AdjList* array;
};
 
// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* newNode =
            (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
 
// A utility function that creates a graph of V vertices
struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
 
    // Create an array of adjacency lists.  Size of array will be V
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
 
     // Initialize each adjacency list as empty by making head as NULL
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}
 
// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest)
{
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
 
    // Since graph is undirected, add an edge from dest to src also
 //   newNode = newAdjListNode(src);
  //  newNode->next = graph->array[dest].head;
//    graph->array[dest].head = newNode;
}
// print the adjacenncy list representation of graph
void printGraph(struct Graph* graph)
{
    int v;
    for (v = 1; v <= graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}
int main()
{
	int n,m;
	cin>>n>>m;
	struct Graph* tree=createGraph(n);
	for(int i=1;i<n;i++)
	{int x;
		cin>>x;
		addEdge(tree,x,i+1);
	}
	printGraph(tree);
	
	return 0;
}
