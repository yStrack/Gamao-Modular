/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo Pe�as Finalizadas
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
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*       1.00   GH   01/06/2019 In�cio do desenvolvimento
*
***************************************************************************/

#include   <stdio.h>
#include   <stdlib.h>
#include   "LISTA.H"
#include   "PecasFinalizadas.h"

/***********************************************************************
*
*  $TC Tipo de dado: PEF representa Pe�as Finalizadas de um jogo de gam�o
*
*
***********************************************************************/

   struct PecFin {

	   LIS_tppLista PecFin_pretas ;
		      /* pe�as pretas finalizadas */

	   LIS_tppLista PecFin_brancas ;
		     /* pe�as brancas finalizadas */

	   int quantidade_brancas ;
		     /* quantidade de pe�as brancas finalizadas */

	   int quantidade_pretas ;
		    /* quantidade de pe�as pretas finalizadas */

   };

   typedef struct PecFin * PecFin ;

/*****  Dados encapsulados no m�dulo  *****/

   static PecFin pPecFin  = NULL ;
	          /* ponteiro para Pe�as Finalizadas */

/***** Prot�tipos das fun��es encapuladas no m�dulo *****/

   static void DestruirPeca( void *p ) ;

/********* C�digo das fun��es exportadas pelo m�dulo **********/


/**************************************************************************
*
*  Fun��o: PEF Criar Pe�as Finalizadas
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
*  Fun��o: PEF Destruir Pe�as Finalizadas
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
*  Fun��o: PEF Inserir pe�a
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
*  Fun��o: PEF quantidade de pe�as finalizadas
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



/*****  C�digo das fun��es encapsuladas no m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TAB  -Destruir lista
*
*  $ED Descri��o da fun��o
*     Elimina os espa�os apontados pela lista
*
*  $AE Assertivas de entrada
*     Recebe um ponteiro qualquer
*
*  $AS Assertivas de sa�da
*     O espa�o ocupado, apontado, pelo ponteiro do par�metro ter� sido liberado.
*
***********************************************************************/

	void DestruirPeca ( void * pDado )
   {

	   PCA_DestruirPeca( ( tpPeca ** ) &pDado ) ;
	   return ;
   }

/********** Fim do m�dulo de implementa��o: PEF  Pe�as finalizadas **********/
