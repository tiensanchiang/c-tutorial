#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<time.h>
#include "cpma_main.h"

#define NUM_SUITS 4
#define NUM_RANKS 13

static int p3_main(int, char**);

__attribute__((constructor(PRIOR_NORMAL_BASE + 133)))
static void init(){
  registry_add(cpma_registry, "C13. Project 3 - Deals Card", p3_main, TYPE_CHILD);
}


static int p3_main(int argc, char* argv[]){
  bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
  int num_cards, rank, suit;
  const char* rank_code[] = {"Two", "Three", "Four", "Five","Six","Seven",
			    "Eight", "Nine", "Ten", "Jack","Queen","King","Ace"};
  const char* suit_code[] = {"clubs", "diamonds", "hearts","spades"};

  srand((unsigned) time(NULL));

  printf("Enter number of cards in hand: ");
  fflush(stdout);

  scanf("%d", &num_cards);

  printf("Your hand:");
  while(num_cards >= 0){
    suit = rand() % NUM_SUITS;
    rank = rand() % NUM_RANKS;

    if( !in_hand[suit][rank] ){
      in_hand[suit][rank] = true;
      num_cards --;
      printf(" %s of %s\n", rank_code[rank], suit_code[suit]);
    }
  }
  printf("\n");

  return 0;
}
			    
