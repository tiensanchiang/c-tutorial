#include<stdlib.h>
#include<stdio.h>

#include "cpma_main.h"

static int p5_main(int, char**);

__attribute((constructor(PRIOR_NORMAL_BASE + 136)))
static void init(){
  registry_add(cpma_registry, "C13. Project 5 - Sum Args", p5_main, TYPE_CHILD);
}

static int p5_main(int argc, char* argv[]){

  int i, val = 0;
  
  for(i = 1; i < argc; i++){
    val += atoi(argv[i]);
  }

  printf("Total: %d\n", val);

  return EXIT_SUCCESS;
} 
