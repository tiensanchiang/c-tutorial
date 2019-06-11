#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include "cpma_main.h"

int get_gcd(int , int);

void reduce(int numerator, int denominator,
	    int *reduced_numerator, int *reduced_denominator);

static int p3_main(int, char**);

__attribute__((constructor(PRIOR_NORMAL_BASE + 114)))
static void init(){
  registry_add(cpma_registry, "C11. Project 3 - Reduced Denominator.", p3_main, TYPE_CHILD);
}

static int p3_main(int argc, char* argv[]){

  int num, deno;
  int r_num, r_deno;
  
  printf("Enter a fraction: ");
  fflush(stdout);
  
  scanf("%d/%d", &num, &deno);
  reduce(num, deno, &r_num, &r_deno);

  printf("In lowest term: %d/%d\n", r_num, r_deno);
  
  return EXIT_SUCCESS;
}

int get_gcd(int first, int second){

  int r, gcd, tmp;

  if(first == second)
    return second;
  
  if(first < second){
    tmp = first;
    first = second;
    second = tmp;
  }
  
  while(true){
    r = first % second;

    if( r == 0 ){
      gcd = second;
      break;
    }

    first = second;
    second = r;
  }
}

void reduce(int numerator, int denominator,
	    int *reduced_numerator, int *reduced_denominator){
  int gcd;

  gcd = get_gcd(numerator, denominator);

  *reduced_numerator = numerator / gcd;
  *reduced_denominator = denominator / gcd;

}
