#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int S(),L(),Ldash();
char *ip;
char string[100];
int main() {
    printf("Enter the string: ");
    scanf("%s",string);
    ip=string;
    printf("\n\nProcessing Input\n--------------------------------\n");
    if(S() && *ip=='\0'){
        printf("\n--------------------------------\n");
        printf("\n String is successfully parsed\n");
    }
    else{
        printf("\n--------------------------------\n");
        printf("Error in parsing String\n");
    }
}
int S() {
    if(*ip=='(') {
        printf("%s S->(L) \n",ip);
        ip++;
        if(L()) {
            if(*ip==')') {
                ip++;
                return 1;
            }
            else return 0;
        }
        else return 0;
    }
    else if(*ip=='a') {
        ip++;
        printf("%s S->a \n",ip);
        return 1;
    }
    else
        return 0;
}
int L() {
    printf("%s L->SL' \n",ip);
    if(S()) {
        if(Ldash()) return 1;
        else return 0;
    }
    else return 0;
}
int Ldash() {
    if(*ip==',') {
        printf("%s L'->,SL' \n",ip);
        ip++;
        if(S()) {
            if(Ldash()) return 1;
            else return 0;
        }
        else return 0;
    }
    else {
        printf("%s\tL'->? \n",ip);
        return 1;
    }
}