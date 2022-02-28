#include<stdio.h>
#include <stdlib.h>
#define NUM_PESSOA 3

typedef struct{
char nome[50];
int idade;
}tp_pessoa;

void grava_dados(FILE *arq);
void le_dados(FILE *arq);

int main(){
    char nomearq[30];
    FILE *arq;
    printf("Digite o nome do arquivo: ");
    gets(nomearq);

    arq=fopen(nomearq, "w+b");
    if (arq==NULL){
        printf("Não foi possivel abrir o arquivo");
        exit(0);
    }
grava_dados(arq);
rewind(arq);
le_dados(arq);

fclose(arq);
return 0;
}

void grava_dados(FILE *arq){
    int i;
    tp_pessoa pessoa [NUM_PESSOA];
    for(i=0;i<NUM_PESSOA;i++){
        printf("Digito o nome das pessoas: ");
        scanf(" %[^\n]",pessoa[i].nome);
        printf("Digite a idade da pessoa: ");
        scanf("%d",&pessoa[i].idade);
    }
    fwrite(pessoa,sizeof(tp_pessoa),NUM_PESSOA,arq);
}

void le_dados(FILE *arq){
    tp_pessoa pessoa;
    printf("Pessoas gravadas no arquivo: ");
    do{
        fread(&pessoa,sizeof(tp_pessoa),1,arq);
        if(!feof(arq)){
            printf("\nNome: %s",pessoa.nome);
            printf("\nIdade: %d\n",pessoa.idade);
        }

        } while(!feof(arq));
    }





