#include<stdio.h>
#include<stdlib.h>

#include "cpma_main.h"

#define MAX_LEN  128
#define C_PERIOD '.'
#define C_EXCLAMATION '!'
#define C_QUESTION '?'
#define C_NEW_LINE '\n'

static int p5_main(int, char**);
static int read_sentence(char*);
static void print_reversal(char*, int len);


__attribute__((constructor(PRIOR_NORMAL_BASE + 125)))
static void init(){
  registry_add(cpma_registry, "C12. Project 5 - Reversal Words", p5_main, TYPE_CHILD);
}


int p5_main(int argc, char* argv[]){

  char sentence[MAX_LEN];
  int len;

  len = read_sentence(sentence);
  print_reversal(sentence, len);

  return EXIT_SUCCESS;
}

static int read_sentence(char * sentence){
  char ch;
  int i = 0;

  printf("Enter a sentence: ");
  fflush(stdout);

  ch = getchar();

  while ( ch != C_NEW_LINE && ch != C_PERIOD
	  && ch != C_EXCLAMATION && ch != C_QUESTION
	  && ch != C_NEW_LINE && i < (MAX_LEN-1)){
    sentence[i] = ch;
    i++;

    ch = getchar();
  }
  
  sentence[i] = 0;
  
  return i;
}


static void print_reversal(char *sentence, int len){

  char* ptr;
  int  end;

  end = len - 1;
  ptr = sentence + (len-1);

  printf("Reversal of sentence: ");
  while(ptr != sentence){

    if( *ptr == ' ' ){
      printf("%s ", (ptr+1));

      sentence[end] = 0;
    }

    end--;
    ptr--;
  }

  printf("%s ", sentence);

}
