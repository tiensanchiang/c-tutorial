#include<stdlib.h>
#include<stdio.h>

#include "main.h"

Registry *registry;

__attribute__((constructor(PRIOR_MAIN_BASE)))
static void initialize(){
  printf("init-registry\n");
  registry = registry_new();
}

void print_category(ArrayList *list);
int get_choice();
void clear_input();

int main(int argc, char* argv[]){
  int choice, type, size;
  Registry* selected_registry;
  ArrayList* children;
  RegistryCallable callable;

  selected_registry = registry;
  type = registry_get_type(registry);

  while( type != TYPE_CHILD){
    children = registry_get_children(selected_registry);

    print_category(children);
    choice = get_choice();
    if(choice <= 0){
      printf("\n----Bye----\n");
      exit(EXIT_SUCCESS);
    }
    size = adt_array_list_get_size(children);

    if(choice > size){
      printf("Invalid choice,  choose again!\n");
      continue;
    }
    
    selected_registry = adt_array_list_get(children, choice-1);
    type = registry_get_type(selected_registry);
  }

  printf("\n");
  callable = registry_get_callable(selected_registry);
  callable(argc, argv);
}

void print_category(ArrayList* children){

  Registry* child;
  const char *name;
  int i, size;

  size = adt_array_list_get_size(children);

  printf("\nSelect a program/category:\n");
  
  for( i=0; i<size; i++){
    child = adt_array_list_get(children, i);
    name = registry_get_name(child);
    
    printf(" [%02d]: %-33s", i+1 , name);

    if( (i+1) % 3  == 0 )
      printf("\n");
  }

  if(i%3 != 0)
    printf("\n");
  fflush(stdout);
}



int get_choice(){
  int choice, num ;

  do{
    printf("Etner your choice (0 to exit): ");
    fflush(stdout);
    num = scanf("%d", &choice);
    clear_input();
  } while(num != 1);
  
  return choice;
}

void clear_input(){
  char ch;
  while( (ch = getchar()) != '\n')
    ;
}
	 
  



