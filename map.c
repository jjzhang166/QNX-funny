#include <header.h>

void map() {
	int i;
	// go to upper left corner
	gotoxy (0,0);

	//clear the screen
	clear();

	// write a map
	printf("XXXXXXXXXXXXXXXXX\n");
	for (i = 0; i < 15; i++) {
		printf("X               X\n");
	}
	printf("XXXXXXXXXXXXXXXXX\n");
}
