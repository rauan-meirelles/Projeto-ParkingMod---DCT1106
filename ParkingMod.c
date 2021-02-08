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


void menuCliente(void);
void telaCadastroVei(void);
void telaRecuperarVei(void);
void telaAtualizarVaga(void);
void telaExcluirVei(void);


void menuFuncionario(void);
void telaCadastroFun(void);
void telaRecuperarFun(void);
void telaAtualizarFun(void);
void telaExcluirFun(void);


void menuFinancas(void);
void telaCadastroPre(void);
void telaAtualizarPre(void);
void telaLucroDiario(void);


void telaSobre(void);
























///
/// Programa Principal
///


int main(void) {
  char opcao;
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
































void menuCliente(void) {
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
  do {
    switch (escolha) {
      case '1': telaCadastroVei();
            break;
      case '2': telaRecuperarVei();
            break;
      case '3': telaAtualizarVaga();
            break;
      case '4': telaExcluirVei();
            break;
    }
  } while (escolha != '0');
  
}


















void telaCadastroVei(void) {
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
    	getchar();
	printf("///           0. Voltar ao menu anterior                                  ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
}


















void telaRecuperarVei(void) {
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
    	getchar();  	
	printf("///           2. Informe a placa do Veículo:                              ///\n");
    	scanf("%[A-Z 0-9 -]", placa);
    	getchar();
	printf("///           0. Voltar ao menu anterior                                  ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}




















void telaAtualizarVaga(void) {
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
    	getchar();
  	printf("///    2. Informe o celular que deseja substituir:                      ///\n");
  	scanf("%[0-9]", celularantigo);
    	getchar();
	printf("///    3. Informe a placa do Veículo que deseja substituir:               ///\n");
 	scanf("%[A-Z 0-9 -]", placantiga);
    	getchar();
	printf("///    4. Informe o novo nome:                                            ///\n");
 	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nomenovo);
    	getchar();
  	printf("///    5. Informe o novo número de celular:                               ///\n");
  	scanf("%[0-9]", celularnovo);
    	getchar();
  	printf("///    6. Informe a nova placa:                                           ///\n");
  	scanf("%[A-Z 0-9 -]", placanova);
    	getchar();
	printf("///    0. Voltar ao menu anterior                                         ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}
























void telaExcluirVei(void) {
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
    	getchar();
  	printf("///        1. Informe seu Celular:                                        ///\n");
  	scanf("%[0-9]", celular);
    	getchar();
	printf("///        2. Informe a placa do Veículo que deseja excluir:              ///\n");
  	scanf("%[A-Z 0-9 -]", placa);
    	getchar();
	printf("///        0. Voltar ao menu anterior                                     ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}




















void menuFuncionario(void) {
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
  do {
    switch (escolha) {
      case '1': telaCadastroFun();
            break;
      case '2': telaRecuperarFun();
            break;
      case '3': telaAtualizarFun();
            break;
      case '4': telaExcluirFun();
            break;
    }
  } while (escolha != '0');
  
}












void telaCadastroFun(void) {
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
    	getchar();
	printf("///           2. CPF:                                                     ///\n");
  	scanf("%[0-9.-]", cpf);
    	getchar();
	printf("///           3. Sua função:                                              ///\n");
  	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", funcao);
    	getchar();
	printf("///           0. Voltar ao menu anterior                                  ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}




















void telaRecuperarFun(void) {
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
    	getchar();	
	printf("///           2. Informe seu nome:                                        ///\n");
  	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
    	getchar();
	printf("///           0. Voltar ao menu anterior                                  ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}
















void telaAtualizarFun(void) {
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
    	getchar();
	printf("///     2. Informe o CPF que deseja substituir:                           ///\n");
  	scanf("%[0-9.-]", cpfantigo);
    	getchar();	
	printf("///     3. Informe a Função que deseja substituir:                        ///\n");
  	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", funcaoantiga);
    	getchar();
	printf("///     4. Informe o novo nome:                                           ///\n");
  	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nomenovo);
    	getchar();
	printf("///     5. Informe o novo CPF:                                            ///\n");
  	scanf("%[0-9.-]", cpfnovo);
    	getchar();
	printf("///     6. Informe a nova função:                                         ///\n");
  	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", funcaonova);
    	getchar();
	printf("///     0. Voltar ao menu anterior                                        ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}




















void telaExcluirFun(void) {
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
    	getchar();	
	printf("///        2. Informe o CPF:                                              ///\n");
 	scanf("%[0-9.-]", cpf);
    	getchar();
	printf("///        3. Informe a função:                                           ///\n");
  	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", funcao);
    	getchar();
	printf("///        0. Voltar ao menu anterior                                     ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
    	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}




















void menuFinancas(void) {
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
  do {
    switch (escolha) {
      case '1': telaCadastroPre();
            break;
      case '3': telaAtualizarPre();
            break;
      case '4': telaLucroDiario();
            break;
    }
  } while (escolha != '0');
  
}


















void telaCadastroPre(void) {
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
    	getchar();
	printf("///     0. Voltar ao menu anterior                                        ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}
















void telaAtualizarPre(void) {
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
   	getchar();	
	printf("///           2. Informe o novo preço, em real:                           ///\n");
  	scanf("%[0-9,]", preconovo);
    	getchar();
	printf("///           0. Voltar ao menu anterior                                  ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}






void telaLucroDiario(void) {
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
    	getchar();
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
