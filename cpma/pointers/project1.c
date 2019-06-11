#include<stdio.h>
#include<stdlib.h>

#include "registry.h"
#include "cpma_main.h"
#include "priority_def.h"

static int p1_main(int , char**);
static void pay_amount(int dollars, int *twenties,
		       int *tens, int *fives, int *ones);

__attribute__((constructor(PRIOR_NORMAL_BASE + 112)))
static void init(){
  registry_add(cpma_registry, "C11. Project 1 - Dollars", p1_main, TYPE_CHILD);
}

int p1_main(int argc, char* argv[]){

  int dollars;
  int twenties, tens, fives, ones;

  printf("Enter a dollar amount: ");
  fflush(stdout);

  scanf("%d", &dollars);

  pay_amount(dollars, &twenties, &tens, &fives, &ones);

  printf("$%-2d bills: %d\n", 20, twenties);
  printf("$%-2d bills: %d\n", 10, tens);
  printf("$%-2d bills: %d\n", 5, fives);
  printf("$%-2d bills: %d\n", 1, ones);

  return EXIT_SUCCESS;
}

void pay_amount(int dollars, int *twenties,
		int *tens, int *fives, int *ones){

  int remain;

  *twenties = dollars / 20;
  remain = dollars % 20;

  *tens = remain / 10;
  remain = remain % 10;

  *fives = remain / 5;
  remain = remain % 5;

  *ones = remain;
}
