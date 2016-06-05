#include "graph.h"
#include "init.h"

int i=0, aux, dmin, dmin2, xmin, ymin, ymin2,j;
bool routeOn = false, calculouRota = false;
Vertex prox;
Vertex prox2;
int pi[46], pi2[46], auxiliar[46];
double a[46], a2[46];
Vertex points[8][2];
int numberOfPoints = 0;
int parentDistante[46];
int numVertices = 0;
int pointsLeft = 0;
int numCiclistas = 1;
Digraph digraph;


void desenhar(ALLEGRO_EVENT ev);
void marcaPontos(ALLEGRO_EVENT ev);
void desenharPonto(Vertex w);
void construirRota();
void construirRota2();
void limparTela();

void construirGrafo(){
	digraph = DIGRAPHinit(46);
    insereArestas(digraph);
    inserePosicoes();
    AlgDijkstra(digraph, BASE, pi, a);
 

}


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


     /* for(i = 0; i < numberOfPoints; i++)
       {
           printf("%d(%d) ", points[i][0], points[i][1]);
       }
       printf("\n");

       */

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
        al_draw_bitmap(imagem2, 0,0,0);
        al_draw_bitmap(imagem, 0,0,0);
        al_draw_bitmap(botao3, 1110, 180,0);
        al_draw_bitmap(botao, 1110, 280,0);
        al_draw_bitmap(botao2, 1110, 380,0);
        al_draw_bitmap(icon1, posicoes[BASE].x - 10, posicoes[BASE].y - 35,0);
        al_draw_textf(font, al_map_rgb(255,255,255), 1265, 217, 0, "%d", numCiclistas);
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
    al_draw_bitmap(imagem2, 0,0,0);
    al_draw_bitmap(imagem, 0,0,0);
    al_draw_bitmap(botao3, 1110, 180,0);
    al_draw_bitmap(botao, 1110, 280,0);
    al_draw_bitmap(botao2, 1110, 380,0);
    al_draw_bitmap(icon1, posicoes[BASE].x - 10, posicoes[BASE].y - 35,0);
    al_draw_textf(font, al_map_rgb(255,255,255), 1265, 217, 0, "%d", numCiclistas);
    al_flip_display();

}

void construirRota()
{
    for(i = 0; i < numberOfPoints; i++)
    {
    	if(points[i][1] == 0)
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


void zerarPoints(){
	for(i = 0; i < numberOfPoints; i++){
		points[i][1] = 0; 
	}
}
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

Vertex verticePerto(double a[]){
		int menorDist = INT_MAX;
	Vertex menorVertex;

	for(i = 0; i < numberOfPoints; i++){
		if(points[i][1] == 0){
			if(a[points[i][0]] < menorDist){
				menorDist = a[points[i][0]];
				menorVertex = points[i][0];
				j = i;
			}
		}
	}
	points[j][1] = 1;
	return menorVertex;
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

void calculaProQueSobrou(){

Vertex menorVertex;
int baseatual = BASE;

while(!pontosCobertos()){
	menorVertex = verticePerto(a);
	//printf("\n\n%d %d\n\n",baseatual, menorVertex);
	routeConstruct2(menorVertex, pi, baseatual);
	baseatual = menorVertex;

	AlgDijkstra(digraph, menorVertex, pi, a);

}
AlgDijkstra(digraph, BASE, pi, a);
}


void calculaProsDoisQueSobraram(){
	
	
int qualEstou = 0, verticeProximo;

	Vertex verticePerto1 = verticePerto(a);
	for(i = 0; i < 46; i++){
		auxiliar[i] = pi[i];
	}
	routeConstruct2(verticePerto1, auxiliar, BASE);
	AlgDijkstra(digraph, verticePerto1, pi, a);


	Vertex verticePerto2 = BASE;
	AlgDijkstra(digraph, verticePerto2, pi2, a2);

while(!pontosCobertos()){

	if(qualEstou == 0)
		verticeProximo = verticePerto(a);
	else if(qualEstou == 1)
		verticeProximo = verticePerto(a2);

		if(a[verticeProximo] < a2[verticeProximo]){
			routeConstruct2(verticeProximo, pi, verticePerto1);
			verticePerto1 = verticeProximo;
			AlgDijkstra(digraph, verticePerto1, pi, a);
			qualEstou = 0;

		}else{
			routeConstruct3(verticeProximo, pi2, verticePerto2);
			verticePerto2 = verticeProximo;
			AlgDijkstra(digraph, verticePerto2, pi2, a2);
			qualEstou = 1;
		}
}

AlgDijkstra(digraph, BASE, pi, a);
}


void construirRota2(int x){
numCiclistas = x;
pointsLeft = numberOfPoints;
Vertex maiorVertex = 0;
int state = 0;

if(numCiclistas == pointsLeft){
	state = 1;
}else if(numCiclistas == 1){
	state = 2;
}else if(numCiclistas == 2){
	state = 0;
}else{
	while(!pontosCobertos()){
	maiorVertex = verticeDistante();
  	printf("\n%d\n", maiorVertex);
	caminhoVertexDistante(maiorVertex);
	verificaPontosComuns();

	routeConstruct(maiorVertex, pi);



		if(numCiclistas == pointsLeft)
   	{
   		state = 1;
   		break;
   	}

   	if(numCiclistas == 2)
   		break;

	numVertices = 0;
}
}

if(state == 1)
	construirRota();
else if(state == 2)
{
calculaProQueSobrou();
}else if(state == 0){
	calculaProsDoisQueSobraram();
}
printf("\n---------------------\n");
routeOn = true;
}