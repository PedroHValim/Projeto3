//
// Created by Amd on 18/09/2023.
//

#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// aqui em cima eu adicionei alguns std a mais para facilitar

void limpar() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
};

int criararquivo(Tarefa Nome[], char nomearq[]) {
    FILE *arqtarefas = fopen(nomearq, "wb");
    if (arqtarefas == NULL) {
        return 1;
    }
    fwrite(&Nome, sizeof(Tarefa), maxtarefas, arqtarefas);
    fclose(arqtarefas);
    return 0;
}

void Menu() {
    Tarefa Lista[maxtarefas];
    for (int i = 0; i < maxtarefas; i++) {
        Lista[i].existe = 0;
    }
    int cod;
    cod = lerarquivo(Lista, "arqtarefas");
    if (cod == 1) {
        printf("Nao foi possivel ler o arquivo!");
    }
    int opcao;
    do { // aqui eh praticamente so o print c o menu
        printf(" --- MENU ---\n");
        printf(
                "1 - Criar tarefa.\n2 - Deletar tarefa.\n3 - Listar tarefas.\n4 - "
                "Alterar Tarefa.\n"
                "5 - Filtrar Tarefa pela Prioridade. \n6 - Filtrar Tarefa pelo Estado. "
                "\n7 - Filtrar Tarefa pela Categoria \n"
                "8 - Filtrar Tarefa por Categoria e Prioridade \n9 - Exportar Tarefa "
                "por Prioridade \n10 - Exportar Tarefa pela Categoria \n11 - "
                "Exportar Tarefa por Categoria e Prioridade \n0 - Sair.\n");
        printf("Digite a operacao que deseja realizar: ");
        scanf("%d", &opcao);
        printf("\n");
        getchar();
        switch (opcao) { // e aqui eh aquele metodo de usar tipo, caso seja 1, caso seja 2 e etc
            case 1:
                CriarTarefa(Lista);
                break;
            case 2:
                DeletarTarefa(Lista);
                break;
            case 3:
                ListarTarefas(Lista);
                break;
            case 4:
                Alterartarefa(Lista);
                break;
            case 5:
                FiltrartarefaPri(Lista);
                break;
            case 6:
                FiltrartarefaEstado(Lista);
                break;
            case 7:
                FiltrartarefaCat(Lista);
                break;
            case 8:
                FiltrartarefaCatPri(Lista);
                break;
            case 9:
                ExportarPri(Lista);
                break;
            case 10:
                ExportarCat(Lista);
                break;
            case 11:
                ExportarCatPri(Lista);
                break;
        };
    } while (opcao != 0);
    criararquivo(Lista, "arqtarefas");
}

void CriarTarefa(Tarefa Nome[]) {
    char tarefa[100];
    char descricao[300];
    int prioridade;
    char estado[15];
    char categoria[15];
    size_t len2;
    size_t len;
    size_t len3;
    size_t len4;
    printf("Digite sua tarefa: ");
    fgets(tarefa, sizeof(tarefa), stdin); // aqui n tem mt coisa de difrente, mas
    len3 = strlen(tarefa);
    if (tarefa[len3 - 1] == '\n')tarefa[--len3] = 0;                                     // basicamente oq essa funcao faz
    printf("Digite aqui a descricao desta tarefa: "); // é a conta da variavel que a
                                                            // pessoa digitou c o maximo de
                                                            // caracteres, exemplo na
                                                            // descricao sao 300
    fgets(descricao, sizeof(descricao),stdin); // o stdin faz c oq a pessoa digite va para a variuavel
    len4 = strlen(descricao);                                   // descricao, nesse caso
    if (descricao[len4 - 1] == '\n')descricao[--len4] = 0;
    printf("Digite aqui a prioridade desta tarefa: ");
    scanf("%d", &prioridade);
    limpar();
    char testeestado[15];
    char testeestado2[15];
    char testeestado3[15];
    int comp;
    int comp2;
    int comp3;
    sprintf(testeestado, "Completo");
    sprintf(testeestado2, "Em andamento");
    sprintf(testeestado3, "Nao iniciado");
    do {
        printf("Digite o estado dessa tarefa(Completo,Em andamento ou Nao iniciado): ");
        fgets(estado, sizeof(estado), stdin);
        len = strlen(estado);
        if (estado[len - 1] == '\n')estado[--len] = 0;
        comp = strcmp(estado, testeestado);
        comp2 = strcmp(estado, testeestado2);
        comp3 = strcmp(estado, testeestado3);
    } while (comp != 0 && comp2 != 0 && comp3 != 0);
    char testecategoria[15];
    char testecategoria2[15];
    char testecategoria3[15];
    char testecategoria4[15];
    sprintf(testecategoria, "Casa");
    sprintf(testecategoria2, "Trabalho");
    sprintf(testecategoria3, "Estudo");
    sprintf(testecategoria4, "Lazer");
    int comp4;
    int comp5;
    int comp6;
    int comp7;
    do {
        printf("Digite a categoria dessa tarefa(Casa,Trabalho,Estudo e Lazer): ");
        fgets(categoria, sizeof(categoria), stdin);
        len2 = strlen(categoria);
        if (categoria[len2 - 1] == '\n')
            categoria[--len2] = 0;
        comp4 = strcmp(categoria, testecategoria);
        comp5 = strcmp(categoria, testecategoria2);
        comp6 = strcmp(categoria, testecategoria3);
        comp7 = strcmp(categoria, testecategoria4);
    } while (comp4 != 0 && comp5 != 0 && comp6 != 0 && comp7 != 0);
    for (int i = 0; i < maxtarefas; i++) {
        if (Nome[i].existe == 0) {
            strcpy(Nome[i].tarefa,
                   tarefa); // essa parte de for e if, adiciona as coisas no struct
            strcpy(Nome[i].descricao, descricao);
            strcpy(Nome[i].estado, estado);
            strcpy(Nome[i].categoria, categoria);
            Nome[i].prioridade = prioridade;
            Nome[i].existe = 1;
            break;
        };
    };
};

void DeletarTarefa(Tarefa Nome[]) {
    printf("Aqui está sua lista!\n"); // Aqui na funcao deletar, eu vejo se dentro do .existe
    ListarTarefas2(Nome); // no struct é 1 ou 0, caso seja 1 quer dizer q existe uma tarefa la
    int del;              // e eu deleto igualando esse .existe igual a 0
    printf("Qual tarefa deseja excluir: ");
    scanf("%d", &del);
    int pos = del - 1;
    Nome[pos].existe = 0;
    printf("Tarefa excluida com sucesso!");
};

void ListarTarefas(Tarefa Nome[]) {
    printf("\n--- LISTA DE TAREFAS ---\n"); // aqui passa por cada indice do array
    printf("\n");                           // e da um print para cada indice
    for (int i = 0; i < maxtarefas; i++) {
        if (Nome[i].existe == 1) {
            printf("Tarefa: %s\n", Nome[i].tarefa);
            printf("Descricao: %s\n", Nome[i].descricao);
            printf("Prioridade: %d\n", Nome[i].prioridade);
            printf("Estado: %s\n", Nome[i].estado);
            printf("Categoria: %s", Nome[i].categoria);
            printf("\n-----------------\n");
        }
    }
};

void ListarTarefas2(Tarefa Nome[]) {
    printf("\n---LISTA DE TAREFAS---\n\n");
    for (int i = 0; i < maxtarefas; i++) {                                 // essa funcao é so para deixar um "mini menu" funcao deletar
        if (Nome[i].existe == 1) {
            int num = i + 1;
            printf("Tarefa %d: %s\n", num, Nome[i].tarefa);
        }
    }
    printf("\n");
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
    printf("5. A categoria\n");
    printf("Digite o que deseja mudar: ");
    scanf("%d", &opcao);
    limpar();
    if (opcao == 1) {
        size_t len;
        printf("Digite qual vai ser a nova tarefa: ");
        fgets(novatarefa, sizeof(novatarefa), stdin);
        len = strlen(novatarefa);
        if (novatarefa[len - 1] == '\n')novatarefa[--len] = 0;
        sprintf(Nome[num].tarefa, novatarefa);
        printf("Tarefa alterada com sucesso!\n\n");
    }
    if (opcao == 2) {
        size_t len;
        printf("Digite qual vai ser a nova descricao: ");
        fgets(novadescricao, sizeof(novatarefa), stdin);
        len = strlen(novadescricao);
        if (novadescricao[len - 1] == '\n')novadescricao[--len] = 0;
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
            if (estado[len - 1] == '\n')estado[--len] = 0;
            comp = strcmp(estado, testeestado);
            comp2 = strcmp(estado, testeestado2);
            comp3 = strcmp(estado, testeestado3);
        } while (comp != 0 && comp2 != 0 && comp3 != 0);
        sprintf(Nome[num].estado, novoestado);
        printf("Estado alterado com sucesso!\n\n");
    }
    if(opcao == 5){
        char categoria[15];
        char testecat[15];
        char testecat2[15];
        char testecat3[15];
        char testecat4[15];
        int comp;
        int comp2;
        int comp3;
        int comp4;
        size_t len;
        sprintf(testecat, "Casa");
        sprintf(testecat2, "Trabalho");
        sprintf(testecat3, "Estudo");
        sprintf(testecat4, "Lazer");
        do {
            printf("Digite a nova categoria(Casa,Trabalho,Estudo e Lazer): ");
            fgets(categoria, sizeof(categoria), stdin);
            len = strlen(categoria);
            if (categoria[len - 1] == '\n')categoria[--len] = 0;
            comp = strcmp(categoria, testecat);
            comp2 = strcmp(categoria, testecat2);
            comp3 = strcmp(categoria, testecat3);
            comp4 = strcmp(categoria, testecat4);
        } while (comp != 0 && comp2 != 0 && comp3 != 0 && comp4 != 0);
        sprintf(Nome[num].categoria, categoria);
        printf("Categoria alterada com sucesso!");
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
    FILE *tarefaarq = fopen("tarefas.txt","w"); // cria um arquivo para a tarefa pela prioridade
    fprintf(tarefaarq, "Prioridade desejada: %d\n", pri);
    fprintf(tarefaarq, "----- TAREFAS -----\n");
    fprintf(tarefaarq, "\n");
    printf ("Prioridade desejada: %d\n", pri);
    printf("----- TAREFAS -----\n");
    printf("\n");
    for (int i = 0; i < maxtarefas; i++) {
        if (Nome[i].existe == 1)
            if (Nome[i].prioridade == pri && Nome[i].existe == 1) {
                contador = contador + 1;
                fprintf(tarefaarq, "Tarefa: %s (%d, %s, %s, %s)\n", Nome[i].tarefa,Nome[i].prioridade,Nome[i].categoria,Nome[i].estado,Nome[i].descricao);
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
        printf("Digite a categoria que deseja filtrar(Casa,Trabalho,Estudo e Lazer): ");
        fgets(categoria, sizeof(categoria), stdin);
        len = strlen(categoria);
        if (categoria[len - 1] == '\n')categoria[--len] = 0;
        comp = strcmp(categoria, testecat);
        comp2 = strcmp(categoria, testecat2);
        comp3 = strcmp(categoria, testecat3);
        comp4 = strcmp(categoria, testecat4);
    } while (comp != 0 && comp2 != 0 && comp3 != 0 && comp4 != 0);
    FILE *tarefaarq = fopen("tarefas.txt", "w"); // cria um arquivo para a tarefa pela categoria
    fprintf(tarefaarq, "Categoria desejada: %s\n", categoria);
    fprintf(tarefaarq, "----- TAREFAS -----\n");
    fprintf(tarefaarq, "\n");
    for(int e = 0; e < 100; e++) {
        for (int i = 0; i < maxtarefas; i++) {
            comp5 = strcmp(categoria, Nome[i].categoria);
            if (comp5 == 0 && Nome[i].existe == 1 && Nome[i].prioridade == e){
                contador = contador + 1;
                printf("Tarefa: %s\n", Nome[i].tarefa);
                fprintf(tarefaarq, "Tarefa: %s (%d, %s, %s, %s)\n", Nome[i].tarefa, Nome[i].prioridade,
                        Nome[i].categoria, Nome[i].estado, Nome[i].descricao);
            }
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
        printf("Agora digite a categoria que deseja filtrar(Casa,Trabalho,Estudo e Lazer): ");
        fgets(categoria, sizeof(categoria), stdin);
        len = strlen(categoria);
        if (categoria[len - 1] == '\n')categoria[--len] = 0;
        comp = strcmp(categoria, testecat);
        comp2 = strcmp(categoria, testecat2);
        comp3 = strcmp(categoria, testecat3);
        comp4 = strcmp(categoria, testecat4);
    } while (comp != 0 && comp2 != 0 && comp3 != 0 && comp4 != 0);
    printf("Digite a prioridade que deseja filtrar: ");
    scanf("%d", &pri);
    FILE *tarefaarq = fopen("tarefas.txt", "w"); // cria um arquivo para a tarefa pela categoria
    fprintf(tarefaarq, "Categoria e Prioridade desejada: %s e %d", categoria, pri);
    fprintf(tarefaarq, "\n");
    fprintf(tarefaarq, "----- TAREFAS -----\n");
    fprintf(tarefaarq, "\n");
    for (int i = 0; i < maxtarefas; i++) {
        comp5 = strcmp(categoria, Nome[i].categoria);
        if (Nome[i].prioridade == pri && comp5 == 0 && Nome[i].existe == 1) {
            contador = contador + 1;
            printf("Tarefa: %s\n",Nome[i].tarefa);
            fprintf(tarefaarq, "Tarefa: %s (%d, %s, %s, %s)\n", Nome[i].tarefa,Nome[i].prioridade,Nome[i].categoria,Nome[i].estado,Nome[i].descricao);

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

int lerarquivo(Tarefa Nome[], char nomearq[]) {
    FILE *arqtarefas = fopen(nomearq, "rb");
    if (arqtarefas == NULL) {
        return 1;
    }
    fread(&Nome, sizeof(Tarefa), maxtarefas, arqtarefas);
    fclose(arqtarefas);
    return 0;
};