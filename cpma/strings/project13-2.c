#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "cpma_main.h"

#define MAX_REMIND 50
#define MSG_LEN 60

static int read_line(char str[], int n);
static int remainder_main(int argc, char * argv[]);
static void clear_input();

__attribute__((constructor(PRIOR_NORMAL_BASE+133)))
static void init(){
  registry_add(cpma_registry, "C13. Project 2 - Remainder", remainder_main, TYPE_CHILD);
}

static int remainder_main(int argc, char* argv[]){
  char reminders[MAX_REMIND][MSG_LEN + 9];
  char day_str[3],time_str[6], msg_str[MSG_LEN + 1];
  int day,hour,minute, i, j,k, num_remind = 0;

  for(;;){
    if( num_remind == MAX_REMIND ){
      printf("-- No space left --\n");
      break;
    }

    printf("Enter day and reminder: ");
    fflush(stdout);
    scanf("%2d", &day);

    if(day == 0)
      break;
    if(day < 0 || day >31){
      printf("Invalid day, ignored.\n");
      clear_input();
      continue;
    }

    scanf("%2d:%2d", &hour, &minute);
    if(hour<0 || hour>23 || minute<0 || minute>59){
      printf("Invalid time, ignored.\n");
      clear_input();
      continue;
    }

    sprintf(day_str, "%2d", day);
    sprintf(time_str, "%02d:%02d", hour, minute);

    read_line(msg_str, MSG_LEN);

    for(i=0; i<num_remind; i++){
      if(strcmp(day_str, reminders[i]) <= 0 && strcmp(time_str, &reminders[i][3])<0){
	break;
      }
    }

    

    for( j = num_remind; j>i; j--)
      strcpy(reminders[j], reminders[j-1]);

    strcpy(reminders[i], day_str);
    strcat(reminders[i], " ");
    strcat(reminders[i], time_str);
    strcat(reminders[i], msg_str);

    //    printf("%s", &reminders[0][3]);
    num_remind++;
  }

  printf("\nDay Reminder\n");
  for(i=0; i<num_remind; i++)
    printf(" %s\n", reminders[i]);

  return EXIT_SUCCESS;
}

static int read_line(char str[], int n){
  int ch, i=0;

  while( (ch = getchar() ) != '\n')
    if(i<n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}

static void clear_input(){
  int ch;

  while( (ch = getchar()) != '\n')
    ;
}
