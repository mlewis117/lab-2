#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 3
#define MIN_VAL 1
#define MAX_VAL 10

//Declare functions and specify returns
void show_instructions();
int get_random_number(int min, int max);
int read_guess();
void give_hint(int guess, int actual);

int main() {
    int target_number;
    int guess;
    int i;
    
    //Random number generator
    srand(time(NULL));

    show_instructions();
    
    //Generate random number
    target_number = get_random_number(MIN_VAL, MAX_VAL);

    //Loop
    for (i = 0; i < MAX_TRIES; ++i) {
        guess = read_guess();
        
        //See if guess is right
        if (guess == target_number) {
            printf("Congratulations! You guessed the number.\n");
            return 0;
        } 
        
        //Give hint if not last try
        if (i < MAX_TRIES - 1) {
            give_hint(guess, target_number);
        }
    }

    //Print correct number
    printf("Sorry, you've used all your attempts. The number was: %d\n", target_number);

    return 0;
}

//Print instructions
void show_instructions() {
    printf("Guess the number (between %d and %d). You have %d attempts.\n", MIN_VAL, MAX_VAL, MAX_TRIES);
}

//Generate random number
int get_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int read_guess() {
    int input;
    int result;
    
    while (1) {
        printf("Enter your guess: ");
        result = scanf("%d", &input);
        
        if (result == 1 && input >= MIN_VAL && input <= MAX_VAL) {
            return input;
        } else {
            printf("Invalid input. Please enter a number between %d and %d.\n", MIN_VAL, MAX_VAL);
            while (getchar() != '\n');
        }
    }
}

//Print too high or too low
void give_hint(int guess, int actual) {
    if (guess < actual) {
        printf("Too low! Try again.\n");
    } else {
        printf("Too high! Try again.\n");
    }
}
