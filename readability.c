#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//function declaration
void inpt();
void letters(string let);

//main function
int main(void)
{
    inpt();
}

//function for input 
void inpt()
{
    string text = get_string("Enter your text: ");
    letters(text);

}

//This function prints the grade and can print no.of letters, words and sentences in given input text/ 
void letters(string let)
{
    int n = strlen(let);
    int letter = 0, word = 0, sentence = 0;
    //printf ("%d\n", n);
    if (n != 0)
    {
        word++;

        for (int i = 0; i < n; i++)
        {
            if (isalpha(let[i]) != 0)
            {
                letter++;
            }
            else if (let[i] == 32)
            {
                word++;
            }
            else if (let[i] == 33 || let[i] == 63 || let[i] == 46)
            {
                sentence++;
            }
            else
            {
                int fk = 1;
            }
        }
    }
    
    //printf ("letters = %d   words = %d  sentences = %d\n", letter, word, sentence);

    float grade = 0.0588 * (100 * (float) letter / (float) word) - 0.296 * (100 * (float) sentence / (float) word) - 15.8;
    if (grade < 16 && grade >= 0)
    {
        printf("Grade %i\n", (int) round(grade));
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}
