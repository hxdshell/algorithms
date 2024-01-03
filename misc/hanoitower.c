#include <stdio.h>

void hanoi(int start, int end, int n);
void move(int start, int end, int n);

int main(int argc, char const *argv[])
{
    hanoi(1,3,3);
    return 0;
}
void hanoi(int start, int end, int n){
    int other = 6 - (start+end);
    if(n == 1)
        move(start,end,n);
    else{
        hanoi(start,other,n-1);
        move(start,end,n);
        hanoi(other,end,n-1);
    }
}
void move(int start, int end, int n){
    printf("%d : %d -> %d\n",n,start,end);
}