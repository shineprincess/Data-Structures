#include <stdio.h>
#include<stdlib.h>

struct Graph *adjMatrixOfGraph();
struct Graph {
  int V;
  int E;
  int **Adj; //for 2 dim array
};

struct Graph* adjMatrixOfGraph() {
  int u, v, i; //u-> row , v-> col , i-> loop

  struct Graph *G;
  G = (struct Graph*) malloc(sizeof( struct Graph));
  // if(G) {
  //   printf("Memory Error");
  //   return;
  // }
  printf("Enter the number of nodes and number of edges");
  scanf("%d %d ",&G->V , &G->E);
  G->Adj = malloc(sizeof(int) * (G->V * G->V));

  for(u=0;u<G->V;u++) 
    for(v=0;v<G->V;v++) 
      G->Adj[u][v] = 0;

  printf("Enter node numbers in a pair that connects the edge");
  
  for(i=0;i<G->E;i++) {
    scanf("%d %d ",&u , &v);
    G->Adj[u][v] = 1; //Undirected Graph
    G->Adj[v][u] = 1;
  }
  return(G);
}

int main(void) {
  struct Graph *G;
  return 0;
}