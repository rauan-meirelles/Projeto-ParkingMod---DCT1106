////////////////////////////////////////
////         Módulo Estaciona       ////
////////////////////////////////////////

typedef struct estaciona Estaciona;

struct estaciona {
  int dia;
  int mes;
  int ano;
  char placa[8];
  int status;
}; 

///Saida:
///ler placa
///status = 0;
///regravar (editar)

void moduloEstaciona(void);
char menuEstaciona(void);

Estaciona* telaEstacionarVei(void);
void cadastrarEst(void);
int verificaCadastroCliente(char*);
void gravarEst(Estaciona*);

char* telaRetirarVei(void);
void retirarVei(void);
Estaciona* buscarEst(char*);

void telaErro(void);





// char* telaPesquisarEst(void);
// char* telaAtualizarVei(void);
// void telaErroEstaciona(void);
// void cadastrarEst(void);
// void pesquisarVei(void);
// void atualizarVei(void);
// void retirarEst(void);

// void exibirVei(Cliente*);

// void exibirEst(Cliente*);

