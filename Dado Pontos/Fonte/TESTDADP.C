/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
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
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       1.00   GH   21/04/2019 Início do desenvolvimento
*       1.00   GH   28/04/2019 Finalização
*
*  $ED Descrição do módulo
*     Este mÇodulo contém as funções específicas para o teste do
*     módulo DadoPontos. Ilustra como redigir um interpretador de comandos
*     de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo DadoPontos:
*
*     =criar        - chama a função DADP_CriarDadoPontos( )
*     =inic <Char>
*                   - chama a função DADP_IniciarDadoPontos( <Char> )
*                     Obs. notação: <Char>  é o valor do parâmetro
*                     que se encontra no comando de teste.
*
*     "=obterP" <Char>
*                   - chama a função DADP_ObetrValorPontuacao( <* int> )
*					Obs. notação: <* int>  é o valor do parâmetro
*                   que se encontra no comando de teste.
*     "=MjogPer"    - chama a função DADP_MudarJogadorPermitido( <Char> )
*					Obs. notação: <Char>  é o valor do parâmetro
*                   que se encontra no comando de teste.
*     "=DoPont"     - chama a função DADP_DobrarPontuacao( <Char> )
*					Obs. notação: <Char>  é o valor do parâmetro
*                   que se encontra no comando de teste.
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include    "DadoPontos.h"


/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIAR_DADOPONTOS_CMD          "=criar"
#define     INICIALIZAR_DADOPONTOS_CMD    "=inic"
#define     OBTER_PONTOS_DADOPONTOS_CMD	  "=obterP"
#define     MUDAR_JOGADOR_DADOPONTOS_CMD  "=MjogPer"
#define     DOBRAR_PONTOS_DADOPONTOS_CMD  "=DoPont"
#define     DESTROI_CMD					  "=destruir"


/***********************************************************************
*
*  $FC Função: TDADP Efetuar operações de teste específicas para dado pontos
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     dado pontos sendo testado.
*
*  $EP Parâmetros
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


	  /* Testar DADP Obter valor da Pontuação na partida */

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

         } /* fim ativa: Testar DADP Obter valor da Pontuação na partida */
	   

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

	/* Testar DADP Dobrar pontuação */  

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
                                    "Retorno errado ao tentar dobrar pontuação." );

         } /* fim ativa: Testar DADP Dobrar pontuação */

		 else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
         {

            DADP_DestruirDadoPontos( ) ;

            return TST_CondRetOK ;

         } /* fim ativa: Testar DADP Destruir dado pontos */


		 return TST_CondRetNaoConhec ;

   } /* Fim função: TDADP Efetuar operações de teste específicas para dado pontos */

