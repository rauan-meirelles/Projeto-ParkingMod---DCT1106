////////////////////////////////////////
////       Módulo Ultilidades       ////
////////////////////////////////////////

#include <time.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>


////////////////////////////////////////////////////////////////////////
/// Faz uma pausa por n segundos, com n sendo passado como parâmetro ///
////////////////////////////////////////////////////////////////////////
///                 function developed by @flgorgonio                ///
////////////////////////////////////////////////////////////////////////

void delay(int segundos) {
  int tempo = 1000 * segundos;
  clock_t inicio = clock();
  while (clock() < inicio + tempo) {
    // não faz nada, apenas gasta tempo ///
  }
}


///////////////////////////////////////////
///           Limpa a tela              ///
///////////////////////////////////////////

void limpaTela(void) {
  if (system("clear") || system("cls")) {
  }
}


//////////////////////////////////////////////////
///  Retorna 1 se for um dígito (entre 0 e 9)  ///
///        retorna 0 caso contrário            ///
//////////////////////////////////////////////////

int ehDigito(char c) {
  if (c >= '0' && c <= '9') {
    return 1;
  } else {
    return 0;
  }
}

////////////////////////////////////////////////////////////////////////////
///         Retorna 1 se o caractere recebido for um alfabético          ///
/// (letra entre 'A' e 'Z' ou 'a' e 'z') ou retorna 0 caso contrário     ///
////////////////////////////////////////////////////////////////////////////

int ehLetra(char c) {
  if (c >= 'A' && c <= 'Z') {
    return 1;
  } else if (c >= 'a' && c <= 'z') {
    return 1;
  } else {
    return 0;
  }
}

/////////////////////////////////////////
///      Retorna 1 ano for bissexto   ///
///      Retorna 0 caso contrário     ///
/////////////////////////////////////////
/// function developed by @flgorgonio ///
/////////////////////////////////////////

int ehBissexto(int aa) {
  if ((aa % 4 == 0) && (aa % 100 != 0)) {
    return 1;
  } else if (aa % 400 == 0) {
    return 1;
  } else {
    return 0;
  }
}

//////////////////////////////////////////////
///   Retorna 1 se dia, mes e ano válido  ///
///      Retorna 0 caso contrário         ///
/////////////////////////////////////////////
///    function developed by @flgorgonio  ///
/////////////////////////////////////////////

int ehData(int dd, int mm, int aa) {
  int maiorDia;
  if (aa < 0 || mm < 1 || mm > 12)
    return 0;
  if (mm == 2) {
    if (ehBissexto(aa)) 
      maiorDia = 29;
    else
      maiorDia = 28;
  } else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
    maiorDia = 30;
  } else
    maiorDia = 31;
  if (dd < 1 || dd > maiorDia)
    return 0;
  return 1;
}



////////////////////////////////////////////////////////////
///   Retorna 1 se string for exclusivamente alfabético  ///
///            retorna 0 caso contrário                  ///
////////////////////////////////////////////////////////////
///          function developed by @flgorgonio           ///
////////////////////////////////////////////////////////////

int validarNome(char* nome) {
  for (int i=0; nome[i]!='\0'; i++) {
    if (!ehLetra(nome[i])) {
      return 0;
    }
  }
	return 1;
}



////////////////////////////////////////////////////////////
///           Retorna 1 se Cpf for válido                ///
///            retorna 0 caso contrário                  ///
////////////////////////////////////////////////////////////
///   function developed by @George Henrique Wurthmann   ///
////////////////////////////////////////////////////////////

int validarCPF(char cpf[])
{
    int i, j, digito1 = 0, digito2 = 0;
    if(strlen(cpf) != 11)
        return 0;

    else if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
            (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
            (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
            (strcmp(cpf,"99999999999") == 0)){
            return 0; ///se o CPF tiver todos os números iguais ele é inválido.
            }
        

    else
    {
        ///digito 1---------------------------------------------------
        for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--) ///multiplica os números de 10 a 2 e soma os resultados dentro de digito1
            digito1 += (cpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((cpf[9]-48) != digito1)
            return 0; ///se o digito 1 não for o mesmo que o da validação CPF é inválido
        else
        ///digito 2--------------------------------------------------
        {
            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--) ///multiplica os números de 11 a 2 e soma os resultados dentro de digito2
                    digito2 += (cpf[i]-48) * j;
        digito2 %= 11;
        if(digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if((cpf[10]-48) != digito2)
            return 0; ///se o digito 2 não for o mesmo que o da validação CPF é inválido
        }
    }
    return 1;
}


/////////////////////////////////////////////////////
///   Retorna 1 se data válida formato: ddmmaaaa  ///
///           Retorna 0 caso contrário            ///
/////////////////////////////////////////////////////
///            function by @Marcelo1403           ///
/////////////////////////////////////////////////////

int validarData(int dia, int mes, int ano) {
  int maiorDia;
  if (dia < 1 || mes < 1 || mes > 12 || ano < 0 || ano > 2020) {
    return 0;
  }
  if (mes == 2 ) {
    if (ehBissexto(ano)) {
      maiorDia = 29;
    } else {
      maiorDia = 28;
    }
  } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
    maiorDia = 30;
  } else {
    maiorDia = 31;
  }
  if (dia > maiorDia) {
    return 0;
  }
  return 1;   
}

//////////////////////////////////////////////////////
/// Retorna 1 se string é número de celular válido ///
/// (apenas dígitos) retorna 0 caso contrário      ///
//////////////////////////////////////////////////////
int validarFone(char* fone) {
  int tam;
  tam = strlen(fone);
  if (tam != 11) {
    return 0;
  }
  for (int i = 0; i < tam; i++) {
    if (!ehDigito(fone[i])) {
        return 0;
    }
  }
  return 1;
}

///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se string recebido corresponder a um número de matrícula válido 
/// (apenas dígitos) ou retorna 0 caso contrário
///
int validarMatr(char* matr) {
  int tam;
  tam = strlen(matr);
  if (tam < 10 || tam > 11) {
    return 0;
  }
  for (int i = 0; i < tam; i++) {
    if (!ehDigito(matr[i])) {
      return 0;
    }
  }
  return 1;
}



/////////////////////////////////////////////////////
///            Retorna 1 se placa válida          ///
///            Retorna 0 caso contrário           ///
/////////////////////////////////////////////////////
///
///                 INCOMPLETA
///
int validarPlaca(char* placa) {
  int verifica = 1;
  for (int i = 0; i<12; i++) {
    if ( placa [i]) {}
  }
  return verifica;
}
