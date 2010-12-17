//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//      
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//      
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.
//
//      Name: base2bases
//      Author: Isaac Mechi		R.A.: 0813506479	6° Sem. C. Computação
//      Date: 19/09/10 15:54
//      Description: Trabalho da máteria Arquitetura de Computadores, 
//      Conversor de bases numéricas.
//  
//      Status:
//  
//  	### CONCLUÍDOS ###
//  	19/09/2010 - Decimal para binario e hexadecimal concluído.
//  	26/09/2010 - Binario para decimal e hexadecimal concluido.
//  	02/10/2010 - Hexadecimal para decimal e binário concluído.
//  	04/10/2010 - Correções finais.
//  	### PENDÊNCIAS ###//			
//  	Testes e debugs 
//
#include <stdio.h>
#include <math.h>
#include <locale.h>    // Biblioteca para uso de configurações regionais.
#include <string.h>
#include <stdlib.h>

#define MAX_BIT 16	// Este programa trabalha com números de 16 bits.
#define TRUE 1
#define FALSE 0

// modulo decimal para binario e hexadecimal
// modulo int2hex converte nr de 10 a 15 a suas respectivas letras Hex.
void dec2bin(int num, int disp);
void dec2hex(int num, char *label);
void int2hex(char *vet);

// modulo hexadecimal para decimal e binario
void hex2bin(char *str, char *label, int disp);
int hex2dec(char *str, char *label, int disp);

// modulo binario para hexadecimal e decimal
void bin2hex(char * str);
int bin2dec(char * str, int disp);

// função help e warning
void help(void);
void warning(int n, char *label);







/*
 * NOTA: Usar atoi() para argv to int.
 * NOTA: Um método fácil para acessar cada caracter das strings de argv,
 * por exemplo:
 * 
 * argv[1] // Primeiro argumento de linha de comando. Isto é uma String
 * e não um caracter. * 
 * para acessar os carecteres, use argv[1][x], onde o x são os indíces 
 * desta String.
 * para usar a biblioteca math.h sera preciso linkar
 * com o parâmetro ( -lm ). * 
 * ex.: gcc -Wall -o test -lm test.c
 * */
 
int main(int argc, char *argv[]){
 int num=0;
 char opt;
 
 if( argc != 3 ){
	help();
	exit(EXIT_FAILURE);
} 
 opt = argv[1][0]; 
 switch (opt){
	case 'b':    
		num = strlen(argv[2]);
		if(num > MAX_BIT) warning(num, "Número > que 16 bits");		
		bin2dec(argv[2],TRUE);
		bin2hex(argv[2]);
		break;
	case 'd':
		num = atoi(argv[2]);		
		if(num <= 0 || num > 65535) warning(num, "Número > que 65.535");		
		dec2bin(num,TRUE);
		dec2hex(num,"Hexadecimal");
		break;
	
	case 'h':		
		num = strlen(argv[2]);
		if(num > 4) warning(num, "Número > que 16 bits em Hexadecimal");
		hex2dec(argv[2],"Decimal",TRUE);
		hex2bin(argv[2],"Binário",FALSE);		
		break;
	} 
 return 0;
}



















int hex2dec(char *str,char *label, int disp){
	int h,aux=0,r=0;
	
	printf("\nConvertido Para %s:\n\n",label);	
	for(h=4-1;h>=0;--h){				
		if(str[h] == 'A' || str[h] == 'a')			
			aux = 10;
        if(str[h] == 'B' || str[h] == 'b') 
            aux = 11;
        if(str[h] == 'C' || str[h] == 'c')            
            aux = 12;
        if(str[h] == 'D' || str[h] == 'd')        
            aux = 13;
        if(str[h] == 'E' || str[h] == 'e')			
			aux = 14;
        if(str[h] == 'F' || str[h] == 'f')           
            aux = 15;
		if(str[h] == '1' || str[h] == '2' ||
		   str[h] == '3' || str[h] == '4' ||
		   str[h] == '5' || str[h] == '6' ||
		   str[h] == '7' || str[h] == '8' ||
		   str[h] == '9') 
			aux = str[h]-'0';
		
		r += (aux)*(pow(16,h));			
	}
	if(disp) printf("%d\n",r);
	return r;
}

void hex2bin(char *str,char *label, int disp){
	int h;
		
	h = hex2dec(str,label,disp);
	dec2bin(h,FALSE);		 
}

int bin2dec(char *str, int disp){
	int b=0,d=0; 
	
	if(disp) printf("\nConvertido Para Decimal:\n\n");
	for(b=0; b<MAX_BIT; ++b)
		if(str[b] == '1') d += pow(2,b);              
		 
	return d;
}

void bin2hex(char *str){
    int b;
    
    b = bin2dec(str,FALSE);
    printf("%d\n",b);    
	dec2hex(b,"Hexadecimal");
}











void int2hex(char *vet){
     int i;
     
     for(i = 0; i < MAX_BIT -12; ++i){
           if(vet[i] == 10)
                printf("A");                
           if(vet[i] == 11)
                printf("B");                 
           if(vet[i] == 12)
                printf("C");                   
           if(vet[i] == 13)
                printf("D");                   
           if(vet[i] == 14)
				printf("E");				         
           if(vet[i] == 15)
                printf("F");                     
           if(vet[i] >= 0 && vet[i] <10)
               	printf("%d",vet[i]);               
	   }
	   printf("\n");
     }

void dec2hex(int num,char *label){
     int d;
     char hex[MAX_BIT];
     
     printf("\nConvertido Para Base %s:\n\n",label);     
     for(d = 0; d < MAX_BIT; ++d)
           hex[d] = 0;
     for(d = MAX_BIT -13; d >=0; --d){
           hex[d] = num%16;
           num /= 16;            
           }           
           int2hex(hex);     
     }
     
void dec2bin(int num, int disp){
     int d;
     char bin[MAX_BIT];
     
     if(disp) printf("\nConvertido Para Base Binaria:\n\n");     
     for(d = MAX_BIT - 1; d >= 0; --d){
           bin[d] = num%2;
           num /= 2;                   
       }
     
     for(d = 0; d < MAX_BIT; ++d){
     if( d == 4 || d == 8 || d == 12) printf(" -- ");       
           printf("%d",bin[d]);
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


void warning(int num, char *label){			
	printf("\nWARNING: Operação inválida!\n\n");	
	printf("%s\n",label);
	printf("Entrada: %d\n\n",num);
	exit(EXIT_FAILURE);
}
