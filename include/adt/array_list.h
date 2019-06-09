#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define DEFAULT_CAPACITY 20

struct _ArrayList;

typedef struct _ArrayList ArrayList;

typedef void* ArrayListItemDataPtr;

ArrayList * adt_array_list_new(int capacity);

ArrayListItemDataPtr adt_array_list_get(const ArrayList* list,int index);

int adt_array_list_get_index(ArrayList *list, ArrayListItemDataPtr data);

void adt_array_list_add(ArrayList* list, ArrayListItemDataPtr data);

void adt_array_list_remove(ArrayList* list, ArrayListItemDataPtr data);

void adt_array_list_remove_at(ArrayList* list, int index);

void adt_array_list_append(ArrayList* list, ArrayListItemDataPtr data);

void adt_array_list_prepend(ArrayList* list, ArrayListItemDataPtr data);

void adt_array_list_insert(ArrayList* list, ArrayListItemDataPtr, int index);

int adt_array_list_get_size(const ArrayList* list);

int adt_array_list_get_capacity(const ArrayList* list);

void adt_array_list_destroy(ArrayList* list);

#endif
