#pragma once

#include<stdio.h>
#include<stdint.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define intt int32_t

void romanTransfer(intt integer);
intt even_or_odd(intt disk_num);
void hanoi(intt disk_num, intt control);
void hanoi_recursion(intt disk_num, intt control, intt k);
double factorial(intt num);
double get_ans(intt k);
double equivalent(intt n,intt r);
intt get_result();
intt check_input(intt input);
void int_to_str(intt *str,intt integer);
intt game(intt *guess, intt *result);
