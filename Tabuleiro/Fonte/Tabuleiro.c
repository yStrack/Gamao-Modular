/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo Tabuleiro
*
*  Arquivo gerado:              Tabuleiro.c
*  Letras identificadoras:      TAB
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\...\...\Tabuleiro.c
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

   #include<stdio.h>
   #include<stdlib.h>
   #include"Tabuleiro.h"

   #define TABULEIRO_OWN
   #include"LISTA.H"
   #undef TABULEIRO_OWN
/***********************************************************************
*
*  $TC Tipo de dado: LIS representa um tabuleiro de gam�o
*
*
***********************************************************************/

   struct Tabuleiro {

	   LIS_tppLista casas ;
			   /* casas do tabuleiro */

	   short inic ;
			   /* indicador de tabuleiro inicializado */
   } ;

   typedef struct Tabuleiro * Tabuleiro ;
/*****  Dados encapsulados no m�dulo  *****/

   static Tabuleiro  pTab = NULL ;
   		   /* Ponteiro para um tabuleiro */

/***** Prot�tipos das fun��es encapuladas no m�dulo *****/

   static void DestruirValor( void * pDado ) ;

   static int CriaCasasTab( Tabuleiro tppTab ) ;

   static void DestruirPeca( void * pDado ) ;



/********* C�digo das fun��es exportadas pelo m�dulo **********/


/**************************************************************************
*
*  Fun��o: TAB Criar Tabuleiro
*  ****/

   TAB_tpCondRet TAB_CriarTabuleiro ( void )
   {

	   if ( pTab != NULL )
	   {

		   TAB_DestruirTabuleiro() ;
	   }/* if */

	   pTab = ( Tabuleiro ) malloc(sizeof( struct Tabuleiro ) ) ;
	   if ( pTab )
	   {

		   pTab->casas = LIS_CriarLista( DestruirValor ) ;
		   pTab->inic = 0 ;
		   return TAB_CondRetOk ;
	   }/* if */

	   return TAB_FaltouMemoria ;
   }


/**************************************************************************
*
*  Fun��o: TAB Destruir Tabuleiro
*  ****/

   void TAB_DestruirTabuleiro( void )
   {
	   int casas ;
	   LIS_tppLista pListaAux ;
	   if ( pTab != NULL )
	   {

		   LIS_DestruirLista ( pTab->casas ) ;
		   free( pTab ) ;
		   pTab = NULL ;
	   }/* if */

	   return ;
   }


/**************************************************************************
*
*  Fun��o: TAB Criar Casas
*  ****/

   TAB_tpCondRet TAB_InicializarTabuleiro( void )
   {

	   int verificacao ;
	   if ( pTab == NULL )
	   {

		   return TAB_NaoExiste ;
	   }/* if */

	   else if ( pTab->inic )
	   {

		   return TAB_CondRetOk ;
	   }/* if */

	   verificacao = CriaCasasTab( pTab ) ;
	   if ( verificacao == 0 )
	   {

		   return TAB_FaltouMemoria ;
	   }/* if */

	   pTab->inic = 1 ;
	   return TAB_CondRetOk ;
   }


/**************************************************************************
*
*  Fun��o: TAB Obter uma pe�a na casa corrente do tabuleiro
*  ****/

   TAB_tpCondRet TAB_ObterPeca( tpPeca **tppPeca )
   {

	   tpPeca * aux;
	   char cor;
	   if (  pTab == NULL )
	   {

		   return TAB_NaoExiste ;
	   }/* if */

	   else if ( pTab->inic == 0 )
	   {

		   return TAB_NaoInicializado ;
	   }/* if */

	   aux = ( tpPeca * ) LIS_ObterValor( ( LIS_tppLista ) LIS_ObterValor( pTab->casas ) ) ;
	   if ( aux == NULL )
	   {

		   return TAB_CasaVazia ;
	   }/* if */

	   PCA_ObterCor( aux , &cor ) ;
	   PCA_CriarPeca( tppPeca , cor ) ;
	   return TAB_CondRetOk ;
   }


/**************************************************************************
*
*  Fun��o: TAB Obter a quantidade de pe�as na casa corrente
*  ****/

   TAB_tpCondRet TAB_ObterQuantidadePEC( int * quantidade )
   {

	   int q = 0;
	   LIS_tppLista CasaCorrente ;
	   LIS_tpCondRet CondRetLis = LIS_CondRetOK;
	   if (  pTab == NULL )
	   {

		   return TAB_NaoExiste ;
	   }/* if */

	   else if ( pTab->inic == 0 )
	   {

		   return TAB_NaoInicializado ;
	   }/* if */

	   CasaCorrente = ( LIS_tppLista ) LIS_ObterValor( pTab->casas ) ;
	   IrInicioLista( CasaCorrente ) ;
	   while ( 1 )
	   {

       CondRetLis = LIS_AvancarElementoCorrente( CasaCorrente , 1 ) ;
		   if ( CondRetLis == LIS_CondRetListaVazia )
		   {
         *quantidade = q;
			   break ;
		   }
       if (CondRetLis == LIS_CondRetFimLista){
         *quantidade = q+1;
         break;
       }
		   q++ ;
	   }/* while */

	   return TAB_CondRetOk ;
   }
/**************************************************************************
*
*  Fun��o: TAB Andar no Tabuleiro
*  ****/

   TAB_tpCondRet TAB_AndarTabuleiro( int numElem )
   {

	   LIS_tpCondRet CondRetLIS ;
	   if (  pTab == NULL )
	   {

		   return TAB_NaoExiste ;
	   }/* if */

	   else if ( pTab->inic == 0 )
	   {

		   return TAB_NaoInicializado ;
	   }/* if */

	   CondRetLIS = LIS_AvancarElementoCorrente( pTab->casas , numElem ) ;
	   if ( CondRetLIS == LIS_CondRetFimLista )
	   {

		   return TAB_FimTabuleiro ;
	   }/* if */

	   return TAB_CondRetOk ;
   }

/**************************************************************************
*
*  Fun��o: TAB Ir para in�cio do Tabuleiro
*  ****/

    TAB_tpCondRet TAB_IrInicioTabuleiro( void )
	{

		if ( pTab == NULL )
		{

			return TAB_NaoExiste ;
		}/* if */

		IrInicioLista( pTab->casas ) ;
		return TAB_CondRetOk ;
	}


/**************************************************************************
*
*  Fun��o: TAB Ir para final do Tabuleiro
*  ****/

    TAB_tpCondRet TAB_IrFinalTabuleiro( void )
	{

		if ( pTab == NULL )
		{

			return TAB_NaoExiste ;
		}/* if */

		IrFinalLista( pTab->casas ) ;
		return TAB_CondRetOk ;
	}


/**************************************************************************
*
*  Fun��o: TAB Inserir Peca na casa corrente do tabuleiro
*  ****/

   TAB_tpCondRet TAB_InserirPeca( tpPeca *peca )
   {

	   char cor ;
	   tpPeca * p ;
	   LIS_tpCondRet CondRetLIS ;
	   if (  pTab == NULL )
	   {

		   return TAB_NaoExiste ;
	   }/* if */

	   else if ( pTab->inic == 0 )
	   {

		   return TAB_NaoInicializado ;
	   }/* if */

	   PCA_ObterCor( peca , &cor );
	   PCA_CriarPeca( &p , cor ) ;
	   CondRetLIS = LIS_InserirElementoAntes( ( LIS_tppLista )LIS_ObterValor( pTab->casas ) , p ) ;
	   if ( CondRetLIS == LIS_CondRetFaltouMemoria  )
	   {

		   return TAB_FaltouMemoria ;
	   }/* if */

	   return TAB_CondRetOk ;
   }


/**************************************************************************
*
*  Fun��o: TAB excluir Peca na casa corrente do tabuleiro
*  ****/

   TAB_tpCondRet TAB_ExcluirPeca( void )
   {

	   LIS_tpCondRet CondRetLIS ;
	   if (  pTab == NULL )
	   {

		   return TAB_NaoExiste ;
	   }/* if */

	   else if ( pTab->inic == 0 )
	   {

		   return TAB_NaoInicializado ;
	   }/* if */

	   CondRetLIS = LIS_ExcluirElemento( ( LIS_tppLista )LIS_ObterValor( pTab->casas ) ) ;
	   if ( CondRetLIS == LIS_CondRetListaVazia  )
	   {

		   return TAB_CasaVazia ;
	   }/* if */

	   return TAB_CondRetOk ;
   }


/********* C�digo das fun��es encapsuladas pelo m�dulo *********/


/***********************************************************************
*
*  $FC Fun��o: TAB  - Cria Casas Tabuleiro
*
*  $ED Descri��o da fun��o
*     Criar listas que armazenam as pe�as em cada casa do tabuleiro
*
***********************************************************************/

   int CriaCasasTab( Tabuleiro tppTab )
   {

	   int casas = 24 ;
	   LIS_tpCondRet CondRetLIS ;
	   LIS_tppLista LIS_Pecas ;

	   while ( casas )
	   {

		   LIS_Pecas = LIS_CriarLista( DestruirPeca ) ;
		   if ( LIS_Pecas == NULL )
		   {

			   return 0 ;
		   }/* if */

		   CondRetLIS = LIS_InserirElementoAntes( tppTab->casas ,  LIS_Pecas ) ;
		   if ( CondRetLIS == LIS_CondRetFaltouMemoria )
		   {

			   return 0;
		   }/* if */

		   casas-- ;
	   }/* while */

	   return 1 ;
   }


/***********************************************************************
*
*  $FC Fun��o: TAB  -Destruir lista
*
*  $ED Descri��o da fun��o
*     Elimina os espa�os apontados pela lista
*
***********************************************************************/

   void DestruirValor( void * pDado )
   {

	   LIS_DestruirLista( (LIS_tppLista) pDado );
   }

/***********************************************************************
*
*  $FC Fun��o: TAB  -Destruir Pe�a
*
*  $ED Descri��o da fun��o
*     Elimina os espa�os apontados para pe�as na lista
*
***********************************************************************/

   void DestruirPeca( void * pDado )
   {

	   PCA_DestruirPeca( (tpPeca ** ) &pDado ) ;
   }


/********** Fim do m�dulo de implementa��o: TAB  Tabuleiro **********/
