#include "graph.h"
#include "init.h" 

int i=0, aux, dmin, xmin, ymin;
Vertex prox;
Vertex pi[46];

void desenhar(ALLEGRO_EVENT ev);
void marcaPontos(ALLEGRO_EVENT ev);
void desenharPonto(Vertex w);
void limparTela();

void posicao(int q, int w)
{
    printf("x:%d  y:%d  \n", q, w);
}

void desenhar(ALLEGRO_EVENT ev)
{
    if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                for(i = 1; i<= 45; i++){
                  ymin = ((ev.mouse.x - posicoes[i].x) * (ev.mouse.x - posicoes[i].x)) + ((ev.mouse.y - posicoes[i].y) * (ev.mouse.y - posicoes[i].y));

                  if(ymin < dmin){
                    dmin = ymin;
                    prox = i;
                  }
                }
                if(ev.mouse.x < 1100){
                  routeConstruct(prox,pi);
                  dmin = INT_MAX;
                }
    }
}

void desenharPonto(Vertex w)
{
        bool hasPoint = false;

        for(i = 0; i < numberOfPoints; i++)
        {
          if(points[i] == w){
            hasPoint = true;
            break;
          }
        }

        if(!hasPoint){
          points[numberOfPoints] = w;
          numberOfPoints++;
        }


       for(i = 0; i < numberOfPoints; i++)
       {
           printf("%d ", points[i]);
       }
       printf("\n");

}

void marcaPontos(ALLEGRO_EVENT ev){
    if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                for(i = 1; i<= 45; i++){
                  ymin = ((ev.mouse.x - posicoes[i].x) * (ev.mouse.x - posicoes[i].x)) + ((ev.mouse.y - posicoes[i].y) * (ev.mouse.y - posicoes[i].y));

                  if(ymin < dmin){
                    dmin = ymin;
                    prox = i;
                  }
                }
                if(ev.mouse.x < 1100){
                  al_draw_bitmap(icon, posicoes[prox].x- 10, posicoes[prox].y - 35,0);
                  desenharPonto(prox);
                  dmin = INT_MAX;
                }
    }
}

void limparTela()
{
numberOfPoints = 0;
 al_draw_bitmap(imagem, 0,0,0);
 al_draw_bitmap(icon, posicoes[BASE].x - 10, posicoes[BASE].y - 35,0);
}
