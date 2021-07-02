#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define intt int32_t

void sort_decrease(intt *array, intt array_size);
void sort_increase(intt *array, intt array_size);
void printArray(intt *array, intt array_size);
intt arr_det(intt m[4][4]);
void polynomial_print(intt *pc, intt degree);
intt max(intt a, intt b);
intt min(intt a, intt b);
double getAverage(double *num_arr, intt arr_size);
void checkInput(intt *input, intt max, intt min);
void UI(intt width);
intt gameinput(intt *input, intt max, intt min);
void diffusion(intt *mine, intt *map, intt *open, intt x, intt y, intt h, intt w);
