////////////////////////////////////////
////         Módulo Gerençia        ////
////////////////////////////////////////

typedef struct gerente Gerente;


struct gerente {
  int dia;
  int mes;
  int ano;
  char nome[51];
  char cpf[12];
  int status;
};


void moduloGerente(void);
char menuGerente(void);
Gerente* telaCadastrarGerente(void);
void* telaPesquisarGerente(void);
void* telaAtualizarGerente(void);
void* telaExcluirGerente(void);
void telaErroGerente(void);
void cadastrarGerente(void);
void pesquisarGerente(void);
void atualizarGerente(void);
void excluirGerente(void);
void gravarGerente(Gerente*);
void exibirGerente(Gerente*);
Gerente* buscarGerente(char*);
void exibirGerente(Gerente*);
void regravarGerente(Gerente*);
