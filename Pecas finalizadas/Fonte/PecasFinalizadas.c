/***************************************************************************
*  $MCI Módulo de implementação: Módulo Peças Finalizadas
*
*  Arquivo gerado:              PecasFinalizadas.C
*  Letras identificadoras:      PEF
*
*  Nome da base de software:    Teste automatizado
*  Arquivo da base de software: D:\...\...\...
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: GH  - Gabriel Heffer
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       1.00   GH   01/06/2019 Início do desenvolvimento
*
***************************************************************************/

#include   <stdio.h>
#include   <stdlib.h>
#include   "LISTA.H"
#include   "PecasFinalizadas.h"

/***********************************************************************
*
*  $TC Tipo de dado: PEF representa Peças Finalizadas de um jogo de gamão
*
*
***********************************************************************/

   struct PecFin {

	   LIS_tppLista PecFin_pretas ;
		      /* peças pretas finalizadas */

	   LIS_tppLista PecFin_brancas ;
		     /* peças brancas finalizadas */

	   int quantidade_brancas ;
		     /* quantidade de peças brancas finalizadas */

	   int quantidade_pretas ;
		    /* quantidade de peças pretas finalizadas */

   };

   typedef struct PecFin * PecFin ;

/*****  Dados encapsulados no módulo  *****/

   static PecFin pPecFin  = NULL ;
	          /* ponteiro para Peças Finalizadas */

/***** Protótipos das funções encapuladas no módulo *****/

   static void DestruirPeca( void *p ) ;

/********* Código das funções exportadas pelo módulo **********/


/**************************************************************************
*
*  Função: PEF Criar Peças Finalizadas
*  ****/

    PEF_tpCondRet PEF_CriarFinalizadas( void )
	{

		if ( pPecFin != NULL )
		{

			DestruirFinalizadas() ;
		}/* if */

		pPecFin = ( PecFin )malloc( sizeof(struct PecFin ) ) ;
		if ( pPecFin == NULL )
		{

			return PEF_FaltouMemoria ;
		}/* if */

		pPecFin->PecFin_brancas = LIS_CriarLista( DestruirPeca ) ;
		pPecFin->quantidade_brancas = 0 ;
		pPecFin->PecFin_pretas  = LIS_CriarLista( DestruirPeca ) ;
		pPecFin->quantidade_pretas = 0 ;
		return PEF_CondRetOk ;
	}


/**************************************************************************
*
*  Função: PEF Destruir Peças Finalizadas
*  ****/

	void DestruirFinalizadas( void )
	{

		if ( pPecFin != NULL )
		{

			LIS_DestruirLista( pPecFin->PecFin_brancas ) ;
			LIS_DestruirLista( pPecFin->PecFin_pretas ) ;
			free( pPecFin ) ;
			pPecFin = NULL ;
		}/* if */

		return ;
	}


/**************************************************************************
*
*  Função: PEF Inserir peça
*  ****/

	PEF_tpCondRet PEF_InserirFinalizadas( tpPeca * peca )
	{

		LIS_tppLista aux ;
		char cor ;
		tpPeca *pec ;
		if ( pPecFin == NULL )
		{

			return PEF_NaoExiste ;
		}/* if */

		if ( PCA_ObterCor( peca , &cor ) == PCA_NaoExiste )
		{

		   return PEF_PecaNaoExiste ;
		}/* if */

		PCA_ObterCor( peca , &cor ) ;
		PCA_CriarPeca( &pec , cor ) ;
		if ( cor == 'B' && LIS_InserirElementoAntes( pPecFin->PecFin_brancas , pec ) != LIS_CondRetFaltouMemoria )
		{

			pPecFin->quantidade_brancas ++ ;
			return PEF_CondRetOk ;
		}/* if */

		else if ( cor == 'P' && LIS_InserirElementoAntes( pPecFin->PecFin_pretas , pec ) != LIS_CondRetFaltouMemoria )
		{

			pPecFin->quantidade_pretas ++;
			return PEF_CondRetOk ;
		}/* if */

		return PEF_FaltouMemoria ;
	}


/**************************************************************************
*
*  Função: PEF quantidade de peças finalizadas
*  ****/

	PEF_tpCondRet PEF_quantidadeFinalizadas( char cor , int * quantidade )
	{

		if ( pPecFin == NULL )
		{

			return PEF_NaoExiste ;
		}/* if */

		if ( cor == 'B' )
		{

			*quantidade = pPecFin->quantidade_brancas ;
		}else
		{

			*quantidade = pPecFin->quantidade_pretas ;
		}/* if */

		return PEF_CondRetOk ;
	}



/*****  Código das funções encapsuladas no módulo  *****/


/***********************************************************************
*
*  $FC Função: TAB  -Destruir lista
*
*  $ED Descrição da função
*     Elimina os espços apontados pela lista
*
*  $AE Assertivas de entrada
*     Recebe um ponteiro qualquer
*
*  $AS Assertivas de saída
*     O espaço ocupado, apontado, pelo ponteiro do parâmetro terá sido liberado.
*
***********************************************************************/

	void DestruirPeca ( void * pDado )
   {

	   PCA_DestruirPeca( ( tpPeca ** ) &pDado ) ;
	   return ;
   }

/********** Fim do módulo de implementação: PEF  Peças finalizadas **********/
