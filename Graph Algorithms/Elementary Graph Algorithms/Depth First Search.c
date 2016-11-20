/*
This is a demo example input :- 
First line represents the no.of inputs and the alternate lines there after represents the no of edges and the corresponding edges

4
2
1 2
1
2
2
0 3
1
3

*/
#include<stdio.h>
#include<malloc.h>          
typedef struct graph
{
	int vertex;
	struct graph *next;
}node;
node *topo = NULL;

// create a adjacency list for the graph 
void createGraph(node *adjacent[],int n)
{
	int i = 0;
	for(i = 0;i < n;i++)
	{
		adjacent[i] = NULL;
	}
}
// display the adjacency list
void display(node *adjacent[],int n)
{
	node *p = NULL;
	int i = 0;
	for(i = 0;i < n;i++)
	{
		p = adjacent[i];
		printf("Vertex %d : ",i);
		if(p == NULL)
			printf("Empty");
		while(p != NULL)
		{
			printf("%d -> ",p->vertex);
			p = p->next;
		}
		printf("\n");
	}
}
// insert a node at the end of the linked list
void insertend(node **head,int data)
{
	node *p = NULL, *temp = NULL;
	p = (node *)malloc(sizeof(node));

	p->vertex = data;
	p->next = NULL;

	if(*head == NULL)
	{
		*head = p;
		return;
	}
	for(temp = *head;temp->next != NULL; temp = temp->next);

	temp->next = p;
}
// insert elements to the adjacency list
void insert(node *adjacent[],int n)
{
	int i = 0,j = 0,num = 0,item = 0;
	node *p = NULL,*temp = NULL;
	for(i = 0;i < n;i++)
	{
		printf("Enter the no of edges and then the edge(s) for vertex %d respectively: ",i);
		scanf("%d",&num);
		for(j = 0;j < num;j++)
		{
			scanf("%d",&item);
			insertend(&adjacent[i],item);
		}
	}
}
// function to visit each unvisited neighbour vertice
void DFS_Visit(node *adjacent[],int visited[],int v,int n)
{
	int i = 0;
	node *p = NULL;
	p = adjacent[i];
	visited[v] = 1;
	printf("%d\t",v);
	//to visit the adjoining vertics or neighbours of v
	while(p != NULL)
  	{
       i = p->vertex;
       if(visited[i] == 0)
	   {
			DFS_Visit(adjacent,visited,i,n);
	   }
		p = p->next;
    }
}
// will visit all the vertices and call DFS_Visit for a vertex if it is unvisited
void DFS(node *adjacent[],int visited[],int n)
{
	int i = 0;
	for(i = 0;i < n;i++)
	{
		if(visited[i] == 0)
		{
			DFS_Visit(adjacent,visited,i,n);
		}
	}
}
int main(void)
{
	int n = 0,i = 0;
	printf("Enter the no of vertices : ");
	scanf("%d",&n);
	int visited[n];
	node *adjacent[n],*head = NULL;
	
	createGraph(adjacent,n);
	insert(adjacent,n);
	
	for(i = 0;i < n;i++)
	{
		visited[i] = 0;
	}
	
	printf("\nThe DFS graph traversal ordering is : \n");
	DFS(adjacent,visited,n);
	return 0;
}
