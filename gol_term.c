// Game of Life in a terminal
// Compil with "gcc -s -o2 -O"

#include <sys/ioctl.h>										// ioctl() for terminal size
#include <stdio.h>											// printf()
#include <stdlib.h>											// rand() & srand()
#include <time.h>											// time()
#include <unistd.h>											// usleep()
#include <signal.h>											// signal()

void the_end() {exit(0);}									// Exit prog with Ctrl-C

int main (void)
{
	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w);						 		// get terminal size
	int lines = w.ws_row;
	int columns = w.ws_col;
	int l, c, neighbors;

	int world[lines][columns], world_temp[lines][columns];	// world's a 2d array + a buffer
	srand(time(NULL));										// init random seed
	for (l = 0; l < lines; l++)
		for (c = 0; c < columns; c++)
			world[l][c] = world_temp[l][c] = rand()%2;		// fill world with random life

	signal(SIGINT, the_end);								// Catch Ctrl-C
	while(1) 												// Loop until a key is pressed
	{
		printf("\033[0;0H");								// Set cursor to position (0:0)

		for (l = 0; l < lines; l++)							// For each cell...
			for (c = 0; c < columns; c++)
			{
				printf(world[l][c] == 1 ? "•" : " ");		// Print it then count neighbors

				neighbors = world[(l-1+lines)%lines][(c-1+columns)%columns]
						  + world[l][(c-1+columns)%columns] 
						  + world[(l+1)%lines][(c-1+columns)%columns]
						  + world[(l-1+lines)%lines][c]
						  + world[(l+1)%lines][c]
						  + world[(l-1+lines)%lines][(c+1)%columns]
						  + world[l][(c+1)%columns]
						  + world[(l+1+lines)%lines][(c+1)%columns];

				if (neighbors != 2)		
					world_temp[l][c] = (neighbors == 3);	// 2=same 3=alive else=dead
			}

		for (l = 0; l < lines; l++)
			for (c = 0; c < columns; c++)
				world[l][c] = world_temp[l][c];				// Copy new generation from buffer

		usleep(100000);										// Meditation is good for you
	}
}
