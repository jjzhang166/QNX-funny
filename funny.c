#include <header.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main (int argc, char *argv[]) {
	//variables
	int i, num_of_threads;

	// Handle arguments
	if( argc == 2 ) {
		if (! is_number (argv[1]) ) {
			printf ("%s is not a number\n", argv[1]);
			return 1;
		}
	} else {
		printf("One argument expected.\n");
		return 1;
	}

	num_of_threads = atoi (argv[1]);
	printf("Number of balls %s", argv[1]);
	// check if all balls will fit on the map 15x15
	if (num_of_threads > 225) {
		printf (" is too high for this map\n");
		return 1;
	}
	printf ("\n");

	// Setting random numbers
	srand (time (NULL) );

	// write a map to the console
	map();

	// Mutex stuff
	pthread_mutexattr_t mutexattr;
	pthread_mutexattr_init(&mutexattr);
	pthread_mutex_init(&screen, &mutexattr);

	// Pthread stuff
	pthread_attr_t attr;
	pthread_attr_init( &attr );

	pthread_t tid[num_of_threads];
	int id[num_of_threads];

	for (i = 0; i < num_of_threads; i++) {
		id[i] = i;
		pthread_create (&tid[i], NULL, thread_function, NULL);
		usleep (100000);
	}

	for (i = 0; i < num_of_threads; i++) {
		pthread_join(tid[i], NULL);
	}

    gotoxy (18, 0);
	return EXIT_SUCCESS;
}
