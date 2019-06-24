
/***************************************************************************
*  $MCI Módulo de implementação: Módulo DadoPontos
*
*  Arquivo gerado:              DadoPontos.h
*  Letras identificadoras:      DADP
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\...\...\DdoPontos.h
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: GH  - Gabriel Heffer
*           LD  - Lucas Damo
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       3.00   LD   01/05/2019 Criação das assertivas de entrada e saída
*       2.00   GH   28/04/2019 Finalização
*       1.00   GH   21/04/2019 Início do desenvolvimento
*
***************************************************************************/



/***********************************************************************
*
*  $TC Tipo de dados: DADP Condicoes de retorno
*
*
***********************************************************************/

   typedef enum {
	   DADP_CondRetOK = 0 ,
               /* Executou correto */

	   DADP_FaltouMemoria = 1 ,
			   /* Faltou memória */

	   DADP_NaoExiste = 2 ,
	           /* Dado Pontos não existe */

	   DADP_NaoInicializado = 3 ,
			   /* Dado Pontos não inicializado */

	   DADP_JogadorNaoPermitido = 4 ,
			   /* Jogador não está permitido dobrar pontuação da partida */

	   DADP_PontuacaoMaxima = 5 ,
			   /* Partida está com pontuação máxima */

   } DADP_tpCondRet ;


/***********************************************************************
*
*  $FC Função: DADP Criar dado pontos
*
*  $ED Descrição da função
*     Cria um novo dado pontos.
*     Caso já exista um, este será destruído.
*
*  $FV Valor retornado
*     DADP_CondRetOK
*     DADP_FaltouMemoria
*
*  $AE Assertivas de entrada
*     Espera ter espaço em memória suficiente para alocar um struct
*     DadoPontos, e que o ponteiro global ao módulo, Pdp, tenha sido
*     inicializado.
*
*  $AS Assertivas de saída
*     O espaço associado ao ponteiro global ao módulo Pdp é liberado
*     e Pdp aponta para um novo espaço alocado com o tamanho de
*     DadoPontos.
*     O valor do jogador é '?'
*
***********************************************************************/

   DADP_tpCondRet DADP_CriarDadoPontos( void );


/***********************************************************************
*
*  $FC Função: DADP Destruir dado pontos
*
*  $ED Descrição da função
*     Destrói o corpo e a cabeça da árvore, anulando a árvore corrente.
*     Faz nada caso a árvore corrente não exista.
*
*  $AE Assertivas de entrada
*     Espera que o ponteiro global ao módulo, Pdp tenha sido inicializado.
*
*  $AS Assertivas de saída
*     Libera o espaço apontado pelo ponteiro global ao módulo Pdp, e
*     Pdp se torna NULL.
*
***********************************************************************/

   void DADP_DestruirDadoPontos ( void ) ;


/***********************************************************************
*
*  $FC Função: DADP iniciar dado pontos
*
*  $EP Parâmetros
*     $P jogador - valor a ser inserido no jogador Permitido a dobrar partida.
*
*  $FV Valor retornado
*     DADP_NaoExiste
*     DADP_CondRetOK
*
*  $AE Assertivas de entrada
*     Espera que o ponteiro global ao módulo, Pdp seja diferente de Nulo
*     e aponte para um espaço alocado com tamanho suficiente para
*     o struct DadoPontos
*     O parâmetro Jogador é um char que pode ser 'P' ou 'B' representando
*     a cor das peças do jogador que poderá optar por dobrar o valor
*     da partida.
*
*  $AS Assertivas de saída
*     O valor do jogador na struct é o passado como parâmetro e o valor
*     da partida é 1.
*
***********************************************************************/

   DADP_tpCondRet DADP_IniciarDadoPontos ( char jogador ) ;


/***********************************************************************
*
*  $FC Função: DADP Obter valor da Pontuação na partida
*
*  $EP Parâmetros
*     $P pontuacao - receberá pontução da partida caso o dado pontos
*     exista e tenha sido inicializado.
*
*  $FV Valor retornado
*     DADP_NaoExiste
*     DADP_NaoInicializado
*     DADP_CondRetOK
*
*  $AE Assertivas de entrada
*     Pdp aponta para um struct DadosPontos
*     O parâmetro pontuação é um ponteiro para um espaço de memória de
*     tamanho maior ou igual ao de um inteiro
*
*  $AS Assertivas de sáida
*     Se o retorno dor CondRetOK, o valor apontado pelo ponteiro
*     pontuação é igual ao valor da struct DadoPontos
*     Senão, o valor apontado por pontuação não terá sido alterado
*
***********************************************************************/

   DADP_tpCondRet DADP_ObetrValorPontuacao( int * pontuacao ) ;


/***********************************************************************
*
*  $FC Função: DADP Mudar jogador permitido a dobrar valor da partida
*
*  $EP Parâmetros
*     $P jogador - novo jogador a ser permitido a dobrar pontuação na partida
*
*  $FV Valor retornado
*     DADP_NaoExiste
*     DADP_NaoInicializado
*     DADP_CondRetOK
*
*  $AE Assertivas de entrada
*     Pdp aponta para um struct DadoPontos
*     O parametro jogador é o char 'P' ou 'B', indicando a cor das peças
*     controladas pelo jogador
*
*  $AS Assertivas de saída
*     Caso o retorno seja CondRetOK, o valor do jogador no struct apontado
*     por Pdp será igual ao parâmetro jogador.
*     Senão, nada terá sido alterado.
*
***********************************************************************/

   DADP_tpCondRet DADP_MudarJogadorPermitido( char jogador ) ;


/***********************************************************************
*
*  $FC Função: DADP Dobrar pontuação
*
*  $EP Parâmetros
*     $P jogador - jogador que deseja dobrar pontuação na partida
*
*  $FV Valor retornado
*     DADP_NaoExiste
*     DADP_NaoInicializado
*     DADP_JogadorNaoPermitido
*     DADP_PontuacaoMaxima
*     DADP_CondRetOK
*
*  $AE Assertivas de entrada
*     O ponteiro global Pdp aponta para uma regiao de memoria que contém
*     um struct DadosPontos inicializado.
*     O parâmetro jogador é 'B' ou 'P' indicando a cor das peças
*     do jogador que pediu para dobrar a pontuação
*
*  $AS Assertivas de saída
*     Caso o jogador que tenha autorização para dobrar o valor seja o
*     o mesmo do parâmetro e o valor da partida for menor do que 64,
*     então o valor da partida terá sido dobrado. Se não, nada terá sido feito.
*
***********************************************************************/

   DADP_tpCondRet DADP_DobrarPontuacao( char jogador ) ;





/********** Fim do módulo de definição: Módulo árvore **********/