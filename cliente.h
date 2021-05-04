////////////////////////////////////////
////         Módulo Cliente         ////
////////////////////////////////////////

typedef struct cliente Cliente;

struct cliente {
  int dia;
  int mes;
  int ano;
  char nasc[11];
  char nome[51];
  char matr[12];
  char celular[12];
  char placa[8];
  char cpf[12];
  int status;
};

void moduloCliente(void);
char menuCliente(void);
Cliente* telaCadastroVei(void);
char* telaPesquisarVei(void);
char* telaAtualizarVei(void);
char* telaExcluirVei(void);
void telaErroCliente(void);
void cadastrarVei(void);
void pesquisarVei(void);
void atualizarVei(void);
void excluirVei(void);
void gravarVei(Cliente*);
void exibirVei(Cliente*);
Cliente* buscarVei(char*);
void exibirVei(Cliente*);
void regravarVei(Cliente*);
