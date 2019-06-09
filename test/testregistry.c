#include<stdio.h>
#include<stdlib.h>
#include "registry.h"
#include "adt/array_list.h"

int main(){

  Registry* root;
  Registry* registry;
  ArrayList* children;

  int i, size;
  
  root = registry_new();

  registry_add(root, "Chapter 01", 0);
  registry_add(root, "Chapter 02", 0);

  children = registry_get_children(root);
  size = adt_array_list_get_size(children);

  for( i=0; i<size; i++){
    registry = adt_array_list_get(children, i);
    printf("Registry name: %s, type: %d.\n", registry_get_name(registry), registry_get_type(registry));
  }

}
  
