//
// Created by Amd on 18/09/2023.
//

#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// aqui em cima eu adicionei alguns std a mais para facilitar

Tarefa Lista[maxtarefas];

int criararquivo(){
    FILE*arqtarefas = fopen("arqtarefas","wb");
  if(arqtarefas == NULL){
    return 1;
  }
    fwrite(&Lista,sizeof(Tarefa),maxtarefas,arqtarefas);
    fclose(arqtarefas);
    return 0;
}

void Menu(){
  int cod;
  cod = lerarquivo();
  if(cod == 1){
    printf("Nao foi possivel ler o arquivo!");
  }
  Tarefa *tarefa = malloc(sizeof(Tarefa));
  int opcao;
  do{                                             // aqui eh praticamente so o print c o menu
      printf(" --- MENU ---\n");
      printf("1 - Criar tarefa.\n2 - Deletar tarefa.\n3 - Listar tarefas.\n0 - Sair.\n");
      printf("Digite a operacao que deseja realizar: ");
      scanf("%d",&opcao);
      getchar();
      switch(opcao){                  // e aqui eh aquele metodo de usar tipo, caso seja 1, caso seja 2 e etc
          case 1:
              CriarTarefa();
          break;
          case 2:
              DeletarTarefa();
          break;
          case 3:
              ListarTarefas();
          break;
        };
    }while(opcao != 0);
    criararquivo();
}

void CriarTarefa(){
    char tarefa[100];
    char descricao[300];
    int prioridade;
    printf("Digite sua tarefa: ");
    fgets(tarefa,sizeof(tarefa),stdin);             // aqui n tem mt coisa de difrente, mas basicamente oq essa funcao faz
    printf("Digite aqui a descricao desta tarefa: ");           // é a conta da variavel que a pessoa digitou c o maximo de caracteres, exemplo na descricao sao 300
    fgets(descricao,sizeof(descricao),stdin);       // o stdin faz c oq a pessoa digite va para a variuavel descricao, nesse caso
    printf("Digite aqui a prioridade desta tarefa: ");
    scanf("%d",&prioridade);
    for(int i = 0; i < maxtarefas; i++){
        if (Lista[i].existe == 0){
            strcpy(Lista[i].tarefa, tarefa);                // essa parte de for e if, adiciona as coisas no struct 
            strcpy(Lista[i].descricao, descricao);
            Lista[i].prioridade = prioridade;
            Lista[i].existe = 1;
            break;
        };
    };
};
void DeletarTarefa(){
    printf("Aqui está sua lista!\n");               //Aqui na funcao deletar, eu vejo se dentro do .existe
    ListarTarefas2();                                      // no struct é 1 ou 0, caso seja 1 quer dizer q existe uma tarefa la
    int del;                                                // e eu deleto igualando esse .existe igual a 0
    printf("Qual tarefa deseja excluir: ");
    scanf("%d", &del);
    int pos = del - 1;
    Lista[pos].existe = 0;
    printf("Tarefa excluida com sucesso!");
};
void ListarTarefas(){
    printf("--- LISTA DE TAREFAS ---\n");               //aqui passa por cada indice do array
    printf("\n");                                       // e da um print para cada indice
    for(int i = 0; i < maxtarefas; i++){
        if(Lista[i].existe == 1) {
            printf("Tarefa: %s", Lista[i].tarefa);
            printf("Descricao: %s", Lista[i].descricao);
            printf("Prioridade: %d", Lista[i].prioridade);
            printf("\n-----------------\n");
        }
    }
};

void ListarTarefas2(){
    for(int i = 0; i < maxtarefas; i++){            //essa funcao é so para deixar um "mini menu" funcao deletar
        if(Lista[i].existe == 1) {
            int num = i + 1;
            printf("Tarefa %d: %s\n",num, Lista[i].tarefa);
        }
    }
};

void Alterartarefa(Tarefa Nome[]) {
    char novatarefa[20];
    char novadescricao[100];
    int novaprioridade;
    char novoestado[15];
    int num;
    int alt;
    int opcao;
    ListarTarefas2(Nome);
    printf("Digite qual tarefa deseja alterar: ");
    scanf("%d", &alt);
    num = alt - 1;
    printf("1. A tarefa.\n");
    printf("2. A descricao.\n");
    printf("3. A prioridade.\n");
    printf("4. O estado.\n");
    printf("Digite o que deseja mudar: ");
    scanf("%d", &opcao);
    limpar();
    if (opcao == 1) {
        printf("Digite qual vai ser a nova tarefa: ");
        fgets(novatarefa, sizeof(novatarefa), stdin);
        sprintf(Nome[num].tarefa, novatarefa);
        printf("Tarefa alterada com sucesso!\n\n");
    }
    if (opcao == 2) {
        printf("Digite qual vai ser a nova descricao: ");
        fgets(novadescricao, sizeof(novatarefa), stdin);
        sprintf(Nome[num].descricao, novadescricao);
        printf("Descricao alterada com sucesso!\n");
    }
    if (opcao == 3) {
        printf("Digite qual vai ser a nova prioridade: ");
        scanf("%d", &novaprioridade);
        Nome[num].prioridade = novaprioridade;
        printf("Prioridade alterada com sucesso!\n");
    }
    if (opcao == 4) {
        char estado[15];
        char testeestado[15];
        char testeestado2[15];
        char testeestado3[15];
        int comp;
        int comp2;
        int comp3;
        size_t len;
        sprintf(testeestado, "Completo");
        sprintf(testeestado2, "Em andamento");
        sprintf(testeestado3, "Nao iniciado");
        do {
            printf("Digite o novo estado(Completo,Em andamento ou Nao iniciado): ");
            fgets(novoestado, sizeof(novoestado), stdin);
            len = strlen(estado);
            if (estado[len - 1] == '\n')
                estado[--len] = 0;
            comp = strcmp(estado, testeestado);
            comp2 = strcmp(estado, testeestado2);
            comp3 = strcmp(estado, testeestado3);
        } while (comp != 0 && comp2 != 0 && comp3 != 0);
        sprintf(Nome[num].estado, novoestado);
        printf("Estado alterado com sucesso!\n\n");
    }
};

void FiltrartarefaPri(Tarefa Nome[]) {
    int pri;
    int contador;
    printf("Digite a prioridade que deseja filtrar: ");
    scanf("%d", &pri);
    printf("\n");
    printf("Prioridade desejada: %d", pri);
    printf("\n");
    printf("----- TAREFAS -----\n");
    printf("\n");
    for (int i = 0; i < maxtarefas; i++) {
        if (Nome[i].existe == 1)
            if (Nome[i].prioridade == pri) {
                contador = contador + 1;
                printf("Tarefa: %s", Nome[i].tarefa);
            }
    }
    if (contador == 0) {
        printf("Nao tem nenhuma tarefa com essa prioridade!\n");
    }
    printf("\n");
}

void FiltrartarefaEstado(Tarefa Nome[]) {
    int contador;
    char estado[15];
    char testeestado[15];
    char testeestado2[15];
    char testeestado3[15];
    int comp;
    int comp2;
    int comp3;
    int comp4;
    size_t len;
    sprintf(testeestado, "Completo");
    sprintf(testeestado2, "Em andamento");
    sprintf(testeestado3, "Nao iniciado");
    do {
        printf("Digite o estado que deseja filtrar(Completo,Em andamento ou Nao "
               "iniciado): ");
        fgets(estado, sizeof(estado), stdin);
        len = strlen(estado);
        if (estado[len - 1] == '\n')
            estado[--len] = 0;
        comp = strcmp(estado, testeestado);
        comp2 = strcmp(estado, testeestado2);
        comp3 = strcmp(estado, testeestado3);
    } while (comp != 0 && comp2 != 0 && comp3 != 0);
    printf("\n");
    printf("Estado desejada: %s", estado);
    printf("\n");
    printf("----- TAREFAS -----\n");
    printf("\n");
    for (int i = 0; i < maxtarefas; i++) {
        comp4 = strcmp(estado, Nome[i].estado);
        if (comp4 == 0 && Nome[i].existe == 1) {
            contador = contador + 1;
            printf("Tarefa: %s", Nome[i].tarefa);
        }
    }
    if (contador == 0) {
        printf("Nao tem nenhuma tarefa com esse estado!\n");
    }
    printf("\n");
}

void FiltrartarefaCat(Tarefa Nome[]) {
    int contador;
    char categoria[15];
    char testecat[15];
    char testecat2[15];
    char testecat3[15];
    char testecat4[15];
    int comp;
    int comp2;
    int comp3;
    int comp4;
    int comp5;
    size_t len;
    sprintf(testecat, "Casa");
    sprintf(testecat2, "Trabalho");
    sprintf(testecat3, "Estudo");
    sprintf(testecat4, "Lazer");
    do {
        printf("Digite a categoria que deseja filtrar(Casa,Trabalho,Estudo e "
               "Lazer): ");
        fgets(categoria, sizeof(categoria), stdin);
        len = strlen(categoria);
        if (categoria[len - 1] == '\n')
            categoria[--len] = 0;
        comp = strcmp(categoria, testecat);
        comp2 = strcmp(categoria, testecat2);
        comp3 = strcmp(categoria, testecat3);
        comp4 = strcmp(categoria, testecat4);
    } while (comp != 0 && comp2 != 0 && comp3 != 0 && comp4 != 0);
    printf("\n");
    printf("Categoria desejada: %s", categoria);
    printf("\n");
    printf("----- TAREFAS -----\n");
    printf("\n");
    for (int i = 0; i < maxtarefas; i++) {
        comp5 = strcmp(categoria, Nome[i].categoria);
        if (comp5 == 0 && Nome[i].existe == 1) {
            printf("Tarefa: %s", Nome[i].tarefa);
            contador += 1;
        }
    }
    if(contador == 0){
        printf("Nao tem nenhuma tarefa com essa categoria!\n");
    }
    printf("\n");
}

void FiltrartarefaCatPri(Tarefa Nome[]) {
    int pri;
    int contador;
    char categoria[15];
    char testecat[15];
    char testecat2[15];
    char testecat3[15];
    char testecat4[15];
    int comp;
    int comp2;
    int comp3;
    int comp4;
    int comp5;
    size_t len;
    sprintf(testecat, "Casa");
    sprintf(testecat2, "Trabalho");
    sprintf(testecat3, "Estudo");
    sprintf(testecat4, "Lazer");
    do {
        printf("Agora digite a categoria que deseja filtrar(Casa,Trabalho,Estudo e "
               "Lazer): ");
        fgets(categoria, sizeof(categoria), stdin);
        len = strlen(categoria);
        if (categoria[len - 1] == '\n')
            categoria[--len] = 0;
        comp = strcmp(categoria, testecat);
        comp2 = strcmp(categoria, testecat2);
        comp3 = strcmp(categoria, testecat3);
        comp4 = strcmp(categoria, testecat4);
    } while (comp != 0 && comp2 != 0 && comp3 != 0 && comp4 != 0);
    printf("Digite a prioridade que deseja filtrar: ");
    scanf("%d", &pri);
    printf("\n");
    printf("Categoria e Prioriade desejadas: %s e %d", categoria, pri);
    printf("\n");
    printf("----- TAREFAS -----\n");
    printf("\n");
    for (int i = 0; i < maxtarefas; i++) {
        comp5 = strcmp(categoria, Nome[i].categoria);
        if (Nome[i].prioridade == pri && comp5 == 0 && Nome[i].existe == 1) {
            contador = contador + 1;
            printf("Tarefa: %s", Nome[i].tarefa);
        }
    }
    if (contador == 0) {
        printf("Nao tem nenhuma tarefa com essa prioridade em comum com a "
               "categoria!\n");
    }
    printf("\n");
}

void ExportarPri(Tarefa Nome[]) {
    int contador;
    int pri;
    printf("Digite a prioridade das tarefas quais deseja exportar: ");
    scanf("%d", &pri);
    FILE *tarefaarq = fopen("tarefas.txt",
                            "w"); // cria um arquivo para a tarefa pela prioridade
    fprintf(tarefaarq, "Prioridade desejada: %d", pri);
    fprintf(tarefaarq, "\n");
    fprintf(tarefaarq, "----- TAREFAS -----\n");
    fprintf(tarefaarq, "\n");
    for (int i = 0; i < maxtarefas; i++) {
        if (Nome[i].existe == 1)
            if (Nome[i].prioridade == pri && Nome[i].existe == 1) {
                contador = contador + 1;
                fprintf(tarefaarq, "Tarefa: %s", Nome[i].tarefa);
                printf("Tarefa: %s", Nome[i].tarefa);
            }
    }

    if (contador == 0) {
        printf("Nao tem nenhuma tarefa com essa prioridade!\n");
        fprintf(tarefaarq,"Nao tem nenhuma tarefa com essa prioridade!\n");
    }
    fclose(tarefaarq);
}

void ExportarCat(Tarefa Nome[]) {
    int contador;
    char categoria[15];
    char testecat[15];
    char testecat2[15];
    char testecat3[15];
    char testecat4[15];
    int comp;
    int comp2;
    int comp3;
    int comp4;
    int comp5;
    size_t len;
    sprintf(testecat, "Casa");
    sprintf(testecat2, "Trabalho");
    sprintf(testecat3, "Estudo");
    sprintf(testecat4, "Lazer");
    do {
        printf("Digite a categoria que deseja filtrar(Casa,Trabalho,Estudo e "
               "Lazer): ");
        fgets(categoria, sizeof(categoria), stdin);
        len = strlen(categoria);
        if (categoria[len - 1] == '\n')
            categoria[--len] = 0;
        comp = strcmp(categoria, testecat);
        comp2 = strcmp(categoria, testecat2);
        comp3 = strcmp(categoria, testecat3);
        comp4 = strcmp(categoria, testecat4);
    } while (comp != 0 && comp2 != 0 && comp3 != 0 && comp4 != 0);
    FILE *tarefaarq =
            fopen("tarefas.txt", "w"); // cria um arquivo para a tarefa pela categoria
    fprintf(tarefaarq, "Categoria desejada: %s", categoria);
    fprintf(tarefaarq, "\n");
    fprintf(tarefaarq, "----- TAREFAS -----\n");
    fprintf(tarefaarq, "\n");
    for (int i = 0; i < maxtarefas; i++) {
        comp5 = strcmp(categoria, Nome[i].categoria);
        if (comp5 == 0 && Nome[i].existe == 1) {
            contador = contador + 1;
            printf("Tarefa: %s", Nome[i].tarefa);
            fprintf(tarefaarq, "Tarefa: %s", Nome[i].tarefa);
        }
    }
    if (contador == 0) {
        printf("Nao tem nenhuma tarefa com essa categoria!\n");
        fprintf(tarefaarq,"Nao tem nenhuma tarefa com essa categoria!\n");
    }
    fclose(tarefaarq);
    printf("\n");
}

void ExportarCatPri(Tarefa Nome[]) {
    int pri;
    int contador;
    char categoria[15];
    char testecat[15];
    char testecat2[15];
    char testecat3[15];
    char testecat4[15];
    int comp;
    int comp2;
    int comp3;
    int comp4;
    int comp5;
    size_t len;
    sprintf(testecat, "Casa");
    sprintf(testecat2, "Trabalho");
    sprintf(testecat3, "Estudo");
    sprintf(testecat4, "Lazer");
    do {
        printf("Agora digite a categoria que deseja filtrar(Casa,Trabalho,Estudo e "
               "Lazer): ");
        fgets(categoria, sizeof(categoria), stdin);
        len = strlen(categoria);
        if (categoria[len - 1] == '\n')
            categoria[--len] = 0;
        comp = strcmp(categoria, testecat);
        comp2 = strcmp(categoria, testecat2);
        comp3 = strcmp(categoria, testecat3);
        comp4 = strcmp(categoria, testecat4);
    } while (comp != 0 && comp2 != 0 && comp3 != 0 && comp4 != 0);
    printf("Digite a prioridade que deseja filtrar: ");
    scanf("%d", &pri);
    FILE *tarefaarq =
            fopen("tarefas.txt", "w"); // cria um arquivo para a tarefa pela categoria
    fprintf(tarefaarq, "Categoria e Prioridade desejada: %s e %d", categoria,
            pri);
    fprintf(tarefaarq, "\n");
    fprintf(tarefaarq, "----- TAREFAS -----\n");
    fprintf(tarefaarq, "\n");
    for (int i = 0; i < maxtarefas; i++) {
        comp5 = strcmp(categoria, Nome[i].categoria);
        if (Nome[i].prioridade == pri && comp5 == 0 && Nome[i].existe == 1) {
            contador = contador + 1;
            printf("Tarefa: %s", Nome[i].tarefa);
            fprintf(tarefaarq, "Tarefa: %s", Nome[i].tarefa);
        }
    }

    if (contador == 0) {
        printf("Nao tem nenhuma tarefa com essa prioridade em comum com a "
               "categoria!\n");
        fprintf(tarefaarq,"Nao tem nenhuma tarefa com essa prioridade em comum com a "
               "categoria!\n");
    }
    fclose(tarefaarq);
    printf("\n");
}

int lerarquivo(){
    FILE*arqtarefas = fopen("arqtarefas","rb");
  if(arqtarefas == NULL){
    return 1;
  } 
    fread(&Lista,sizeof(Tarefa),maxtarefas,arqtarefas);
    fclose(arqtarefas);
    return 0;
};