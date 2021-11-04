//  cash.c
/*
 $ ./cash
 Change owed: -0.41
 Change owed: xyz
 Change owed: 0.41
 4
*/

#include<stdio.h>
#include<cs50.h>
#include<math.h>

int get_cents(string num)  //"string" from cs50.h
{
    float dollars;
    int cents;
    
    do
    {
        dollars = get_float("%s",num);  //"get_float" from cs50.h
    }
    while (dollars<0);
    return cents = round(dollars*100);
}

int main(void)
{
    int a = get_cents("Change owed: ");  
    
    int quarters, dimes, nickles, pennies, b, c, d, coins;
    
    quarters = a/25;
    b = a%25;
    dimes = b/10;
    c = b%10;
    nickles = c/5;
    d = c%5;
    pennies = d;
    coins = quarters+dimes+nickles+pennies;
    printf("%i\n",coins);
}
