////////////////////////////////////////
////       Módulo Funcionario       ////
////////////////////////////////////////

typedef struct funcionario Funcionario;


struct funcionario {
  char placa[12];
  char nome[51];
  char nasc[11];
  char cpf[12];
  int status;
};


void moduloFuncionario(void);
char menuFuncionario(void);
Funcionario* telaCadastrarFuncionario(void);
void* telaPesquisarFuncionario(void);
void* telaAtualizarFuncionario(void);
void* telaExcluirFuncionario(void);
void telaErroFuncionario(void);
void cadastrarFuncionario(void);
void pesquisarFuncionario(void);
void atualizarFuncionario(void);
void excluirFuncionario(void);
void gravarFuncionario(Funcionario*);
void exibirFuncionario(Funcionario*);
Funcionario* buscarFuncionario(char*);
void exibirFuncionario(Funcionario*);
void regravarFuncionario(Funcionario*);
