#include <stdio.h>
#include <cs50.h>
#include <math.h>

//function declarations
bool prompt(long int n_d);
string type(long int n_dp, int digit);

int main()
{
    long int n;
    long int n_d;
    int r = 0, digits;
    do
    {
        n = get_long("Enter a card number \n");
        n_d = n;
    }
    while (prompt(n_d) == true);
    digits = (long int)log10(n) + 1;
    long int n_dp = n;

    

    int m = 0, a = 0, i = 1;
    
    //printf("Digits %i\n", digits);

    if (digits == 15)
    {
        while (n != 0)
        {
            r = n % 10;
            n = n / 10;
            
            if (i % 2 == 0)
            {
                
                int mi = r * 2;
                if (mi >= 10)
                {   
                    while (mi != 0)
                    {
                        r = mi % 10;
                        m = m + r;
                        mi = mi / 10;
                    }
                }
                else
                {
                    m = m + r * 2;
                }
                i++;
            }
            else
            {
                a = a + r;
                i++;
            }
        }
    }
    else if (digits % 2 != 0)
    {
        while (n != 0)
        {
            r = n % 10;
            n = n / 10;
            
            if (i % 2 != 0)
            {
                int mi = r * 2;
                if (mi >= 10)
                {   
                    while (mi != 0)
                    {
                        r = mi % 10;
                        m = m + r;
                        mi = mi / 10;
                    }
                }
                else
                {
                    m = m + r * 2;
                }
                i++;
            }
            else
            {
                a = a + r;
                i++;
            }
        }
    }
    else
    {
        while (n != 0)
        {
            r = n % 10;
            n = n / 10;
            
            if (i % 2 == 0)
            {
                
                int mi = r * 2;
                if (mi >= 10)
                {   
                    while (mi != 0)
                    {
                        r = mi % 10;
                        m = m + r;
                        mi = mi / 10;
                    }
                }
                else
                {
                    m = m + r * 2;
                }
                i++;
            }
            else
            {
                a = a + r;
                i++;
            }
        }
    }
    //printf("mul = %d    add = %d    total = %d\n", m,a,m+a);
    int chsm = m + a;
    if (chsm % 10 == 0)
    {
        //printf("Cheksum = %d Checksum is valid\n", chsm);
        string card = type(n_dp, digits);
        printf("%s", card);
    }
    else
    {
        printf("INVALID\n");
    }
        
    
    
    return 0;
}


//This function is to reprompt if input is invalid
bool prompt(long int n_d)
{   
    int r = 0;
    bool c;
    while (n_d != 0)
    {   
        
        r = n_d % 10;
        n_d = n_d / 10;
        if (r < 0 || r > 9)
        {
            c = true;
        }
        else
        {
            c = false;
        }
    }
    return c;
}

//This function is to to check the type of card
string type(long int n_dp, int digit)
{   
    int secondDigit = (long int)(n_dp / pow(10, digit - 2));
    
    /*printf("digits %d\n\n",digit);
    printf("n %ld\n\n",n_dp);
    printf("second  digit %d\n\n",secondDigit);
    */
    
    string ctype;
    if ((secondDigit >= 40 && secondDigit <= 49) && (digit == 13 || digit == 16))
    {
        ctype = "VISA\n";
    }
    else if ((secondDigit == 34 || secondDigit == 37) && (digit == 15))
    {
        ctype = "AMEX\n";
    }
    else if ((secondDigit >= 51 && secondDigit <= 55) && (digit == 16))
    {   
        ctype = "MASTERCARD\n";
    }
    else
    {
        ctype = "INVALID\n";
    }
    return ctype;
}
