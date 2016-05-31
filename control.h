#include "graph.h"
#include "init.h"

int i=0, aux, dmin, dmin2, xmin, ymin, ymin2,j;
bool routeOn = false, calculouRota = false;
Vertex prox;
Vertex prox2;
int pi[46];
double a[46];
Vertex points[8][2];
int numberOfPoints = 0;
int parentDistante[46];
int numVertices = 0;
int pointsLeft = 0;
int numCiclistas = 0;


void desenhar(ALLEGRO_EVENT ev);
void marcaPontos(ALLEGRO_EVENT ev);
void desenharPonto(Vertex w);
void construirRota();
void construirRota2();
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
          if(points[i][0] == w){
            hasPoint = true;
            break;
          }
        }

        if(!hasPoint){
          points[numberOfPoints][0] = w;
          points[numberOfPoints][1] = 0;
          numberOfPoints++;
        }


       for(i = 0; i < numberOfPoints; i++)
       {
           printf("%d(%d) ", points[i][0], points[i][1]);
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

void prevePontos(ALLEGRO_EVENT ev){
    if(ev.type == ALLEGRO_EVENT_MOUSE_AXES) {
    	for(i = 1; i<= 45; i++){
	    	ymin2 = ((ev.mouse.x - posicoes[i].x) * (ev.mouse.x - posicoes[i].x)) + ((ev.mouse.y - posicoes[i].y) * (ev.mouse.y - posicoes[i].y));

    	 	if(ymin2 < dmin2){
    	        dmin2 = ymin2;
    	        prox2 = i;
    	    }
    	}
	}
  al_clear_to_color(al_map_rgb(250,250,250));
        al_draw_rectangle(1150, 500, 1250, 450, al_map_rgb(1, 1, 1), 1);
        al_draw_rectangle(1150, 580, 1250, 530, al_map_rgb(1, 1, 1), 1);
        al_draw_bitmap(imagem, 0,0,0);
        al_draw_bitmap(icon, posicoes[BASE].x - 10, posicoes[BASE].y - 35,0);
        al_draw_textf(font, al_map_rgb(0,0,0), 1200, 100, 0, "%d", numCiclistas);
        al_draw_rectangle(1195, 95, 1220, 85, al_map_rgb(1, 1, 1), 1);
        al_draw_rectangle(1195, 140, 1220, 130, al_map_rgb(1, 1, 1), 1);
        al_flip_display();


        if(routeOn){construirRota2();}

        for(j = 0; j < numberOfPoints; j++){
          al_draw_bitmap(icon, posicoes[points[j][0]].x- 10, posicoes[points[j][0]].y - 35,0);
        }

        al_draw_bitmap(icon2, posicoes[prox2].x- 10, posicoes[prox2].y - 35,0);
        dmin2 = INT_MAX;
}

void limparTela()
{
    routeOn = false;
    numberOfPoints = 0;
    al_clear_to_color(al_map_rgb(250,250,250));
    al_draw_rectangle(1150, 500, 1250, 450, al_map_rgb(1, 1, 1), 1);
    al_draw_rectangle(1150, 580, 1250, 530, al_map_rgb(1, 1, 1), 1);
    al_draw_bitmap(imagem, 0,0,0);
    al_draw_bitmap(icon, posicoes[BASE].x - 10, posicoes[BASE].y - 35,0);
    al_draw_textf(font, al_map_rgb(0,0,0), 1200, 100, 0, "%d", numCiclistas);
    al_draw_rectangle(1195, 95, 1220, 85, al_map_rgb(1, 1, 1), 1);
    al_draw_rectangle(1195, 140, 1220, 130, al_map_rgb(1, 1, 1), 1);
    al_flip_display();

}

void construirRota()
{
    for(i = 0; i < numberOfPoints; i++)
    {
        routeConstruct(points[i][0], pi);
    }
    routeOn = true;
}


bool pontosCobertos(){

	for(i = 0; i < numberOfPoints; i++)
	{
		if(points[i][1] == 0)
			return false;
	}
return true;
}

/*void construirRota2(int numCiclistas){
	int j = 0, k = 0, *w, *v, aux = 0, maior = INT_MIN, state = 0, x;
	w = malloc(numCiclistas * sizeof(int));
	v = malloc(numCiclistas * sizeof(int));

	for(j = 0; j < numCiclistas; j++){
		w[j] = INT_MAX;
	}

	//while(!pontosCobertos()){
		for(j = 0; j < numberOfPoints; j++){
			aux = a[points[j][0]];


			for(k = 0; k < numCiclistas; k++){
				if(aux < w[k])
					state = 1;

				if(w[k] > maior){
					maior = w[k];
					x = k;
				
				}
			}

			if(state == 1){
				w[x] = aux;
				v[x] = points[j][0];
			}

			state = 0;
			maior = INT_MIN;
		}
	//}
for(k = 0; k < numCiclistas; k++){
	printf("%d\n", v[k]);
}
free(w);
free(v);
}*/


Vertex verticeDistante(){
	int maiorDist = INT_MIN;
	Vertex maiorVertex;

	for(i = 0; i < numberOfPoints; i++){
		if(points[i][1] == 0){
			if(a[points[i][0]] > maiorDist){
				maiorDist = a[points[i][0]];
				maiorVertex = points[i][0];
				j = i;
			}
		}
	}
	points[j][1] = 1;
  numCiclistas--;
  pointsLeft--;
	return maiorVertex;
}

void caminhoVertexDistante(int maiorVertex){
	int w = maiorVertex;
	i = 0;
	while(pi[w] != BASE){
		parentDistante[i] = pi[w];
		numVertices++;
		i++;
		w = pi[w];
	}
}

void verificaPontosComuns(){
	for(i = 0; i < numVertices; i++){
		for(j = 0; j < numberOfPoints; j++){
			if(points[j][1] == 0){
				if(points[j][0] == parentDistante[i]){
					points[j][1] = 1;
          pointsLeft--;
				}
			}
		}
	}
}

void construirRota2(int x){
numCiclistas = x;
pointsLeft = numberOfPoints;
Vertex maiorVertex = 0;

	while(!pontosCobertos()){
	maiorVertex = verticeDistante();
  printf("\n%d\n", maiorVertex);
	caminhoVertexDistante(maiorVertex);
	verificaPontosComuns();
 // if(numCiclistas == 1)
   // printf("estou aqui aff %d\n", pointsLeft);
	routeConstruct(maiorVertex, pi);
	numVertices = 0;
}

routeOn = true;
}