/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
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
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       1.00   GH   02/06/2019 Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Este mÇodulo contém as funções específicas para o teste do
*     módulo DadoPontos. Ilustra como redigir um interpretador de comandos
*     de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo DadoPontos:
*
*     =criar        - chama a função PEF_CriarFinalizadas( )
*
*     =destruir     - chama a função DestruirFinalizadas()
*     =inserir <Char>
*                   - chama a função PEF_InserirFinalizadas( tpPeca )
*					Obs. notação: <char>  é o valor do parâmetro
*                   que se encontra no comando de teste.
*     =obterQTD <char> <*int>
*                  - chama a função PEF_quantidadeFinalizadas( <Char> )
*					Obs. notação: <Char> e <*int> são os valores dos parâmetros
*                   que se encontram no comando de teste.
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include    "PecasFinalizadas.h"


/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIAR_PECFIN_CMD          "=criar"
#define     OBTER_QTD_PECFIN_CMD	  "=obterQTD"
#define     INSERIR_PECFIN_CMD        "=inserir"
#define     DESTROI_CMD				  "=destruir"


/***********************************************************************
*
*  $FC Função: TPecFin Efetuar operações de teste específicas para dado pontos
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
                                    "Retorno errado ao criar Peças Finalizadas." );

         } /* fim ativa: Testar PEF Criar Finalizadas */

	  /* Testar PEF obter quantidade de peças finalizadas */

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
                                    "Retorno errado ao obter quantidade de peças finalizadas." );

         } /* fim ativa: Testar PEF obter quantidade de peças finalizadas */


	  /* Testar PEF inserir peça ( finalizar peça ) */

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
                                    "Retorno errado ao inserir peça." );

         } /* fim ativa: Testar PEF inserir peça ( finalizar peça ) */

		 else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
         {

            DestruirFinalizadas( ) ;

            return TST_CondRetOK ;

         } /* fim ativa: Testar PEF Destruir Peças finalizadas */


		 return TST_CondRetNaoConhec ;

   } /* Fim função: PEF Efetuar operações de teste específicas para Peças finalizadas */

