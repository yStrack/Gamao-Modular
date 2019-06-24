#if ! defined( PECA_ )
#define PECA_
/***************************************************************************
*  $MCI Módulo de implementação: Módulo Peça
*
*  Arquivo gerado:              PECA.h
*  Letras identificadoras:      PCA
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: YS  - Yuri Strack
*           LD  - Lucas Damo
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       2.00   LD   02/05/2019 Criação das assertivas de entrada e saída
*       2.00   YS   22/04/2019 Revisão de código, alteraçao nos ponteiros e finalizacao.
*       1.00   YS   22/04/2019 Inicio do desenvolvimento
*
***************************************************************************/

#if defined( PECA_OWN )
   #define PECA_EXT
#else
   #define PECA_EXT extern
#endif

/***** Declarações exportadas pelo módulo *****/

/* Tipo referência peça */

typedef struct peca tpPeca;

/***********************************************************************
*
*  $TC Tipo de dados: PCA Condicoes de retorno
*
*
***********************************************************************/

   typedef enum {
	   PCA_CondRetOK = 0 ,
         /* Executou correto */

	   PCA_FaltouMemoria = 1 ,
			   /* Faltou memória */

	   PCA_NaoExiste = 2 ,
	       /* Peca não existe */

   } PCA_tpCondRet ;


/***********************************************************************
*
*  $FC Função: PCA Criar peca
*
*  $ED Descrição da função
*     Cria uma nova peca.
*
*  $EP Parâmetros
*     $P cor - cor da peca.
*
*  $FV Valor retornado
*     PCA_CondRetOK
*     PCA_FaltouMemoria
*
*  $AE Assertivas de entrada
*     O parâmetro Cor é o char 'B' ou 'P' representando a cor das peça a
*     ser criada.
*     Existe memória suficiente para alocar um struct Peca e seus ponteiros
*
*  $AS Aseertivas de saída
*     O ponteiro do tipo tpPeca aponta para um struct do tipo tpPeca,
*     cuja cor é igual a passada como argumento.
*
***********************************************************************/

   PCA_tpCondRet PCA_CriarPeca( tpPeca ** peca , char cor );


/***********************************************************************
*
*  $FC Função: PCA Destruir peça
*
*  $EP Parâmetros
*     $P peça - ponteiro para uma peça.
*
*  $ED Descrição da função
*     Destrói a peça recebida.
*
*  $AE Assertivas de entrada
*     O parâmetro peca é um ponteiro para um ponteiro de uma estrutura
*     peça existente.
*
*  $AS Assertivas de saída
*     O parametro tpPeca** agora aponta para um ponteiro nulo e a região
*     antes alocada por ele foi liberada.
*
***********************************************************************/

   void PCA_DestruirPeca ( tpPeca ** peca ) ;


/***********************************************************************
*
*  $FC Função: PCA Obter cor da peça
*
*  $EP Parâmetros
*     $P peca - ponteiro para uma peça.
*
*  $FV Valor retornado
*     PCA_NaoExiste
*     PCA_CondRetOK
*
*  $AE Assertivas de entrada
*     Peça é um ponteiro válido para uma estrutura do tipo tpPeca
*     existente.
*
*  $AS Assertivas de saída
*     O ponteiro cor, passado como parâmetro, aponta para um char 'P'
*     ou 'B' igual a cor da peça
*
***********************************************************************/

   PCA_tpCondRet PCA_ObterCor( tpPeca * peca , char * cor ) ;


#undef PECA_EXT

/********** Fim do módulo de definição: Módulo PEÇA **********/

#else
#endif
