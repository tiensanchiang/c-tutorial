#include<stdio.h>
#include<stdlib.h>

#include "main.h"

__attribute__((constructor(PRIOR_NORMAL_BASE)))
static void init_cpma(){
  printf("add registry\n");
  registry_add(registry, "C Programming, A Morden Approch", 0);
}

int cpma_main(int argc, char* argv){
  printf("cpma_main");
}
  
