#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include "graph.h"

bool inicializar();
void desenhar(ALLEGRO_EVENT ev1, int q, int w);

const int LARGURA_TELA = 1100;
const int ALTURA_TELA = 648;

int i=0, aux, dmin, xmin, ymin;
Vertex prox;
Vertex pi[46];

ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_BITMAP *imagem = NULL;
ALLEGRO_BITMAP *icon = NULL;

int main(){

	Digraph teste = DIGRAPHinit(46);
	double a[46];
  dmin = INT_MAX;


	insereArestas(teste);
    inserePosicoes();
    AlgDijkstra(teste, BASE, pi, a);


int i;
for(i = 1; i < 46; i++){
printf("%d ", pi[i]);
}
printf("\n");

for(i = 1; i < 46; i++){
   printf("%.f ",a[i]);
}
printf("\n");


    if (!inicializar()){
        return -1;
    }

    al_draw_bitmap(imagem, 0,0,0);
    al_draw_bitmap(icon, posicoes[BASE].x - 10, posicoes[BASE].y - 35,0);
	al_flip_display();

    while(1){

      	ALLEGRO_EVENT ev;
      	al_wait_for_event(event_queue, &ev);

        al_draw_bitmap(imagem, 0,0,0);

      	if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
       	  break;
      	}

        desenhar(ev, ev.mouse.x, ev.mouse.y);
   }

   al_destroy_display(janela);
   al_destroy_event_queue(event_queue);
   al_destroy_bitmap(imagem);
   al_destroy_bitmap(icon);

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
    icon = al_load_bitmap("iconMapa.png");
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
    if(ev1.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            posicao(q,w);
                for(i = 1; i<= 45; i++){
                  ymin = ((ev1.mouse.x - posicoes[i].x) * (ev1.mouse.x - posicoes[i].x)) + ((ev1.mouse.y - posicoes[i].y) * (ev1.mouse.y - posicoes[i].y));

                  if(ymin < dmin){
                    dmin = ymin;
                    prox = i;
                  }
                }

                routeConstruct(prox,pi);
                al_draw_bitmap(icon, posicoes[prox].x- 10, posicoes[prox].y - 35,0);
                al_draw_bitmap(icon, posicoes[BASE].x - 10, posicoes[BASE].y - 35,0);
                al_flip_display();
                dmin = INT_MAX;
}
}

/*
for(i = 1 ; i < 46; i++)
                {
                    if(ev1.mouse.x > posicoes[i].x && ev1.mouse.x < posicoes[i+1].x)
                    {
                        if(ev1.mouse.x - posicoes[i].x < posicoes[i+1].x - ev1.mouse.x)
                        {
                            aux = i;
                            printf("no Teste");

                        }
                        else
                        {
                            printf("Teste");
                            aux = i+1;

                        }
                    }
                }
*/
