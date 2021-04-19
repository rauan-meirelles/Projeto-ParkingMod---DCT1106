////////////////////////////////////////
////         Módulo Cliente         ////
////////////////////////////////////////

typedef struct cliente Cliente;

struct cliente {
  char nome[51];
  char celular[12];
  char placa[12];
  char nasc[11];
  char cpf[11];
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
