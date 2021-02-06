///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///            Projeto Sistema de Controle de Estacionamentos               ///
///              Developed by  @rauan-meirelles - Jan, 2021                 ///
///////////////////////////////////////////////////////////////////////////////




#include <stdio.h>
#include <stdlib.h>








/// 
/// Assinaturas das funções
///
char menuPrincipal(void);

char menuCliente(void);
void telacadastrovei(void);
void telarecuperarvei(void);
void telaatualizarvaga(void);
void telaexcluirvei(void);

char menuFuncionario(void);
void telacadastrofun(void);
void telarecuperarfun(void);
void telaatualizarfun(void);
void telaexcluirfun(void);

char menuFinancas(void);
void telacadastropre(void);
void telaatualizarpre(void);
void telalucrodiario(void);

void telaSobre(void);












///
/// Programa Principal
///

int main(void) {
  char opcao;
  char escolha;
  do {
    opcao = menuPrincipal();
    switch (opcao) {
      case '1': menuCliente();
            break;
      case '2': menuFuncionario();
            break;
      case '3': menuFinancas();
            break;
      case '4': telaSobre();
            break;
    }
  } while (opcao != '0');
  return 0;
}


/// Interfaces




char menuPrincipal(void) {
  system("clear");
  char escolha;
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///              (o ! o) == ==  PARKINGMOD   = == == (o ! o)              ///\n");
	printf("///                Sistema de Controle de Estacionamentos                 ///\n");
  	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = (o ! o) = = =  Menu Principal = = = (o ! o) =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           1. Módulo Cliente                                           ///\n");
	printf("///           2. Módulo Funcionário                                       ///\n");
	printf("///           3. Módulo Finanças                                          ///\n");
	printf("///           4. Sobre                                                    ///\n");
  	printf("///           0. Encerrar programa                                        ///\n");
	printf("///                                                                       ///\n");
  	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("Escolha a opção desejada: ");
  	scanf("%c", &escolha);
	getchar();
  return escolha;
}
















char menuCliente(void) {
  system("clear");
  char escolha;
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///              (o ! o) == ==  PARKINGMOD   = == == (o ! o)              ///\n");
	printf("///                Sistema de Controle de Estacionamentos                 ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = (o ! o) = = = Menu Cliente  = = =  (o ! o)  =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           1. Cadastrar Veículo                                        ///\n");
	printf("///           2. Recuperar Veículo                                        ///\n");
	printf("///           3. Atualizar Vaga                                           ///\n");
	printf("///           4. Excluir Veículo de uma Vaga                              ///\n");
	printf("///           0. Voltar ao menu anterior                                  ///\n");
	printf("///                                                                       ///\n");
	printf("///           Escolha a opção desejada:                                   ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("Escolha a opção desejada: ");
  	scanf("%c", &escolha);
	getchar();
  return escolha;
}










void telacadastrovei(void) {
  char nome[51];
  char celular[12];
  char placa[9];
  system("clear");
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///              (o ! o) == ==  PARKINGMOD   = == == (o ! o)              ///\n");
	printf("///                Sistema de Controle de Estacionamentos                 ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = (o ! o)  =  Cadastro de Veículo =  (o ! o)  =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           1. Informe seu nome:                                        ///\n");
  	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
  	getchar();
	printf("///           2. Celular:                                                 ///\n");
  	scanf("%[0-9]", celular);
  	getchar();
	printf("///           3. Placa do Veículo:                                        ///\n");
  	scanf("%[A-Z 0-9 -]", placa);
	printf("///           0. Voltar ao menu anterior                                  ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
}









void telarecuperarvei(void) {
  char nome[51];
  char placa[9];
  system("clear");
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///              (o ! o) == ==  PARKINGMOD   = == == (o ! o)              ///\n");
	printf("///                Sistema de Controle de Estacionamentos                 ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = (o ! o)   =  Recuperar Veículo  =  (o ! o)  =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           1. Informe seu Nome:                                        ///\n");
  	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);  	
	printf("///           2. Informe a placa do Veículo:                              ///\n");
  	scanf("%[A-Z 0-9 -]", placa);
	printf("///           0. Voltar ao menu anterior                                  ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}










void telaatualizarvaga(void) {
  char nomeantigo[51];
  char nomenovo[51];
  char placantiga[9];
  char placanova[9];
  char celularantigo[12];
  char celularnovo[12];
  system("clear");
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///              (o ! o) == ==  PARKINGMOD   = == == (o ! o)              ///\n");
	printf("///                Sistema de Controle de Estacionamentos                 ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = (o ! o)   =   Atualizar Vaga    =  (o ! o)  =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///    1. Informe o nome que deseja substituir:                           ///\n");
  	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nomeantigo);
  	printf("///    2. Informe o celular que deseja substituir:                        ///\n");
  	scanf("%[0-9]", celularantigo);
	printf("///    3. Informe a placa do Veículo que deseja substituir:               ///\n");
 	scanf("%[A-Z 0-9 -]", placantiga);
	printf("///    4. Informe o novo nome:                                            ///\n");
 	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nomenovo);
  	printf("///    5. Informe o novo número de celular:                               ///\n");
  	scanf("%[0-9]", celularnovo);
  	printf("///    6. Informe a nova placa:                                           ///\n");
  	scanf("%[A-Z 0-9 -]", placanova);
	printf("///    0. Voltar ao menu anterior                                         ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}












void telaexcluirvei(void) {
  char nome[51];
  char celular[12];
  char placa[9];
  system("clear");
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///              (o ! o) == ==  PARKINGMOD   = == == (o ! o)              ///\n");
	printf("///                Sistema de Controle de Estacionamentos                 ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = (o ! o)   =   Excluir Veículo  =   (o ! o)  =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///        1. Informe seu Nome:                                           ///\n");
  	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
  	printf("///        1. Informe seu Celular:                                        ///\n");
  	scanf("%[0-9]", celular);
	printf("///        2. Informe a placa do Veículo que deseja excluir:              ///\n");
  	scanf("%[A-Z 0-9 -]", placa);
	printf("///        0. Voltar ao menu anterior                                     ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}










char menuFuncionario(void) {
  system("clear");
  char escolha;
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///              (o ! o) == ==  PARKINGMOD   = == == (o ! o)              ///\n");
	printf("///                Sistema de Controle de Estacionamentos                 ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           (o ! o) = = = Menu Funcionário  = = =  (o ! o)              ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           1. Cadastrar Funcionário                                    ///\n");
	printf("///           2. Recuperar Funcionário                                    ///\n");
	printf("///           3. Atualizar Funcionário                                    ///\n");
  	printf("///           4. Excluir Funcionário                                      ///\n");
	printf("///           0. Voltar ao menu anterior                                  ///\n");
	printf("///                                                                       ///\n");
	printf("///           Escolha a opção desejada:                                   ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("Escolha a opção desejada: ");
  scanf("%c", &escolha);
	getchar();
  return escolha;
}








void telacadastrofun(void) {
  char nome[51];
  char cpf[15];
  char funcao[30];
  system("clear");
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///              (o ! o) == ==  PARKINGMOD   = == == (o ! o)              ///\n");
	printf("///                Sistema de Controle de Estacionamentos                 ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = (o ! o) = Cadastro de Funcionário = (o ! o) =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           1. Informe seu nome:                                        ///\n");
  	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
	printf("///           2. CPF:                                                     ///\n");
  	scanf("%[0-9.-]", cpf);
	printf("///           3. Sua função:                                              ///\n");
  	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", funcao);
	printf("///           0. Voltar ao menu anterior                                  ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}










void telarecuperarfun(void) {
  char nome[51];
  char cpf[15];
  system("clear");
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///              (o ! o) == ==  PARKINGMOD   = == == (o ! o)              ///\n");
	printf("///                Sistema de Controle de Estacionamentos                 ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = (o ! o)   =  Recuperar Função   =  (o ! o)  =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           1. Informe seu CPF:                                         ///\n");
  	scanf("%[0-9.-]", cpf);	
	printf("///           2. Informe seu nome:                                        ///\n");
  	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
	printf("///           0. Voltar ao menu anterior                                  ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}








void telaatualizarfun(void) {
  char nomeantigo[51];
  char nomenovo[51];
  char cpfantigo[15];
  char cpfnovo[15];
  char funcaoantiga[20];
  char funcaonova[20];
  system("clear");
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///              (o ! o) == ==  PARKINGMOD   = == == (o ! o)              ///\n");
	printf("///                Sistema de Controle de Estacionamentos                 ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = (o ! o) =  Atualizar Funcionário  = (o ! o) =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///     1. Informe o nome que deseja substituir:                          ///\n");
  	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nomeantigo);
	printf("///     2. Informe o CPF que deseja substituir:                           ///\n");
  	scanf("%[0-9.-]", cpfantigo);	
	printf("///     3. Informe a Função que deseja substituir:                        ///\n");
  	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", funcaoantiga);
	printf("///     4. Informe o novo nome:                                           ///\n");
  	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nomenovo);
	printf("///     5. Informe o novo CPF:                                            ///\n");
  	scanf("%[0-9.-]", cpfnovo);
	printf("///     6. Informe a nova função:                                         ///\n");
  	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", funcaonova);
	printf("///     0. Voltar ao menu anterior                                        ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}










void telaexcluirfun(void) {
  char nome[51];
  char cpf[15];
  char funcao[30];
  system("clear");
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///              (o ! o) == ==  PARKINGMOD   = == == (o ! o)              ///\n");
	printf("///                Sistema de Controle de Estacionamentos                 ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = (o ! o)  = Excluir Funcionário =  (o ! o)   =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///        1. Informe o nome para ser excluido:                           ///\n");
  	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);	
	printf("///        2. Informe o CPF:                                              ///\n");
 	scanf("%[0-9.-]", cpf);
	printf("///        3. Informe a função:                                           ///\n");
  	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", funcao);
	printf("///        0. Voltar ao menu anterior                                     ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
    	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}










char menuFinancas(void) {
  system("clear");
  char escolha;
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///              (o ! o) == ==  PARKINGMOD   = == == (o ! o)              ///\n");
	printf("///                Sistema de Controle de Estacionamentos                 ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           =  (o ! o) = = = Menu Finanças  = = =  (o ! o) =            ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           1. Cadastrar preços das vagas (em real)                     ///\n");
	printf("///           2. Rever preço das Vagas                                    ///\n");
	printf("///           3. Atualizar preço das Vagas (em real)                      ///\n");
  	printf("///           4. Lucro diário                                             ///\n");
	printf("///           0. Voltar ao menu anterior                                  ///\n");
	printf("///                                                                       ///\n");
	printf("///           Escolha a opção desejada:                                   ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("Escolha a opção desejada: ");
  	scanf("%c", &escolha);
	getchar();
  return escolha;
}









void telacadastropre(void) {
  char preco[20];
  system("clear");
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///              (o ! o) == ==  PARKINGMOD   = == == (o ! o)              ///\n");
	printf("///                Sistema de Controle de Estacionamentos                 ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = (o ! o)   =  Cadastro de Preço   =  (o ! o) =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///     1. Informe o preço fixo das vagas por dia, em reais:              ///\n");
  	scanf("%[0-9,]", preco);
	printf("///     0. Voltar ao menu anterior                                        ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}








void telaatualizarpre(void) {
  char precoantigo[9];
  char preconovo[9];
  system("clear");
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///              (o ! o) == ==  PARKINGMOD   = == == (o ! o)              ///\n");
	printf("///                Sistema de Controle de Estacionamentos                 ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           =(o ! o) = Atualizar Preço das Vagas = (o ! o)=             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           1. Informe o preço anterior, em real:                       ///\n");
  	scanf("%[0-9,]", precoantigo);	
	printf("///           2. Informe o novo preço, em real:                           ///\n");
  	scanf("%[0-9,]", preconovo);
	printf("///           0. Voltar ao menu anterior                                  ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}



void telalucrodiario(void) {
  char vaga[5];
  system("clear");
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///              (o ! o) == ==  PARKINGMOD   = == == (o ! o)              ///\n");
	printf("///                Sistema de Controle de Estacionamentos                 ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           =   (o ! o)   =   Lúcro Diário   =  (o ! o)   =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///     1. Informe a quantidade de vagas ocupadas atualmente:             ///\n");
  	scanf("%[0-9]", vaga);
	printf("///     0. Voltar ao menu anterior                                        ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}







void telaSobre(void) {
  system("clear");
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///             Universidade Federal do Rio Grande do Norte               ///\n");
	printf("///                 Centro de Ensino Superior do Seridó                   ///\n");
	printf("///               Departamento de Computação e Tecnologia                 ///\n");
	printf("///                  Disciplina DCT1106 -- Programação                    ///\n");
	printf("///            Projeto Sistema de Controle de Estacionamentos             ///\n");
 	printf("///              = == ==       PARKINGMOD        = == ==                  ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///                               (o ! o)                                 ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///   == == ParkingMod: Um Sistema de Controle de Estacionamentos == ==   ///\n");
	printf("///                                                                       ///\n");
	printf("///    Programa utilizado com a intenção de facilitar a admnistração de   ///\n");
	printf("///   estacionamentos, para fins de organização e de admnistração. O      ///\n");
	printf("///   programa contém os principais módulos e funcionalidades úteis que   ///\n");
	printf("///   serão usados para tornar o estacionamneto mais viável e mais bem    ///\n");
	printf("///   avaliado por seus ultilizadores. Como: Vagas disponíveis e          ///\n");
	printf("///   Indisponíveis, Preços por hora das vagas , entre outros, como       ///\n");
	printf("///   o Lucro final diário.                                               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///    Em desenvolvimento pelo aluno de Sistemas da Informação - UFRN     ///\n");
	printf("///                 Rauan Meirelles Dantas de Araújo                      ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}
