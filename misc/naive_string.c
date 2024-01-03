#include <stdio.h>
#include <string.h>

void naive_string_matcher(char *t, char *p);

int main(int argc, char const *argv[])
{
    char *t = "000010001010001";
    char *p = "0001";
    naive_string_matcher(t,p); 
    return 0;
}
void naive_string_matcher(char *t, char *p){
    int n = strlen(t);
    int m = strlen(p);
    int flag;

    printf("pattern found at following shifts : ");
    for(int s = 0; s <= n-m; s++){
        flag = 1;
        for(int i = 0; i < m; i++){
            if(t[s+i] != p[i]){
                flag = 0;
                break;
            }
        }
        if(flag == 1)
            printf("%d,",s);
    }
}