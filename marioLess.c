//  marioLess.c

/*
Input:
$ ./mario
Height: 8

Output:
        #
       ##
      ###
     ####
    #####
   ######
  #######
 ########
*/

#include <cs50.h>
#include <stdio.h>

int get_number(string num)
{
    int a;
    do
    {
        a = get_int("%s", num);
    }
    while(a<1 || a>8);
    return a;
}

int main(void)
{
    int n=get_number("Height: ");
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<n-i; j++)
        {
            printf(" ");
        }
        for(int k=0; k<i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
