#include<stdio.h>
#include<stdlib.h>

#include "cpma_main.h"

#define NUM 8

static int p2_main(int, char**);

static char* departure_times[] = {"8:00 a.m","9:43 a.m","11:19 a.m",
				"12:47 p.m","2:00 p.m",	"3:45 p.m",
				"7:00 p.m","9:45 p.m"};
static char* arrival_times[]= { "10:16 a.m","11:52 a.m", "1:31 p.m",
			       "3:00 p.m","4:08 p.m", "5:55 p.m",
			       "9:20 p.m","11:58 p.m"};


static void read_times(const char ** arr, unsigned int, int * times);

static void find_closed_flight(int desired_time,
			       char **departure_time,
			       char **arrival_time);

__attribute__((constructor(PRIOR_NORMAL_BASE + 113)))
static void init(){
  registry_add(cpma_registry, "C11. Project 2 - Closest Flight.",p2_main, TYPE_CHILD);
}

static int p2_main(int argc, char* argv[]){

  int hour, minute;
  int total_minutes, delta;
  int times[NUM];
  char *departure_time;
  char *arrival_time;
  
  printf("Enter a 24-hour time: ");
  fflush(stdout);

  scanf("%d:%d", &hour, &minute);
  total_minutes = hour * 60 + minute;

  fflush(stdout);

  find_closed_flight(total_minutes, &departure_time, &arrival_time);

  printf("Closed departure time is %s, arriving at %s.\n", departure_time, arrival_time);
  
  return EXIT_SUCCESS;
}

static void read_times(const char ** str_times, unsigned int size, int *times){
  int hour, minute;
  int i;
  char c;

  for(i=0; i<size; i++){
    sscanf(str_times[i], "%d:%d %c.m", &hour, &minute, &c);

    if(c == 'p')
      hour = hour%12 + 12;

    times[i] = hour *60 + minute;
  }

}

static void find_closed_flight(int desired_time,
			       char **departure_time,
			       char **arrival_time){
  int min = -1,index, i;
  int times[NUM];

  read_times((const char**)departure_times, NUM, times);

  for(i=0;i<NUM;i++){
    int delta = abs(times[i] - desired_time);
    if(min < 0 || delta < min){
      min = delta;
      index = i;
    }
  }

  *departure_time = departure_times[index];
  *arrival_time = arrival_times[index];
}
  
    
