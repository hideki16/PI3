#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include <stdio.h>
#include <stdbool.h>
#include "graph.h"

bool inicializar();
void desenhar(ALLEGRO_EVENT ev1, int q, int w);

const int LARGURA_TELA = 1100;
const int ALTURA_TELA = 648;

int i=0;
Vertex pi[46];

ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_BITMAP *imagem = NULL;

coordenadas posicoes[46];

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

int main()
{

    Digraph teste = DIGRAPHinit(46);


double a[46];

insereArestas(teste);

//coordenadas posicoes[46];
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
posicoes[39].y = 490;

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
AlgDijkstra(teste, 13, pi, a);
int i;
for(i = 1; i < 46; i++){
printf("%d ", pi[i]);
}
printf("\n");

for(i = 1; i < 46; i++){
   printf("%.f ",a[i]);
}
printf("\n");


    if (!inicializar())
    {
        return -1;
    }
al_clear_to_color(al_map_rgb(0, 0, 0));

   al_flip_display();
       while(1)
   {

al_draw_bitmap(imagem, 0,0,0);
      ALLEGRO_EVENT ev;
      al_wait_for_event(event_queue, &ev);

      if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
         break;
      }




      desenhar(ev, ev.mouse.x, ev.mouse.y);



   }

   al_destroy_display(janela);
   al_destroy_event_queue(event_queue);
   al_destroy_bitmap(imagem);

   return 0;
}

bool inicializar()
{
    if (!al_init())
    {
        fprintf(stderr, "Falha ao inicializar a biblioteca Allegro.\n");
        return false;
    }

    if (!al_init_primitives_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on de primitivas.\n");
        return false;
    }

    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela)
    {
        fprintf(stderr, "Falha ao criar janela.\n");
        return false;
    }

       if(!al_install_mouse()) {
      fprintf(stderr, "failed to initialize the mouse!\n");
      return -1;
   }

   event_queue = al_create_event_queue();
   if(!event_queue) {
      fprintf(stderr, "failed to create event_queue!\n");
      al_destroy_display(janela);
      return -1;
   }
    al_init_image_addon();

    imagem = al_load_bitmap("telafinal.png");
   al_register_event_source(event_queue, al_get_display_event_source(janela));
   al_register_event_source(event_queue, al_get_mouse_event_source());

    return true;
}

void posicao(int q, int w)
{
    printf("x:%d  y:%d  \n", q, w);
}

void desenhar(ALLEGRO_EVENT ev1, int q, int w)
{
    ALLEGRO_EVENT ev2;
      al_wait_for_event(event_queue, &ev2);
    if(ev1.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            posicao(ev2.mouse.x,ev2.mouse.y);
            //if(i < 5){
                i++;
                al_draw_filled_circle(ev2.mouse.x, ev2.mouse.y, 10, al_map_rgb(0, 0, 255));
                routeConstruct(45,pi);
                al_flip_display();
            //}
            /*else
            {
                al_flip_display();
            }*/
      }
}
