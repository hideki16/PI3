#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

const int LARGURA_TELA = 1300;
const int ALTURA_TELA = 648;

ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_BITMAP *imagem = NULL;
ALLEGRO_BITMAP *icon = NULL;


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

void destroy(){
	al_destroy_display(janela);
    al_destroy_event_queue(event_queue);
    al_destroy_bitmap(imagem);
    al_destroy_bitmap(icon);
}