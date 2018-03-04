#include <header.h>
#include <stdlib.h>
#include <stdio.h>

void * thread_function () {
	int i;
	int a = 2;
	int b = 16;
	int c = random_range (a, b);
	int x = a + rand() % c;
	int y = a + rand() % c;

	for (i = 0; i < 100; i++) {
		// critical section - start
		while (pthread_mutex_trylock(&screen) != 0) {}
		//write a ball
		gotoxy (x, y);
		printf ("O");
		fflush(stdout);
		pthread_mutex_unlock(&screen);
		// critical section - end

		// set delay before move
		usleep (1000000);

		// critical section - start
		while (pthread_mutex_trylock(&screen) != 0) {}
		// earse old ball before printing new one
		gotoxy (x, y);
		printf(" ");
		fflush(stdout);
		pthread_mutex_unlock(&screen);
		// critical section - end

		// direction random
		a = -1;
		b = 1;
		c = random_range (a, b);
		int dx = a + rand() % c;
		int dy = a + rand() % c;

		// check border
		if ( 	(x + dx) > 16 || (x + dx) < 2 ||
				(y + dy) > 16 || (y + dy) < 2 ) {
			continue;
		} else {
			x = x + dx;
			y = y + dy;
		}
	}
	return(NULL);
}
