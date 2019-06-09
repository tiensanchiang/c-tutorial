#ifndef __REGISTRY_H__
#define __REGISTRY_H__

#include "adt/array_list.h"

struct _Regestry;

typedef struct _Registry Registry;

Registry* registry_new();

void registry_add(Registry* parent, const char* name, int type);

ArrayList *registry_get_children(Registry* parent);

const char* registry_get_name(Registry *registry);

int registry_get_type(Registry *registry);

#endif
