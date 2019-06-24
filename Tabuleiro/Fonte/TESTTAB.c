/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              TESTAB.C
*  Letras identificadoras:      TAB
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\...\...\TESTTAB
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: GH  - Gabriel Heffer
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       1.00   GH   22/04/2019 Inicio do desenvolvimento
*       1.00   GH   24/04/2019 Correção de erros
*       1.00   GH   25/04/2019 Revisão.
*       1.00   GH   28/04/2019 Finalização.
*
*  $ED Descrição do módulo
*     Este mÇodulo contém as funções específicas para o teste do
*     módulo Tabuleiro. Ilustra como redigir um interpretador de comandos
*     de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo Tabuleiro:
*
*     =criar        - chama a função TAB_CriarTabuleiro( )
*     =inic        - chama a função TAB_InicializarTabuleiro( )
*     =ObterPEC <**Peça>
*                   - chama a função TAB_ObterPeca( <**Peça> )
*                     Obs. notação: <Peça>  é o valor do parâmetro
*                     que se encontra no comando de teste.
*
*     "=andar" <int>
*                   - chama a função TAB_AndarTabuleiro( <int> )
*                     Obs. notação: <int>  é o valor do parâmetro
*                     que se encontra no comando de teste.
*
*     "=IrInic"     - chama a função TAB_IrInicioTabuleiro( )
*     "=IrFinal"    - chama a função TAB_IrFinalTabuleiro( )
*     "=inserir" <*Peça>
*                   - chama a função TAB_AndarTabuleiro( <*Peça> )
*                     Obs. notação: <*Peça>  é o valor do parâmetro
*                     que se encontra no comando de teste.
*
*     "=excluir"    - chama a função TAB_ExcluirPeca( )
*     "=ObterQUANT" - chama a função TAB_ObterQuantidadePEC( )
*     "=destroi"    - chama a função TAB_DestruirTabuleiro( )
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include"Tabuleiro.h"
#include"PECA.h"

/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIAR_TAB_CMD       "=criar"
#define     INIC_TAB_CMD        "=inic"
#define     OBT_PEC_CMD         "=ObterPEC"
#define     AND_TAB_CMD         "=andar"
#define     INS_PEC_CMD         "=inserir"
#define     EXC_PEC_CMD         "=excluir"
#define     OBTER_QUANT_CMD     "=ObterQUANT"
#define     DESTROI_CMD         "=destruir"
#define     IRINIC_CMD          "=IrInic"
#define     IRFINAL_CMD         "=IrFinal"

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TAB Efetuar operações de teste específicas para Tabuleiro
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     Tabuleiro sendo testado.
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

      TAB_tpCondRet CondRetObtido   = TAB_CondRetOk ;
      TAB_tpCondRet CondRetEsperada = TAB_CondRetOk ;
                                      /* inicializa para qualquer coisa */

      char ValorEsperado = '?'  ;
      char ValorObtido   = '!'  ;
      char ValorDado     = '\0' ;
	  int a , b = -1;
	  char pec ='?';
      int  NumLidos = -1 ;
	  tpPeca * peca = NULL;

      /* Testar TAB Criar Tabuleiro */

         if ( strcmp( ComandoTeste , CRIAR_TAB_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */
            CondRetObtido = TAB_CriarTabuleiro( ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar Tabuleiro." );

         } /* fim ativa: Testar TAB Criar Tabuleiro */

      /* Testar TAB inicializar Tabuleiro */

         else if ( strcmp( ComandoTeste , INIC_TAB_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = TAB_InicializarTabuleiro( ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao inicializar Tabuleiro." );

         } /* fim ativa: Testar TAB inicializar Tabuleiro */

      /* Testar TAB Obter uma peça no tabuleiro */

         else if ( strcmp( ComandoTeste , OBT_PEC_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = TAB_ObterPeca( &peca ) ;
			PCA_ObterCor( peca , &pec ) ;
			printf("\tpeça obtida: %c",pec ) ;
            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao obter peça da casa corrente." );

         } /* fim ativa: Testar TAB Obter uma peça no tabuleiro */

      /* Testar TAB andar pelas casas do tabuleiro */

         else if ( strcmp( ComandoTeste , AND_TAB_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" ,
                              &a , &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = TAB_AndarTabuleiro( a ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao andar pelas casas do tabuleiro." );

         } /* fim ativa: Testar TAB andar pelas casas do tabuleiro */

	   /* Testar TAB iR Início tabuleiro */

         else if ( strcmp( ComandoTeste , IRINIC_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = TAB_IrInicioTabuleiro(  ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao ir para início do tabuleiro." );

         } /* fim ativa: Testar TAB iR Início tabuleiro */


	   /* Testar TAB iR Final tabuleiro */

         else if ( strcmp( ComandoTeste , IRFINAL_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
                              &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = TAB_IrFinalTabuleiro(  ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao ir para o final do tabuleiro." );

         } /* fim ativa: Testar TAB iR Final tabuleiro */


      /* Testar TAB inserir peca na casa corrente */

         else if ( strcmp( ComandoTeste , INS_PEC_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ci" ,
                               &pec , &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */
			PCA_CriarPeca( &peca , pec );
            CondRetObtido = TAB_InserirPeca( peca ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao inserir peça." );

         } /* fim ativa: Testar TAB inserir peca na casa corrente */

      /* Testar TAB excluir peca na casa corrente */

         else if ( strcmp( ComandoTeste , EXC_PEC_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = TAB_ExcluirPeca(  ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao excluir peça." );

         } /* fim ativa: Testar TAB excluir peca na casa corrente */

		/* Testar TAB excluir peca na casa corrente */

         else if ( strcmp( ComandoTeste , OBTER_QUANT_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */
            CondRetObtido = TAB_ObterQuantidadePEC( &b ) ;
			printf("\t quantidade: %d",b);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao obter quantidade de peças na casa corrente." );

         } /* fim ativa: Testar TAB excluir peca na casa corrente */

      
         else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
         {

            TAB_DestruirTabuleiro( ) ;

            return TST_CondRetOK ;

         } /* fim ativa: Testar ARV Destruir árvore */

		 

      return TST_CondRetNaoConhec ;

   } /* Fim função: TARV Efetuar operações de teste específicas para árvore */

/********** Fim do módulo de implementação: Módulo de teste específico **********/

