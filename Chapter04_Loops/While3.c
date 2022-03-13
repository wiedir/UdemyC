#include <stdio.h>
#include <stdbool.h>


int main()
{
  int num_iterations = 5;
  int i = 0;
  int goal = 13;
  int selection;
  bool won = false;

  printf("Welcome to our guessing game!\n");
  printf("You have to guess the right number from the interval of [1, 20] .\n");

  do
  {
      printf("What is your %d. guess? ", i+1);
      scanf("%d", &selection);

      if ((selection >= 1) && (selection <= 20))
      {
          if (selection == goal)
          {
              won = true;
              break;
          }
          else
          {
              printf("Nope - you are wrong!\n");
              i++;
          }
      }
      else
      {
          printf("You bet a number outside the valid range :-( \n");
      }

  } while (i < num_iterations);

  if (won)
  {
      printf("Gratulations - You won!\n");
  }
  else
  {
      printf("You used your 5 guesses and lose!\n");
  }

  return 0;
}
