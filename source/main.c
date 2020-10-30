#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_JOKE_LENGTH 1000
#define MAX_NUM_JOKES 50

int main(void) {
  // Initialize random numbers
  srand(time(NULL));

  // Open File
  FILE* fp;
  fp = fopen("jokes.txt", "r");

  // Make sure file exists
  if (fp == NULL)
  {
    printf("Error! Could Not Load File!");
    exit(1);
  }

  // Generating Joke Array
  char joke_list[MAX_NUM_JOKES][MAX_JOKE_LENGTH]; 

  int total_jokes = 0;
  while (fgets(joke_list[total_jokes], MAX_JOKE_LENGTH, fp))
  {
    //joke_list[total_jokes][strlen(joke_list[total_jokes])-1] = '\0'; // Add null terminator to end of string
    total_jokes++; // increment  line count
  }
  fclose(fp);

  printf("Total Jokes: %d\n", total_jokes);

    // Joke loop
  while (1)
  {
    // Prompt User
    printf("Would you like to hear a joke? y/n: ");
    char answer = getchar();

    // Check user's response
    if (answer == 'y')
    {
      // Tell a joke
      int joke = (rand() % (total_jokes));
      printf("Joke #%d: %s\n\n", joke+1, joke_list[joke]);
    }
    else if (answer == 'n')
    {
      // Exit Generator
      break;
    }
  }

  printf("\nHave a happy Halloween!\n");
  return 0;
}
