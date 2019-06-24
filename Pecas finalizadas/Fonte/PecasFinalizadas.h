#include  "PECA.h"

/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo Pe�as Finalizadas
*
*  Arquivo gerado:              PecasFinalizadas.h
*  Letras identificadoras:      TAB
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\...\...\PecasFinalizadas.h
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: GH  - Gabriel Heffer
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*       1.00   GH   02/06/2019 Inicio de desenvolvimento
*
***************************************************************************/


/***** Declara��es exportadas pelo m�dulo *****/


/* Tipo refer�ncia para um Tabuleiro */

/***********************************************************************
*
*  $TC Tipo de dados: PEF Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es do Tabuleiro
*
***********************************************************************/

typedef enum {

   PEF_CondRetOk = 0 ,
   /* Condi��o de retorno ok */

           PEF_FaltouMemoria = 1 ,
   /* Condi��o de retorno faltou mem�ria para aloca��o */

           PEF_NaoExiste = 2 ,
   /* Condi��o de retorno estrutura para armazenar Pe�as Finalizadas n�o existe */

           PEF_PecaNaoExiste = 3 ,
   /* Condi��o de retorno pe�a n�o existe */

} PEF_tpCondRet ;


/***********************************************************************
*
*  $FC Fun��o: PEF Criar estrutura para pe�as finalizadas
*
*  $ED Descri��o da fun��o
*     Cria uma nova estrutura para pe�as finalizadas
*
*  $FV Valor retornado
*     PEF_FaltouMemoria
*     PEF_CondRetOk
*
*  $AE Assertivas de Entrada
*     Tem espa�o em mem�ria suficiente para alocar pe�as finalizadas
*
*  $AS Assertivas de Sa�da
*     Pe�as finalizadas foi criada e inicializada
*
***********************************************************************/

PEF_tpCondRet PEF_CriarFinalizadas( void ) ;


/***********************************************************************
*
*  $FC Fun��o: PEF Destruir estrutura para pe�as finalizadas
*
*  $ED Descri��o da fun��o
*     Destruir estrutura para pe�as finalizadas
*
*  $AE Assertivas de entrada
*     Pe�as finalizadas foi inicializada
*
*  $AS Assertivas de Sa�da
*     Pe�as finalizadas deixa de existir e seu espa�o alocado � liberado
*
***********************************************************************/

void DestruirFinalizadas( void ) ;


/***********************************************************************
*
*  $FC Fun��o: PEF Inserir pe�a na estrutura de pe�as finalizadas
*
*  $ED Descri��o da fun��o
*     Inserir uma pe�a ( finalizar uma pe�a )
*
*  $EP Par�metros
*     $P cor - char que representa a cor das pe�as.
*     $P tpPeca - ponteiro para uma PE�A.
*
*  $FV Valor retornado
*     PEF_NaoExiste
*     PEF_FaltouMemoria
*     PEF_CondRetOk
*
*  $AE Assertivas de Entrada
*     Pe�as finalizadas foi inicializada, ponteiro para peca aponta para
*     uma pe�a inicializada corretamente, com cor.
*
* $AS Assertivas de Sa�da
*    Pecas finalizadas ter� incrementado seu contador em 1 para a mesma
*    cor da pe�a passada como par�metro
*
***********************************************************************/

PEF_tpCondRet PEF_InserirFinalizadas( tpPeca * peca ) ;


/***********************************************************************
*
*  $FC Fun��o: PEF quantidade de pe�as finalizadas
*
*  $ED Descri��o da fun��o
*     quantidade de pe�as finalizadas da cor passada como par�metro
*
*  $EP Par�metros
*     $P cor - char que representa a cor das pe�as.
*     $P *quantidade - ponteiro para um inteiro.
*
*  $FV Valor retornado
*     PEF_NaoExiste
*     PEF_CondRetOk
*
*  $AE Assertivas de Entrada
*     Pecas finalizadas foi inicializada
*
* $AS Assertivas de Sa�da
*     O ponteiro para inteiro aponta para um inteiro com o numero de
*     pe�as finalizadas da cor passada como par�metro
*
***********************************************************************/

PEF_tpCondRet PEF_quantidadeFinalizadas( char cor , int * quantidade ) ;


/********** Fim do m�dulo de defini��o: PEF  Pe�as Finalizadas **********/
