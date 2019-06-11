#include<stdio.h>
#include<stdlib.h>

#include "main.h"
#include "cpma_main.h"

Registry *cpma_registry;

__attribute__((constructor(PRIOR_NORMAL_BASE)))
static void cpma_init(){
  cpma_registry = registry_add(registry, "C Programming, A Morden Approch",NULL, TYPE_PARENT);
}
  
