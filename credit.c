#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card;
    card = get_long("Enter credit card number: ");
    int formula = 0;
    int count = 1;
    // Loop that iterates through the card to process the validation formula
    for (long i = card; i > 0; i /= 10)
    {
        if (count % 2 == 0){
            if (i % 10 > 4){
                formula += ((i % 10) * 2) - 9;
            }
            else {
                formula += (i % 10) * 2;
            }
        }
        else{
            formula += i % 10;
        }
        count++;
    }
    //RESULTS
    if (formula % 10 > 0){
        printf("INVALID\n");
    }
    else if((card > 339999999999999 && card < 350000000000000) || (card > 369999999999999 && card < 380000000000000)){
        printf("AMEX\n");
    }
    else if((card > 5099999999999999 && card < 5400000000000000) || (card > 5499999999999999 && card < 5600000000000000)){
        printf("MASTERCARD\n");
    }
    else if((card > 3999999999999 && card < 5000000000000) || (card > 39999999999999 && card < 50000000000000)|| (card > 399999999999999 && card < 500000000000000)|| (card > 3999999999999999 && card < 5000000000000000)){
        printf("VISA\n");
    }
    else{
        printf("INVALID\n");
    }
}
