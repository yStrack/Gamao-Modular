/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              TESTPECA.C
*  Letras identificadoras:      TPCA
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: YS  - Yuri Strack
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       2.00   YS   22/04/2019 Revisão de código, alteraçao nos ponteiros e finalizacao.
*       1.00   YS   22/04/2019 Inicio do desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo contém as funções específicas para o teste do
*     módulo peça. Ilustra como redigir um interpretador de comandos
*     de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo árvore:
*
*     =criarpeca           - chama a função PCA_CriarPeca( )
*     =destruirpeca        - chama a função PCA_DestruirPeca( )
*     =obtercor            - chama a função PCA_ObterCor( )
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include    "PECA.H"

/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIA_PECA_CMD       "=criarpeca"
#define     DESTROI_PECA_CMD    "=destruirpeca"
#define     OBTEM_COR_CMD       "=obtercor"

tpPeca* vPeca[3] = {NULL,NULL,NULL};
        /* vetor de ponteiros para peças */

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TPCA Efetuar operações de teste específicas para a peça
*
*  $ED Descrição da função
*     Efetua diversos comandos de teste específicos para o módulo peça sendo
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

      PCA_tpCondRet CondRetObtido = PCA_CondRetOK;
      PCA_tpCondRet CondRetEsperada = PCA_CondRetOK;
                                      /* inicializa para qualquer coisa */

      int pos = -1;
      char cor = -1;
      char corEsp = -1;
      char corObt = -1;
      int NumLidos = -1;

      TST_tpCondRet Ret ;

      /* Testar PCA criar peca */
      if ( strcmp( ComandoTeste , CRIA_PECA_CMD ) == 0 )
      {

        NumLidos = LER_LerParametros( "ici" , &pos, &cor, &CondRetEsperada ) ;
        if (NumLidos != 3)
        {
          return TST_CondRetParm ;
        }

        CondRetObtido = PCA_CriarPeca( &vPeca[pos] , cor );
        return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                "Retorno errado ao criar peca." );
      } /* fim ativa: Testar PCA criar peça */
      /* Testar PCA obter cor peca */
      else if ( strcmp( ComandoTeste , OBTEM_COR_CMD ) == 0 )
      {

        NumLidos = LER_LerParametros( "ici" , &pos, &corEsp, &CondRetEsperada ) ;
        if (NumLidos != 3)
        {
          return TST_CondRetParm ;
        }

        CondRetObtido = PCA_ObterCor( vPeca[pos] , &corObt );

        Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                   "Retorno errado ao obter cor da peca." );

        if ( Ret != TST_CondRetOK )
        {
           return Ret ;
        } /* if */

		if (CondRetObtido == 2)
		{
			return Ret;

		}/* if */

		else if ( CondRetObtido == 0)
		{
			
			return TST_CompararChar( corEsp , corObt ,
                                 "Cor da peca esta errada." ) ;
		}/* if */

      } /* fim ativa: Testar PCA obter cor da peça */
      /* Testar PCA destruir peca */
      else if ( strcmp( ComandoTeste , DESTROI_PECA_CMD ) == 0 )
      {
        NumLidos = LER_LerParametros( "i", &pos ) ;
        PCA_DestruirPeca( &vPeca[pos] ) ;
        return TST_CondRetOK ;
      } /* fim ativa: Testar PCA destruir peça */
      return TST_CondRetNaoConhec ;

    } /* Fim função: TPCA Efetuar operações de teste específicas para árvore */

/********** Fim do módulo de implementação: Módulo de teste específico **********/
