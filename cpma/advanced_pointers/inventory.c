#include<stdio.h>
#include<stdlib.h>

#include "cpma_main.h"
#include "../structures/inventory/readline.h"

#define NAME_LEN  25

struct  part{
  int number;
  char name[NAME_LEN+1];
  int on_hand;
  struct part *next;
};

struct part *inventory = NULL;

static int inventory_main(int,char**);
static struct part *find_part(int number);
static void insert(void);
static void search(void);
static void update(void);
static void print(void);


construct_child(cpma_registry, PRIOR_NORMAL_BASE + 1701, "C17. Program - Inventory", inventory_main);

static int inventory_main(int argc, char** argv){
  char code;

  for(;;){
    printf("Enter operation code: ");
    fflush(stdout);
    scanf(" %c", &code);
    
    while(getchar() !='\n')
      ;
    switch(code){
    case 'i':
      insert();
      break;
    case 's':
      search();
      break;
    case 'u':
      update();
      break;
    case 'p':
      print();
      break;
    case 'q':
      return 0;
    default:
      printf("Illegal code\n");
    }

    printf("\n");
  }

  return EXIT_SUCCESS;
}


static struct part* find_part(int number){
  struct part *p;

  for(p = inventory;
      p !=NULL && number > p->number;
      p = p->next)
    ;

  if(p != NULL && number == p->number)
    return p;

  return NULL;
}

void insert(void){
  struct part *cur, *prev, *new_node;

  new_node = malloc(sizeof(struct part));

  if(new_node == NULL){
    printf("Database is full; can't add more parts.\n");
    return;
  }

  printf("Enter part number: ");
  fflush(stdout);
  scanf("%d", &new_node->number);

  for(cur=inventory, prev=NULL;
      cur!=NULL && new_node->number > cur->number;
      prev=cur,cur = cur->next)
    ;

  if(cur != NULL && new_node->number == cur->number){
    printf("Part already exists.\n");
    free(new_node);
    return;
  }

  printf("Enter part name: ");
  fflush(stdout);
  read_line(new_node->name, NAME_LEN);
  printf("Enter quantity on hand: ");
  fflush(stdout);
  scanf("%d", &new_node->on_hand);

  new_node->next = cur;
  if(prev == NULL)
    inventory = new_node;
  else
    prev->next = new_node;
}

static void search(void){
  int number;
  struct part* p;

  printf("Enter part number: ");
  fflush(stdout);
  scanf("%d", &number);

  p = find_part(number);
  if(p != NULL){
    printf("Part name: %s\n", p->name);
    printf("Quantity on hand: %d\n", p->on_hand);
  }else{
    printf("Part not found.\n");
  }
}

static void update(void){
  int number, change;
  struct part* p;

  printf("Enter part number: ");
  fflush(stdout);
  scanf("%d", &number);

  p = find_part(number);
  if(p != NULL){
    printf("Enter change in quatity on hand: ");
    fflush(stdout);
    scanf("%d", &change);
    p->on_hand += change;
  }else{
    printf("Part not found.\n");
  }
}

static void print(void){
  struct part *p;
  
  printf("Part Number      Part Name               Quantity on hand\n");
  for(p = inventory; p != NULL; p = p->next){
    printf("%7d      %-25s%11d\n", p->number, p->name, p->on_hand);
  }
  
}
  
  


