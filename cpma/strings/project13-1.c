#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "cpma_main.h"

#define WORD_LEN 20

static int p1_main(int, char**);

__attribute__((constructor(PRIOR_NORMAL_BASE + 132)))
static void init(){
  registry_add(cpma_registry, "C13. Project 1 - Word Compare", p1_main, TYPE_CHILD);
}

static int p1_main(int argc, char* argv[]){

  char word[WORD_LEN + 1];
  char smallest[WORD_LEN+1] = {0};
  char largest[WORD_LEN+1] = {0};
  int len = 0, i = 0;
  char ch;
  
  while(len != 4){
    printf("Enter word: ");
    fflush(stdout);

    i=0;
    while( (ch = getchar()) != '\n' && i<(WORD_LEN+1) && ch != EOF){
      word[i] = ch;
      i++;
    }
    word[i] = '\0';

    len = strlen(word);

    if(strlen(smallest)==0 || strcmp(word, smallest) < 0){
      strcpy(smallest, word);
    }

    if(strlen(largest) == 0 || strcmp(word, largest) > 0){
      strcpy(largest, word);
    }
  }

  printf("Smallest word: %s \n", smallest);
  printf("Largest word: %s \n", largest);

  return EXIT_SUCCESS;
}
    
