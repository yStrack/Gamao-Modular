#include"PECA.h"
#if ! defined( Tabuleiro_ )
#define Tabuleiro_


/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo Tabuleiro
*
*  Arquivo gerado:              Tabuleiro.h
*  Letras identificadoras:      TAB
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\...\...\Tabuleiro.h
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: GH  - Gabriel Heffer
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*       2.00   GH   25/04/2019 Revis�o.
*       2.00   GH   28/04/2019 Finaliza��o.
*       2.00   GH   25/04/2019 Revis�o.
*       2.00   GH   24/04/2019 Corre��o de erros
*       1.00   GH   22/04/2019 Inicio do desenvolvimento
*
***************************************************************************/

#if defined( Tabuleiro_OWN )
   #define Tabuleiro_EXT
#else
   #define Tabuleiro_EXT extern
#endif

/***** Declara��es exportadas pelo m�dulo *****/


/* Tipo refer�ncia para um Tabuleiro */


/***********************************************************************
*
*  $TC Tipo de dados: TAB Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es do Tabuleiro
*
***********************************************************************/

   typedef enum {

	   TAB_CondRetOk = 0 ,
			   /* Condi��o de retorno ok */

	   TAB_FaltouMemoria = 1 ,
			   /* Condi��o de retorno faltou mem�ria para aloca��o */

	   TAB_NaoExiste = 2 ,
			   /* Condi��o de retorno tabuleiro n�o existe */

	   TAB_NaoInicializado = 3 ,
			   /* Condi��o de retorno Tabuleiro n�o inicializado */

	   TAB_FimTabuleiro = 4 ,
			   /* Condi��o de retorno de fim do tabuleiro */

	   TAB_CasaVazia = 5 ,
			   /* Casa n�o tem pe�as */

   } TAB_tpCondRet ;


/***********************************************************************
*
*  $FC Fun��o: TAB Criar Tabuleiro
*
*  $ED Descri��o da fun��o
*     Cria um novo Tabuleiro.
*
*
*  $FV Valor retornado
*     TAB_CondRetOk
*     TAB_FaltouMemoria
*
*  $AE Assertivas de Entrada
*     Tabuleiro n�o existe e n�o foi inicializado
*
*  $AS Assertivas de Sa�da
*     Tabuleiro ter� sido criado
*
***********************************************************************/

   TAB_tpCondRet TAB_CriarTabuleiro ( void ) ;


/***********************************************************************
*
*  $FC Fun��o: TAB Destroi Tabuleiro
*
*  $ED Descri��o da fun��o
*     Destroi um Tabuleiro.
*
*  $EP Par�metros
*     $P tppTab - Ponteiro de um tabuleiro.
*
*  $AE Assertivas de Entrada
*     Tabuleiro existe
*
*  $AS Assertivas de Sa�da
*     Tabuleiro deixar� de existir e o espa�o alocado ter� sido liberado
*
***********************************************************************/

    void TAB_DestruirTabuleiro( void ) ;


/***********************************************************************
*
*  $FC Fun��o: TAB Inicializar Tabuleiro
*
*  $ED Descri��o da fun��o
*     Inicializa um Tabuleiro.
*
*
*  $FV Valor retornado
*     TAB_CondRetOk
*     TAB_FaltouMemoria
*     TAB_NaoExiste
*
*  $AE Assertivas de Entrada
*     Tabuleiro existe mas n�o foi inicializado
*
*  $AS Assertivas de Sa�da
*     Tabuleiro ter� sido inicializado
*
***********************************************************************/

   TAB_tpCondRet TAB_InicializarTabuleiro( void ) ;


/***********************************************************************
*
*  $FC Fun��o: TAB Obter pe�a
*
*  $ED Descri��o da fun��o
*     Coloca em tppPeca o endere�o de uma c�pia de uma pe�a da casa.
*
*  $EP Par�metros
*     $P tppPeca - Ponteiro de Ponteiro para PE�A.
*
*  $FV Valor retornado
*     TAB_CondRetOk
*     TAB_NaoInicializado
*     TAB_NaoExiste
*     TAB_CasaVazia
*
*  $AE Assertivas de Entrada
*     Tabuleiro existe e foi inicializado e casa corrente aponta para
*       uma casa v�lida
*
*  $AS Assertivas de Sa�da
*     O par�metro apontar� para um ponteiro de uma pe�a igual a da
*       casa corrente
*
***********************************************************************/

   TAB_tpCondRet TAB_ObterPeca( tpPeca **tppPeca ) ;


/***********************************************************************
*
*  $FC Fun��o: TAB Andar Tabuleiro
*
*  $ED Descri��o da fun��o
*     Anda pelas casas do tabuleiro.
*     se numElem for maior que 0 anda para a direita, se for menor para a esquerda
*
*  $EP Par�metros
*     $p numElem - quantidade de casas que deve dandar apartir da corrente
*
*  $FV Valor retornado
*     TAB_CondRetOk
*     TAB_NaoInicializado
*     TAB_NaoExiste
*     TAB_FimTabuleiro
*
*  $AE Assertivas de Entrada
*     Tabuleiro existe e foi inicializado
*
*  $AS Assertivas de Sa�da
*     Casa corrente apontar� para uma nova casa, calculada a partir da
*       da casa corrente anterior acrescido de numElem
*
***********************************************************************/

   TAB_tpCondRet TAB_AndarTabuleiro( int numElem ) ;


/***********************************************************************
*
*  $FC Fun��o: TAB Ir in�cio Tabuleiro
*
*  $ED Descri��o da fun��o
*     Casa corrente passa a ser a primeira do tabuleiro
*     Faz nada se Tabuleiro n�o foi inicializado.
*
*
*  $FV Valor retornado
*     TAB_CondRetOk
*     TAB_NaoExiste
*
*  $AE Assertivas de Entrada
*     Tabuleiro existe e foi inicializado
*
*  $AS Assertivas de Sa�da
*     Casa corrente apontar� para a primeira casa do tabuleiro
*
***********************************************************************/

   TAB_tpCondRet TAB_IrInicioTabuleiro( void ) ;


/***********************************************************************
*
*  $FC Fun��o: TAB Ir final Tabuleiro
*
*  $ED Descri��o da fun��o
*     Casa corrente passa a ser a �ltima do tabuleiro
*     Faz nada se Tabuleiro n�o foi inicializado.
*
*  $FV Valor retornado
*     TAB_CondRetOk
*     TAB_NaoExiste
*
*  $AE Assertivas de Entrada
*     Tabuleiro existe e foi inicializado
*
*  $AS Assertivas de Sa�da
*     Casa corrente apontar� para a �ltima casa do tabuleiro
*
***********************************************************************/

   TAB_tpCondRet TAB_IrFinalTabuleiro( void ) ;


/***********************************************************************
*
*  $FC Fun��o: TAB Inserir pe�a
*
*  $ED Descri��o da fun��o
*     Insere uma c�pia da pe�a na casa corrente do tabuleiro.
*
*  $EP Par�metros
*     $p *peca - ponteiro para uma pe�a.
*
*  $FV Valor retornado
*     TAB_CondRetOk
*     TAB_NaoInicializado
*     TAB_NaoExiste
*
*  $AE Assertivas de Entrada
*     Ponteiro para pe�a passado como argumento aponta para uma pe�a
*       existente e v�lida, casa corrente n�o possui pe�as ou possui
*       pe�as de mesma cor da pe�a passada como argumento
*
*  $AS Assertivas de Sa�da
*     Casa corrente possuir� mais uma pe�a com a mesma cor da pe�a
*       passada como argumento
*
***********************************************************************/

   TAB_tpCondRet TAB_InserirPeca( tpPeca *peca ) ;


/***********************************************************************
*
*  $FC Fun��o: TAB excluir pe�a
*
*  $ED Descri��o da fun��o
*     exclui uma pe�a na casa corrente do tabuleiro.
*
*  $FV Valor retornado
*     TAB_CondRetOk
*     TAB_NaoInicializado
*     TAB_NaoExiste
*     TAB_CasaVazia
*
*  $AE Assertivas de Entrada
*     Casa corrente aponta para uma casa existente
*
*  $AS Assertivas de Sa�da
*     Casa corrente ter� uma pe�a a menos
*
***********************************************************************/

   TAB_tpCondRet TAB_ExcluirPeca( void ) ;

/***********************************************************************
*
*  $FC Fun��o: TAB Obter Quantidade Pe�as
*
*  $ED Descri��o da fun��o
*     Quantidade ir� receber a quantidade de pe�as na casa corrente
*
*  $EP Par�metros
*     $P *quantidade - Ponteiro para um inteiro.
*
*  $FV Valor retornado
*     TAB_CondRetOk
*     TAB_NaoInicializado
*     TAB_NaoExiste
*
* $AE Assertivos de Entrada
*     Tabuleiro existe e foi inicializado, casa corrente existe
*     e aponta para uma casa v�lida
*
* $AS Assertivas de Sa�da
*     Valor apontado pelo ponteiro para inteiro quantidade, passado comop
*       argumento, agora corresponde ao numero de pe�as na casa corrente.
*
***********************************************************************/

   TAB_tpCondRet TAB_ObterQuantidadePEC( int * quantidade ) ;


#undef Tabuleiro_EXT


/********** Fim do m�dulo de defini��o: TAB  Tabuleiro **********/


#else
#endif
