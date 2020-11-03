#include <stdio.h>
#include <cs50.h>
#include <string.h>


int sumofdigits(int t);
bool OnlyNumber(string entered);
int numero, soma, SumOthersMulti, Sum;
string cardtype = "INVALID";
string cardnumber = "none";
int main(void)
{
    do
    {
        cardnumber = get_string("Enter credit card number: ");
    }
    while (! OnlyNumber(cardnumber));

    if (strlen(cardnumber) < 13 || strlen(cardnumber) > 16)
    {
        printf("INVALID\n");
        return 0;
    }

    switch (cardnumber[0])
    {
        case '3':
            if (cardnumber[1] == '4' || cardnumber[1] == '7')
            {
                cardtype = "AMEX";
            }
            break;
        case '4':
            cardtype = "VISA";
            break;
        case '5':
            if (cardnumber[1] > '0' && cardnumber[1] < '6')
            {
                cardtype = "MASTERCARD";
            }

            break;
    }

    for (int i = (strlen(cardnumber) - 2), n = 0; i >= n; i -= 2)
    {
        numero = ((cardnumber[i] - '0') * 2);
        SumOthersMulti = SumOthersMulti + sumofdigits(numero);;


    }
    for (int i = (strlen(cardnumber) - 1), n = 0; i >= n; i -= 2)
    {
        numero = (cardnumber[i] - '0');
        Sum = Sum + sumofdigits(numero);


    }
    soma = SumOthersMulti + Sum;

    int resultado = (soma % 10);
    if (resultado == 0)
    {
        printf("%s\n", cardtype);
    }
    else
    {
        printf("INVALID\n");
    }


}


/* Source: https://www.programmingsimplified.com/c/program/c-program-add-number-digits */
int sumofdigits(int n)
{
    int t, sum = 0, remainder;

    t = n;

    while (t != 0)
    {
        remainder = t % 10;
        sum       = sum + remainder;
        t         = t / 10;
    }

    return sum;
}

bool OnlyNumber(string entered)
{
    for (int i = 0, n = strlen(entered); i < n; i++)
    {
        if (entered[i] < 48 || entered[i] > 57)
        {
            return 0;
        }

    }
    return 1;
}

