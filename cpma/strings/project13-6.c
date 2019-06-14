#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "cpma_main.h"

#define NUM_PLANETS 9

static int p6_main(int, char**);
static int strcmp_i(const char*, const char*);

//__attribute__((constructor(PRIOR_NORMAL_BASE + 1306)))
//static void init(){
//  registry_add(cpma_registry, "C13. Project 6 - Planets", p6_main, TYPE_CHILD);
//}

construct_child(cpma_registry, (PRIOR_NORMAL_BASE+1306), "C13. Project 6 - Planets", p6_main);

static int p6_main(int argc, char* argv[]){

  char* planets[] = {"Mercury", "Venus", "Earth",
		     "Mars", "Jupiter", "Saturn",
		     "Uranus", "Neptune", "Pluto"};

  int i, j;
  for(i=1; i<argc; i++){
    for(j=0; j<NUM_PLANETS; j++){
      if(strcmp_i(argv[i], planets[j]) == 0){
	printf("%s is planet %d\n", argv[i], j+1);
	break;
      }
    }

    if( j == NUM_PLANETS)
      printf("%s is not a planet\n", argv[i]);
  }
  
  return EXIT_SUCCESS;
}

static int strcmp_i(const char* s1, const char* s2){
  char s1_i[strlen(s1) + 1];
  char s2_i[strlen(s2) + 1];

  char* p;

  strcpy(s1_i, s1);
  strcpy(s2_i, s2);

  p = s1_i;
  while(*p){
   
    if(isalpha(*p)){
      *p = tolower(*p);
    }
    p++;
  }
    
  p = s2_i;
  while(*p){
    if(isalpha(*p)){
      *p = tolower(*p);
    }
    p++;
  }
  
  return strcmp(s1_i, s2_i);
}

  
