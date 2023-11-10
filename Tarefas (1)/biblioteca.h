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
    int existe;
}Tarefa;


void Menu();

void ListarTarefas2();
void CriarTarefa();
void DeletarTarefa();
void ListarTarefas();
void ExportarPri(Tarefa Nome[]);
void ExportarCat(Tarefa Nome[]);
void ExportarCatPri(Tarefa Nome[]);
int criararquivo();
int lerarquivo();


#endif //CLIONPROJECTS_BIBLIOTECA_H
