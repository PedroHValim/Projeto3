//
// Created by Amd on 18/09/2023.
//

#ifndef CLIONPROJECTS_BIBLIOTECA_H
#define CLIONPROJECTS_BIBLIOTECA_H

#define maxtarefas 100

typedef struct{
    char tarefa[100];
    char descricao[300];
    int prioridade;
    int pos;
    char estado[20];
    char categoria[15];
    int existe;
}Tarefa;


void Menu();
void ListarTarefas2(Tarefa Nome[]);
void CriarTarefa(Tarefa Nome[]);
void DeletarTarefa(Tarefa Nome[]);
void ListarTarefas(Tarefa Nome[]);
int criararquivo(Tarefa Nome[],char nomearq[]);
int lerarquivo(Tarefa Nome[],char nomearq[]);
void Alterartarefa(Tarefa Nome[]);
void FiltrartarefaPri(Tarefa Nome[]);
void FiltrartarefaEstado(Tarefa Nome[]);
void FiltrartarefaCat(Tarefa Nome[]);
void FiltrartarefaCatPri(Tarefa Nome[]);
void ExportarPri(Tarefa Nome[]);
void ExportarCat(Tarefa Nome[]);
void ExportarCatPri(Tarefa Nome[]);
void limpar();

#endif //CLIONPROJECTS_BIBLIOTECA_H