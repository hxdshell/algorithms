// Euclidean GCD algorithm
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int gcd(long a,long b);
int main(int argc, char const *argv[])
{
    if (argc < 3){
        printf("usage : ./gcd a b\n");
        return 0;
    }
    
    long a = atol(argv[1]);
    long b = atol(argv[2]);

    long d = gcd(a,b);
    printf("gcd = %ld\n",d);
    
    return 0;
}
int gcd(long a, long b){
    printf("%ld %ld\n",a,b);
    if(a == 0 && b == 0)
        return 0;
    if(a == 0)
        return b;
    if(b == 0)
        return a;


    return gcd(b,a % b);
}
