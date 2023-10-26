#ifndef TEMPORIZADOR_H
#define TEMPORIZADOR_H

#include <time.h>

clock_t initTime();
clock_t finalTime();
double totalTime(clock_t finalTime, clock_t initTime);

#endif