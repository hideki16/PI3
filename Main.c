#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "control.h"


int main(){

    int i;

    Digraph digraph = DIGRAPHinit(46);
    dmin = INT_MAX;

    insereArestas(digraph);
    inserePosicoes();
    AlgDijkstra(digraph, BASE, pi, a);

    if (!inicializar()){return -1;}

    limparTela();

    while(1){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {break;}
        if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            if (ev.mouse.x >= 1150 && ev.mouse.x <= 1250 && ev.mouse.y >= 450 && ev.mouse.y <= 500){construirRota2(3);}
            if (ev.mouse.x >= 1150 && ev.mouse.x <= 1250 && ev.mouse.y >= 530 && ev.mouse.y <= 580){limparTela();}
        }
        prevePontos(ev);
        marcaPontos(ev);
        al_flip_display();
    }
    destroy();
    return 0;
}


