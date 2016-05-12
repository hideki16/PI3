#include <stdio.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include "control.h"


int main(){
    double a[46];
    int i;
    
    Digraph teste = DIGRAPHinit(46);
    dmin = INT_MAX;
    
    insereArestas(teste);
    inserePosicoes();
    AlgDijkstra(teste, BASE, pi, a);
    
    
    for(i = 1; i < 46; i++){
        printf("%d ", pi[i]);
    }
    printf("\n");
    
    for(i = 1; i < 46; i++){
       printf("%.f ",a[i]);
    }
    printf("\n");
    
    if (!inicializar()){return -1;}
    
    al_clear_to_color(al_map_rgb(250,250,250));
    al_draw_rectangle(1150, 500, 1250, 450, al_map_rgb(1, 1, 1), 1);
    al_draw_rectangle(1150, 580, 1250, 530, al_map_rgb(1, 1, 1), 1);
    al_draw_bitmap(imagem, 0,0,0);
    al_draw_bitmap(icon, posicoes[BASE].x - 10, posicoes[BASE].y - 35,0);
    al_flip_display();
    
    while(1){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        
        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {break;}
        if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            if (ev.mouse.x >= 1150 && ev.mouse.x <= 1250 && ev.mouse.y >= 450 && ev.mouse.y <= 500){desenhar(ev);}
            if (ev.mouse.x >= 1150 && ev.mouse.x <= 1250 && ev.mouse.y >= 530 && ev.mouse.y <= 580){limparTela();}
        }
        marcaPontos(ev);
        al_flip_display();
    }
    destroy();
    return 0;
}
