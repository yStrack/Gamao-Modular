/***************************************************************************
*  $MCI Módulo de implementação: Módulo Barra
*
*  Arquivo gerado:              Barra.c
*  Letras identificadoras:      BAR
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: GH  - Gabriel Heffer
*
*  $HA Histórico de evolução:
*     Vers�o  Autor    Data     Observações
*       1.00   GH   28/05/2019 Inicio do desenvolvimento.
*       2.00   GH   02/06/2019 Pequenas Mudanças nas funções
*
***************************************************************************/

   #include<stdio.h>
   #include<stdlib.h>
   #include"LISTA.H"
   #include"Barra.h"

/***********************************************************************
*
*  $TC Tipo de dado: BAR representa um tabuleiro de gamão
*
*
***********************************************************************/

   struct Barra {

	   LIS_tppLista PEC_pretas ;
		   /* peças pretas capturadas */

	    LIS_tppLista PEC_brancas ;
		   /* peças brancas capturadas */

	   int quantidade_pretas ;
		   /* quantidade de peças pretas */

	   int quantidade_brancas ;
		   /* quantidade de peças brancas */

   };

   typedef struct Barra * Barra ;

/*****  Dados encapsulados no módulo  *****/

   static Barra pBarra = NULL ;
	   /* ponteiro para Barra */

/***** Protótipos das funções encapuladas no módulo *****/

   static void DestruirPeca( void *p ) ;


/********* Código das funções exportadas pelo módulo **********/


/**************************************************************************
*
*  Função: BAR Criar Tabuleiro
*  ****/

   BAR_tpCondRet BAR_CriarBarra( void )
   {

	   if ( pBarra != NULL )
	   {

		   BAR_DestruirBarra( ) ;
	   }/* if */

	   pBarra = ( Barra ) malloc( sizeof(struct Barra) ) ;
	   if ( pBarra == NULL )
	   {

		   return BAR_FaltouMemoria ;
	   }/* if */

	   pBarra->PEC_brancas = LIS_CriarLista( DestruirPeca ) ;
	   pBarra->PEC_pretas  = LIS_CriarLista( DestruirPeca ) ;
	   pBarra->quantidade_brancas = 0 ;
	   pBarra->quantidade_pretas = 0 ;
	   return BAR_CondRetOk ;
   }


/**************************************************************************
*
*  Função: BAR Destruir Barra
*  ****/

   void BAR_DestruirBarra( void )
   {

	   if ( pBarra != NULL )
	   {

		   LIS_DestruirLista( pBarra->PEC_brancas ) ;
		   LIS_DestruirLista( pBarra->PEC_pretas  ) ;
		   free( pBarra ) ;
		   pBarra = NULL ;
	   }/* if */

	   return ;
   }


/**************************************************************************
*
*  Função: BAR Inserir Peça em Barra
*  ****/

   BAR_tpCondRet BAR_InserirBarra( tpPeca * peca )
   {

	   tpPeca *NvPeca ;
	   char  cor ;
	   if ( pBarra == NULL )
	   {

		   return BAR_NaoExiste ;
	   }/* if */

	   if ( PCA_ObterCor( peca , &cor ) == PCA_NaoExiste )
	   {

		   return BAR_PecaNaoExiste ;
	   }/* if */

	   PCA_CriarPeca( &NvPeca , cor ) ;
	   if ( cor == 'B' && LIS_InserirElementoAntes( pBarra->PEC_brancas , NvPeca ) != LIS_CondRetFaltouMemoria )
	   {

		   pBarra->quantidade_brancas ++;
		   return BAR_CondRetOk ;
	   }/* if */

	   else if ( cor == 'P' && LIS_InserirElementoAntes( pBarra->PEC_pretas , NvPeca ) != LIS_CondRetFaltouMemoria )
	   {

		   pBarra->quantidade_pretas ++;
		   return BAR_CondRetOk ;
	   }

	   return BAR_FaltouMemoria ;
   }

/**************************************************************************
*
*  Função: BAR quantidade de peças na Barra
*  ****/

   BAR_tpCondRet BAR_QuantidadeBarra( char cor , int * quantidade )
   {

	   if ( pBarra == NULL )
	   {

		   return BAR_NaoExiste ;
	   }/* if */

	   if ( cor == 'B' )
	   {

		   *quantidade = pBarra->quantidade_brancas ;
	   }else
	   {

		   *quantidade = pBarra->quantidade_pretas ;
	   }/* if */

	   return BAR_CondRetOk ;
   }


/**************************************************************************
*
*  Função: BAR Verificar se Barra da cor 'cor' está vazia
*  ****/


   BAR_tpCondRet BAR_RetirarBarra( tpPeca ** peca , char cor )
   {

	   LIS_tppLista bar ;
	   int qtd = 0;
	   *peca = NULL ;
	   if ( pBarra == NULL )
	   {

		   return BAR_NaoExiste ;
	   }/* if */

	   BAR_QuantidadeBarra( cor , &qtd ) ;
	   if ( qtd && cor == 'B' )
	   {

		   PCA_ObterCor(( tpPeca * ) LIS_ObterValor( pBarra->PEC_brancas ) , &cor ) ;
		   PCA_CriarPeca( peca , cor ) ;
		   LIS_ExcluirElemento( pBarra->PEC_brancas ) ;
		   pBarra->quantidade_brancas --;
		   return BAR_CondRetOk ;
	   }/* if */

	   else if ( qtd && cor == 'P' )
	   {

		   PCA_ObterCor(( tpPeca * ) LIS_ObterValor( pBarra->PEC_brancas ) , &cor ) ;
		   PCA_CriarPeca( peca , cor ) ;
		   LIS_ExcluirElemento( pBarra->PEC_pretas ) ;
		   pBarra->quantidade_pretas --;
		   return BAR_CondRetOk ;
	   }/* if */

	   return BAR_BarraVazia ;
   }

/*****  Código das funções encapsuladas no módulo  *****/


   void DestruirPeca ( void * pDado )
   {

	   PCA_DestruirPeca( ( tpPeca ** ) &pDado ) ;
	   return ;
   }

/********** Fim do módulo de implementação: BAR  Barra **********/
