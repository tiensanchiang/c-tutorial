#include<stdio.h>
#include<stdlib.h>

#include "cpma_main.h"

#define NUM  50

static int p1_main(int, char **);

__attribute__((constructor(PRIOR_NORMAL_BASE + 121)))
static void init(){
  registry_add(cpma_registry, "C12. Project 1 - Reversal ", p1_main, TYPE_CHILD);
}

static int p1_main(int argc, char* argv[]){
  char sentence [NUM];
  char *p;
  int i, len;

  printf("Enter a message: ");
  fflush(stdout);

  for(i=0; i<NUM && (sentence[i] = getchar()) !='\n'; i++)
    ;

  len = i;

  printf("Reversal is: ");
  for(i=len - 1;i>=0;i--)
    printf("%c", sentence[i]);
  printf("\n");

  printf("Reversal use pointer: ");
  for(p = &sentence[len-1]; p >= sentence; p--)
    printf("%c", *p);

  printf("\n");

  return EXIT_SUCCESS;
}

