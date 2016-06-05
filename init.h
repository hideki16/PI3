#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

const int LARGURA_TELA = 1300;
const int ALTURA_TELA = 648;

ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_BITMAP *imagem = NULL;
ALLEGRO_BITMAP *imagem2 = NULL;
ALLEGRO_BITMAP *botao = NULL;
ALLEGRO_BITMAP *botao2 = NULL;
ALLEGRO_BITMAP *botao3 = NULL;
ALLEGRO_BITMAP *icon = NULL;
ALLEGRO_BITMAP *icon1 = NULL;
ALLEGRO_BITMAP *icon2 = NULL;
ALLEGRO_FONT *font = NULL;
ALLEGRO_COLOR c[8];

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
    al_init_font_addon();
        
    if (!al_init_ttf_addon()){
        fprintf(stderr, "Falha ao inicializar add-on allegro_ttf.\n");
        return -1;
    }

    font = al_load_font("Dense-Regular.otf", 25, 0);

    imagem = al_load_bitmap("telafinal.png");
    imagem2 = al_load_bitmap("fundo.png");
    botao = al_load_bitmap("botao.png");
    botao2 = al_load_bitmap("botao2.png");
    botao3 = al_load_bitmap("botao3.png");
    icon = al_load_bitmap("iconMapa.png");
    icon1 = al_load_bitmap("iconMapa2.png");
    icon2 = al_load_bitmap("iconmap2.png");
    c[0] = al_map_rgba_f(255, 255, 0, 0.5);
    c[1] = al_map_rgba_f(255, 0, 0, 0.5);
    c[2] = al_map_rgba_f(0,0,255, 0.5);
    c[3] = al_map_rgba_f(0,255,0, 0.5);
    c[4] = al_map_rgba_f(255,0,255, 0.5);
    c[5] = al_map_rgba_f(0,255,255, 0.5);
    c[6] = al_map_rgba_f(105,105,105, 0.5);
    c[7] = al_map_rgba_f(255,140,0,0.5);

   al_register_event_source(event_queue, al_get_display_event_source(janela));
   al_register_event_source(event_queue, al_get_mouse_event_source());

    return true;
}

void destroy(){
	al_destroy_display(janela);
    al_destroy_event_queue(event_queue);
    al_destroy_bitmap(imagem);
    al_destroy_bitmap(imagem2);
    al_destroy_bitmap(icon);
    al_destroy_bitmap(icon1);
    al_destroy_bitmap(icon2);
    al_destroy_font(font);
    al_destroy_bitmap(botao);
    al_destroy_bitmap(botao2);
    al_destroy_bitmap(botao3);
}