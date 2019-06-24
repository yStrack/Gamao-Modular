#if ! defined( BARRA_ )
#define BARRA_
/***************************************************************************
*  $MCD M�dulo de defini��o: M�dulo Barra
*
*  Arquivo gerado:              Barra.h
*  Letras identificadoras:      TAB
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: GH  - Gabriel Heffer
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*       1.00   GH   28/04/2019 Inicio do desenvolvimento
*
***************************************************************************/

#include"PECA.h"

#if defined( BARRA_OWN )
#define BARRA_EXT
#else
#define BARRA_EXT extern
#endif


/***** Declara��es exportadas pelo m�dulo *****/


/***********************************************************************
*
*  $TC Tipo de dados: BAR Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es da Barra
*
***********************************************************************/


typedef enum {

   BAR_CondRetOk = 0 ,
   /* Condi��o de retorno ok */

           BAR_FaltouMemoria = 1 ,
   /* Condi��o de retorno faltou mem�ria para aloca��o */

           BAR_NaoExiste = 2 ,
   /* Condi��o de retorno Barra n�o existe */

           BAR_PecaNaoExiste = 3 ,
   /* Condi��o de retorno erro ao inserir pe�a que n�o existe */

           BAR_BarraVazia = 4 ,
   /* Condi��o de retorno barra est� vazia */

} BAR_tpCondRet ;

/***********************************************************************
*
*  $FC Fun��o: BAR Criar Barra
*
*  $ED Descri��o da fun��o
*     Cria barra para pe�as capituradas.
*
*  $FV Valor retornado
*     BAR_CondRetOk
*     BAR_FaltouMemoria
*
*  $AE Assertivas de Entrada
*     Tem espa�o suficiente em mem�ria para alocar Barra
*
*  $AS Assertivas de Sa�da
*     Barra foi criado e inicializado
*
************************************************************************/

BAR_tpCondRet BAR_CriarBarra( void )  ;


/***********************************************************************
*
*  $FC Fun��o: BAR Destruir Barra
*
*  $ED Descri��o da fun��o
*     Destroi barra.
*
*  $AE Assertivas de Entrada
*     Barra foi criado e inicializado
*
*  $AS Assertivas de Sa�da
*     Barra ter� deixado de existir e o espa�o em mem�ria alocado por ela,
*     ter� sido liberado
*
************************************************************************/

void BAR_DestruirBarra( void ) ;


/***********************************************************************
*
*  $FC Fun��o: BAR Inserir na Barra
*
*  $EP Par�metros
*     $P peca - ponteiro para uma pe�a.
*
*  $ED Descri��o da fun��o
*     Insere peca na Barra.
*     Se Barra n�o existir nada ser� feito.
*     Se ponteiro para pe�a for nulo, inser��o n�o acontecer�.
*
*  $FV Valor retornado
*     BAR_PecaNaoExiste
*     BAR_NaoExiste
*     BAR_FaltouMemoria
*     BAR_CondRetOk
*
*  $AE Assertivas de Entrada
*     Barra foi inicializada, ponteiro para peca aponta para
*     uma pe�a inicializada corretamente, com cor.
*
*  $AS Assertivas de Sa�da
*     Barra ter� incrementado seu contador em 1 para a mesma
*     cor da pe�a passada como par�metro
*
*********************************************************************/

BAR_tpCondRet BAR_InserirBarra( tpPeca * peca ) ;


/***********************************************************************
*
*  $FC Fun��o: BAR Quantidade de pe�as na Barra.
*
*  $EP Par�metros
*     $P cor - qual pe�a deve ser verificada
*     $P quantidade - rece a quantidade de pe�as na Barra
*
*  $ED Descri��o da fun��o
*     Coloca em quantidade quantidade de pe�as capturadas.
*
*  $FV Valor retornado
*     BAR_CondRetOk
*     BAR_NaoExiste
*
*  $AE Assertivas de Entrada
*     Barra foi inicializada
*
*  $AS Assertivas de Sa�da
*     O ponteiro para inteiro aponta para um inteiro com o numero de
*     pe�as na barra da cor passada como par�metro
*
*********************************************************************/

BAR_tpCondRet BAR_QuantidadeBarra( char cor , int * quantidade ) ;


/***********************************************************************
*
*  $FC Fun��o: BAR Retirar da Barra.
*
*  $EP Par�metros
*     $P cor - qual pe�a deve ser retirada.
*     $P peca - ponteiro para uma pe�a, recebe pe�a do Tabuleiro.
*
*  $ED Descri��o da fun��o
*     Retira da Barra uma pe�a da cor passada como par�metro.
*     Se Barra n�o exitir ou Barra estiver vazia ao t�rmino da fun��o peca � null.
*
*  $FV Valor retornado
*     BAR_NaoExiste
*     BAR_BarraVazia
*     BAR_CondRetOk
*
*  $AE Assertivas de Entrada
*     Barra foi criada e inicializada
*
*  $AS Assertivas de Sa�da
*     Barra ter� decrementado seu contador em 1 para a mesma
*     cor da pe�a passada como par�metro e a pe�a apontada ser�
*     uma c�pia da pe�a que estava na casa corrente.
*
*********************************************************************/

BAR_tpCondRet BAR_RetirarBarra( tpPeca ** peca , char cor ) ;



#undef BARRA_EXT

/********** Fim do m�dulo de defini��o: M�dulo Barra **********/

#else
#endif