#if ! defined( BARRA_ )
#define BARRA_
/***************************************************************************
*  $MCD Módulo de definição: Módulo Barra
*
*  Arquivo gerado:              Barra.h
*  Letras identificadoras:      TAB
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: GH  - Gabriel Heffer
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       1.00   GH   28/04/2019 Inicio do desenvolvimento
*
***************************************************************************/

#include"PECA.h"

#if defined( BARRA_OWN )
#define BARRA_EXT
#else
#define BARRA_EXT extern
#endif


/***** Declarações exportadas pelo módulo *****/


/***********************************************************************
*
*  $TC Tipo de dados: BAR Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções da Barra
*
***********************************************************************/


typedef enum {

   BAR_CondRetOk = 0 ,
   /* Condição de retorno ok */

           BAR_FaltouMemoria = 1 ,
   /* Condição de retorno faltou memória para alocação */

           BAR_NaoExiste = 2 ,
   /* Condição de retorno Barra não existe */

           BAR_PecaNaoExiste = 3 ,
   /* Condição de retorno erro ao inserir peça que não existe */

           BAR_BarraVazia = 4 ,
   /* Condição de retorno barra está vazia */

} BAR_tpCondRet ;

/***********************************************************************
*
*  $FC Função: BAR Criar Barra
*
*  $ED Descrição da função
*     Cria barra para peças capituradas.
*
*  $FV Valor retornado
*     BAR_CondRetOk
*     BAR_FaltouMemoria
*
*  $AE Assertivas de Entrada
*     Tem espaço suficiente em memória para alocar Barra
*
*  $AS Assertivas de Saída
*     Barra foi criado e inicializado
*
************************************************************************/

BAR_tpCondRet BAR_CriarBarra( void )  ;


/***********************************************************************
*
*  $FC Função: BAR Destruir Barra
*
*  $ED Descrição da função
*     Destroi barra.
*
*  $AE Assertivas de Entrada
*     Barra foi criado e inicializado
*
*  $AS Assertivas de Saída
*     Barra terá deixado de existir e o espaço em memória alocado por ela,
*     terá sido liberado
*
************************************************************************/

void BAR_DestruirBarra( void ) ;


/***********************************************************************
*
*  $FC Função: BAR Inserir na Barra
*
*  $EP Parâmetros
*     $P peca - ponteiro para uma peça.
*
*  $ED Descrição da função
*     Insere peca na Barra.
*     Se Barra não existir nada será feito.
*     Se ponteiro para peça for nulo, inserção não acontecerá.
*
*  $FV Valor retornado
*     BAR_PecaNaoExiste
*     BAR_NaoExiste
*     BAR_FaltouMemoria
*     BAR_CondRetOk
*
*  $AE Assertivas de Entrada
*     Barra foi inicializada, ponteiro para peca aponta para
*     uma peça inicializada corretamente, com cor.
*
*  $AS Assertivas de Saída
*     Barra terá incrementado seu contador em 1 para a mesma
*     cor da peça passada como parâmetro
*
*********************************************************************/

BAR_tpCondRet BAR_InserirBarra( tpPeca * peca ) ;


/***********************************************************************
*
*  $FC Função: BAR Quantidade de peças na Barra.
*
*  $EP Parâmetros
*     $P cor - qual peça deve ser verificada
*     $P quantidade - rece a quantidade de peças na Barra
*
*  $ED Descrição da função
*     Coloca em quantidade quantidade de peças capturadas.
*
*  $FV Valor retornado
*     BAR_CondRetOk
*     BAR_NaoExiste
*
*  $AE Assertivas de Entrada
*     Barra foi inicializada
*
*  $AS Assertivas de Saída
*     O ponteiro para inteiro aponta para um inteiro com o numero de
*     peças na barra da cor passada como parâmetro
*
*********************************************************************/

BAR_tpCondRet BAR_QuantidadeBarra( char cor , int * quantidade ) ;


/***********************************************************************
*
*  $FC Função: BAR Retirar da Barra.
*
*  $EP Parâmetros
*     $P cor - qual peça deve ser retirada.
*     $P peca - ponteiro para uma peça, recebe peça do Tabuleiro.
*
*  $ED Descrição da função
*     Retira da Barra uma peça da cor passada como parâmetro.
*     Se Barra não exitir ou Barra estiver vazia ao término da função peca é null.
*
*  $FV Valor retornado
*     BAR_NaoExiste
*     BAR_BarraVazia
*     BAR_CondRetOk
*
*  $AE Assertivas de Entrada
*     Barra foi criada e inicializada
*
*  $AS Assertivas de Saída
*     Barra terá decrementado seu contador em 1 para a mesma
*     cor da peça passada como parâmetro e a peça apontada será
*     uma cópia da peça que estava na casa corrente.
*
*********************************************************************/

BAR_tpCondRet BAR_RetirarBarra( tpPeca ** peca , char cor ) ;



#undef BARRA_EXT

/********** Fim do módulo de definição: Módulo Barra **********/

#else
#endif