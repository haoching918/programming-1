#pragma once

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<math.h>

#define intt int32_t

void byte_position(int64_t *ptr_integer);
void valueChage(int64_t *ptr_integer, intt position, intt change);
intt redo(intt *undo, intt undo_idx);
void update(intt *editor, intt *editor_idx);
void rotate( double *x, double *y, double theta );
void getPlane(intt a, intt b, intt c, intt d);
void project( double *x, double *y, double *z, intt a, intt b, intt c,intt d);
void print_card( const uint8_t player[13] );
void checkCard(uint8_t player[13]);
void sort_card(uint8_t player[13], intt (*compare)(intt a, intt b));
intt func01(intt a, intt b);
intt func02(intt a, intt b);
intt func03(intt a, intt b);
intt suitDet(intt card);
intt numDet(intt card);