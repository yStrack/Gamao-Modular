/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo de teste espec�fico
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
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*       1.00   GH   22/04/2019 Inicio do desenvolvimento
*       1.00   GH   24/04/2019 Corre��o de erros
*       1.00   GH   25/04/2019 Revis�o.
*       1.00   GH   28/04/2019 Finaliza��o.
*
*  $ED Descri��o do m�dulo
*     Este m�odulo cont�m as fun��es espec�ficas para o teste do
*     m�dulo Tabuleiro. Ilustra como redigir um interpretador de comandos
*     de teste espec�ficos utilizando o arcabou�o de teste para C.
*
*  $EIU Interface com o usu�rio pessoa
*     Comandos de teste espec�ficos para testar o m�dulo Tabuleiro:
*
*     =criar        - chama a fun��o TAB_CriarTabuleiro( )
*     =inic        - chama a fun��o TAB_InicializarTabuleiro( )
*     =ObterPEC <**Pe�a>
*                   - chama a fun��o TAB_ObterPeca( <**Pe�a> )
*                     Obs. nota��o: <Pe�a>  � o valor do par�metro
*                     que se encontra no comando de teste.
*
*     "=andar" <int>
*                   - chama a fun��o TAB_AndarTabuleiro( <int> )
*                     Obs. nota��o: <int>  � o valor do par�metro
*                     que se encontra no comando de teste.
*
*     "=IrInic"     - chama a fun��o TAB_IrInicioTabuleiro( )
*     "=IrFinal"    - chama a fun��o TAB_IrFinalTabuleiro( )
*     "=inserir" <*Pe�a>
*                   - chama a fun��o TAB_AndarTabuleiro( <*Pe�a> )
*                     Obs. nota��o: <*Pe�a>  � o valor do par�metro
*                     que se encontra no comando de teste.
*
*     "=excluir"    - chama a fun��o TAB_ExcluirPeca( )
*     "=ObterQUANT" - chama a fun��o TAB_ObterQuantidadePEC( )
*     "=destroi"    - chama a fun��o TAB_DestruirTabuleiro( )
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include"Tabuleiro.h"
#include"PECA.h"

/* Tabela dos nomes dos comandos de teste espec�ficos */

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

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TAB Efetuar opera��es de teste espec�ficas para Tabuleiro
*
*  $ED Descri��o da fun��o
*     Efetua os diversos comandos de teste espec�ficos para o m�dulo
*     Tabuleiro sendo testado.
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

      /* Testar TAB Obter uma pe�a no tabuleiro */

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
			printf("\tpe�a obtida: %c",pec ) ;
            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao obter pe�a da casa corrente." );

         } /* fim ativa: Testar TAB Obter uma pe�a no tabuleiro */

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

	   /* Testar TAB iR In�cio tabuleiro */

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
                                    "Retorno errado ao ir para in�cio do tabuleiro." );

         } /* fim ativa: Testar TAB iR In�cio tabuleiro */


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
                                    "Retorno errado ao inserir pe�a." );

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
                                    "Retorno errado ao excluir pe�a." );

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
                                    "Retorno errado ao obter quantidade de pe�as na casa corrente." );

         } /* fim ativa: Testar TAB excluir peca na casa corrente */

      
         else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
         {

            TAB_DestruirTabuleiro( ) ;

            return TST_CondRetOK ;

         } /* fim ativa: Testar ARV Destruir �rvore */

		 

      return TST_CondRetNaoConhec ;

   } /* Fim fun��o: TARV Efetuar opera��es de teste espec�ficas para �rvore */

/********** Fim do m�dulo de implementa��o: M�dulo de teste espec�fico **********/

