#include <pthread.h>

#pragma once

#define clear() printf("\033[H\033[J")
#define gotoxy(x, y) printf("\033[%d;%dH", (x), (y));

int random_range (int, int);
void * thread_function ();
int is_number (char []);

// Mutex
pthread_mutex_t	screen;

