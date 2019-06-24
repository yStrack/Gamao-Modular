/***************************************************************************
*  $MCI Módulo de implementação: Módulo Dado
*
*  Arquivo gerado:              DADO.C
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
***************************************************************************/

#include   <malloc.h>
#include   <stdio.h>
#include   <stdlib.h>
#include   <time.h>

#define DADO_OWN
#include "DADO.h"
#undef DADO_OWN

/***************************************************************************
*
*  Função: DAD Jogar dado
*  ****/

DAD_tpCondRet DAD_Jogar(int *valor1, int *valor2){
		srand((unsigned int) time(0));
		*valor1 = (rand() % 6) +1;
		*valor2 = (rand() % 6) +1;
    return DAD_CondRetOK;
}

/********** Fim do módulo de implementação: Módulo DADO **********/
