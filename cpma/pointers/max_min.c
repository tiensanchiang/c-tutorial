#include<stdio.h>
#include<stdlib.h>

#include "registry.h"
#include "cpma_main.h"
#include "priority_def.h"

int max_min_main(int argc, char** argv);

__attribute__((constructor(PRIOR_NORMAL_BASE + 111)))
static void init(){
  registry_add(cpma_registry, "C11. Maximu and Minium", max_min_main, TYPE_CHILD);
}

void max_min(int a[], int n, int *min, int *max);

int max_min_main(int argc, char* argv[]){

  int n, i, min, max;
  int *arr;
  
  printf("How many numbers to be compare? ");
  //  printf("\n");
  fflush(stdout);
  scanf("%d", &n);

  if(n<=0){
    printf("Bye\n");
    return EXIT_SUCCESS;
  }

  arr = malloc(sizeof(int) * n);
  
  for(i=0;i<n;i++){
    printf("Number %d is: ", (i+1));
    fflush(stdout);
    scanf("%d", &arr[i]);
  }
  
  max_min(arr, n , &min, &max);
  printf("max: %d, min: %d\n", max, min);

  free(arr);
  return EXIT_SUCCESS;
}

void max_min(int a[], int n, int *min, int *max){

  int i;

  *min = a[0];
  *max = a[0];
  for(i=0;i<n;i++){
    if(a[i] > *max)
      *max = a[i];
    if(a[i] < *min)
      *min = a[i];
  }

}
	
