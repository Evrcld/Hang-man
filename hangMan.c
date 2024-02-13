#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>



//Function Prototypes

void Press_Enter_to_Continue();
void Hangman_Lobby();
void Game_Difficulty();
void Game_Logic(char chosenWord[]);
void drawHangman(int incorrectGuesses);



//-----------------Main function-----------------

int main ()
{
    //Hangman Game

    Hangman_Lobby();
    Game_Difficulty();

    return 0;
}

//-------------------------------------------------
void Hangman_Lobby()
{


    printf("********************\n");
    printf("Welcome to the Game! \n");

    Press_Enter_to_Continue();

}

//--------------------------------------------------
void Press_Enter_to_Continue()
{
    printf("Press enter to continue\n");

    while(getchar() != '\n');
}
//-------------------------------------------------



void drawHangman(int incorrectGuesses) {
    printf("    _______\n");
    printf("   |/      |\n");
    printf("   |      %c%c%c\n", (incorrectGuesses >= 1 ? '(' : ' '), (incorrectGuesses >= 1 ? '_' : ' '), (incorrectGuesses >= 1 ? ')' : ' '));
    printf("   |      %c%c%c\n", (incorrectGuesses >= 3 ? '/' : ' '), (incorrectGuesses >= 2 ? '|' : ' '), (incorrectGuesses >= 4 ? '\\' : ' '));
    printf("   |       %c\n", (incorrectGuesses >= 2 ? '|' : ' '));
    printf("   |      %c %c\n", (incorrectGuesses >= 5 ? '/' : ' '), (incorrectGuesses >= 6 ? '\\' : ' '));
    printf("___|___\n\n");

    
    if (incorrectGuesses == 6)
    {
            printf("  _____          __  __ ______    ______      ________ _____  \n");
    printf(" / ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\ \n");
    printf("| |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) |\n");
    printf("| | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  / \n");
    printf("| |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \\ \\ \n");
    printf(" \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_\\ \n");
    printf("                                                              \n");
    exit(0);
    }



}




void Game_Logic(char chosenWord[])
{
    int wordLength;
    wordLength = strlen(chosenWord);
    char guesssedLetter;
    int index;
    char updated_word[wordLength + 1];
    int attempts = 0;
    int input_output_comparison;
    int incorrectGuesses = 0;
    

    printf("Guess the word...\n\n");

    for (int i = 0; i < wordLength; i++)
    {
        printf("_");
    }
    printf("\n\n\n\n");

    scanf("%d"); // To clean the buffer


  for (int k = 0; k < wordLength; k++) // Loop for the updated word
  {
    updated_word[k] = '_';
  }
  updated_word[wordLength] = '\0';


   
    input_output_comparison = strcmp(updated_word, chosenWord);
    while (input_output_comparison != 0)  // A while loop to keep asking the user for letters
    {

    scanf("%c", &guesssedLetter); // Scans the guessed letter


    
    for (int j = 0; j < wordLength; j++) //This loop tests the inputed letter against chosenWords letters.
    {
        if (guesssedLetter == chosenWord[j])
        {
            index = j;

            updated_word[index] = guesssedLetter;
        }
           
    }
if (guesssedLetter == chosenWord[index])
{
    printf("Correct!\n");
}
else
{
    printf("Incorrect!\n");
    incorrectGuesses++;
    drawHangman(incorrectGuesses);
}


    attempts++;

    printf("%s\n", updated_word);
    printf("\t\t\t\tattempt: %d\n", attempts);
    
    input_output_comparison = strcmp(updated_word, chosenWord);
     // we are recomparing the the updatedword with the chosenword to see 
    if (input_output_comparison == 0) //If statement to break the loop if conditions are met
    {                                                                                                
        break;
    }
    
    scanf("%d");

    } //The while loop ends
   

        printf("You won the game!\n");
        printf("Total attempts: %d", attempts);

    }



//------------------------------------------------
void Game_Difficulty()
{
    int difficultyLevel;
    char chosenWord[25];


    printf("********************\n");
    printf("Choose game difficulty: \n");
    printf("1.Easy       2.Medium       3.Hard       4.Insane\n"); 


    scanf("%d", &difficultyLevel);

    switch (difficultyLevel)
    {
    case 1:
        strcpy(chosenWord, "molecule");
        break;
    case 2:
        strcpy(chosenWord, "refrigerator");
        break;

    case 3:
        strcpy(chosenWord, "extraordinary");
        break;

    case 4:
        strcpy(chosenWord, "grandiloquent");
        break;
    
    default: 
        printf("Choose available difficulty levels...\n");
        exit(0);

        
    }

    Game_Logic(chosenWord);
}
