#include <stdio.h>
#include <ctype.h>

#define PENNY 1
#define NICKEL 5
#define DIME 10
#define QUARTER 25

void greedy_change(int amount);
int main(int argc, char const *argv[])
{
    int amount;
    printf("Enter an amount: ");
    scanf("%d", &amount);
    greedy_change(amount);
    return 0;
}
void greedy_change(int amount)
{
    int p, n, d, q;
    p = n = d = q = 0;

    if (amount >= QUARTER)
    {
        q = amount / QUARTER;
        amount = amount % QUARTER;
    }
    if (amount >= DIME)
    {
        d = amount / DIME;
        amount = amount % DIME;
    }
    if (amount >= NICKEL)
    {
        n = amount / NICKEL;
        amount = amount % NICKEL;
    }
    if (amount >= PENNY)
    {
        p = amount / PENNY;
        amount = amount % PENNY;
    }
    printf("It would take %d coin to pay the amount.\n", (p + d + n + q));
    printf("%d pennies, %d dime(s), %d nickel(s), %d quarter(s)\n", p, d, n, q);
}
