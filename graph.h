#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#define Vertex int
#define INFINITO 100000
#define maxV 100
#define BASE 21

Vertex points[8];
int numberOfPoints = 0;

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


void calculaRotas(int numberOfPoints){

}

void insereArestas(Digraph digraph){
   DIGRAPHinsertA(digraph, 1, 7, 120);
   DIGRAPHinsertA(digraph, 1, 8, 120);
   
   DIGRAPHinsertA(digraph, 2, 8, 120);
   DIGRAPHinsertA(digraph, 2, 9, 120);
   
   DIGRAPHinsertA(digraph, 3, 9, 120);
   DIGRAPHinsertA(digraph, 3, 10, 130);
   
   DIGRAPHinsertA(digraph, 4, 10, 130);
   
   DIGRAPHinsertA(digraph, 5, 16, 240);
   DIGRAPHinsertA(digraph, 5, 11, 130);
   
   DIGRAPHinsertA(digraph, 6, 11, 130);
   DIGRAPHinsertA(digraph, 6, 12, 120);
   
   DIGRAPHinsertA(digraph, 7, 13, 110);
   
   DIGRAPHinsertA(digraph, 8, 13, 110);
   DIGRAPHinsertA(digraph, 8, 14, 130);
   
   DIGRAPHinsertA(digraph, 9, 14, 120);
   DIGRAPHinsertA(digraph, 9, 15, 140);
   
   DIGRAPHinsertA(digraph, 10, 15, 120);
   DIGRAPHinsertA(digraph, 10, 16, 150);
   
   DIGRAPHinsertA(digraph, 11, 17, 120);
   
   DIGRAPHinsertA(digraph, 12, 17, 120);
   
   DIGRAPHinsertA(digraph, 13, 18, 120);
   DIGRAPHinsertA(digraph, 13, 19, 140);
   
   DIGRAPHinsertA(digraph, 14, 19, 120);
   DIGRAPHinsertA(digraph, 14, 20, 140);
   
   DIGRAPHinsertA(digraph, 15, 20, 120);
   DIGRAPHinsertA(digraph, 15, 21, 140);
   
   DIGRAPHinsertA(digraph, 16, 21, 110);
   DIGRAPHinsertA(digraph, 16, 22, 120);
   
   DIGRAPHinsertA(digraph, 17, 23, 120);
   DIGRAPHinsertA(digraph, 17, 24, 120);
   
   DIGRAPHinsertA(digraph, 18, 25, 130);
   
   DIGRAPHinsertA(digraph, 19, 25, 120);
   DIGRAPHinsertA(digraph, 19, 26, 75);
   DIGRAPHinsertA(digraph, 19, 27, 140);
   
   DIGRAPHinsertA(digraph, 20, 27, 110);
   DIGRAPHinsertA(digraph, 20, 28, 140);
   
   DIGRAPHinsertA(digraph, 21, 28, 110);
   DIGRAPHinsertA(digraph, 21, 29, 120);
   
   DIGRAPHinsertA(digraph, 22, 29, 120);
   DIGRAPHinsertA(digraph, 22, 30, 110);
   
   DIGRAPHinsertA(digraph, 23, 30, 120);
   DIGRAPHinsertA(digraph, 23, 31, 110);
   
   DIGRAPHinsertA(digraph, 24, 31, 120);
   
   DIGRAPHinsertA(digraph, 25, 32, 120);
   DIGRAPHinsertA(digraph, 25, 33, 75);
   DIGRAPHinsertA(digraph, 25, 34, 140);
   
   DIGRAPHinsertA(digraph, 26, 33, 110);
   DIGRAPHinsertA(digraph, 26, 27, 57);
   
   DIGRAPHinsertA(digraph, 27, 34, 120);
   DIGRAPHinsertA(digraph, 27, 35, 150);
   
   DIGRAPHinsertA(digraph, 28, 35, 130);
   DIGRAPHinsertA(digraph, 28, 36, 120);
   
   DIGRAPHinsertA(digraph, 29, 36, 120);
   DIGRAPHinsertA(digraph, 29, 37, 120);
   
   DIGRAPHinsertA(digraph, 30, 38, 130);
   DIGRAPHinsertA(digraph, 30, 37, 120);
   
   DIGRAPHinsertA(digraph, 31, 38, 120);
   DIGRAPHinsertA(digraph, 31, 39, 120);
   
   DIGRAPHinsertA(digraph, 32, 40, 140);
   
   DIGRAPHinsertA(digraph, 33, 34, 63);
   
   DIGRAPHinsertA(digraph, 34, 40, 120);
   DIGRAPHinsertA(digraph, 34, 41, 140);
   
   DIGRAPHinsertA(digraph, 35, 41, 130);
   DIGRAPHinsertA(digraph, 35, 42, 120);
   
   DIGRAPHinsertA(digraph, 36, 42, 100);
   DIGRAPHinsertA(digraph, 36, 43, 130);
   
   DIGRAPHinsertA(digraph, 37, 43, 130);
   DIGRAPHinsertA(digraph, 37, 44, 110);
   
   DIGRAPHinsertA(digraph, 38, 44, 120);
   DIGRAPHinsertA(digraph, 38, 45, 120);
   
   DIGRAPHinsertA(digraph, 39, 45, 110);

}

void inserePosicoes(){
posicoes[1].x = 70;
posicoes[1].y = 67;
posicoes[2].x = 244;
posicoes[2].y = 52;
posicoes[3].x = 434;
posicoes[3].y = 56;
posicoes[4].x = 619;
posicoes[4].y = 55;
posicoes[5].x = 815;
posicoes[5].y = 67;
posicoes[6].x = 989;
posicoes[6].y = 58;

posicoes[7].x = -5;
posicoes[7].y = 160;
posicoes[8].x = 162;
posicoes[8].y = 149;
posicoes[9].x = 352;
posicoes[9].y = 147;
posicoes[10].x = 541;
posicoes[10].y = 150;
posicoes[11].x = 912;
posicoes[11].y = 152;
posicoes[12].x = 1082;
posicoes[12].y = 138;

posicoes[13].x = 81;
posicoes[13].y = 239;
posicoes[14].x = 270;
posicoes[14].y = 239;
posicoes[15].x = 462;
posicoes[15].y = 243;
//aqui ^
posicoes[16].x = 655;
posicoes[16].y = 251;
posicoes[17].x = 1002;
posicoes[17].y = 234;

posicoes[18].x = 5;
posicoes[18].y = 332;
posicoes[19].x = 190;
posicoes[19].y = 332;
posicoes[20].x = 380;
posicoes[20].y = 337;
posicoes[21].x = 578;
posicoes[21].y = 346;
posicoes[22].x = 751;
posicoes[22].y = 340;
posicoes[23].x = 924;
posicoes[23].y = 325;
posicoes[24].x = 1094;
posicoes[24].y = 315;

posicoes[25].x = 111;
posicoes[25].y = 426;
posicoes[26].x = 252;
posicoes[26].y = 385;
posicoes[27].x = 301;
posicoes[27].y = 426;
posicoes[28].x = 495;
posicoes[28].y = 436;
posicoes[29].x = 675;
posicoes[29].y = 432;
posicoes[30].x = 836;
posicoes[30].y = 413;
posicoes[31].x = 1015;
posicoes[31].y = 406;

posicoes[32].x = 32;
posicoes[32].y = 519;
posicoes[33].x = 170;
posicoes[33].y = 477;
posicoes[34].x = 221;
posicoes[34].y = 522;
posicoes[35].x = 417;
posicoes[35].y = 530;
posicoes[36].x = 589;
posicoes[36].y = 520;
posicoes[37].x = 753;
posicoes[37].y = 508;
posicoes[38].x = 936;
posicoes[38].y = 500;
posicoes[39].x = 1098;
posicoes[39].y = 480;

posicoes[40].x = 140;
posicoes[40].y = 612;
posicoes[41].x = 338;
posicoes[41].y = 626;
posicoes[42].x = 517;
posicoes[42].y = 618;
posicoes[43].x = 684;
posicoes[43].y = 604;
posicoes[44].x = 854;
posicoes[44].y = 588;
posicoes[45].x = 1030;
posicoes[45].y = 578;
}