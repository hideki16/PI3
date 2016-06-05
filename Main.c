#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "control.h"


int main(){

    int i;
    dmin = INT_MAX;

    /*Digraph digraph = DIGRAPHinit(46);
    insereArestas(digraph);
    inserePosicoes();
    AlgDijkstra(digraph, BASE, pi, a);*/

    construirGrafo();

    if (!inicializar()){return -1;}

    limparTela();

    while(1){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {break;}

        if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            if (ev.mouse.x >= 1110 && ev.mouse.x <= 1290 && ev.mouse.y >= 280 && ev.mouse.y <= 370){
                construirRota2(numCiclistas);
                calculouRota = true;
            }
            if (ev.mouse.x >= 1110 && ev.mouse.x <= 1290 && ev.mouse.y >= 380 && ev.mouse.y <= 470){
                limparTela();
                numCiclistas = 1;
                calculouRota = false;
            }
        }

        if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            if(!calculouRota){
                if (ev.mouse.x >= 1255 && ev.mouse.x <= 1285 && ev.mouse.y >= 190 && ev.mouse.y <= 210){
                numCiclistas++;
                if(numCiclistas > 8){numCiclistas = 8;}

                }
                if (ev.mouse.x >= 1255 && ev.mouse.x <= 1285 && ev.mouse.y >= 245 && ev.mouse.y <= 265){
                    numCiclistas--;
                if(numCiclistas < 1) {numCiclistas = 1;}
                }
            }
        }

        if(!calculouRota){
            prevePontos(ev);
        }

        marcaPontos(ev);
        al_flip_display();
    }
    destroy();
    return 0;
}

/*
al_draw_bitmap(botao3, 1110, 180,0);
al_draw_bitmap(botao, 1110, 280,0);
al_draw_bitmap(botao2, 1110, 380,0);

al_draw_textf(font, al_map_rgb(0,0,0), 1260, 217, 0, "%d", numCiclistas);
        al_draw_rectangle(1255, 190, 1285, 210, al_map_rgb(1, 1, 1), 1);
        al_draw_rectangle(1255, 245, 1285, 265, al_map_rgb(1, 1, 1), 1);
*/

