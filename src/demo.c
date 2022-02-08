
#include <stdio.h>
#include "pdigits.h"

/*
* simple driver program which takes 4 numbers (stored in
*	array values[]) and prints each of them using 
*	a variety of bases (stored in bases[]).
*/
int main(){
unsigned int values[4] = {40892, 18, 891, 736};
unsigned int bases[6] = {10, 8, 7, 5, 3, 2};
unsigned int val;
int nvals, nbases;
int i, j;


for(i=0; i<4; i++) {
  val = values[i];
  for(j=0; j<6; j++) {
    printf("  %-6u in base %-3u: ", val, bases[j]);
    pdigits(val, bases[j]);
  }
  printf("-----------\n");
}
  return 0;
}
