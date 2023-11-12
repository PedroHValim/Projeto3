# Projeto3
O repositório do Projeto 3 de Tarefas

Projeto 3 das Tarefas em código C.

Esse programa tem como objetivo armazenar tarefas para auxiliar no dia a dia.
O programa oferece recursos, como a prioridade da sua tareda, a descrição da tal, assim como o estado dela, podendo ser Completo, Em andamento e Nao iniciado e também fornecemos o espaço para que possa ser colocado a categoria, sendo elas, Casa, Estudos, Trabalho
e Lazer. Existe a opção, no Menu Principal, para alterar qualquer dessas coisa citadas anteriormente na sua tarefa.
O programa também tem a possibilidade de Filtrar suas tarefas, usando como parâmetro a prioridade, a categoria, o estado e até mesmo a categoria juntamento com a prioridade. Além da opção de filtrar, tem disponível a parte das exportações, onde pode adiquirir
um arquivo de texto com todas as tarefas que deseja exportar, o parâmetro para exportação é o mesmo do filtramento porém sem a opção da exportação por estado. 
Todas suas tarefas digitadas, são salvas em um arquivo quando se fecha o programa, assim, quando o abrir novamente, la terá todas as tarefas digitadas anteriormente!
Aqui vão os nomes e funções de cada opção do Programa:

CriarTarefa: Cria uma nova tarefa na Lista geral do programa, pedindo informações como, nome da tarefa, descrição, prioridade, estado e categoria. Essas informações serão armazenada em um arquivo externo e usadas para as outros funções.

DeletarTarefa: Caso queira deletar alguma tarefa, essa é a opção para isso, ja que ela retira a tarefa que desejar, da nossa Lista geral.

ListarTarefa: Uma função rápida e prática para listar todas as tarefas pertencentes a Lista geral de tarefas, que é onde está todas as tarefas digitadas pelo usuário.

Listartarefas2: Uma mini listagem de tarefas, para auxiliar nas outras funções.

FiltrartarefaPri, FiltrartarefaEstado, FiltrartarefaCat e FiltrartarefaCatPri: Todas essas funções tem como objetivo filtrar e mostrar na tela, as tarefas que o cliente deseja usando como parâmetro, respectivamente a prioridade, o estado, a categoria
e a prioridade juntamente com a categoria.

ExportarPri, ExportarCat e ExportarCatPri: Idem ao anterior, todas essas funções tem como objetivo exportar um arquivo .txt com as tarefas desejadas pelo usuário, tendo como parâmetro, respectivamente a prioridade, a categoria e 
a categoria juntamente com a prioridade.

Tudo é salvo em um arquivo externo e o programa é de extrema funcionalidade e muito interativo e fácil de se compreender! 
Espero que gostem!
