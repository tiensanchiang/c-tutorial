#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>

#include "cpma_main.h"

#define MAX_LEN  50

int read_message(char * message);
bool palindrome(const char*, int);
bool palindrome_ptr(const char*, int);
static int p2_main(int, char**);

__attribute__((constructor(PRIOR_NORMAL_BASE + 122)))
static void init(){
  registry_add(cpma_registry, "C12. Project 2 - Palindrome", p2_main, TYPE_CHILD);
}

static int p2_main(int argc, char ** argv){

  int len;
  char message[MAX_LEN];
  
  printf("Enter a message: ");
  fflush(stdout);

  len = read_message(message);
  printf("message is: %s, with lenth: %d \n", message, len);

  if(palindrome(message, len))
    printf("Palindrome");
  else
    printf("Not a palindrome");

  printf("\n");

  if(palindrome_ptr(message, len))
    printf("Palindrome");
  else
    printf("Not a palindrome");

  printf("\n");
}

int read_message(char *message){
  int i, len;
  char ch;

  i=0;
  ch = getchar();

  while(i<MAX_LEN && ch != '\n'){
    if(isalpha(ch)){
      message[i] = tolower(ch);
      i++;

      len = i;
    }
    ch = getchar();
  }

  message[MAX_LEN - 1] = 0;
  return len;
}

bool palindrome(const char *message, int len){
  int head, tail;
  head = 0;
  tail = len - 1;

  while(head<=tail){
    if(message[head++] != message[tail--])
      return false;
  }
  
  return true;
}

bool palindrome_ptr(const char *message, int len){

  const char *head, *tail;
  head = message;
  tail = message + (len-1);

  while(head <= tail){
    if( *(head++) != *(tail--) )
      return false;
  }
	
  return true;
}
