#include<stdio.h>
#include <stdlib.h>

void decimalToBinary(int dec){
    char arr[100];int i=0;
    while(dec>0){
        char c=(dec%16)+'0';
        if(c>57){
            c+=7;
        }
        arr[i]=c;
        dec/=16;
        i++;
    }
    for(int j=i;j>=0;j--){
        printf("%c",arr[j]);
    }
    
}
int main(){
    printf("Decimal to binary OR hex:\n");
    decimalToBinary(2500);
}