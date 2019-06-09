#include<stdlib.h>
#include<stdio.h>

#include "main.h"

Registry *registry;

__attribute__((constructor(PRIOR_MAIN_BASE)))
static void initialize(){
  printf("init-registry\n");
  registry = registry_new();
}

void print_category(Registry *parent);

int main(int argc, char* argv[]){
  print_category(registry);
}


void print_category(Registry *parent){

  ArrayList* children;
  Registry* child;
  char *name;
  int i, size;

  children = registry_get_children(parent);
  size = adt_array_list_get_size(children);
  for( i=0; i<size; i++){
    child = adt_array_list_get(children, i);
    printf("%s \n", registry_get_name(child));
  }
}
  
  



