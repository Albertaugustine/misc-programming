Program for Greedy algorithm,using C

#include<stdio.h>
#include<cs50.h>
#include<math.h>

//declaring functions
 
void input();
int owed(float a);

// main fuction
int main(void)
{
    input();
}

//input function
void input(void)
{
    float change;
    do
    {
        change = get_float("Enter the change needed: ");
    }
    while (change < 0 || change == 0);
    int ret = owed(change);
    printf("Coins: %i\n", ret);
    
}

// function for finding no. of coins
int owed(float change)
{
    int coins = 0, change_i;
    change_i = round(100 * change);

// checking for coins to be selected until owed change = 0
    while (change_i != 0)
    {
        if (change_i >= 25)
        {
            change_i -= 25;
            coins++;
        }
        else if (change_i >= 10)
        {
            change_i -= 10;
            coins++;
        }
        else if (change_i >= 5)
        {
            change_i -= 5;
            coins++;
        }
        else
        {
            change_i -= 1;
            coins++;
        }
    }
    return coins;
}
