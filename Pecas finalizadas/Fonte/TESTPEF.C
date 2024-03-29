/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo de teste espec�fico
*
*  Arquivo gerado:              TESTPEF.C
*  Letras identificadoras:      PEF
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
*       1.00   GH   02/06/2019 In�cio do desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Este m�odulo cont�m as fun��es espec�ficas para o teste do
*     m�dulo DadoPontos. Ilustra como redigir um interpretador de comandos
*     de teste espec�ficos utilizando o arcabou�o de teste para C.
*
*  $EIU Interface com o usu�rio pessoa
*     Comandos de teste espec�ficos para testar o m�dulo DadoPontos:
*
*     =criar        - chama a fun��o PEF_CriarFinalizadas( )
*
*     =destruir     - chama a fun��o DestruirFinalizadas()
*     =inserir <Char>
*                   - chama a fun��o PEF_InserirFinalizadas( tpPeca )
*					Obs. nota��o: <char>  � o valor do par�metro
*                   que se encontra no comando de teste.
*     =obterQTD <char> <*int>
*                  - chama a fun��o PEF_quantidadeFinalizadas( <Char> )
*					Obs. nota��o: <Char> e <*int> s�o os valores dos par�metros
*                   que se encontram no comando de teste.
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include    "PecasFinalizadas.h"


/* Tabela dos nomes dos comandos de teste espec�ficos */

#define     CRIAR_PECFIN_CMD          "=criar"
#define     OBTER_QTD_PECFIN_CMD	  "=obterQTD"
#define     INSERIR_PECFIN_CMD        "=inserir"
#define     DESTROI_CMD				  "=destruir"


/***********************************************************************
*
*  $FC Fun��o: TPecFin Efetuar opera��es de teste espec�ficas para dado pontos
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

      PEF_tpCondRet CondRetObtido = PEF_CondRetOk;
      PEF_tpCondRet CondRetEsperada = PEF_CondRetOk;
                                      /* inicializa para qualquer coisa */

	  int valor1=0 ;
	  char jog = '?' ;
	  int  NumLidos = -1 ;
	  tpPeca *peca;

	  /* Testar PEF Criar Finalizadas */

         if ( strcmp( ComandoTeste , CRIAR_PECFIN_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = PEF_CriarFinalizadas( ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar Pe�as Finalizadas." );

         } /* fim ativa: Testar PEF Criar Finalizadas */

	  /* Testar PEF obter quantidade de pe�as finalizadas */

         else if ( strcmp( ComandoTeste , OBTER_QTD_PECFIN_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ci" ,
                               &jog , &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = PEF_quantidadeFinalizadas( jog , &valor1 ) ;
			printf("\t quantidae obtida: %d\t",valor1);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao obter quantidade de pe�as finalizadas." );

         } /* fim ativa: Testar PEF obter quantidade de pe�as finalizadas */


	  /* Testar PEF inserir pe�a ( finalizar pe�a ) */

         else if ( strcmp( ComandoTeste , INSERIR_PECFIN_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ci" , &jog ,
											&CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

			PCA_CriarPeca( &peca , jog ) ;
            CondRetObtido = PEF_InserirFinalizadas( peca ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao inserir pe�a." );

         } /* fim ativa: Testar PEF inserir pe�a ( finalizar pe�a ) */

		 else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
         {

            DestruirFinalizadas( ) ;

            return TST_CondRetOK ;

         } /* fim ativa: Testar PEF Destruir Pe�as finalizadas */


		 return TST_CondRetNaoConhec ;

   } /* Fim fun��o: PEF Efetuar opera��es de teste espec�ficas para Pe�as finalizadas */

