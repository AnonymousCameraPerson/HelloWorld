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


ALLEGRO_COLOR makeColor();
void draw_random_pixel(ALLEGRO_COLOR color, const int width, const int height);
void draw_random_lines(ALLEGRO_COLOR color, const int width, const int height);
void draw_random_rectangles(ALLEGRO_COLOR color, const int width, const int height);
void draw_random_filled_rectangles(ALLEGRO_COLOR color, const int width, const int height);
void draw_random_circles(ALLEGRO_COLOR color, const int width, const int height);
void draw_random_filled_circles(ALLEGRO_COLOR color, const int width, const int height);
void draw_random_filled_triangles(ALLEGRO_COLOR color, const int width, const int height);
void draw_random_ellipse(ALLEGRO_COLOR color, const int width, const int height);
void draw_random_filled_ellipse(ALLEGRO_COLOR color, const int width, const int height);


int main(int argc, char** argv)
{
    ALLEGRO_DISPLAY *display = NULL; //Set up display and sizes for width/height
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
    srand(time(NULL));
    bool clear = false;
    bool done = false;
    
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
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
		draw_random_pixel(makeColor(), width, height);
        draw_random_lines(makeColor(), width, height);
        draw_random_rectangles(makeColor(), width, height);
        draw_random_filled_rectangles(makeColor(), width, height);
        draw_random_circles(makeColor(), width, height);
        draw_random_filled_circles(makeColor(), width, height);
        draw_random_filled_triangles(makeColor(), width, height);
        draw_random_ellipse(makeColor(), width, height);
        draw_random_filled_ellipse(makeColor(), width, height);
        al_draw_line(width/2, height/2, width, height, makeColor(), 5);


        al_flip_display();
        if (clear == true) {
            al_clear_to_color(al_map_rgb(0, 0, 0)); //Sets start color to black
            clear = false;
        }
	}
    
    //al_rest(5); //Lets the display sit for 5 seconds for viewing pleasure
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);

    return 0;
}

ALLEGRO_COLOR makeColor() {
	int red = rand() % 255; //Random red value
	int green = rand() % 255; //Random green value
	int blue = rand() % 255; //Random blue value
	return (al_map_rgb(red, green, blue)); //Returns the color
}
void draw_random_pixel(ALLEGRO_COLOR color, const int SCREEN_W, const int SCREEN_H) {
	int x = rand() % (SCREEN_W - 450);
	int y = rand() % (SCREEN_H - 400);
    al_put_pixel(x, y, color);
}

void draw_random_ellipse(ALLEGRO_COLOR color, const int SCREEN_W, const int SCREEN_H) {
	int x = 200-rand() % (SCREEN_W - 200);
	int y = 300+rand() % (SCREEN_H - 300);
    if (x < 1) x = 100;
    if (y < 1) y = 100;
	int rx = rand() % (x-101);
    int ry = rand() % (y - 101);
    if (rx < 1) rx = 1;
    if (ry < 1) ry = 1;
    float thickness = rand() % 5;
	al_draw_ellipse(x, y, rx, ry, color, thickness);
}

void draw_random_filled_ellipse(ALLEGRO_COLOR color, const int SCREEN_W, const int SCREEN_H) {
	int x = 200 - rand() % (SCREEN_W - 400);
	int y = 300 + rand() % (SCREEN_H - 300);
    int rx = rand() % 100;
	int ry = rand() % 100;
    if (rx < 1) rx = 1;
	if (ry < 1) ry = 1;
	al_draw_filled_ellipse(x, y, rx, ry, color);
}

void draw_random_lines(ALLEGRO_COLOR color, const int SCREEN_W, const int SCREEN_H) {
	int x = 400+rand() % (SCREEN_W - 40);
	int y = 100-rand() % (SCREEN_H - 100);
	int x1 = 400+rand() % (SCREEN_W - 400);
	int y1 = 100-rand() % (SCREEN_H - 100);
	float thickness = rand() % 5;
	al_draw_line(x, y, x1, y1, color, thickness);
}

void draw_random_rectangles(ALLEGRO_COLOR color, const int SCREEN_W, const int SCREEN_H) {
	int x = 400 + rand() % (SCREEN_W - 400);
	int y = 250 - rand() % (SCREEN_H - 400);
	int x1 = 400 + rand() % (SCREEN_W - 400);
	int y1 = 250 - rand() % (SCREEN_H - 400);
	float thickness = rand() % 5;
	al_draw_rectangle(x, y, x1, y1, color, thickness);
}

void draw_random_filled_rectangles(ALLEGRO_COLOR color, const int SCREEN_W, const int SCREEN_H) {
	int x = 200 - rand() % (SCREEN_W - 200);
	int y = 250 - rand() % (SCREEN_H - 400);
	int x1 = 200 - rand() % (SCREEN_W - 200);
	int y1 = 250 - rand() % (SCREEN_H - 400);
	al_draw_filled_rectangle(x, y, x1, y1, color);
}

void draw_random_circles(ALLEGRO_COLOR color, const int SCREEN_W, const int SCREEN_H) {
	int x = 350 - rand() % (SCREEN_W - 525);
	int y = 100 - rand() % (SCREEN_H - 400);
	int radius = rand() % 30;
	float thickness = rand() % 5;
	al_draw_circle(x, y, radius, color, thickness);
}

void draw_random_filled_circles(ALLEGRO_COLOR color, const int SCREEN_W, const int SCREEN_H) {
	int x = 200 + rand() % (SCREEN_W - 450);
	int y = 300 + rand() % (SCREEN_H);
	int radius = rand() % 30;
	al_draw_filled_circle(x, y, radius, color);
}

void draw_random_filled_triangles(ALLEGRO_COLOR color, const int SCREEN_W, const int SCREEN_H) {
	int x1 = 350 - rand() % (SCREEN_W - 500);
	int y1 = 150 + rand() % (SCREEN_H - 300);
	int x2 = 350 - rand() % (SCREEN_W - 500);
	int y2 = 150 + rand() % (SCREEN_H - 300);
	int x3 = 350 - rand() % (SCREEN_W - 500);
	int y3 = 150 + rand() % (SCREEN_H - 300);
	al_draw_filled_triangle(x1, y1, x2, y2, x3, y3, color);
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