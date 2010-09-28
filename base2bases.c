/*
  Name: base2bases
  Copyright: GPL
  Author: Isaac Mechi
  Date: 19/09/10 15:54
  Description: Trabalho da máteria Arquitetura de Computadores, 
  Conversor de bases numéricas.
  
  Status:
  
  ### CONCLUÍDOS ###
  19/09/2010 - Decimal para binario e hexadecimal concluído.
  26/09/2010 - Binario para decimal e hexadecimal concluido.
  
  ### PENDÊNCIAS ###
  * heximadecimal para binario e decimal
  
*/
#include <stdio.h>
#include <locale.h>    /* Biblioteca necessária para uso de configurações regionais. */
#include <stdlib.h>
#define MAX_BIT 4// Este programa trabalha com números de 16 bits, inteiros e maiores que "0".
#define TRUE 1
#define FALSE 0

// modulo decimal para binario e hexadecimal
// modulo int2hex converte nr de 10 a 15 a suas respectivas letras Hex.
void dec2bin(int num);
void dec2hex(int num,char *disp);
void int2hex(char vet[]);

// modulo hexadecimal para decimal e binario
void hex2bin(int num);
void hex2dec(int num);

// modulo binario para hexadecimal e decimal
void bin2hex(char * str);
int bin2dec(char * str, int disp);

// função help
void help(void);

/*
 * NOTA: Um método fácil para acessar cada caracter das strings de argv,
 *  é indexando. Por exemplo:
 * 
 * argv[1] // Primeiro argumento de linha de comando. Isto é uma String
 * e não um caracter.
 * 
 * para acessar os carecteres, use argv[1][x], onde o x são os indíces 
 * desta String.
 * 
 * */
int main(int argc, char *argv[]){ // * Usar atoi() para argv to int.
 int num=0;
 char opt;
 
 if( argc != 3 ){
	help();
	exit(EXIT_FAILURE);
} 
 opt = argv[1][0]; 
 switch (opt){
	case 'b':        
		bin2dec(argv[2],TRUE);
		bin2hex(argv[2]);
		break;
	case 'd':
		num = atoi(argv[2]);		
		if(num <= 0 || num > 65535){
			printf("WARNING: Operação inválida!\n");
			exit(1);
		}
		dec2bin(num);
		dec2hex(num,"Hexadecimal");
		break;
	
	case 'h':
		printf("Hexadecimal\n");
		break;
	} 
 return 0;
}


int bin2dec(char *str, int disp){
     int i=0,c=0; 

 for(i=0;i<MAX_BIT;++i)
    if(str[i] == '1')
       c += pow(2,i);
    if(disp)
       printf("\nConvertido Para Decimal:\n");
 
 return c;
}

void bin2hex(char *str){
    int b;
    b = bin2dec(str,FALSE);
    printf("\n%d\n",b);    
	dec2hex(b,"Hexadecimal");
}

void int2hex(char vet[]){
     int i,aux=0;
     
     for(i = 0; i < MAX_BIT; ++i){
           if(vet[i] == 10){
                printf("A");
                aux = TRUE;
                }
           if(vet[i] == 11){
                printf("B");
                 aux = TRUE;
                }
           if(vet[i] == 12){
                printf("C");
                 aux = TRUE;
                }                     
           if(vet[i] == 13){
                printf("D");
                 aux = TRUE;
                }                     
           if(vet[i] == 14){
				printf("E");
				aux = TRUE;
                }                     
           if(vet[i] == 15){
                printf("F");
                aux = TRUE;
                }                     
           if(vet[i] >= 0 && vet[i] <10)
               	printf("%d",vet[i]);
           //if(aux == 1 && vet[i] == 0)
           	//printf("%d",vet[i]);
           }
           printf("\n");     
     }

void dec2hex(int num,char *disp){
     int h;
     char hex[MAX_BIT];
     
     printf("\nConvertido Para Base %s:\n\n",disp);
     //printf("%d\n",num); //para debug
     for(h = 0; h < MAX_BIT; ++h)
           hex[h] = 0;
     for(h = MAX_BIT -1; h >=0; --h){
           hex[h] = num%16;
           num /= 16; 
           //printf("%d",hex[h]); //para debug
           }
           //printf("\n%d\n",h); //para debug
           int2hex(hex);     
     }
     
void dec2bin(int num){
     int b;
     char bin[MAX_BIT];
     
     printf("\nConvertido Para Base Binaria:\n\n");
     //printf("%d\n",num);  //para debug
     for(b = MAX_BIT - 1; b >= 0; --b){
           bin[b] = num%2;
           num /= 2;        
           //printf("%d",bin[i]); //para debug      
       }
     //printf("\n%d\n",i); //para debug
     for(b = 0; b < MAX_BIT; ++b){
           if( b == 4 || b == 8 || b == 12)
                 printf(" -- ");       
           printf("%d",bin[b]);
       }
       printf("\n");     
     }

void help(void){
	printf("\nNOME\n");
	printf("\tbase2bases\n\n");
	printf("USO\n");
	printf("\tbase2bases opções parametro\n\n");
	printf("OPCÕES\n\n");
	printf("\tb Binario para hexadecimal e decimal.\n");
	printf("\td Decimal para binario e hexadecimal.\n");	
	printf("\th Hexadecimal para decimal e binario.\n\n");
	printf("PARAMETRO\n");
	printf("\tnúmeros de 1 a 65.535.\n\n");
	printf("AUTOR\n");
	printf("\t Isaac Mechi - R.A.: 0813506479 C.Computação FAC IV\n\n");
}
