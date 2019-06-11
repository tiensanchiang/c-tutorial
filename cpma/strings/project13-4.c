#include<stdio.h>
#include<stdlib.h>

#include "cpma_main.h"

static int p4_main(int argc, char ** argv);

__attribute__((constructor(PRIOR_NORMAL_BASE+135)))
static void init(){
  registry_add(cpma_registry, "C13. Project 4 - Reverse Arg", p4_main, TYPE_CHILD);
}

static int p4_main(int argc, char * argv[]){

  for(;argc>1;argc--)
    printf(" %s", argv[argc-1]);
}
	      
