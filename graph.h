#define Vertex int
#define INFINITO 100000
#define maxV 100
#define BASE 13

typedef struct node *link2;
struct node {
   Vertex w;
   double cost;
   link2 next;
};

struct digraph {
   int V;
   int A;
   link2 *adj;
};

typedef struct digraph *Digraph;

struct coord
{
   int x;
   int y;
};
typedef struct coord coordenadas;

link2 NEWnode( Vertex w, double cost, link2 next) {
   link2 a = malloc( sizeof (struct node));
   a->cost = cost;
   a->w = w;
   a->next = next;
   return a;
}


Digraph DIGRAPHinit( int V) {
   Vertex v;
   Digraph G = malloc( sizeof *G);
   G->V = V;
   G->A = 0;
   G->adj = malloc( V * sizeof (link2));
   for (v = 0; v < V; v++)
      G->adj[v] = NULL;
   return G;
}

void DIGRAPHinsertA( Digraph G, Vertex v, Vertex w, double cost) {
   link2 a;
   for (a = G->adj[v]; a != NULL; a = a->next)
      if (a->w == w) return;
   G->adj[v] = NEWnode( w, cost, G->adj[v]);
   G->adj[w] = NEWnode( v, cost, G->adj[w]);
   G->A += 2;
}


void showDigraph(Digraph G){
   link2 a;
   int v;
   for(v = 0; v < G->V; v++){
      printf("%d: ", v);
         for (a = G->adj[v]; a != NULL; a = a->next) {
         printf("%d(%.f) ", a->w, a->cost);
         }
         printf("\n");
         }
}



void initialize( Digraph G, Vertex s, Vertex parent[], double dist[], Vertex frj[])
{
   Vertex w; link2 a; double c;
   for (w = 0; w < G->V; w++) {
      parent[w] = -1;
      dist[w] = INFINITO;
   }
   parent[s] = s;
   dist[s] = 0.0;
   for (a = G->adj[s]; a != NULL; a = a->next) {
      w = a->w, c = a->cost;
      dist[w] = c;
      frj[w] = s;
   }
}