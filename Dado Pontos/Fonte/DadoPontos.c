/***************************************************************************
*  $MCI Módulo de implementação: Módulo DadoPontos
*
*  Arquivo gerado:              DadoPontos.C
*  Letras identificadoras:      DADP
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\...\...\DadoPontos.c
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: GH  - Gabriel Heffer
*           LD  - Lucas Damo
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       3.00   LD   01/05/2019 Criação das assertivas de entrada e saída
*       2.00   GH   28/04/2019 Finalização
*       1.00   GH   21/04/2019 Início do desenvolvimento
*
***************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include"DadoPontos.h"



   typedef struct DadoPontos{
	
	   int  PontuacaoPartida ;
	      /* Pontuação na partida */
	   
	   char JogadorPem ;
	   /* Jogador Permitido a dobrar valor da Partida */

} Dpontos;

  
/********** Dados encapsulados pelo módulo *************/

   static Dpontos * Pdp = NULL ;   
      /* Ponteiro para dado Pontos */



/********* Código das funções exportadas pelo módulo **********/

/**************************************************************************
*
*  Função: DADP Criar Dado Pontos
*  ****/

   DADP_tpCondRet DADP_CriarDadoPontos( void )
   {

	   if ( Pdp != NULL )
	   {

		   DADP_DestruirDadoPontos() ;
	   }/* if */

	   Pdp = ( Dpontos * ) malloc( sizeof( Dpontos )) ;
	   if ( Pdp == NULL )
	   {

		   return DADP_FaltouMemoria ;
	   }/* if */

	   Pdp->JogadorPem = '?' ;
	   return DADP_CondRetOK ;
   }

   /**************************************************************************
*
*  Função: DADP Destruir Dado Pontos
*  ****/

   void DADP_DestruirDadoPontos ( void )
   {

	   free( Pdp );
	   Pdp = NULL ;
	   return ;
   }

/**************************************************************************
*
*  Função: DADP Iniciar Dado Pontos
*  ****/

   DADP_tpCondRet DADP_IniciarDadoPontos ( char jogador )
   {

	   if ( Pdp == NULL )
	   {

		   return DADP_NaoExiste ;
	   }/* if */

	   Pdp->JogadorPem = jogador ;
	   Pdp->PontuacaoPartida = 1 ;
	   return DADP_CondRetOK ;
   }

/**************************************************************************
*
*  Função: DADP Obter Valor Pontuação
*  ****/

   DADP_tpCondRet DADP_ObetrValorPontuacao( int * pontuacao )
   {

	   if ( Pdp == NULL )
	   {

		   return DADP_NaoExiste ;
	   }/* if */

	   else if ( Pdp->JogadorPem == '?' )
	   {

		   return DADP_NaoInicializado ;
	   }/* if */

	   * pontuacao = Pdp->PontuacaoPartida ;
	   return DADP_CondRetOK ;
   }

/**************************************************************************
*
*  Função: DADP Mudar Jogador Permitido
*  ****/

   DADP_tpCondRet DADP_MudarJogadorPermitido( char jogador )
   {

	   DADP_tpCondRet CondRet ;
	   if ( Pdp == NULL )
	   {

		   return DADP_NaoExiste ;
	   }/* if */

	   else if ( Pdp->JogadorPem == '?' )
	   {

		   CondRet = DADP_IniciarDadoPontos( jogador ) ;
		   return CondRet ;   
	   }/* if */

	   Pdp->JogadorPem = jogador ;
	   return DADP_CondRetOK ;
   }

   /**************************************************************************
*
*  Função: DADP Dobrar pontuação
*  ****/

   DADP_tpCondRet DADP_DobrarPontuacao( char jogador )
   {

	   if ( Pdp == NULL )
	   {

		   return DADP_NaoExiste ;
	   }/* if */

	   else if ( Pdp->JogadorPem == '?' )
	   {

		   return DADP_NaoInicializado ;
	   }else
	   {

		   if ( Pdp->JogadorPem != jogador )
		   {

			   return DADP_JogadorNaoPermitido ;
		   }/* if */

		   else if ( Pdp->PontuacaoPartida == 64 )
		   {

			   return DADP_PontuacaoMaxima ;
		   }/* if */

		   Pdp->PontuacaoPartida = Pdp->PontuacaoPartida * 2 ;
		   return DADP_CondRetOK ;
	   }/* if */

   }




