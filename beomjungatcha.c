#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//welcome to "beonmjun gatcha"
void deck(int player[12]);
void sort(int player[12]);
void print(int num , int player[12]);
void change(int num , int player[12]);
int score(int player[12]);

int main(void)
{
  int people;
  int player1[12],player2[12];
  int a_num,b_num;
  srand(time(NULL));
  
  deck(player1); deck(player2);
  sort(player1); sort(player2);
  print(1,player1); print(2,player2);
  for(int i = 0 ; i<3 ; i++)
    {
      printf("----Round %d----\n",i+1);
      printf("player1, Choose : ");
      scanf("%d",&a_num);
      printf("player2, Choose : ");
      scanf("%d",&b_num);
      change(a_num,player1); change(b_num,player2);
      sort(player1); print(1,player1); sort(player2); print(2,player2);
    }
  printf("[score]\nplayer1 : %d\nplayer2 : %d\n\n",score(player1),score(player2));
  if(score(player1)>score(player2)) printf("[player1 win!!]\n");
  else if(score(player1)<score(player2)) printf("[player2 win!!]\n");
  else printf("[same!]\n");
}

void deck(int player[12])
{
  int temp,i;
  for(i = 0 ; i<10 ; i++)
    {
      player[i] = rand()%12+1;
    }
}

void sort(int player[12])
{
  int temp;
  for(int j = 0; j<10 ; j++){
    for(int i = 0 ; i<9 ; i++){
        if(player[j]<player[i]){
             temp = player[j];
             player[j] = player[i];
             player[i] = temp;
          }
       }
    }
}

void print(int num , int player[12])
{
  printf("\nplayer%d\n[\t",num);
  for(int i = 0 ; i<10 ; i++)
    {
      printf("%d\t",player[i]);
    }
  printf("]\n\n");
}

void change(int num , int player[12])
{
  player[num-1] = rand()%12+1;
}


int score(int player[12])
{
  int score = 0,samecount = 0,samescore;
  int straight=0,strscore=0;
  
  for(int i = 0 ; i<9 ; i++)
    {
      if(player[i] == player[i+1]) samecount += 1;
    }
  samescore = 10 * samecount;
 
  for(int i = 0 ; i<9 ; i++)
    {
      if(player[i] + 1 == player[i+1]) straight += 1;
      else
      {
        if(straight >= 4) strscore += 50 + 10 * (straight-4);
        straight = 0;
      }
    }
  score = samescore + strscore;
  return score;
}

