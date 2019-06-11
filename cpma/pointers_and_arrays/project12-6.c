#include<stdio.h>
#include<stdlib.h>

#define N 10
#include "cpma_main.h"

static int p6_main(int, char**);
static void quick_sort(int a[], int *low, int *high);
static int* split(int a[], int *low, int *high);

__attribute__((constructor(PRIOR_NORMAL_BASE + 126)))
static void init(){
  registry_add(cpma_registry, "C12. Project 6 - Quick Sort", p6_main, TYPE_CHILD);
}


static int p6_main(int argc, char** argv){
  int a[N], i;

  printf("Enter %d numbers to be sorted: ", N);
  fflush(stdout);
  for(i=0; i<N; i++){
    scanf("%d", &a[i]);
  }

  quick_sort(a, &a[0], &a[N-1]);

  printf("In sorted order: ");
  for(i=0; i<N; i++){
    printf("%d ", a[i]);
  }
  printf("\n");

  return EXIT_SUCCESS;
}

static void quick_sort(int a[], int *low, int *high){
  int *middle;

  if(low >= high)
    return;

  middle = split(a, low, high);
  quick_sort(a, low, middle-1);
  quick_sort(a, middle+1, high);
}

static int* split(int a[], int *low, int *high){
  
  int part_element = *low;

  for(;;){
    while(low < high && part_element <= *high)
      high--;
    if(low>=high)
      break;

    *(low++) = *high;

    while(low<high && *low <= part_element)
      low++;

    if(low >= high)
      break;
    *(high--) = *low;
  }

  *high = part_element;
  
  return high;
}
