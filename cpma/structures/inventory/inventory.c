#include<stdio.h>
#include "readline.h"
#include "cpma_main.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part{
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
} inventory[MAX_PARTS];


static int num_parts = 0;

static int find_part(int number);
static void insert(void);
static void search(void);
static void update(void);
static void print(void);
static int inventory_main(int, char**);

construct_child(cpma_registry, PRIOR_NORMAL_BASE + 1601, "C16. Program - Inventory", inventory_main);

int inventory_main(int argc, char* argv[]){
  char code;

  for(;;){
    printf("Enter operation code: ");
    fflush(stdout);

    scanf(" %c", &code);
    while( getchar()!= '\n')
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
}

static int find_part(int number){
  int i;
  for(i=0; i<num_parts; i++){
    if(inventory[i].number == number)
      return i;
  }

  return -1;
}

static void insert(void){
  int part_number;

  if(num_parts == MAX_PARTS){
    printf("Database is full; can't add more parts.\n");
    return;
  }

  printf("Enter part number: ");
  fflush(stdout);

  scanf("%d", &part_number);
  if(find_part(part_number) >=0){
    printf("Part already exits.\n");
    return;
  }

  inventory[num_parts].number = part_number;
  printf("Enter part name: ");
  fflush(stdout);
  read_line(inventory[num_parts].name, NAME_LEN);
  printf("Enter quantity on hand: ");
  fflush(stdout);
  scanf("%d", &inventory[num_parts].on_hand);

  num_parts++;
}

void search(void){
  int i, number;
  printf("Enter part number: ");
  fflush(stdout);
  scanf("%d", &number);

  i = find_part(number);
  if(i<0){
    printf("Part #%d does not exist.\n", number);
    return;
  }

  printf("Part name: %s\n", inventory[i].name);
  printf("Quantity on hand: %d\n", inventory[i].on_hand);
}

void update(void){
  int i, number, change;

  printf("Enter part number: ");
  fflush(stdout);
  scanf("%d", &number);
  i = find_part(number);

  if( i>=0 ){
    printf("Enter change in quantity on hand: ");
    fflush(stdout);
    scanf("%d", &change);
    inventory[i].on_hand += change;
  }else{
    printf("Part not found.\n");
  }
}

void print(void){
  int i;

  printf("Part Number    Part Name                          ");
  printf("Quantity on Hand \n");

  for(i=0; i<num_parts; i++){
    printf("%7d      %-25s%11d\n", inventory[i].number,
	   inventory[i].name, inventory[i].on_hand);
  }

}
  
  
	      
  
  
