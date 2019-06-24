/***************************************************************************
*  $MCI Módulo de implementação: Módulo Peça
*
*  Arquivo gerado:              PECA.C
*  Letras identificadoras:      PCA
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: YS  - Yuri Strack
*           LD  - Lucas Damo
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       2.00   LD   02/05/2019 Criação das assertivas de entrada e saída
*       2.00   YS   22/04/2019 Revisão de código, alteraçao nos ponteiros e finalizacao.
*       1.00   YS   22/04/2019 Inicio do desenvolvimento
*
***************************************************************************/

/* #include   <malloc.h> */
#include   <stdio.h>
#include   <stdlib.h>

#define PECA_OWN
#include "PECA.H"
#undef PECA_OWN


   struct peca{

	   char  Cor ;
        /* Cor da peca ('P' representa cor preta 'B' representa cor branca) */

   } ;

/********* Código das funções exportadas pelo módulo **********/

/**************************************************************************
*
*  Função: PCA Criar Peça
*  ****/

   PCA_tpCondRet PCA_CriarPeca( tpPeca** peca , char cor )
   {

	   *peca = ( tpPeca * ) malloc( sizeof( tpPeca )) ;
	   if ( peca == NULL )
	   {

		   return PCA_FaltouMemoria ;
	   }/* if */

	   (*peca)->Cor = cor ;
	   return PCA_CondRetOK ;
   }

/**************************************************************************
*
*  Função: PCA Destruir Peça
*  ****/

   void PCA_DestruirPeca ( tpPeca ** peca )
   {

	   free( *peca );
	   *peca = NULL ;
	   return ;
   }

/**************************************************************************
*
*  Função: PCA Obter Cor da Peça
*  ****/

   PCA_tpCondRet PCA_ObterCor( tpPeca * peca , char * cor )
   {

	   if ( peca == NULL )
	   {

		   return PCA_NaoExiste ;
	   }/* if */

	   * cor = peca->Cor ;
	   return PCA_CondRetOK ;
   }
