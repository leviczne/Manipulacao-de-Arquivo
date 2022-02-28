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
    while(fscanf(arq, "%f %f %f", &notas[i][0],&notas[i][1],&notas[i][2])!= EOF ){
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

int desafio(FILE *arq,char nomearq []){
   /* ESSA DESGRAÇA NÃO FUNCIONA*/
    int quant_alunos,n;
    float maior_media=0,menor_media=0,media;
    int i=0;
    char nome [30];
    char al_maior_media[30];
    char al_menor_media[30];
    char seek[1000];
    char str[1000];
    char line[1000];
    arq=fopen(nomearq, "r+");
    if (!arq)return 0;
    
    printf("Digite a quantidade de alunos a fazerem parte: ");
    scanf("%d",&quant_alunos);
    float notas[quant_alunos][3];

   fseek(arq,229,SEEK_SET);
   while(fscanf(arq, " %s %f %f %f",&str,&notas[i][0],&notas[i][1],&notas[i][2]) != EOF){

           media= (notas[i][0]+notas[i][1]+notas[i][2])/3;
          
           if(i==0){
            menor_media=media;
            maior_media=media;
         
           }
           if(maior_media<media){
               maior_media=media;
             strcpy(al_maior_media,str);
            
            }
            if(menor_media>media){
                menor_media=media;
             strcpy(al_menor_media,str);
            }
        
           i++;
        
           
    }
    fseek(arq,85,SEEK_SET);
    fprintf(arq," %s",al_maior_media);

    fseek(arq,108,SEEK_SET);
    fprintf(arq," %.1f",menor_media);

    fseek(arq,156,SEEK_SET);
    fprintf(arq," %s",al_menor_media);

    fseek(arq,179,SEEK_SET);
    fprintf(arq," %.1f",maior_media);


   
//printf("menor media %.1f do aluno %s \n",menor_media,al_menor_media);
//printf("maior media = %.1f",maior_media);
fclose(arq);
return 1;
}

