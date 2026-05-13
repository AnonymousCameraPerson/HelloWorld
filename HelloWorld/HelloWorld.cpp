// HelloWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Second program in Lecture Notes
/*#include <stdio.h>
#include <allegro5/allegro.h>
int main(int argc, char** argv) {
    ALLEGRO_DISPLAY* display = NULL;
    if (!al_init()) {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }
    display = al_create_display(640, 480);
    if (!display) {
        fprintf(stderr, "failed to create display!\n");
        return -1;
    }
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();
    al_rest(10.0);
    al_destroy_display(display);
    return 0;
}
*/



// First Porgram in the Lecture Notes
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <time.h>
#include <stdio.h>
#include <cstdio>
int main(int argc, char** argv)
{
    ALLEGRO_DISPLAY* display = NULL; //Set up display and sizes for width/height
    int width = 800;
    int height = 600;
    if (!al_init()) { //Checks if allegro can even start
        fprintf(stderr, "couldn't start allegro");
        return -1;
    }
    display = al_create_display(width, height); //Create display
    if (!display) { //Checks for display creation
        fprintf(stderr, "couldn't create display");
        return -1;
    }
    al_init_primitives_addon(); //Allows primitives
    bool clear = false;
    bool done = false;
    srand(time(NULL));
    ALLEGRO_EVENT_QUEUE* event_queue = NULL;
    al_install_keyboard();
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));

	while (!done) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
        /*
        //al_draw_filled_rectangle(300, 450, 600, 800, al_map_rgb(255, 0, 0));
//hill
        al_draw_filled_circle(400, 760, 550, al_map_rgb(0, 255, 0));
        //house front
        al_draw_filled_circle(400, 730, 450, al_map_rgb(255, 255, 124));
        al_draw_filled_circle(350, 700, 300, al_map_rgb(255, 255, 124));
        //door
        al_draw_filled_circle(400, 455, 120, al_map_rgb(0, 128, 0));
        //door frame
        al_draw_circle(400, 460, 120, al_map_rgb(150, 100, 50), 30);

        //windows
        al_draw_circle(590, 420, 45, al_map_rgb(150, 100, 50), 25);
        al_draw_circle(210, 420, 45, al_map_rgb(150, 100, 50), 25);

        //door knob
        al_draw_filled_circle(400, 455, 20, al_map_rgb(255, 255, 0));
        */
        
        draw_random_pixel(makeColor(), width, height);
        draw_random_lines(makeColor(), width, height);
        draw_random_rectangles(makeColor(), width, height);
        draw_random_filled_rectangles(makeColor(), width, height);
        draw_random_circles(makeColor(), width, height);
        draw_random_filled_circles(makeColor(), width, height);
        draw_random_filled_triangles(makeColor(), width, height);
        draw_random_ellipse(makeColor(), width, height);
        draw_random_filled_ellipse(makeColor(), width, height);

        if (ev.type == ALLEGRO_EVENT_KEY_UP) {
            switch (ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_SPACE:
                clear = true;
                break;
                case ALLEGRO_KEY_ESCAPE:
                done = true;
                break;
            }
        }
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			done = true;
		}

        al_flip_display();
        if (clear == true) {
            al_clear_to_color(al_map_rgb(0, 0, 250)); //Sets start color to blue
            clear = false;

        }
	}
    
    //al_rest(5); //Lets the display sit for 5 seconds for viewing pleasure
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);

    return 0;
}
//End of first program in Lecture Notes


/*
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
*/