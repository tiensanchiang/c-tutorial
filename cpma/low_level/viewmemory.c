#include<stdio.h>
#include<ctype.h>
#include "cpma_main.h"

typedef unsigned char BYTE;

int vm_main(int argc, char**);
construct_child(cpma_registry, PRIOR_NORMAL_BASE + 1801, "C18. Program - View Memeroy", vm_main);


int vm_main(int argc, char* argv[]){
  unsigned int addr;
  int i, n;
  BYTE *ptr;

  printf("Address of main function: %x\n", (unsigned int)vm_main);
  printf("Address of addr variable: %x\n", (unsigned int) &addr);

  printf("\nEnter a (hex) address: ");
  fflush(stdout);
  scanf("%x", &addr);
  printf("Enter number of bytes to view: ");
  fflush(stdout);
  scanf("%d", &n);

  printf("\n");
  printf(" Address              Bytes              Characters\n");
  printf(" -------  -----------------------------  ----------\n");

  ptr = (BYTE*) addr;

  for(; n>0; n-=10){
    printf("%8X  ", (unsigned int) ptr);
    for(i=0; i<10 && i<n; i++)
      printf("%.2X ", *(ptr+i));
    for(; i< 10; i++)
      printf("  ");
    printf(" ");
    for(i=0; i<10 && i<n; i++){
      BYTE ch = *(ptr+i);
      if(!isprint(ch))
	ch = '.';
      printf("%c", ch);
    }

    printf("\n");
    ptr += 10;
  }

  return 0;
}
