#ifndef __REGISTRY_H__
#define __REGISTRY_H__

#include "adt/array_list.h"

#define TYPE_PARENT 0
#define TYPE_CHILD 1

#define construct_child(parent, priority, name, callable )	\
  __attribute__((constructor(priority)))	\
  static void init(){                           \
    registry_add(parent, name, callable, TYPE_CHILD);	\
  }

struct _Regestry;

typedef struct _Registry Registry;

typedef int (*RegistryCallable)(int, char**);

Registry* registry_new();

Registry* registry_add(Registry* parent, const char* name, RegistryCallable, int type);

ArrayList *registry_get_children(Registry* parent);

const char* registry_get_name(Registry *registry);

int registry_get_type(Registry *registry);

RegistryCallable registry_get_callable(Registry* registry);
#endif
