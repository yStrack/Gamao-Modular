#include  "PECA.h"

/***************************************************************************
*  $MCI Módulo de implementação: Módulo Peças Finalizadas
*
*  Arquivo gerado:              PecasFinalizadas.h
*  Letras identificadoras:      TAB
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\...\...\PecasFinalizadas.h
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: GH  - Gabriel Heffer
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       1.00   GH   02/06/2019 Inicio de desenvolvimento
*
***************************************************************************/


/***** Declarações exportadas pelo módulo *****/


/* Tipo referência para um Tabuleiro */

/***********************************************************************
*
*  $TC Tipo de dados: PEF Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções do Tabuleiro
*
***********************************************************************/

typedef enum {

   PEF_CondRetOk = 0 ,
   /* Condição de retorno ok */

           PEF_FaltouMemoria = 1 ,
   /* Condição de retorno faltou memória para alocação */

           PEF_NaoExiste = 2 ,
   /* Condição de retorno estrutura para armazenar Peças Finalizadas não existe */

           PEF_PecaNaoExiste = 3 ,
   /* Condição de retorno peça não existe */

} PEF_tpCondRet ;


/***********************************************************************
*
*  $FC Função: PEF Criar estrutura para peças finalizadas
*
*  $ED Descrição da função
*     Cria uma nova estrutura para peças finalizadas
*
*  $FV Valor retornado
*     PEF_FaltouMemoria
*     PEF_CondRetOk
*
*  $AE Assertivas de Entrada
*     Tem espaço em memória suficiente para alocar peças finalizadas
*
*  $AS Assertivas de Saída
*     Peças finalizadas foi criada e inicializada
*
***********************************************************************/

PEF_tpCondRet PEF_CriarFinalizadas( void ) ;


/***********************************************************************
*
*  $FC Função: PEF Destruir estrutura para peças finalizadas
*
*  $ED Descrição da função
*     Destruir estrutura para peças finalizadas
*
*  $AE Assertivas de entrada
*     Peças finalizadas foi inicializada
*
*  $AS Assertivas de Saída
*     Peças finalizadas deixa de existir e seu espaço alocado é liberado
*
***********************************************************************/

void DestruirFinalizadas( void ) ;


/***********************************************************************
*
*  $FC Função: PEF Inserir peça na estrutura de peças finalizadas
*
*  $ED Descrição da função
*     Inserir uma peça ( finalizar uma peça )
*
*  $EP Parâmetros
*     $P cor - char que representa a cor das peças.
*     $P tpPeca - ponteiro para uma PEÇA.
*
*  $FV Valor retornado
*     PEF_NaoExiste
*     PEF_FaltouMemoria
*     PEF_CondRetOk
*
*  $AE Assertivas de Entrada
*     Peças finalizadas foi inicializada, ponteiro para peca aponta para
*     uma peça inicializada corretamente, com cor.
*
* $AS Assertivas de Saída
*    Pecas finalizadas terá incrementado seu contador em 1 para a mesma
*    cor da peça passada como parâmetro
*
***********************************************************************/

PEF_tpCondRet PEF_InserirFinalizadas( tpPeca * peca ) ;


/***********************************************************************
*
*  $FC Função: PEF quantidade de peças finalizadas
*
*  $ED Descrição da função
*     quantidade de peças finalizadas da cor passada como parâmetro
*
*  $EP Parâmetros
*     $P cor - char que representa a cor das peças.
*     $P *quantidade - ponteiro para um inteiro.
*
*  $FV Valor retornado
*     PEF_NaoExiste
*     PEF_CondRetOk
*
*  $AE Assertivas de Entrada
*     Pecas finalizadas foi inicializada
*
* $AS Assertivas de Saída
*     O ponteiro para inteiro aponta para um inteiro com o numero de
*     peças finalizadas da cor passada como parâmetro
*
***********************************************************************/

PEF_tpCondRet PEF_quantidadeFinalizadas( char cor , int * quantidade ) ;


/********** Fim do módulo de definição: PEF  Peças Finalizadas **********/
