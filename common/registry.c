#include<stdlib.h>
#include<string.h>

#include "registry.h"
#include "adt/array_list.h"

#define MAX_NAME_LEN  33
#define TYPE_PARENT 0
#define TYPE_CHILD 1

struct _Registry{
  char name[MAX_NAME_LEN];
  int type;
  ArrayList *children;
};

Registry * registry_new(){

  Registry* root;

  root = malloc(sizeof(Registry));

  strncpy(root->name,  "root", MAX_NAME_LEN-1);
  root->type = -1;
  root->children = NULL;
  
  return root;
}

void registry_add(Registry *parent, const char *name, int type){

  Registry *item;

  item = malloc(sizeof(Registry));

  strncpy(item->name, name, MAX_NAME_LEN-1);
  item->type = type;
  item->children = NULL;

  if(parent->children == NULL){
    parent->children = adt_array_list_new(0);
  }
  
  adt_array_list_add(parent->children, item);

}

ArrayList* registry_get_children(Registry *parent){
  return parent->children;
}

const char* registry_get_name(Registry *registry){
  return registry->name;
}

int registry_get_type(Registry *registry){
  return registry->type;
}
