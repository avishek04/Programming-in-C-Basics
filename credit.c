
//  credit.c
/*
 $ ./credit
 Number: 4003-6000-0000-0014
 Number: foo
 Number: 4003600000000014
 VISA
 
 $ ./credit
 Number: 6176292929
 INVALID
*/

#include<stdio.h>
#include<cs50.h>
#include<math.h>

long get_card_number(string num)  //"string" from cs50.h
{
    long card_num;
    do
    {
        card_num = get_long("%s", num);  //"get_long" from cs50.h
    }
    while(card_num<0);
    return card_num;
}
int digit_count(long num)
{
    
    int counter=0;
    long quo;
    long div = num;
    do
    {
        quo = div/10;
        div = quo;
        counter=counter+1;
    }
    while(div>0);
    return counter;
}

int main(void)
{
    long card = get_card_number("Number: ");  
    //printf ("%li\n", card);
    int valcheck = digit_count(card);
    //printf ("%i\n", valcheck);
    long number = card/10;
    //printf ("%li\n", number);
    int n, n1, i;
    int sum = 0, sum1 = 0, netsum;
    int mast = card/1000000000000000;
    int vis = card/1000000000000;
    for(i=0; i<valcheck/2; i++)
    {
        n = number%10;
        number = number/100;
        if(n>4)
        {
            sum = sum + (n*2)/10 + (n*2)%10;
        }
        else
        {
            sum = sum + n*2;
        }
    }
    
    if(valcheck%2 == 0)
    {
        for(i=0; i<valcheck/2; i++)
        {
            n1 = card%10;
            card = card/100;
            sum1 = sum1 + n1;
        }
    }
    else
    {
        for(i=0; i<(valcheck/2)+1; i++)
        {
            n1 = card%10;
            card = card/100;
            sum1 = sum1 + n1;
        }
    }
    netsum = sum + sum1;
    if(netsum%10 == 0 && valcheck>12)
    {
        if(valcheck == 15)
        {
            printf("AMEX\n");
        }
        else if(valcheck == 16 && mast == 5)
        {
            printf("MASTERCARD\n");
        }
        else if ((valcheck == 16 && mast == 4) || (valcheck ==13 && vis == 4))
        {
            printf("VISA\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
