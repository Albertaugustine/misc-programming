Program using C
#include <cs50.h>
#include <stdio.h>

//function declarations
void pyramid(int a);

//function for taking input & checking
void input(void)
{
    int steps = get_int("Enter the no. of steps: ");

    if (steps > 0 && steps < 9)
    {
        pyramid(steps);
    }
    else
    {
        input();
    }
}

//function for making the pyramid
void pyramid(int steps)
{
    int i, j;
    for (i = 1; i <= steps; i++)
    {       
        for (j = steps; j >= 0; j--)
        {   
            if (j <= i && j != 0)
            {
                printf("#");
            }

            //here starts the rightside part of pyramid
            else if (j == 0)
            {
                printf("  ");
                int c = 0;
                while (i > c)
                {
                    printf("#");
                    c++;
                }
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}    

int main(void)
{
    input();
}
