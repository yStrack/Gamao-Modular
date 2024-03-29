/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo de teste espec�fico
*
*  Arquivo gerado:              TESTDADP.C
*  Letras identificadoras:      TDADP
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\...\...\TESTDADP.c
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: GH  - Gabriel Heffer
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*       1.00   GH   21/04/2019 In�cio do desenvolvimento
*       1.00   GH   28/04/2019 Finaliza��o
*
*  $ED Descri��o do m�dulo
*     Este m�odulo cont�m as fun��es espec�ficas para o teste do
*     m�dulo DadoPontos. Ilustra como redigir um interpretador de comandos
*     de teste espec�ficos utilizando o arcabou�o de teste para C.
*
*  $EIU Interface com o usu�rio pessoa
*     Comandos de teste espec�ficos para testar o m�dulo DadoPontos:
*
*     =criar        - chama a fun��o DADP_CriarDadoPontos( )
*     =inic <Char>
*                   - chama a fun��o DADP_IniciarDadoPontos( <Char> )
*                     Obs. nota��o: <Char>  � o valor do par�metro
*                     que se encontra no comando de teste.
*
*     "=obterP" <Char>
*                   - chama a fun��o DADP_ObetrValorPontuacao( <* int> )
*					Obs. nota��o: <* int>  � o valor do par�metro
*                   que se encontra no comando de teste.
*     "=MjogPer"    - chama a fun��o DADP_MudarJogadorPermitido( <Char> )
*					Obs. nota��o: <Char>  � o valor do par�metro
*                   que se encontra no comando de teste.
*     "=DoPont"     - chama a fun��o DADP_DobrarPontuacao( <Char> )
*					Obs. nota��o: <Char>  � o valor do par�metro
*                   que se encontra no comando de teste.
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include    "DadoPontos.h"


/* Tabela dos nomes dos comandos de teste espec�ficos */

#define     CRIAR_DADOPONTOS_CMD          "=criar"
#define     INICIALIZAR_DADOPONTOS_CMD    "=inic"
#define     OBTER_PONTOS_DADOPONTOS_CMD	  "=obterP"
#define     MUDAR_JOGADOR_DADOPONTOS_CMD  "=MjogPer"
#define     DOBRAR_PONTOS_DADOPONTOS_CMD  "=DoPont"
#define     DESTROI_CMD					  "=destruir"


/***********************************************************************
*
*  $FC Fun��o: TDADP Efetuar opera��es de teste espec�ficas para dado pontos
*
*  $ED Descri��o da fun��o
*     Efetua os diversos comandos de teste espec�ficos para o m�dulo
*     dado pontos sendo testado.
*
*  $EP Par�metros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      DADP_tpCondRet CondRetObtido = DADP_CondRetOK;
      DADP_tpCondRet CondRetEsperada = DADP_CondRetOK;
                                      /* inicializa para qualquer coisa */

	  int valor1=0 ;
	  char jog = '?' ;
	  int  NumLidos = -1 ;

	  /* Testar DADP Criar Dado Pontos */

         if ( strcmp( ComandoTeste , CRIAR_DADOPONTOS_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = DADP_CriarDadoPontos( ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar dado pontos." );

         } /* fim ativa: Testar DADP Criar dado pontos */

	  /* Testar DADP inicializar dado pontos */

         else if ( strcmp( ComandoTeste , INICIALIZAR_DADOPONTOS_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ci" ,
                               &jog , &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = DADP_IniciarDadoPontos( jog ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao incializar dado pontos." );

         } /* fim ativa: Testar DADP inicializar dado pontos */


	  /* Testar DADP Obter valor da Pontua��o na partida */

         else if ( strcmp( ComandoTeste , OBTER_PONTOS_DADOPONTOS_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" , &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = DADP_ObetrValorPontuacao( &valor1 ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao obter pontos." );

         } /* fim ativa: Testar DADP Obter valor da Pontua��o na partida */
	   

	  /* Testar DADP Mudar jogador permitido a dobrar valor da partida */

         else if ( strcmp( ComandoTeste , MUDAR_JOGADOR_DADOPONTOS_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros(  "ci" ,
                               &jog , &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = DADP_MudarJogadorPermitido( jog ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao mudar jogador." );

         } /* fim ativa: Testar DADP Mudar jogador permitido a dobrar valor da partida */

	/* Testar DADP Dobrar pontua��o */  

	  else if ( strcmp( ComandoTeste , DOBRAR_PONTOS_DADOPONTOS_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros(  "ci" ,
                               &jog , &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = DADP_DobrarPontuacao( jog ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao tentar dobrar pontua��o." );

         } /* fim ativa: Testar DADP Dobrar pontua��o */

		 else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
         {

            DADP_DestruirDadoPontos( ) ;

            return TST_CondRetOK ;

         } /* fim ativa: Testar DADP Destruir dado pontos */


		 return TST_CondRetNaoConhec ;

   } /* Fim fun��o: TDADP Efetuar opera��es de teste espec�ficas para dado pontos */

