#include<ctype.h>
#include<stdio.h>
#include "readline.h"

int read_line(char str[], int n){
  int ch, i=0;

  while(isspace(ch = getchar()))
    ;

  while( ch != '\n' && ch != EOF){
    if( i<n )
      str[i++] = ch;
    ch = fgetc(stdin);
  }

  str[i] = '\0';
  return i;
}
       
