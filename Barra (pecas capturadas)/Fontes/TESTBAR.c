/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              TESTBAR.C
*  Letras identificadoras:      BAR
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\...\...\TESTBAR
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: GH  - Gabriel Heffer
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       1.00   GH   29/05/2019 Inicio do desenvolvimento
*
*  $ED Descrição do módulo
*     Este mÇodulo contém as funções específicas para o teste do
*     módulo Barra. Ilustra como redigir um interpretador de comandos
*     de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo Tabuleiro:
*
*     =criar        - chama a função BAR_CriarBarra( )
*     "=retirar" <**peça> <char>
*                   - chama a função BAR_RetirarBarra( <**peça> , <char> )
*                     Obs. notação: <char> e <**peça>  são os valores dos parâmetros
*                     que se encontram no comando de teste.
*
*     "=VerVazia"     - chama a função BAR_QuantidadeBarra( )
*     "=inserir" <*Peça>
*                   - chama a função BAR_InserirBarra( <*Peça> )
*                     Obs. notação: <*Peça>  é o valor do parâmetro
*                     que se encontra no comando de teste.
*     "=destroi"    - chama a função BAR_DestruirBarra( )
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include"Barra.h"
#include"PECA.h"

/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIAR_BAR_CMD       "=criar"
#define     RETIRAR_BAR_CMD     "=retirar"
#define     QUANTIDADE_BAR_CMD  "=quantidade"
#define     INSERIR_BAR_CMD     "=inserir"
#define     DESTRUIR_BAR_CMD    "=destruir"

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: BAR Efetuar operações de teste específicas para Tabuleiro
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     Barra sendo testado.
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

      BAR_tpCondRet CondRetObtido   = BAR_CondRetOk ;
      BAR_tpCondRet CondRetEsperada = BAR_CondRetOk ;
                                      /* inicializa para qualquer coisa */
	  int a , b = -1;
	  char pec ='?';
      int  NumLidos = -1 ;
	  tpPeca * peca = NULL;

      /* Testar BAR Criar Barra */

         if ( strcmp( ComandoTeste , CRIAR_BAR_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */
            CondRetObtido = BAR_CriarBarra( ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar Barra." );

         } /* fim ativa: Testar BAR Criar Barra */


      /* Testar BAR inserir peça na Barra */

         else if ( strcmp( ComandoTeste , INSERIR_BAR_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ci" , &pec ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */
			
			PCA_CriarPeca( &peca , pec ) ;
            CondRetObtido = BAR_InserirBarra( peca ) ;
            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao inserir peça na Barra." );

         } /* fim ativa: Testar BAR Inserir uma peça na Barra */

      /* Testar BAR Verificar se Barra está vazia */

         else if ( strcmp( ComandoTeste , QUANTIDADE_BAR_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ci" ,
                              &pec , &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = BAR_QuantidadeBarra( pec , &b ) ;

			printf("\tquantidade obtida: %d\t",b) ;
            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado para a quantidade de peças." );

         } /* fim ativa: Testar BAR Verificar se Barra está vazia */

	   /* Testar BAR Retirar peça da Barra */

         else if ( strcmp( ComandoTeste , RETIRAR_BAR_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ci" , &pec ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */
			peca = NULL ;
            CondRetObtido = BAR_RetirarBarra( &peca , pec ) ;
			pec = '?' ;
			PCA_ObterCor( peca , &pec );
			printf("\tpeça obtida = %c",pec);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao retirar peça da Barra." );

         } /* fim ativa: Testar BAR Retirar peça da Barra */


      /* Testar BAR destruir Barra */

      
         else if ( strcmp( ComandoTeste , DESTRUIR_BAR_CMD ) == 0 )
         {

            BAR_DestruirBarra( ) ;

            return TST_CondRetOK ;

         } /* fim ativa: Testar BAR destruir Barra */

		 

      return TST_CondRetNaoConhec ;

   } /* Fim função: BAR Efetuar operações de teste específicas para Barra */

/********** Fim do módulo de implementação: Módulo de teste específico **********/

