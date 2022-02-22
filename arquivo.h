#include <stdio.h>
#include <locale.h>
#include <string.h>
#define ARQUIVO_H



int gravar(FILE *arq,char nomearq[]){
    char mensagem [50];
    arq=fopen(nomearq,"w");
    if(arq==NULL) return 0;
    printf("Digite mensagem 1 para gravar no arquivo ");
    fflush(stdin);
    gets(mensagem);
    fprintf(arq,strcat(mensagem,"\n"));
    printf("Digite mensagem 2 para gravar no arquivo");
    fflush(stdin);
    gets(mensagem);
    fputs(mensagem,arq);
    fclose(arq);
    return 1;


}

int alterar_no_final(FILE *arq,char nomearq[]){
    char mensagem[50];
    arq=fopen(nomearq,"a");
    if(!arq) return 0;
    printf("Digite mensagem para gravar no arquivo: ");
    gets(mensagem);
    fprintf(arq,"\n%s",mensagem);
    fclose(arq);
    return 1;

}

int ler (FILE *arq, char nomearq[]){
    char registro[50];
    arq=fopen(nomearq, "r");
    if(!arq) return 0;
    while(fgets(registro, sizeof(registro), arq)){
        printf ("%s",registro);}
        fclose(arq);
        return 1;
}

int ler_formatado (FILE *arq, char nomearq[]){
    float nota1, nota2, nota3;
    arq=fopen(nomearq, "r");
    if (!arq)return 0;
    while(fscanf(arq, "%f %f %f", &nota1,&nota2,&nota3) != EOF) {
     printf ("Nota1: %.1f,nota2: %.1f,nota3:%.1f\n",nota1,nota2,nota3);}
     fclose(arq);
     return 1;



}

int ler_alterar_geral (FILE *arq,char nomearq[]){
    float notas [3][3];
    char registro [20];
    int i=0;
    arq=fopen(nomearq, "r+");
    if (!arq)return 0;
    while(fscanf(arq, "%f %f %f", &notas[i][0],&notas[i][1],&notas[i][2]) != EOF){
        printf("\nAluno %d\n",i+1);
        printf("Nota 1 - Atual: %.1f Nova: ", notas[i][0]);
        scanf("%f", &notas [i][0]);
        printf("Nota 2 - Atual: %.1f Nova: ", notas[i][1]);
        scanf ("%f", &notas[i][1]);
        printf("Nota 3 - Atual: %.1f Nova: ",notas [i][2]);
        scanf ("%f", &notas[i][2]);
        i++;
       }
       rewind(arq);//volta o cursor para o inicio do arquivo
       for(i=0;i<3 ; i++){
           sprintf(registro, "%.1f %.1f %.1f\n",notas[i][0], notas[i][1], notas [i][2]);//formata string
           fputs(registro,arq);
       }
       fclose(arq);
       return 1;






}



