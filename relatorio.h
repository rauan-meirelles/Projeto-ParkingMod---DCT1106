////////////////////////////////////////
////         Módulo Relatório       ////
////////////////////////////////////////

typedef struct relatorio Relatorio;

struct relatorio {
  int dia;
  int mes;
  int ano;
  int status;
}; 

void moduloRelatorio(void);
char menuRelatorio(void);

void veiPorData(void);
void totalVeiEstacionado(void);
void totalFunciCadastrados(void);
void totalGerCadastrados(void);

Relatorio* telaVeiPorData(void);

void relatVeiPorData(Relatorio*);

void listaVeiPorData(Relatorio*);
void listaVeiTotal(void);
void listaFunciTotal(void);
void listaGerTotal(void);

void telaErroRelatório(void);
