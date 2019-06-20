#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "cpma_main.h"
#include "../structures/inventory/readline.h"

#define MAX_WORDS 5
#define WORD_LEN 20

static int p5_main(int, char**);
static int compare_str(const void *p, const void *q);

construct_child(cpma_registry, PRIOR_NORMAL_BASE + 1706, "C17. Project 5 - Sort word", p5_main);
static int p5_main(int argc, char* argv[]){
  char *words[MAX_WORDS];
  char word[WORD_LEN+1];
  char *p;
  int i;
  int len;
  int count = 0;

  for(;;){
    if(count==MAX_WORDS)
      break;
    
    printf("Enter word: ");
    fflush(stdout);

    len = read_line(word, WORD_LEN);

    if(len == 0){
      break;
    }else{
      p = malloc((len+1) * sizeof(char));
      strcpy(p, word);
      words[count++] = p;
    }
  }

  qsort(words, count, sizeof(char*), compare_str);
  
  printf("In sorted order: ");
  for(i=0;i<count;i++)
    printf("%s ", words[i]);

  printf("\n");

  return EXIT_SUCCESS;
}

static int compare_str(const void *p, const void *q){
  return strcmp( *(char**)p, *(char**)q);
}
