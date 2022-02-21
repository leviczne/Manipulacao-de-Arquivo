#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "arquivo.h"

int main(){

int i,n,x=0;
setlocale(LC_ALL,"portuguese");
int opcao;
char nomearq[50];
FILE *arq;
printf("Digite a opção desejada:\n");
printf("1- Abrir um arquivo para gravação \n");
printf("2- Abrir um arquivo para atualizar no final \n");
printf("3 - Abrir um arquivo para leitura: \n");
printf("4 - Abrir um arquivo só para leitura formatada: \n");

scanf("%d" , &opcao);
fflush(stdin);
printf("Digite o nome do arquivo: ");
gets(nomearq);
switch(opcao){

    case 1 : gravar(arq,nomearq);
             break;
    case 2 : alterar_no_final(arq,nomearq);
             break;
    case 3: ler(arq, nomearq);
			break;
    case 4:ler_formatado(arq,nomearq);
           break;

}
return 0;
}


