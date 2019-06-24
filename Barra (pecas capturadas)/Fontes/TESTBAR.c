/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo de teste espec�fico
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
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*       1.00   GH   29/05/2019 Inicio do desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Este m�odulo cont�m as fun��es espec�ficas para o teste do
*     m�dulo Barra. Ilustra como redigir um interpretador de comandos
*     de teste espec�ficos utilizando o arcabou�o de teste para C.
*
*  $EIU Interface com o usu�rio pessoa
*     Comandos de teste espec�ficos para testar o m�dulo Tabuleiro:
*
*     =criar        - chama a fun��o BAR_CriarBarra( )
*     "=retirar" <**pe�a> <char>
*                   - chama a fun��o BAR_RetirarBarra( <**pe�a> , <char> )
*                     Obs. nota��o: <char> e <**pe�a>  s�o os valores dos par�metros
*                     que se encontram no comando de teste.
*
*     "=VerVazia"     - chama a fun��o BAR_QuantidadeBarra( )
*     "=inserir" <*Pe�a>
*                   - chama a fun��o BAR_InserirBarra( <*Pe�a> )
*                     Obs. nota��o: <*Pe�a>  � o valor do par�metro
*                     que se encontra no comando de teste.
*     "=destroi"    - chama a fun��o BAR_DestruirBarra( )
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include"Barra.h"
#include"PECA.h"

/* Tabela dos nomes dos comandos de teste espec�ficos */

#define     CRIAR_BAR_CMD       "=criar"
#define     RETIRAR_BAR_CMD     "=retirar"
#define     QUANTIDADE_BAR_CMD  "=quantidade"
#define     INSERIR_BAR_CMD     "=inserir"
#define     DESTRUIR_BAR_CMD    "=destruir"

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: BAR Efetuar opera��es de teste espec�ficas para Tabuleiro
*
*  $ED Descri��o da fun��o
*     Efetua os diversos comandos de teste espec�ficos para o m�dulo
*     Barra sendo testado.
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


      /* Testar BAR inserir pe�a na Barra */

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
                                    "Retorno errado ao inserir pe�a na Barra." );

         } /* fim ativa: Testar BAR Inserir uma pe�a na Barra */

      /* Testar BAR Verificar se Barra est� vazia */

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
                                    "Retorno errado para a quantidade de pe�as." );

         } /* fim ativa: Testar BAR Verificar se Barra est� vazia */

	   /* Testar BAR Retirar pe�a da Barra */

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
			printf("\tpe�a obtida = %c",pec);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao retirar pe�a da Barra." );

         } /* fim ativa: Testar BAR Retirar pe�a da Barra */


      /* Testar BAR destruir Barra */

      
         else if ( strcmp( ComandoTeste , DESTRUIR_BAR_CMD ) == 0 )
         {

            BAR_DestruirBarra( ) ;

            return TST_CondRetOK ;

         } /* fim ativa: Testar BAR destruir Barra */

		 

      return TST_CondRetNaoConhec ;

   } /* Fim fun��o: BAR Efetuar opera��es de teste espec�ficas para Barra */

/********** Fim do m�dulo de implementa��o: M�dulo de teste espec�fico **********/

