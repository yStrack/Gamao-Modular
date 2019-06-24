#if ! defined( DADO_ )
#define DADO_
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Dado
*
*  Arquivo gerado:              DADO.H
*  Letras identificadoras:      DAD
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: YS  - Yuri Strack
*           LD  - Lucas Damo
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       2.00   LD   01/05/2019 Criação das assertivas de entrada e saída
*       2.00   YS   16/04/2019 Revisão do código e termino do desenvolvimento
*       1.00   YS   15/04/2019 Inicio do desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo implementa uma simples função para simular
*     a jogada de um dado simples (valores de 1 a 6).
*
***************************************************************************/

#if defined( DADO_OWN )
   #define DADO_EXT
#else
   #define DADO_EXT extern
#endif

/***********************************************************************
*
*  $TC Tipo de dados: DAD Condicao de retorno
*
*
***********************************************************************/

   typedef enum {

         DAD_CondRetOK = 0 ,
               /* Executou correto */

   } DAD_tpCondRet ;

/***********************************************************************
*
*  $FC Função: DAD Jogar dado
*
*  $ED Descrição da função
*     Simula a jogada de um dado, gerando um valor aleatorio entre 1 e 6.
*
*  $FV Valor retornado
*     DADO_CondRetOK
*
*  $AE Assertivas de entrada
*     Recebe dois ponteiros, valor1 e valor2 que apontam para regioes de
*     memória capazes de armazenar um inteiro cada.
*
*  $AS Assertivas de saída
*     Salva dois valores aleatórios (de 1 a 6), um no espaço apontado
*     pelo parâmetro valor1 e o outro pelo valor2.
*
***********************************************************************/

DAD_tpCondRet DAD_Jogar(int *valor1, int *valor2);


#undef DADO_EXT

/********** Fim do módulo de definição: Módulo DADO **********/

#else
#endif
