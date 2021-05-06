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

void moduloEstaciona(void);
char menuEstaciona(void);

Estaciona* telaEstacionarVei(void);
void cadastrarEst(void);
int verificaCadastroCliente(char*);
void gravarEst(Estaciona*);

Estaciona* telaRetirarVei(void);
void retirarVei(void);
int verificaCadEstacionamento(char*);
void excluirEst(Estaciona*);

void telaErro(void);

