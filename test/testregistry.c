#include<stdio.h>
#include<stdlib.h>
#include "registry.h"
#include "adt/array_list.h"

int test_callable(int, char**);

int main(){

  Registry* root;
  Registry* registry;
  ArrayList* children;
  RegistryCallable callable;

  int i, size;
  
  root = registry_new();

  registry_add(root, "Chapter 01",test_callable, 0);
  registry_add(root, "Chapter 02", NULL, 0);

  children = registry_get_children(root);
  size = adt_array_list_get_size(children);

  for( i=0; i<size; i++){
    registry = adt_array_list_get(children, i);
    printf("Registry name: %s, type: %d.\n", registry_get_name(registry), registry_get_type(registry));

    callable = registry_get_callable(registry);
    if(callable){
      callable(100, NULL);
    }
  }

}

int test_callable(int i, char** argv){
  printf("This is test callable\n");
}
  
