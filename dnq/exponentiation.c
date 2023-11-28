#include <stdio.h>

long exponentiation(long a, long m);
int main(int argc, char const *argv[])
{
    long a,m;
    printf("Enter a and m (a^m): ");
    scanf("%ld%ld",&a,&m);
    printf("%d ^ %d = %ld\n",a,m,exponentiation(a,m));
    return 0;
}
long exponentiation(long a, long m){
    if(m == 0)
        return 1;
    
    long result = exponentiation(a,m/2);

    // check if m is odd
    if(m % 2)
        return result * result * a;
    
    // m is even
    return result * result;

}