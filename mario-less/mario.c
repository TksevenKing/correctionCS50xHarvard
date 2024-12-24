#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n,i,j,k;
    // 1. Ask for the pyramid height
    do{
         n = get_int("Heigth: ");
    }while(n<1);


    // 2. Display the pyramid
    for (i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(j < (n-i)-1){
                printf(" ");
            }else{
                printf("#");
            }
        }
        printf("\n");
    }

    
}
