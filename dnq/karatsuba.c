#include <stdio.h>
#include <math.h>

long multiply(long a, long b);
long main(long argc, char const *argv[])
{
    long a,b;
    
    printf("Enter num1 : ");
    scanf("%ld",&a);
    printf("Enter num2 : ");
    scanf("%ld",&b);

    printf("%d\n", multiply(a, b));
    return 0;
}

long multiply(long a, long b)
{
    if (a < 10 || b < 10)
        return a * b;

    long size_a = (long)ceil(log10(a));
    long size_b = (long)ceil(log10(b));

    long max = (size_a >= size_b) ? size_a : size_b;
    long m = max / 2;

    // Split
    long high1, high2, low1, low2;
    high1 = high2 = low1 = low2 = 0;

    // TIP : round helps with precision errors which may occur in pow()
    long divisor = round(pow(10, m));

    high1 = a / divisor;
    low1 = a % divisor;

    high2 = b / divisor;
    low2 = b % divisor;

    long z0, z1, z2;

    z0 = multiply(low1, low2);
    z1 = multiply(low1 + high1, low2 + high2);
    z2 = multiply(high1, high2);

    return ((round(pow(10, m * 2))) * z2) + divisor * (z1 - z2 - z0) + z0;
}
