#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

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

coordenadas posicoes[46];

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

void AlgDijkstra( Digraph G, Vertex s, Vertex parent[],
                   double dist[])
{
   Vertex v0, w, frj[maxV];
   link2 a; double c;
   initialize( G, s, parent, dist, frj);

   while (1) {
      double mindist = INFINITO;
      for (w = 0; w < G->V; w++)
         if (parent[w] == -1 && mindist > dist[w])
            mindist = dist[v0=w];
      if (mindist == INFINITO) break;
      parent[v0] = frj[v0];
      for (a = G->adj[v0]; a != NULL; a = a->next) {
         w = a->w, c = a->cost;
         if (parent[w] == -1 && dist[w] > dist[v0] + c) {
            dist[w] = dist[v0] + c;
            frj[w] = v0;
         }
      }
   }
}


void routeConstruct(Vertex w, Vertex pi[]){
   while(w != BASE){
          //printf("%\nh%d\n", w);
      al_draw_line(posicoes[w].x,posicoes[w].y, posicoes[pi[w]].x, posicoes[pi[w]].y, al_map_rgb(0,255,0),4);
      w = pi[w];

   }

}

void insereArestas(Digraph teste){
   DIGRAPHinsertA(teste, 1, 7, 120);
   DIGRAPHinsertA(teste, 1, 8, 120);
   
   DIGRAPHinsertA(teste, 2, 8, 120);
   DIGRAPHinsertA(teste, 2, 9, 120);
   
   DIGRAPHinsertA(teste, 3, 9, 120);
   DIGRAPHinsertA(teste, 3, 10, 130);
   
   DIGRAPHinsertA(teste, 4, 10, 130);
   
   DIGRAPHinsertA(teste, 5, 16, 240);
   DIGRAPHinsertA(teste, 5, 11, 130);
   
   DIGRAPHinsertA(teste, 6, 11, 130);
   DIGRAPHinsertA(teste, 6, 12, 120);
   
   DIGRAPHinsertA(teste, 7, 13, 110);
   
   DIGRAPHinsertA(teste, 8, 13, 110);
   DIGRAPHinsertA(teste, 8, 14, 130);
   
   DIGRAPHinsertA(teste, 9, 14, 120);
   DIGRAPHinsertA(teste, 9, 15, 140);
   
   DIGRAPHinsertA(teste, 10, 15, 120);
   DIGRAPHinsertA(teste, 10, 16, 150);
   
   DIGRAPHinsertA(teste, 11, 17, 120);
   
   DIGRAPHinsertA(teste, 12, 17, 120);
   
   DIGRAPHinsertA(teste, 13, 18, 120);
   DIGRAPHinsertA(teste, 13, 19, 140);
   
   DIGRAPHinsertA(teste, 14, 19, 120);
   DIGRAPHinsertA(teste, 14, 20, 140);
   
   DIGRAPHinsertA(teste, 15, 20, 120);
   DIGRAPHinsertA(teste, 15, 21, 140);
   
   DIGRAPHinsertA(teste, 16, 21, 110);
   DIGRAPHinsertA(teste, 16, 22, 120);
   
   DIGRAPHinsertA(teste, 17, 23, 120);
   DIGRAPHinsertA(teste, 17, 24, 120);
   
   DIGRAPHinsertA(teste, 18, 25, 130);
   
   DIGRAPHinsertA(teste, 19, 25, 120);
   DIGRAPHinsertA(teste, 19, 26, 75);
   DIGRAPHinsertA(teste, 19, 27, 140);
   
   DIGRAPHinsertA(teste, 20, 27, 110);
   DIGRAPHinsertA(teste, 20, 28, 140);
   
   DIGRAPHinsertA(teste, 21, 28, 110);
   DIGRAPHinsertA(teste, 21, 29, 120);
   
   DIGRAPHinsertA(teste, 22, 29, 120);
   DIGRAPHinsertA(teste, 22, 30, 110);
   
   DIGRAPHinsertA(teste, 23, 30, 120);
   DIGRAPHinsertA(teste, 23, 31, 110);
   
   DIGRAPHinsertA(teste, 24, 31, 120);
   
   DIGRAPHinsertA(teste, 25, 32, 120);
   DIGRAPHinsertA(teste, 25, 33, 75);
   DIGRAPHinsertA(teste, 25, 34, 140);
   
   DIGRAPHinsertA(teste, 26, 33, 110);
   DIGRAPHinsertA(teste, 26, 27, 57);
   
   DIGRAPHinsertA(teste, 27, 34, 120);
   DIGRAPHinsertA(teste, 27, 35, 150);
   
   DIGRAPHinsertA(teste, 28, 35, 130);
   DIGRAPHinsertA(teste, 28, 36, 120);
   
   DIGRAPHinsertA(teste, 29, 36, 120);
   DIGRAPHinsertA(teste, 29, 37, 120);
   
   DIGRAPHinsertA(teste, 30, 38, 130);
   DIGRAPHinsertA(teste, 30, 37, 120);
   
   DIGRAPHinsertA(teste, 31, 38, 120);
   DIGRAPHinsertA(teste, 31, 39, 120);
   
   DIGRAPHinsertA(teste, 32, 40, 140);
   
   DIGRAPHinsertA(teste, 33, 34, 63);
   
   DIGRAPHinsertA(teste, 34, 40, 120);
   DIGRAPHinsertA(teste, 34, 41, 140);
   
   DIGRAPHinsertA(teste, 35, 41, 130);
   DIGRAPHinsertA(teste, 35, 42, 120);
   
   DIGRAPHinsertA(teste, 36, 42, 100);
   DIGRAPHinsertA(teste, 36, 43, 130);
   
   DIGRAPHinsertA(teste, 37, 43, 130);
   DIGRAPHinsertA(teste, 37, 44, 110);
   
   DIGRAPHinsertA(teste, 38, 44, 120);
   DIGRAPHinsertA(teste, 38, 45, 120);
   
   DIGRAPHinsertA(teste, 39, 45, 110);

}