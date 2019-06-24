/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo DadoPontos
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
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*       3.00   LD   01/05/2019 Cria��o das assertivas de entrada e sa�da
*       2.00   GH   28/04/2019 Finaliza��o
*       1.00   GH   21/04/2019 In�cio do desenvolvimento
*
***************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include"DadoPontos.h"



   typedef struct DadoPontos{
	
	   int  PontuacaoPartida ;
	      /* Pontua��o na partida */
	   
	   char JogadorPem ;
	   /* Jogador Permitido a dobrar valor da Partida */

} Dpontos;

  
/********** Dados encapsulados pelo m�dulo *************/

   static Dpontos * Pdp = NULL ;   
      /* Ponteiro para dado Pontos */



/********* C�digo das fun��es exportadas pelo m�dulo **********/

/**************************************************************************
*
*  Fun��o: DADP Criar Dado Pontos
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
*  Fun��o: DADP Destruir Dado Pontos
*  ****/

   void DADP_DestruirDadoPontos ( void )
   {

	   free( Pdp );
	   Pdp = NULL ;
	   return ;
   }

/**************************************************************************
*
*  Fun��o: DADP Iniciar Dado Pontos
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
*  Fun��o: DADP Obter Valor Pontua��o
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
*  Fun��o: DADP Mudar Jogador Permitido
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
*  Fun��o: DADP Dobrar pontua��o
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

		   if ( Pdp->JogadorPem != jogador)
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


      /**************************************************************************
*
*  Fun��o: DADP Dono dado
*  ****/

   DADP_tpCondRet DADP_DonoDado ( char* jogador ){
	   *jogador = Pdp->JogadorPem;
	   return DADP_CondRetOK;
   }