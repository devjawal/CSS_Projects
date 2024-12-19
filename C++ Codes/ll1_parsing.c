#include <stdio.h>
#include<stdlib.h>
#include<string.h>
char input[100];
int pos=0;
char current;
void advance(){
    current=input[pos++];
}
void error(){
    printf("Error at pos:%d\n",pos-1);
    exit(1);
}
void match(char next){
    if(current==next){
        advance();
    }
    else{
        error();
    }
}
void E();
void E_prime();
void T();
void T_prime();
void F();
//E->TE'
void E(){
    printf("Entered E\n");
    T();
    E_prime();
    printf("Exit E\n");
}
//E'->+TE'
void E_prime(){
    
    printf("Entered E_prime\n");
    if(current=='+'){
        match('+');
        T();E_prime();
    }
    printf("Exit E'\n");
}
//T->FT'
void T(){
    printf("Entered T\n");
    F();
    T_prime();
    printf("Exit T\n");
}
//T'->*FT'/e
void T_prime(){
    printf("Entered T'\n");
    if(current=='*'){
        match('*');
        F();
        T_prime();
    }
    printf("Exit T'\n");
}
//F->(E)/id
void F(){
    printf("Entered F\n");
    if(current=='('){
        match('(');
        T();
        match(')');
    }
    else if(current == 'i'){
        match('i');
    }
    else{
        error();
    }
    printf("Exit F\n");
}

int main(){
    printf("Enter string to be parsed:\n");
    scanf("%s",input);
    advance();
    E();
    if(current=='$'){
        printf("Parsing successfull\n");
    }
    else{
        error();
    }
    return 0;
}
