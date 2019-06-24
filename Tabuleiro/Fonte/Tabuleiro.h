#include"PECA.h"
#if ! defined( Tabuleiro_ )
#define Tabuleiro_


/***************************************************************************
*  $MCI Módulo de implementação: Módulo Tabuleiro
*
*  Arquivo gerado:              Tabuleiro.h
*  Letras identificadoras:      TAB
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\...\...\Tabuleiro.h
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: GH  - Gabriel Heffer
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       2.00   GH   25/04/2019 Revisão.
*       2.00   GH   28/04/2019 Finalização.
*       2.00   GH   25/04/2019 Revisão.
*       2.00   GH   24/04/2019 Correção de erros
*       1.00   GH   22/04/2019 Inicio do desenvolvimento
*
***************************************************************************/

#if defined( Tabuleiro_OWN )
   #define Tabuleiro_EXT
#else
   #define Tabuleiro_EXT extern
#endif

/***** Declarações exportadas pelo módulo *****/


/* Tipo referência para um Tabuleiro */


/***********************************************************************
*
*  $TC Tipo de dados: TAB Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções do Tabuleiro
*
***********************************************************************/

   typedef enum {

	   TAB_CondRetOk = 0 ,
			   /* Condição de retorno ok */

	   TAB_FaltouMemoria = 1 ,
			   /* Condição de retorno faltou memória para alocação */

	   TAB_NaoExiste = 2 ,
			   /* Condição de retorno tabuleiro não existe */

	   TAB_NaoInicializado = 3 ,
			   /* Condição de retorno Tabuleiro não inicializado */

	   TAB_FimTabuleiro = 4 ,
			   /* Condição de retorno de fim do tabuleiro */

	   TAB_CasaVazia = 5 ,
			   /* Casa não tem peças */

   } TAB_tpCondRet ;


/***********************************************************************
*
*  $FC Função: TAB Criar Tabuleiro
*
*  $ED Descrição da função
*     Cria um novo Tabuleiro.
*
*
*  $FV Valor retornado
*     TAB_CondRetOk
*     TAB_FaltouMemoria
*
*  $AE Assertivas de Entrada
*     Tabuleiro não existe e não foi inicializado
*
*  $AS Assertivas de Saída
*     Tabuleiro terá sido criado
*
***********************************************************************/

   TAB_tpCondRet TAB_CriarTabuleiro ( void ) ;


/***********************************************************************
*
*  $FC Função: TAB Destroi Tabuleiro
*
*  $ED Descrição da função
*     Destroi um Tabuleiro.
*
*  $EP Parâmetros
*     $P tppTab - Ponteiro de um tabuleiro.
*
*  $AE Assertivas de Entrada
*     Tabuleiro existe
*
*  $AS Assertivas de Saída
*     Tabuleiro deixará de existir e o espaço alocado terá sido liberado
*
***********************************************************************/

    void TAB_DestruirTabuleiro( void ) ;


/***********************************************************************
*
*  $FC Função: TAB Inicializar Tabuleiro
*
*  $ED Descrição da função
*     Inicializa um Tabuleiro.
*
*
*  $FV Valor retornado
*     TAB_CondRetOk
*     TAB_FaltouMemoria
*     TAB_NaoExiste
*
*  $AE Assertivas de Entrada
*     Tabuleiro existe mas não foi inicializado
*
*  $AS Assertivas de Saída
*     Tabuleiro terá sido inicializado
*
***********************************************************************/

   TAB_tpCondRet TAB_InicializarTabuleiro( void ) ;


/***********************************************************************
*
*  $FC Função: TAB Obter peça
*
*  $ED Descrição da função
*     Coloca em tppPeca o endereço de uma cópia de uma peça da casa.
*
*  $EP Parâmetros
*     $P tppPeca - Ponteiro de Ponteiro para PEÇA.
*
*  $FV Valor retornado
*     TAB_CondRetOk
*     TAB_NaoInicializado
*     TAB_NaoExiste
*     TAB_CasaVazia
*
*  $AE Assertivas de Entrada
*     Tabuleiro existe e foi inicializado e casa corrente aponta para
*       uma casa válida
*
*  $AS Assertivas de Saída
*     O parâmetro apontará para um ponteiro de uma peça igual a da
*       casa corrente
*
***********************************************************************/

   TAB_tpCondRet TAB_ObterPeca( tpPeca **tppPeca ) ;


/***********************************************************************
*
*  $FC Função: TAB Andar Tabuleiro
*
*  $ED Descrição da função
*     Anda pelas casas do tabuleiro.
*     se numElem for maior que 0 anda para a direita, se for menor para a esquerda
*
*  $EP Parâmetros
*     $p numElem - quantidade de casas que deve dandar apartir da corrente
*
*  $FV Valor retornado
*     TAB_CondRetOk
*     TAB_NaoInicializado
*     TAB_NaoExiste
*     TAB_FimTabuleiro
*
*  $AE Assertivas de Entrada
*     Tabuleiro existe e foi inicializado
*
*  $AS Assertivas de Saída
*     Casa corrente apontará para uma nova casa, calculada a partir da
*       da casa corrente anterior acrescido de numElem
*
***********************************************************************/

   TAB_tpCondRet TAB_AndarTabuleiro( int numElem ) ;


/***********************************************************************
*
*  $FC Função: TAB Ir início Tabuleiro
*
*  $ED Descrição da função
*     Casa corrente passa a ser a primeira do tabuleiro
*     Faz nada se Tabuleiro não foi inicializado.
*
*
*  $FV Valor retornado
*     TAB_CondRetOk
*     TAB_NaoExiste
*
*  $AE Assertivas de Entrada
*     Tabuleiro existe e foi inicializado
*
*  $AS Assertivas de Saída
*     Casa corrente apontará para a primeira casa do tabuleiro
*
***********************************************************************/

   TAB_tpCondRet TAB_IrInicioTabuleiro( void ) ;


/***********************************************************************
*
*  $FC Função: TAB Ir final Tabuleiro
*
*  $ED Descrição da função
*     Casa corrente passa a ser a última do tabuleiro
*     Faz nada se Tabuleiro não foi inicializado.
*
*  $FV Valor retornado
*     TAB_CondRetOk
*     TAB_NaoExiste
*
*  $AE Assertivas de Entrada
*     Tabuleiro existe e foi inicializado
*
*  $AS Assertivas de Saída
*     Casa corrente apontará para a última casa do tabuleiro
*
***********************************************************************/

   TAB_tpCondRet TAB_IrFinalTabuleiro( void ) ;


/***********************************************************************
*
*  $FC Função: TAB Inserir peça
*
*  $ED Descrição da função
*     Insere uma cópia da peça na casa corrente do tabuleiro.
*
*  $EP Parâmetros
*     $p *peca - ponteiro para uma peça.
*
*  $FV Valor retornado
*     TAB_CondRetOk
*     TAB_NaoInicializado
*     TAB_NaoExiste
*
*  $AE Assertivas de Entrada
*     Ponteiro para peça passado como argumento aponta para uma peça
*       existente e válida, casa corrente não possui peças ou possui
*       peças de mesma cor da peça passada como argumento
*
*  $AS Assertivas de Saída
*     Casa corrente possuirá mais uma peça com a mesma cor da peça
*       passada como argumento
*
***********************************************************************/

   TAB_tpCondRet TAB_InserirPeca( tpPeca *peca ) ;


/***********************************************************************
*
*  $FC Função: TAB excluir peça
*
*  $ED Descrição da função
*     exclui uma peça na casa corrente do tabuleiro.
*
*  $FV Valor retornado
*     TAB_CondRetOk
*     TAB_NaoInicializado
*     TAB_NaoExiste
*     TAB_CasaVazia
*
*  $AE Assertivas de Entrada
*     Casa corrente aponta para uma casa existente
*
*  $AS Assertivas de Saída
*     Casa corrente terá uma peça a menos
*
***********************************************************************/

   TAB_tpCondRet TAB_ExcluirPeca( void ) ;

/***********************************************************************
*
*  $FC Função: TAB Obter Quantidade Peças
*
*  $ED Descrição da função
*     Quantidade irá receber a quantidade de peças na casa corrente
*
*  $EP Parâmetros
*     $P *quantidade - Ponteiro para um inteiro.
*
*  $FV Valor retornado
*     TAB_CondRetOk
*     TAB_NaoInicializado
*     TAB_NaoExiste
*
* $AE Assertivos de Entrada
*     Tabuleiro existe e foi inicializado, casa corrente existe
*     e aponta para uma casa válida
*
* $AS Assertivas de Saída
*     Valor apontado pelo ponteiro para inteiro quantidade, passado comop
*       argumento, agora corresponde ao numero de peças na casa corrente.
*
***********************************************************************/

   TAB_tpCondRet TAB_ObterQuantidadePEC( int * quantidade ) ;


#undef Tabuleiro_EXT


/********** Fim do módulo de definição: TAB  Tabuleiro **********/


#else
#endif
