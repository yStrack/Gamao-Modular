/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              TESTDADO.C
*  Letras identificadoras:      TDADO
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: YS  - Yuri Strack
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       1.00   YS   15/04/2019 Inicio do desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo contém as funções específicas para o teste do
*     módulo dado. Ilustra como redigir um interpretador de comandos
*     de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo árvore:
*
*     =jogardado        - chama a função DAD_Jogar( )
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include    "DADO.H"

/* Tabela dos nomes dos comandos de teste específicos */

#define     JOGAR_DADOS_CMD       "=jogardados"

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TDADO Efetuar operações de teste específicas para o dado
*
*  $ED Descrição da função
*     Efetua o comando de teste específico para o módulo dado sendo
*     testado.
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

      DAD_tpCondRet CondRetObtido = DAD_CondRetOK;
      DAD_tpCondRet CondRetEsperada = DAD_CondRetOK;
                                      /* inicializa para qualquer coisa */

      int valor1=0;
	  int valor2=0;
	  int  NumLidos = -1 ;

      TST_tpCondRet Ret ;

      /* Testar DAD Jogar dado */

         if ( strcmp( ComandoTeste , JOGAR_DADOS_CMD ) == 0 )
         {
			 NumLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
			if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = DAD_Jogar(&valor1, &valor2) ;
			printf("\n       Valor obtido no dado1: %d \n",valor1);
			printf("       Valor obtido no dado2: %d \n",valor2);
            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao jogar dados." );
 ;

         } /* fim ativa: Testar DAD Jogar dado */

      return TST_CondRetNaoConhec ;

   } /* Fim função: TDADO Efetuar operação de teste específico para o dado */

/********** Fim do módulo de implementação: Módulo de teste específico **********/
