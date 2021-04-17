////////////////////////////////////////
////         Módulo Cliente         ////
////////////////////////////////////////

typedef struct cliente Cliente;

struct cliente {
  char nome[51];
  char placa[9];
  char nasc[11];
  char funcao[30];
  char cpf[12];
  int status;
};

void moduloCliente(void);
char menuCliente(void);
Cliente* telaCadastroVei(void);
char* telaPesquisarAluno(void);
char* telaAtualizarVei(void);
char* telaExcluirVei(void);
void telaErroArquivo(void);
void cadastrarVei(void);
void pesquisarVei(void);
void atualizarVei(void);
void excluirVei(void);
void gravarVei(Cliente*);
void exibirVei(Cliente*);
Cliente* buscarVei(char*);
void exibirVei(Cliente*);
void regravarVei(Cliente*);
