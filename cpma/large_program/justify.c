#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "word.h"
#include "line.h"
#include "cpma_main.h"

#define MAX_WORD_LEN 20

static int justify_main(int argc, char *argv[]);

construct_child(cpma_registry, PRIOR_NORMAL_BASE+1501, "C15. Program - Justify", justify_main);

static int justify_main(int argc, char* argv[]){
//int main(int argc, char* argv[])
  char word[MAX_WORD_LEN + 2];
  int word_len;

  freopen(argv[1], "r", stdin);
  fflush(stdout);
  clear_line();
  for(;;){
    read_word(word, MAX_WORD_LEN + 1);
    word_len = strlen(word);

    if(word_len == 0){
      flush_line();
      return EXIT_SUCCESS;
    }

    if(word_len > MAX_WORD_LEN){
      word[MAX_WORD_LEN] = '*';
    }

    if(word_len+1 > space_remaining()){
      write_line();
      clear_line();
    }

    add_word(word);
  }

  return EXIT_SUCCESS;
}
