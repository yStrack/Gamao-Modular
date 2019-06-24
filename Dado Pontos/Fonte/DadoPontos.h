
/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo DadoPontos
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
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*       3.00   LD   01/05/2019 Cria��o das assertivas de entrada e sa�da
*       2.00   GH   28/04/2019 Finaliza��o
*       1.00   GH   21/04/2019 In�cio do desenvolvimento
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
			   /* Faltou mem�ria */

	   DADP_NaoExiste = 2 ,
	           /* Dado Pontos n�o existe */

	   DADP_NaoInicializado = 3 ,
			   /* Dado Pontos n�o inicializado */

	   DADP_JogadorNaoPermitido = 4 ,
			   /* Jogador n�o est� permitido dobrar pontua��o da partida */

	   DADP_PontuacaoMaxima = 5 ,
			   /* Partida est� com pontua��o m�xima */

   } DADP_tpCondRet ;


/***********************************************************************
*
*  $FC Fun��o: DADP Criar dado pontos
*
*  $ED Descri��o da fun��o
*     Cria um novo dado pontos.
*     Caso j� exista um, este ser� destru�do.
*
*  $FV Valor retornado
*     DADP_CondRetOK
*     DADP_FaltouMemoria
*
*  $AE Assertivas de entrada
*     Espera ter espa�o em mem�ria suficiente para alocar um struct
*     DadoPontos, e que o ponteiro global ao m�dulo, Pdp, tenha sido
*     inicializado.
*
*  $AS Assertivas de sa�da
*     O espa�o associado ao ponteiro global ao m�dulo Pdp � liberado
*     e Pdp aponta para um novo espa�o alocado com o tamanho de
*     DadoPontos.
*     O valor do jogador � '?'
*
***********************************************************************/

   DADP_tpCondRet DADP_CriarDadoPontos( void );


/***********************************************************************
*
*  $FC Fun��o: DADP Destruir dado pontos
*
*  $ED Descri��o da fun��o
*     Destr�i o corpo e a cabe�a da �rvore, anulando a �rvore corrente.
*     Faz nada caso a �rvore corrente n�o exista.
*
*  $AE Assertivas de entrada
*     Espera que o ponteiro global ao m�dulo, Pdp tenha sido inicializado.
*
*  $AS Assertivas de sa�da
*     Libera o espa�o apontado pelo ponteiro global ao m�dulo Pdp, e
*     Pdp se torna NULL.
*
***********************************************************************/

   void DADP_DestruirDadoPontos ( void ) ;


/***********************************************************************
*
*  $FC Fun��o: DADP iniciar dado pontos
*
*  $EP Par�metros
*     $P jogador - valor a ser inserido no jogador Permitido a dobrar partida.
*
*  $FV Valor retornado
*     DADP_NaoExiste
*     DADP_CondRetOK
*
*  $AE Assertivas de entrada
*     Espera que o ponteiro global ao m�dulo, Pdp seja diferente de Nulo
*     e aponte para um espa�o alocado com tamanho suficiente para
*     o struct DadoPontos
*     O par�metro Jogador � um char que pode ser 'P' ou 'B' representando
*     a cor das pe�as do jogador que poder� optar por dobrar o valor
*     da partida.
*
*  $AS Assertivas de sa�da
*     O valor do jogador na struct � o passado como par�metro e o valor
*     da partida � 1.
*
***********************************************************************/

   DADP_tpCondRet DADP_IniciarDadoPontos ( char jogador ) ;


/***********************************************************************
*
*  $FC Fun��o: DADP Obter valor da Pontua��o na partida
*
*  $EP Par�metros
*     $P pontuacao - receber� pontu��o da partida caso o dado pontos
*     exista e tenha sido inicializado.
*
*  $FV Valor retornado
*     DADP_NaoExiste
*     DADP_NaoInicializado
*     DADP_CondRetOK
*
*  $AE Assertivas de entrada
*     Pdp aponta para um struct DadosPontos
*     O par�metro pontua��o � um ponteiro para um espa�o de mem�ria de
*     tamanho maior ou igual ao de um inteiro
*
*  $AS Assertivas de s�ida
*     Se o retorno dor CondRetOK, o valor apontado pelo ponteiro
*     pontua��o � igual ao valor da struct DadoPontos
*     Sen�o, o valor apontado por pontua��o n�o ter� sido alterado
*
***********************************************************************/

   DADP_tpCondRet DADP_ObetrValorPontuacao( int * pontuacao ) ;


/***********************************************************************
*
*  $FC Fun��o: DADP Mudar jogador permitido a dobrar valor da partida
*
*  $EP Par�metros
*     $P jogador - novo jogador a ser permitido a dobrar pontua��o na partida
*
*  $FV Valor retornado
*     DADP_NaoExiste
*     DADP_NaoInicializado
*     DADP_CondRetOK
*
*  $AE Assertivas de entrada
*     Pdp aponta para um struct DadoPontos
*     O parametro jogador � o char 'P' ou 'B', indicando a cor das pe�as
*     controladas pelo jogador
*
*  $AS Assertivas de sa�da
*     Caso o retorno seja CondRetOK, o valor do jogador no struct apontado
*     por Pdp ser� igual ao par�metro jogador.
*     Sen�o, nada ter� sido alterado.
*
***********************************************************************/

   DADP_tpCondRet DADP_MudarJogadorPermitido( char jogador ) ;


/***********************************************************************
*
*  $FC Fun��o: DADP Dobrar pontua��o
*
*  $EP Par�metros
*     $P jogador - jogador que deseja dobrar pontua��o na partida
*
*  $FV Valor retornado
*     DADP_NaoExiste
*     DADP_NaoInicializado
*     DADP_JogadorNaoPermitido
*     DADP_PontuacaoMaxima
*     DADP_CondRetOK
*
*  $AE Assertivas de entrada
*     O ponteiro global Pdp aponta para uma regiao de memoria que cont�m
*     um struct DadosPontos inicializado.
*     O par�metro jogador � 'B' ou 'P' indicando a cor das pe�as
*     do jogador que pediu para dobrar a pontua��o
*
*  $AS Assertivas de sa�da
*     Caso o jogador que tenha autoriza��o para dobrar o valor seja o
*     o mesmo do par�metro e o valor da partida for menor do que 64,
*     ent�o o valor da partida ter� sido dobrado. Se n�o, nada ter� sido feito.
*
***********************************************************************/

   DADP_tpCondRet DADP_DobrarPontuacao( char jogador ) ;





/********** Fim do m�dulo de defini��o: M�dulo �rvore **********/