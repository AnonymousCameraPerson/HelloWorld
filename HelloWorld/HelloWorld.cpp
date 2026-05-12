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
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
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
    al_clear_to_color(al_map_rgb(0, 0, 250)); //Sets start color to blue
    al_draw_filled_rectangle(300, 450, 600, 800, al_map_rgb(255, 0, 0));
	al_draw_filled_circle(400, 600, 400, al_map_rgb(0, 255, 0));
    al_draw_filled_circle(400, 455, 120, al_map_rgb(0, 128, 0));
    al_draw_circle(400, 460, 120, al_map_rgb(150, 100, 50), 30);
    al_draw_line(0, height, width, height, al_map_rgb(0, 255, 0), 10);
    al_flip_display();
    al_rest(5); //Lets the display sit for 5 seconds for viewing pleasure
    al_destroy_display(display);
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