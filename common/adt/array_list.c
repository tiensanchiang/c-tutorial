#include<stdio.h>
#include<stdlib.h>
#include "adt/array_list.h"

typedef struct _ArrayListItem{
  ArrayListItemDataPtr data;
} ArrayListItem;

struct _ArrayList{
  ArrayListItem **storage;

  int capacity;
  int size;
};

static void assert_mem_alloc(void* ptr);
static void alloc_new_storage(ArrayList *list);

ArrayList* adt_array_list_new(int capacity){

  ArrayList *list;
  
  if(capacity <= 0)
    capacity = 20;

  list = malloc(sizeof( struct _ArrayList));
  assert_mem_alloc(list);
  
  list->storage = malloc(sizeof(ArrayListItem*) * capacity);
  assert_mem_alloc(list->storage);

  list->capacity = capacity;
  list->size = 0;

  return list;
}

void adt_array_list_add(ArrayList* list, ArrayListItemDataPtr data){

  ArrayListItem *item;

  if(list->size == list->capacity)
    alloc_new_storage(list);
  
  item = malloc(sizeof(ArrayListItem));
  assert_mem_alloc(item);

  item->data = data;

  list->storage[list->size++] = item;
}

void adt_array_list_append(ArrayList *list, ArrayListItemDataPtr data){
  adt_array_list_add(list, data);
}

void adt_array_list_prepend(ArrayList *list, ArrayListItemDataPtr data){

  int i;
  ArrayListItem *item;

  item = malloc(sizeof(ArrayListItem));
  assert_mem_alloc(item);

  item->data = data;
  
  if(list->size == list->capacity)
    alloc_new_storage(list);

  for( i=list->size; i>0; i--){
    list->storage[i] = list->storage[i-1];
  }

  list->storage[0] = item;
  list->size++;
}

void adt_array_list_insert(ArrayList *list, ArrayListItemDataPtr data, int index){

  int i;
  ArrayListItem *item;

  if( index<0 || index > list->size)
    return;

  if(index == 0){
    adt_array_list_prepend(list, data);
  }else if(index == list->size){
    adt_array_list_append(list, data);
  }else{
    if(list->size == list->capacity)
      alloc_new_storage(list);

    item = malloc(sizeof(ArrayListItem));
    assert_mem_alloc(item);

    item->data = data;
    for(i=list->size; i>=index; i--)
      list->storage[i+1] = list->storage[i];

    list->storage[index] = item;

    list->size++;
  }
  
}

void adt_array_list_remove(ArrayList *list, ArrayListItemDataPtr data){
  int i;

  i = adt_array_list_get_index(list, data);
  if( i>= 0){
    adt_array_list_remove_at(list,i);
  }
}

void adt_array_list_remove_at(ArrayList *list, int index){
  int i;
  ArrayListItem *item;

  if(index < 0 || index >= list->size){
    return;
  }

  item = list->storage[index];

  for(i = index; i<list->size-1; i++){
    list->storage[i] = list->storage[i+1];
  }
  list->storage[list->size-1] = NULL;

  free(item->data);
  free(item);

  list->size--;
}
  

ArrayListItemDataPtr adt_array_list_get(const ArrayList* list, int index){
  if( index<0 || index>=list->size){
    printf("Out of bound.\n");
    return NULL;
  }

  return list->storage[index]->data;
}

int adt_array_list_get_index(ArrayList *list, ArrayListItemDataPtr data){

  int i;
  ArrayListItem *item;
  for(int i=0; i<list->size; i++){
    item = list->storage[i];

    item->data == data;
    break;
  }

  if(i>=list->size)
    return -1;

  return i;
}

int adt_array_list_get_size(const ArrayList* list){
  return list->size;
}

int adt_array_list_get_capacity(const ArrayList* list){
  return list->capacity;
}

void adt_array_list_destroy(ArrayList *list){

  int i;
  ArrayListItem *item;

  for( i=0; i<list->size; i++ ){
    item = list->storage[i];
    
    free( item -> data);
    free( item );
  }

  free(list->storage);

  free(list);
}

static void alloc_new_storage(ArrayList* list){

  int i;
  ArrayListItem ** old_storage;

  //  printf("alloc new stoage, origin capaciy: %d, ", list->capacity);
  list->capacity *= 2;
  //  printf("new capacity: %d.\n", list->capacity);
  
  old_storage = list->storage;

  list->storage = malloc(sizeof(ArrayListItem*) * (list->capacity));
  assert_mem_alloc(list->storage);

  for( i=0; i<list->size; i++){
    list->storage[i] = old_storage[i];
  }

  free(old_storage);
}
  

static void assert_mem_alloc(void *ptr){
  if(ptr == NULL){
    printf("Stack overflow!\n");
    exit(EXIT_FAILURE);
  }
}
    
    
