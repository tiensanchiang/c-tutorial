#include<stdio.h>
#include<stdlib.h>
#include "adt/array_list.h"

static void print_list(const ArrayList* list);

int main(){

  int i, *val;
  ArrayList* list;

  list = adt_array_list_new(100);

  printf("list size: %d.\n", adt_array_list_get_size(list));

  for( i=0; i<64; i++){
    val = malloc( sizeof(int) );
    *val = i;
    adt_array_list_add(list, val);
  }
  
  printf("after add 9 int: \n");
  print_list(list);

  val = malloc(sizeof(int));

  *val = 10;
  adt_array_list_append(list, val);
  printf("after append %d\n", *val);
  print_list(list);

  adt_array_list_prepend(list, val);
  printf("after prepend %d\n", *val);
  print_list(list);

  adt_array_list_insert(list, val, 5);
  printf("after insert %d at %d\n", *val, 5);
  print_list(list);

  adt_array_list_remove_at(list, 2);
  printf("after remove at %d\n", 2);
  print_list(list);

  adt_array_list_destroy(list);
  
  return EXIT_SUCCESS;
}

static void print_list(const ArrayList* list){

  int i, size, capacity;
  int *val;
  
  size = adt_array_list_get_size(list);
  capacity = adt_array_list_get_capacity(list);
  
  printf("-------------list-info-----------------\n");
  printf("list size: %d, list capacity: %d\n", size, capacity);
  printf("list values: \n");

  for(i=0; i<size; i++){
    val = adt_array_list_get(list, i);
    printf("%-3d", *val);

    if( (i+1) % 10 == 0)
      printf("\n");
  }

  printf("\n---------------------------------------\n\n");

}

  

  
