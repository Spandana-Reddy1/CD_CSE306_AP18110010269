#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define input(x) scanf("%d",&x)
#define and &&
#define or ||

void FRIST(void);
void FOLLOW(void);
void _frist_(char [], char);
void _result_(char Result[],char val);
void _follow_(char);
void frist(char);
void _result(char c);

int numOfProductionrules;
char fristdata[10][10], temp_frist_rules[10];
int n, m = 0, p, i = 0, j = 0;
char followdata[10][10],followResult[10], temp_follow_rules[10];

int main(void) {
	int op;
	printf("\n1.FRIST\n2.FOLLOW");
	printf("\nchoose your option : ");
	input(op);
		
	if (op == 1)
		FRIST();
	else if (op == 2)
		FOLLOW();
	else {
		printf("YOU choose wrong option bye!");
		exit(0);
	}
	
	return 0;
}

void FRIST(void) {
	int i,l = 0, k=0;
    char f;
    char result[20];
    printf("How many number of productions ? :");
    input(numOfProductionrules);
	
    for(i = 0; i < numOfProductionrules; i++) {
        printf("Enter productions Number %d : ",i+1);
        scanf("%s",&fristdata[i]);
		
		int flag;
		printf("if production doesn't exists enter it 1 else any number : ");
		input(flag);
		
		if (flag == 1) 
			temp_frist_rules[k++] = fristdata[i][0];
    }

    while(l != k) {
        f=temp_frist_rules[l++];
		
        _frist_(result, f); 
		
        printf("\n FIRST(%c)= { ",f);
        for(i = 0; result[i] !='\0'; i++)
			printf("%c",result[i]);  
        printf("}\n");
    } 
}

void FOLLOW(void) {
	int l=0,k=0;
	char c;
	
	printf("Enter the no.of productions: ");
	input(n);
	
	printf(" Enter %d productions\nProduction with multiple terms should be give as separate productions \n", n);
	for (int i = 0; i < n; i++) {
		printf("Enter productions Number %d : ",i+1);
        scanf("%s",&followdata[i]);
		
		int flag;
		printf("if production doesn't exists enter it 1 else any number : ");
		input(flag);
		
		if (flag == 1) 
			temp_follow_rules[k++] = followdata[i][0];
	}
	
	while (l != k) {
		c = temp_follow_rules[l++];
		
		_follow_(c);
		
		printf("FOLLOW(%c) = { ",c);
		for(int i = 0; i < m; i++)
			printf("%c ",followResult[i]);
		printf(" }\n");
	} 
}

void _frist_(char *Result, char c) {
	int i,j,k;
    char subResult[20];
    int foundEpsilon;
    subResult[0]='\0';
    Result[0]='\0';
    
    if (!(isupper(c))) {
        _result_(Result,c);
        return ;
    }
    
    for (i = 0 ; i < numOfProductionrules; i++) {  
		if (fristdata[i][0] == c) {
			if (fristdata[i][2] == '$') 
				_result_(Result,'$');
            
			else {
                j = 2;
                while (fristdata[i][j] != '\0') {
					foundEpsilon = 0;
					_frist_(subResult,fristdata[i][j]);
					
					for (k = 0; subResult[k] != '\0'; k++)
						_result_(Result,subResult[k]);
					
					for ( k = 0; subResult[k] != '\0'; k++)
						if (subResult[k] == '$') {
                           foundEpsilon = 1;
                           break;
						}
             
					if (!foundEpsilon)
						break;
					j++;
                }
            }
        }
    }
    return ;
}

void _result_(char Result[],char val)
{
    int k;
    for (k=0; Result[k] != '\0'; k++)
        if ( Result[k] == val)
            return;
    Result[k] = val;
    Result[k+1] = '\0';
}

void _follow_(char c) {
	if ( followdata[0][0] == c)
		_result('$');
	
	for (int i = 0; i < n; i++){
		for (int j = 2; j < strlen(followdata[i]); j++){
			if (followdata[i][j] == c) {
				if (followdata[i][j+1] != '\0')
					frist(followdata[i][j+1]);
				
			if(followdata[i][j+1] == '\0' and c != followdata[i][0])
			_follow_(followdata[i][0]);
		}
	}
 }
}

void frist(char c) {
    if (!(isupper(c)))
		_result(c);
	
    for (int k = 0; k < n; k++) {
        if (followdata[k][0] == c) {
            if (followdata[k][2] == '$') 
				_follow_(followdata[i][0]);
			
            else if(islower(followdata[k][2]))
                 _result(followdata[k][2]);
            else 
				frist(followdata[k][2]);
        }
    }
}

void _result(char c){
    for (int i = 0; i <= m; i++)
        if (followResult[i]==c)
            return;
   followResult[m++] = c;
}