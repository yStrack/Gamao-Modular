/***************************************************************************
*  $MCI Módulo de implementação: Módulo Jogo
*
*  Arquivo gerado:              Jogo.c
*  Letras identificadoras:      JOG
*
*  Projeto: Disciplina INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: LD  - Lucas Damo
*						YS  - Yuri Strack
*						GH  - Gabriel Heffer
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*				3.00   YS   16/06/2019 Funcoes atualizadas e funcionando.
*				3.00   YS   15/06/2019 Funcoes atualizadas e funcionando.
*				2.04   YS   14/06/2019 Correção de erros e ajustes em todas funções.
*				2.03   YS   12/06/2019 Correção de erros e ajustes em todas funções.
*				2.02   YS   10/06/2019 Correção de erros e ajustes em todas funções.
*				2.01   YS   09/06/2019 Correção de erros e ajustes em todas funções.
*				2.00   YS   08/06/2019 Correção de erros e ajustes em todas funções.
*				2.00   YS   08/06/2019 Desenvolvimento da main.
*       1.00   LD   04/06/2019 Inicio do desenvolvimento.
*
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Barra.h"
#include "PecasFinalizadas.h"
#include "Tabuleiro.h"
#include "DADO.h"
#include "DadoPontos.h"
#include "PECA.h"

#define TRUE 1

    typedef enum {

       JOG_CondRetOk = 0,
          /* Executou corretamente */
       JOG_FaltouMemoria = 1,
          /* Condição de retorno faltou memória para alocação */
       JOG_CasaForaDoTabuleiro = 2,
          /* Condição de retorno casa referenciada não está entre 0 e 24 */
       JOG_SentidoErrado = 3,
         /* A casa destino do movimento de uma peça não está na direção permitida para aquele jogador */
       JOG_JogadorNaoAutorizado = 4,
        /* Jogador não tem a permissão de mover a peça que ele está tentando */
       JOG_DestinoNaoAutorizado = 5,
    	/* casa destino possuie mais de uma peça do aponente ou movimentação não condiz com valor dos dados */
       JOG_ErroAoIniciarPartida = 6,
        /* Não foi possível iniciar a partida */
       JOG_CasaOrigemVazia = 7 ,
        /* Casa de inicio da jogada esta vazia */
       JOG_DadoPontosNaoInicializado = 8 ,
    	/* Dado Pontos não existe ou não foi inicializado */
       JOG_PartidaNaoInicializada = 9 ,
    	/* Partida não foi inicializada */
       JOG_PecaFinalizada = 10
    	/* Peça foi finalizada na movimentação */
    } JOG_tpCondRet ;


   struct partida
   {
      char vencedor ;
			/* vencedor da partida */

		char jogador ;
			/* jogador a realizar próxima jogada */

		char dado_dobrado ;
			/*flag para verificar se dado foi dobrado */

		int dado1 ;
			/* valor dado 1 */

		int dado2 ;
			/* valor dado 2 */
   } ;

   typedef struct partida Partida ;

/***** Protótipos dos dados encapuladas pelo módulo *****/

   static Partida * jogo  = NULL;

/***** Protótipos das funções encapuladas no módulo *****/

    JOG_tpCondRet JOG_MostrarPontuacao( void );

		static void insere_npecas_corrente(char cor, int num);

		static void inic_jogo( void ) ;

		static JOG_tpCondRet RegraMovimentacao(int origem , int destino ) ;

		static JOG_tpCondRet RegraBarra( int destino ) ;

		static void capturar( ) ;

		static char recebeComando( void);

		static void movimentaPeca( int origem , int destino , int flagBarra);

		static int PossibilidadesJogadas(int origem, int * possibilidade1, int * possibilidade2);

		static int RealizaJogada(int origem, int flagBarra);

/********* Código das funções exportadas pelo módulo **********/


/***********************************************************************
*
*  $FC Função: JOG Inicia partida
*
*  $ED Descrição da Função
*     Inicia a partida colocando as peças na configuração inicial de uma
*     partida de gamão
*
*  $FV Valor retornado
*     JOG_ErroAoIniciarPartida
*     JOG_CondRetOK
*
***********************************************************************/

	JOG_tpCondRet JOG_IniciarPartida(void){
	   TAB_tpCondRet tabcondRet;

	   tabcondRet = TAB_CriarTabuleiro ();
	   if ( tabcondRet != TAB_CondRetOk ){
	      return JOG_ErroAoIniciarPartida;
	   } /* if */
	   tabcondRet = TAB_InicializarTabuleiro();
	   if ( tabcondRet != TAB_CondRetOk ){
	      return JOG_ErroAoIniciarPartida;
	   } /* if */

	   BAR_CriarBarra();
	   PEF_CriarFinalizadas();
	   DADP_CriarDadoPontos();
	   inic_jogo();
	   DADP_IniciarDadoPontos( '-' );

	   /* Colocando as peças nas posições iniciais: */
	   TAB_IrInicioTabuleiro();
	   insere_npecas_corrente('B', 2); /* insere 2 brancas casa 01*/
	   TAB_AndarTabuleiro(5);
	   insere_npecas_corrente('P', 5); /* insere 5 pretas casa 06 */
	   TAB_AndarTabuleiro(2);
	   insere_npecas_corrente('P', 3); /* insere 3 pretas na casa 08 */
	   TAB_AndarTabuleiro(4);
	   insere_npecas_corrente('B', 5); /* insere 5 brancas na casa 12 */
	   TAB_AndarTabuleiro(1);
	   insere_npecas_corrente('P', 5); /* insere 5 pretas na casa 13 */
	   TAB_AndarTabuleiro(4);
	   insere_npecas_corrente('B', 3); /* insere 3 brancas na casa 17 */
	   TAB_AndarTabuleiro(2);
	   insere_npecas_corrente('B', 5); /* insere 5 brancas na casa 19 */
	   TAB_AndarTabuleiro(5);
	   insere_npecas_corrente('P', 2); /* insere 2 pretas na casa 24 */
		 TAB_IrInicioTabuleiro( ) ; /* voltando para o inicio do tabuleiro */
     return JOG_CondRetOk ;
	}

/***********************************************************************
*
*  $FC Função: JOG Mostrar Tabuleiro
*
*  $ED Descrição da Função
*     Exibe o tabuleiro e as peças nele contidas para o usuário
*
***********************************************************************/

	void JOG_MostrarTabuleiro( void ) {

		int i, j , k; /* iteradores */
		tpPeca* p = NULL; /* peca */
		int vet[24]; /* vetor de quantidade de pecas em cada casa */
		char vCor[24]; /* vetor de cor das pecas da casa */
		char cor;
    int qtdB,qtdP;
		TAB_tpCondRet cond;
		TAB_IrInicioTabuleiro(); /* Indo para o inicio do tabuleiro */

		for ( i=0 ; i<24 ; i++ ){
				cond = TAB_ObterPeca( &p ) ;
				if (cond == TAB_CasaVazia){
					cor = '-';
				}
				else{
					PCA_ObterCor( p , &cor); /* cria vetor de cor da casa */
				}
				vCor[i] = cor;
				TAB_ObterQuantidadePEC( &vet[i] ); /* cria vetor de qtd peca na casa */
				TAB_AndarTabuleiro( 1 );
		} /* for */

		TAB_IrInicioTabuleiro();
    system("cls");
    printf("Vez do jogador de cor: ");
    if ( jogo->jogador == 'P'){
       printf("\033[0;31mV");
    }
    else if (jogo->jogador == 'B'){
       printf("\033[0;32mV");
    }
    printf("\033[0m\n\n"); /* voltando para cor branca */

		printf("/-------------------------------------------\\");
		printf("\n");
    printf("| 12 11 10 09 08 07 |   | 06 05 04 03 02 01 |\n");
		printf("|-------------------------------------------|\n");

		for (i=0;i<6;i++){ /*numero de linhas*/
			char linha[50]; /* linha completa */
			char l1[30]; /* parte superior esquerda da linha */
			char l2[30]; /* parte superior direita da linha */
			linha[0] = '|';linha[1]='\0';
			k=11; /* numero da casa de inicio */
			for (j=0;j<19;j++){ /* tamanho da linha */
				l1[j] = ' ';
				if (j==1 || j==4 || j==7 || j==10 || j==13 || j==16){ /* posicao das casas é fixa */
					if (vet[k] > 0 ){
						if (i==5){
							l1[j] = 48+vet[k]; /* char 0 é 48 em decimal */
						} /* if */
						else{
							l1[j] = vCor[k];
							vet[k]--; /* diminui o numero de pecas já exibidas */
						} /* if */
					} /* if */
					k--; /* vai pra proxima casa */
				} /* if */
			} /* for */

			l1[j] = '\0';
			strcat(linha,l1);
			strcat(linha,"| "); /* ate aqui metade da linha esta pronta */
      BAR_QuantidadeBarra('B',&qtdB);
      if (qtdB-i > 0){
        if (i == 5){
          char sobra[4];
          sobra[0] = '0'+qtdB-i;
          sobra[1] = ' ';
          sobra[2] = '|';
          sobra[3] = '\0';
          strcat(linha,sobra);
        }
        else{
          strcat(linha,"B |");
        }
      }
      else{
        strcat(linha,"  |");
      }
			k = 5; /* numero da casa de inicio */

			for (j=0;j<19;j++){
				l2[j] = ' ';
				if (j==1 || j==4 || j==7 || j==10 || j==13 || j==16){ /* posicao das casas é fixa */
					if (vet[k] > 0 ){
						if (i==5){
							l2[j] = 48+vet[k]; /* char 0 é 48 em decimal */
						} /* if */
						else{
							l2[j] = vCor[k];
							vet[k]--; /* diminui o numero de pecas já exibidas */
						} /* if */
					} /* if */
					k--; /* vai pra proxima casa */
				} /* if */
			} /* for */

			l2[j]='|';l2[j+1]='\0';
			strcat(linha,l2); /* linha fica completa */

			/* exibe a linha */
			for (j=0;linha[j]!='\0';j++){
				if (linha[j] == 'P'){
					printf("\033[0;31mo"); /* vermelho pra PRETO */
				} /* if */
				else if(linha[j] == 'B'){
					printf("\033[0;32mo"); /* verede pra BRANCO */
				} /* if */
				else if (linha[j] == ' ' || linha[j] == '|'){
					printf("\033[0m%c",linha[j]);
				} /* if */
				else if (linha[j] >= 48 && linha[j]<= 57){
					printf("\033[0;m+%c",linha[j]); j++;
				} /* if */
			} /* for */

			printf("\n");
		}

		printf("|                   |   |                   |\n");

		for (i=0;i<6;i++){
			char linha[50];
			char l1[30];
			char l2[30];
			linha[0] = '|';linha[1]='\0';
			k=12;
			for (j=0;j<19;j++){
				l1[j] = ' ';
				if (j==1 || j==4 || j==7 || j==10 || j==13 || j==16){ /* posicao das casas é fixa */
					if (vet[k]-(5-i) > 0 ){
						if (i==0){
							l1[j] = 48+vet[k]-5; /* char 0 é 48 em decimal */
						} /* if */
						else{
							l1[j] = vCor[k];
							vet[k]--; /* diminui o numero de pecas já exibidas */
						} /* if */
					} /* if */
					k++; /* vai pra proxima casa */
				} /* if */
			} /* for */

			l1[j] = '\0';
			strcat(linha,l1);
			strcat(linha,"| ");
      BAR_QuantidadeBarra('P',&qtdP);
      if (qtdP-i > 0){
        if (i == 5){
          char sobra[4];
          sobra[0] = '0'+qtdP-i;
          sobra[1] = ' ';
          sobra[2] = '|';
          sobra[3] = '\0';
          strcat(linha,sobra);
        }
        else{
          strcat(linha,"P |");
        }
      }
      else{
        strcat(linha,"  |");
      }

			for (j=0;j<19;j++){
				l2[j] = ' ';
				if (j==1 || j==4 || j==7 || j==10 || j==13 || j==16){ /* posicao das casas é fixa */
					if (vet[k] - (5-i) > 0 ){
						if (i==0){
							l2[j] = 48+vet[k]-5; /* char 0 é 48 em decimal */
						} /* if */
						else{
							l2[j] = vCor[k];
							vet[k]--; /* diminui o numero de pecas já exibidas */
						} /* if */
					} /* if */
					k++; /* vai pra proxima casa */
				} /* if */
			} /* for */

			l2[j]='|';l2[j+1]='\0';
			strcat(linha,l2);

			for (j=0;linha[j]!='\0';j++){
				if (linha[j] == 'P'){
					printf("\033[0;31mo");
				} /* if */
				else if(linha[j] == 'B'){
					printf("\033[0;32mo");
				} /* if */
				else if (linha[j] == ' ' || linha[j] == '|'){
					printf("\033[0m%c",linha[j]);
				} /* if */
				else if (linha[j] >= 48 && linha[j]<= 57){
					printf("\033[0;m+%c",linha[j]); j++;
				} /* if */
			} /* for */

			printf("\n");
		}

		printf("|-------------------------------------------|");
		printf("\n");
		printf("| 13 14 15 16 17 18 |   | 19 20 21 22 23 24 |\n");
		printf("\\-------------------------------------------/");
		printf("\n");

    JOG_MostrarPontuacao() ;
	}

/***********************************************************************
*
*  $FC Função: JOG Mostrar Pontuação
*
*  $ED Descrição da Função
*     Exibe quantos pontos vale a partida, os valores de dado tirados
*     e um vencedor se hover um
*
*  $FV Valor Retornado
*     JOG_CondRetOk
*     JOG_DadoPontosNaoInicializado
*
***********************************************************************/

	JOG_tpCondRet JOG_MostrarPontuacao( void )
	{

		int pontuacao ;
		if ( DADP_ObetrValorPontuacao( &pontuacao ) == DADP_CondRetOK )
		{
			printf("\\---------------------|--------------------/\n") ;
			printf("   Valor partida: %d    Vencedor: %c\n", pontuacao , jogo->vencedor ) ;
			printf("\\---------------------|--------------------/\n") ;
      if (jogo->jogador == '-'){
        return JOG_CondRetOk;
      }
			if ( jogo->dado1 != -1 )
			{

				printf("   valor dado 1: %d",jogo->dado1) ;
			}/* if */

			if ( jogo->dado2 != -1 )
			{

				printf("   valor dado 2: %d",jogo->dado2) ;
			}/* if */
      if (jogo->dado1 == jogo->dado2 && jogo->dado1!=-1 &&jogo->dado2!=-1){
        printf("\n\t  Dado duplicado!") ;
      }
			printf("\n") ;
			return JOG_CondRetOk ;
		}/* if */

		return JOG_DadoPontosNaoInicializado ;
	}

/***********************************************************************
*
*  $FC Função: JOG Salvar Jogo
*
*  $ED Descrição da Função
*     Salva o jogo com um nome escolhido pelo usuário
*
*  $FV Valor Retornado
*     JOG_CondRetOk
*
***********************************************************************/

  JOG_tpCondRet JOG_SalvarJogo ( char * nomeArq , char * jogador ){
    FILE* arq;
    tpPeca* p = NULL;
    int i, qtd, pts; /* iterador, quantidade de pecas, pontuacao da partida */
    char cor, dono;
    TAB_tpCondRet cond;
    arq = fopen(nomeArq, "w");

    DADP_ObetrValorPontuacao( &pts ) ;
    fprintf(arq, "Pontuacao do jogo:\n"); /* linha 0 */
    fprintf(arq, "%d\n", pts);

    fprintf(arq, "Numero de pecas em cada casa (separados por ;) abaixo:\n"); /* linha 2 */

    TAB_IrInicioTabuleiro ( ) ;

    for ( i=0 ; i<24 ; i++ ){
      TAB_ObterQuantidadePEC( &qtd );
      fprintf(arq, "%d;", qtd );
      TAB_AndarTabuleiro( 1 );
    } /* for */

    TAB_IrInicioTabuleiro ( ) ;
    fprintf(arq, "\nCor das pecas de cada casa (separados por ;) abaixo:\n"); /* linha 4 */

    for ( i = 0; i<24 ; i++){
      cond = TAB_ObterPeca( &p ) ;
      if ( cond == TAB_CasaVazia ){
        fprintf(arq, "-;");
      }
      else{
        PCA_ObterCor( p , &cor );
        fprintf(arq, "%c;", cor );
      }
      TAB_AndarTabuleiro( 1 );
    }

    TAB_IrInicioTabuleiro ( ) ;

    fprintf(arq, "\nQuantidade de pecas PRETAS na barra:\n"); /* linha 6 */
    BAR_QuantidadeBarra( 'P' , &qtd ) ;
    fprintf(arq, "%d", qtd);

    fprintf(arq, "\nQuantidade de pecas BRANCAS na barra:\n"); /* linha 8 */
    BAR_QuantidadeBarra( 'B' , &qtd ) ;
    fprintf(arq, "%d", qtd);

    fprintf(arq, "\nQuantidade de pecas PRETAS finalizadas:\n"); /* linha 10 */
    PEF_quantidadeFinalizadas( 'P' , &qtd ) ;
    fprintf(arq, "%d", qtd);

    fprintf(arq, "\nQuantidade de pecas BRANCAS finalizadas:\n"); /* linha 12 */
    PEF_quantidadeFinalizadas( 'B' , &qtd ) ;
    fprintf(arq, "%d\n", qtd);

    /* salvando jogador */
    fprintf(arq, "Era vez do jogador de cor:\n"); /* linha 14 */
    fprintf(arq, "%c\n", *jogador);

    DADP_DonoDado(&dono);
    fprintf(arq, "Jogador dono do dado pontos:\n");
    fprintf(arq, "%c\n", dono);

    fclose(arq);
    return JOG_CondRetOk;
  }

/***********************************************************************
*
*  $FC Função: JOG Carregar Jogo
*
*  $ED Descrição da Função
*     Carrega o jogo a partir de um arquivo no mesmo diretório do
*     programa com o nome fornecido pelo usuário
*
*  $FV Valor Retornado
*     JOG_CondRetOk
*     JOG_ErroAoIniciarPartida
*
***********************************************************************/

  JOG_tpCondRet JOG_CarregarJogo ( char * nomeArq ) {
    FILE* arq;
    int i , j , k , qtdBar , qtdFin , qtd , pts; /* iterador, quantidade de pecas, pontuacao da partida */
    int pontuacao = 0;
    char corBar, corFin, cor, dono;
	 char linha[200];
    int vet[24];
    char vCor[24];
	 char num[2] ;
    tpPeca * p = NULL;
    TAB_tpCondRet tabCond;
	DADP_tpCondRet dcond;

    arq = fopen(nomeArq, "r");
    i = 0; j = 0; k=0;

    tabCond = TAB_CriarTabuleiro ();
    if ( tabCond != TAB_CondRetOk ){
       return JOG_ErroAoIniciarPartida;
    } /* if */
    tabCond = TAB_InicializarTabuleiro();
    if ( tabCond != TAB_CondRetOk ){
       return JOG_ErroAoIniciarPartida;
    } /* if */

	inic_jogo();
    DADP_CriarDadoPontos(  ) ;
    BAR_CriarBarra( );
    PEF_CriarFinalizadas( );

    /* pegando informacoes do arquivo */
    while ( i <= 17 ){
		fgets(linha, 200, arq);
      if ( i == 1 ){ /* pega informacoes da pontuacao da partida */
        pts = atoi(&linha[0]);
      } /* if */

       if ( i == 3 ){
		   k=0;
         for ( j = 0; linha[j] != '\n'; j ++){
           if (linha[j] != ';'){
			   num[0] = linha[j] ;
			   num[1] = '\0' ;
             vet[k] = atoi(num); /* montando o vetor de qtd de pecas na casa */
             k++;
           } /* if */
         } /* for */
       } /* if */

       if ( i == 5 ){
		   k=0;
         for ( j = 0; linha[j] != '\n'; j ++){
           if (linha[j] != ';'){
             vCor[k] = linha[j]; /* montando o vetor de cor das casas */
             k++;
           } /* if */
         } /* for */
       } /* if */

       if ( i == 7 ){ /* pega informacoes da barra */
         qtdBar = atoi(&linha[0]);
         for(j=0;j<qtdBar;j++){
           PCA_CriarPeca(&p,'P');
           BAR_InserirBarra(p);
         }
       } /* if */

       if ( i == 9 ){ /* pega informacoes da barra */
         qtdBar = atoi(&linha[0]);
         for(j=0;j<qtdBar;j++){
           PCA_CriarPeca(&p,'B');
           BAR_InserirBarra(p);
         }
       } /* if */

       if ( i == 11 ){ /* pega informacoes das pecas finalizadas */
         qtdFin = atoi(&linha[0]);
         for(j=0;j<qtdFin;j++){
           PCA_CriarPeca(&p , 'P');
           PEF_InserirFinalizadas(p);
         }
       } /* if */

       if ( i == 13 ){ /* pega informacoes das pecas finalizadas */
         qtdFin = atoi(&linha[0]);
         for(j=0;j<qtdFin;j++){
           PCA_CriarPeca(&p , 'B');
           PEF_InserirFinalizadas(p);
         }
       } /* if */

       if (i == 15){
         jogo->jogador = linha[0]; /* volta a ser a vez do jogador X */
       }

       if (i == 17){
         dono = linha[0]; /* volta a ser a vez do jogador X */
       }

       i++;
    }
    TAB_IrInicioTabuleiro();
    /* montando o tabuleiro */
    for ( i = 0; i<24 ; i ++ ){
		qtd = vet[i];
      if (qtd > 0){
        cor = vCor[i];
        insere_npecas_corrente(cor, qtd);
      }
      TAB_AndarTabuleiro(1);
    }
    TAB_IrInicioTabuleiro();
    /* retornando a pontuacao original */
    DADP_IniciarDadoPontos ( dono ) ;
    dcond = DADP_ObetrValorPontuacao( &pontuacao );
    /* colocando a pontuacao do jogo de volta */
    while (  pontuacao != pts ){
      DADP_DobrarPontuacao( dono ) ;
      DADP_ObetrValorPontuacao( &pontuacao );
    }
    fclose ( arq );
    return JOG_CondRetOk;
  }

/***********************************************************************
*
*  $FC Função: JOG Finalizar Jogo
*
*  $ED Descrição da Função
*     Finaliza o jogo e libera o espaço alocado por suas estruturas
*
***********************************************************************/
	JOG_tpCondRet JOG_FinalizarJogo ( void ){
		JOG_tpCondRet cond;
		BAR_DestruirBarra() ;
		DADP_DestruirDadoPontos() ;
		DestruirFinalizadas() ;
		TAB_DestruirTabuleiro() ;
		return JOG_CondRetOk;
	}

/***********************************************************************
*
*  $FC Função: Insere NPecas Corrente
*
*  $ED Descrição da Função
*     Função auxiliar que insere um certo numero (num) de peças na
*     casa corrente
*
***********************************************************************/

	void insere_npecas_corrente(char cor, int num){
		tpPeca * peca;
		int i; /* indice para o for loop */
		PCA_CriarPeca(&peca, cor);
		for (i = 0; i < num; i++) {
			TAB_InserirPeca(peca);
		}
	}

/***********************************************************************
*
*  $FC Função: Inic Jogo
*
*  $ED Descrição da Função
*     Inicializa o struct partida com valores iniciais para uma partida
*
***********************************************************************/

	void inic_jogo( void )
	{
		jogo = (Partida *)malloc( sizeof(struct partida) ) ;
		jogo->vencedor = '?' ;
		jogo->jogador = '?' ;
		jogo->dado_dobrado = 0 ;
		jogo->dado1 = -1 ;
		jogo->dado2 = -1 ;
		return ;
	}

/***********************************************************************
*
*  $FC Função: JOG  - Mudar jogador
*
*  $ED Descrição da função
*     Muda jogador a realizar próxima ação.
*
***********************************************************************/

	void MudarJogador( void )
	{

		if ( jogo->jogador == 'B' )
			jogo->jogador = 'P' ;
		else
			jogo->jogador = 'B' ;
		return ;
	}

/***********************************************************************
*
*  $FC Função: JOG  - Calcula destino
*
*  $ED Descrição da função
*     Calcula o destino de uma jogada.
*
*  $FV Valor Retornado
*     int - Retorna o número da casa correspondente ao cálculo a partir
*     da origem com o valor de um dado
*
***********************************************************************/

	int CalculaDestinoJogada(int origem , int qtd )
	{

		if ( jogo->jogador == 'B' )
			return origem + qtd ;

		return origem - qtd ;
	}

/***********************************************************************
*
*  $FC Função: JOG  - Recebe Comando
*
*  $ED Descrição da função
*     Recebe input do jogador.
*
*  $FV Valor Retornado
*     Retorna o input de até um character do usuário
*
***********************************************************************/

	char recebeComando( void){
		char input;
		char retorno;
		retorno = '0';
		while(TRUE){
			input = getchar();
			if( input == '\n' ) break;
			else retorno = input;
		}
		return retorno;
	}

/***********************************************************************
*
*  $FC Função: JOG  - Movimenta Peca
*
*  $ED Descrição da função
*     Movimenta a peca de uma casa para outra
*     (so eh chamada quando movimento eh possivel )
*
***********************************************************************/

  void movimentaPeca( int origem , int destino, int flagBarra)
  {
    /* funcao so eh chamada se origem possui peca correta e destino esta livre */
    tpPeca* peca = NULL;
    char cor;
	  int quantidade ;
    /* removo a peca da origem */
    if(!flagBarra){
      TAB_IrInicioTabuleiro() ;
      TAB_AndarTabuleiro( origem ) ;
      TAB_ExcluirPeca() ;
    }
    /* incluo nova peca no destino */
    TAB_IrInicioTabuleiro() ;
    TAB_AndarTabuleiro( destino ) ;
    TAB_ObterQuantidadePEC( &quantidade ) ; /* vejo a quantidade de pecas */
    if ( quantidade > 0 )
    {
      TAB_ObterPeca(&peca);
      PCA_ObterCor(peca,&cor);
      if (cor != jogo->jogador)
        capturar(); /* peca movida para barra */
      PCA_DestruirPeca(&peca);
    }
    TAB_IrInicioTabuleiro() ;
    TAB_AndarTabuleiro( destino ) ;
    if (flagBarra){
      BAR_RetirarBarra( &peca , jogo->jogador ) ;
    }
    PCA_CriarPeca( &peca, jogo->jogador );
    TAB_InserirPeca( peca ) ;
  }

/***********************************************************************
*
*  $FC Função: JOG  - Possibilidades Jogadas
*
*  $ED Descrição da função
*     Calcula todas as casas destino possiveis para origem dada. Salva
*     as origems no inteiro apontado pelos parâmetros e retorna 1 caso
*     exista ao menos uma possibilidade ou 0 caso não haja
*
*  $FV Valor de Retorno
*     1 - Existe ao menos uma possibilidade de movimentação
*     0 - Não existe nenhuma possibilidade de movimentação daquela origem
*
***********************************************************************/
int PossibilidadesJogadas(int origem, int * possibilidade1, int * possibilidade2){
   int quantidade, i;
   char cor;
   tpPeca * peca ;
   int VetorCasa[2] = {-1, -1};
   if ( jogo->dado1 != -1 )
   {
      VetorCasa[0] = CalculaDestinoJogada( origem , jogo->dado1 ) ;

   }
   if ( jogo->dado2 != -1 )
   {
      VetorCasa[1] = CalculaDestinoJogada( origem , jogo->dado2 ) ;
   }
   for ( i = 0 ; i < 2 ; i++ )
   {
      TAB_IrInicioTabuleiro() ;
      if(VetorCasa[i] < 0 || VetorCasa[i] > 23){
         VetorCasa[i] = -1;
      }

      TAB_AndarTabuleiro( VetorCasa[i] ) ; /* vou ate a casa destino */
      TAB_ObterQuantidadePEC( &quantidade ) ; /* vejo a quantidade de pecas */

      if ( quantidade > 0 )
      {
         TAB_ObterPeca( &peca ) ;
         PCA_ObterCor( peca , &cor) ;
         if ( cor != jogo->jogador && quantidade > 1) /* nao da para mover a peca */
         {
            VetorCasa[i] = -1 ;
         }
         PCA_DestruirPeca( &peca );
      }
   }
   if (VetorCasa[0]==-1 && VetorCasa[1]==-1 ){ /* nao da para se mover */
      return 0;
   }
   else {
      *possibilidade1 = VetorCasa[0] ;
      *possibilidade2 = VetorCasa[1] ;
      return 1;
   }
}

/***********************************************************************
*
*  $FC Função: JOG  - Realiza jogada
*
*  $ED Descrição da função
*     Realiza jogada a partir de uma origem escolhida pelo jogador.
*
*  $FV Valor Retornado
*     0 - Não é possível se mover daquela origem com os dados tirados
*     1 - O movimento foi realizado com o valor do dado 1
*     2 - O movimento foi realizado com o valor do dado 2
*
***********************************************************************/

	int RealizaJogada(int origem, int flagBarra)
	{
    int VetorCasa[2];
    int destino , i, possibilidade1, possibilidade2;
    possibilidade1 = -1 ;
    possibilidade2 = -1 ;
    if (!flagBarra) origem = origem -1 ;
    if (!PossibilidadesJogadas(origem, &possibilidade1, &possibilidade2)){ /* nao da para se mover */
      printf("\nNao eh possivel realizar jogada\n");
      printf("Aperte ENTER para continuar\n");
      recebeComando();
      recebeComando();
      return 0;
    }
    VetorCasa[0] = possibilidade1;
    VetorCasa[1] = possibilidade2;
	 destino = -1;
    while( destino != VetorCasa[0]+1 && destino!=VetorCasa[1]+1 ){
    	JOG_MostrarTabuleiro();
      if(flagBarra){
        printf("Voce possui pecas capturadas na barra!\n");
        printf("Eh preciso retira-las!\n");
      }
    	printf("\nCasas possiveis para movimento:\n");
    	for (i=0; i<2;i++){
        if(VetorCasa[i] != -1)
    			printf("%2d - Para mover para casa %02d\n", VetorCasa[i]+1,VetorCasa[i]+1);
    	}
    	if(!flagBarra) printf(" 0 - Para cancelar a jogada a partir dessa casa\n");
    	scanf(" %d",&destino);
    	if (destino == 0 && !flagBarra) return 0;
     }
     movimentaPeca(origem, destino -1, flagBarra);
     if (destino - 1 == VetorCasa[0]){
         return 1 ;
       }
       else if (destino -1 == VetorCasa[1]){
         return 2 ;
       }

   }

/***********************************************************************
*
*  $FC Função: JOG  - Verifica jogada possivel
*
*  $ED Descrição da função
*     Verifica se existe alguma jogada possivel com os dados.
*
*  $FV Valor Retornado
*     1 - Existe uma jogada possível com uma das peças do jogador com
*     os dados tirados
*     0 - Não existe nenhum movimento possível com as peças daquele
*     jogador e os dados tirados
*
***********************************************************************/

int VerificaJogadaPossivel(){
   int i, flag, possibilidade1, possibilidade2 ;
   char cor ;
   tpPeca * pTpPeca ;
   flag = 0;
   pTpPeca = 0;
   for(i=0;i<24;i++){
      TAB_IrInicioTabuleiro() ;
      TAB_AndarTabuleiro( i ) ;
      TAB_ObterPeca( &pTpPeca ) ;
      PCA_ObterCor(pTpPeca, &cor) ;
      if ( cor == jogo->jogador){
         flag = PossibilidadesJogadas(i, &possibilidade1, &possibilidade2) ;
         if (flag == 1) return 1;
      }
   }
   PCA_DestruirPeca( &pTpPeca ) ;
   printf("Não foram encontrados movimentos possiveis com os dados tirados!\n") ;
   printf("Aperte ENTER para continuar\n") ;
   recebeComando() ;
   return 0;
}


/***********************************************************************
*
*  $FC Função: JOG  - capturar
*
*  $ED Descrição da função
*     retira peça do Tabuleiro e coloca na Barra.
*
***********************************************************************/

	void capturar( void )
	{
		tpPeca * pTpPeca ;
		TAB_ObterPeca( &pTpPeca ) ;
		TAB_ExcluirPeca() ;
		BAR_InserirBarra( pTpPeca ) ;
		PCA_DestruirPeca( &pTpPeca ) ;
		return ;
	}

/***********************************************************************
*
*  $FC Função: JOG  - Dobrar pontuacao
*
*  $ED Descrição da função
*     Dobra pontuacao do jogo.
*
***********************************************************************/

	void dobrarPont ( void ){
		DADP_tpCondRet cond;
		char dono, resp;
		DADP_DonoDado(&dono);
		if ( dono == jogo->jogador || dono == '-'){ /* se tem posse do dado ou nao possui dono ainda */
			printf("Oponente aceita ou rejeita dobra?\n") ;
            printf("a - Aceitar dobra\n") ;
            printf("r - Rejeitar dobra\n") ;
            resp = recebeComando();
			if (resp == 'a')
            {
			   DADP_MudarJogadorPermitido(jogo->jogador);
               cond = DADP_DobrarPontuacao( jogo->jogador ) ;
			   if (cond == DADP_PontuacaoMaxima){
				   printf("Pontuacao limite da partida atingida\n");
				   printf("Aperte ENTER para continuar ...");
				   recebeComando();
			   }
			   if (jogo->jogador == 'B'){
				   DADP_MudarJogadorPermitido( 'P' ) ;
			   }
			   else{
				   DADP_MudarJogadorPermitido( 'B' ) ;
			   }
            }
            else if (resp == 'r')
            {
               MudarJogador() ;
               jogo->vencedor = jogo->jogador ;
               system("cls") ;
               JOG_MostrarTabuleiro();
               JOG_FinalizarJogo();
               printf("\nJogo finalizado\n") ;
               printf("Aperte ENTER para sair ...");
               recebeComando();
            }
		}
		else if (dono != jogo->jogador){
			printf("\nJogador nao tem posse do dado dobrador\n");
			printf("Aperte ENTER para escolher outro opcao!\n");
			recebeComando();
		}
	}

/***********************************************************************
*
*  $FC Função: JOG  - Calcula Finalizada
*
*  $ED Descrição da função
*     Calcula origem de pecas finalizadas
*
*  $FV Valor Retornado
*     int - O resultado do cálculo da casa destino possivel com a qtd
*
***********************************************************************/

  int calculaFinalizada(int origem, int qtd){
    if ( jogo->jogador == 'P' )
			return origem + qtd ;

		return origem - qtd ;
  }

/***********************************************************************
*
*  $FC Função: JOG  - Verifica Finalizadas
*
*  $ED Descrição da função
*     Verifica se eh possivel iniciar processo de finalizar pecas.
*
*  $FV Valor Retornado
*     1 - Se peças já podem ser finalizadas
*     0 - Se ainda não for possível finalizar peças
*
***********************************************************************/

  int verificarFinalizadas(char jogador){
    int i, limite, qtdBar; /* conta quantas pecas tem no tabuleiro interior */
    tpPeca* peca = NULL;
    char cor;
    TAB_tpCondRet cond;
    if (jogador == 'B'){
      i = 0;
      limite = 18;
    }
    else if (jogador == 'P'){
      i = 6;
      limite = 24;
    }
    else{ return 0; }
    BAR_QuantidadeBarra(jogo->jogador, &qtdBar);
    if (qtdBar > 0){
      return 0;
    }
    TAB_IrInicioTabuleiro( );
    TAB_AndarTabuleiro(i);
    for ( ;i < limite; i++ ){
      cond = TAB_ObterPeca(&peca);
      if (cond != TAB_CasaVazia){
        PCA_ObterCor(peca, &cor);
        if (cor == jogo->jogador){
          return 0;
        }
        PCA_DestruirPeca(&peca);
      }
      TAB_AndarTabuleiro( 1 );
    }
    TAB_IrInicioTabuleiro( );
    /* se chegou aqui pode finalizar peca */
    return 1;
  }

/***********************************************************************
*
*  $FC Função: JOG  - Verifica Dados
*
*  $ED Descrição da função
*     Verifica se há pecas nas casas onde se pode finalizar pecas.
*
*  $FV Valor Retornado
*     1 - Se existe peças a serem finalizadas
*     0 - Se não houver peças nas casas que poderiam ser finalizadas
*
***********************************************************************/

  int verificaDados( void ){
    int i;
    int ini1=-1, ini2=-1, qtd;
    if (jogo->jogador == 'B'){
      if (jogo->dado1 != -1)
        ini1 = calculaFinalizada(24,jogo->dado1);
      if (jogo->dado2 != -1)
        ini2 = calculaFinalizada(24,jogo->dado2);
    }
    else {
      if (jogo->dado1 != -1)
        ini1 = calculaFinalizada(-1,jogo->dado1);
      if (jogo->dado2 != -1)
        ini2 = calculaFinalizada(-1,jogo->dado2);
    }
    TAB_IrInicioTabuleiro( );
    if (ini1 != -1){
      for (i=0; i<=ini1; i++){
        TAB_ObterQuantidadePEC(&qtd);
        if (qtd > 0){
          return 1;
        }
        TAB_AndarTabuleiro(1);
      }
    }
    if (ini2 != -1){
      for (i=0; i<=ini2; i++){
        TAB_ObterQuantidadePEC(&qtd);
        if (qtd > 0){
          return 1;
        }
        TAB_AndarTabuleiro(1);
      }
    }
    return 0;
  }

/***********************************************************************
*
*  $FC Função: JOG  - Finalizar Peca
*
*  $ED Descrição da função
*     Retira do jogo e coloca nas pecas finalizadas.
*
***********************************************************************/
  void finalizarPeca( int origem ){
    tpPeca* peca = NULL;
    TAB_IrInicioTabuleiro() ;
    TAB_AndarTabuleiro( origem ) ;
    TAB_ObterPeca(&peca);
    PEF_InserirFinalizadas(peca);
    TAB_ExcluirPeca( );
    PCA_DestruirPeca(&peca);
  }

/***********************************************************************
*
*  $FC Função: JOG  - Main
*
*  $ED Descrição da função
*     Jogo em si.
*
***********************************************************************/

	int main(void){
		char jogador, resp;
		char nomeArq[100];
		int v1,v2;
		int quantidade , origem , destino , acao;
		JOG_tpCondRet cond;
		TAB_tpCondRet condT;
		resp = '-';
		while (resp != 'n' && resp != 'c')
		{
			system("cls");
			printf("n - Novo jogo\n");
			printf("c - Carregar jogo\n");
			resp = recebeComando();
			if (resp == 'n')
			{
				JOG_IniciarPartida();
				system("cls");
				/* jogar dados para ver quem comeca */
				printf("Jogar dados para ver quem começa a partida.\n");
				printf("Aperte ENTER para jogar dados e decidir quem começa\n");
				recebeComando();
				while(jogo->jogador == '?') {
               DAD_Jogar(&jogo->dado1, &jogo->dado2);
               printf("\nValores obtidos: Vermelho %d , Verde %d\n", jogo->dado1, jogo->dado2);
               if (jogo->dado1 > jogo->dado2) {
                  jogo->jogador = 'P';
                  printf("Jogador de pecas de cor Vermelha comeca!");
               } else if (jogo->dado1 < jogo->dado2) {
                  jogo->jogador = 'B';
                  printf("Jogador de pecas de cor Verde comeca!");
               }
               else {
                  printf("EMPATE! Aperte ENTER para jogar novamente\n");
                  recebeComando();
               }
            }
				jogo->dado1 = -1;
				jogo->dado2 =-1;
				DADP_CriarDadoPontos() ;
				DADP_IniciarDadoPontos( '-' ) ;
				recebeComando();
			}
			else if (resp == 'c')
			{
				system("cls");
				printf("Nome do arquivo de recuperacao das infos do jogo:\n");
				scanf("%s", nomeArq);
				JOG_CarregarJogo( nomeArq );
			}
			else
			{
				printf("Comando invalido, tentar novamente...\n");
				printf("Aperte ENTER para continuar...\n");
				recebeComando();
			}
		}
		while ( jogo->vencedor == '?' )
		{
         int qtd;
         PEF_quantidadeFinalizadas('P',&qtd);
         if (qtd == 15){
           jogo->vencedor = 'P';
           break;
         }
         PEF_quantidadeFinalizadas('B',&qtd);
         if (qtd == 15){
           jogo->vencedor = 'B';
           break;
         }
         JOG_MostrarTabuleiro();
         printf("j - Jogar\n");
         printf("d - Dobrar pontuacao\n");
         printf("s - Salvar jogo\n");
         printf("f - Finalizar jogo\n");
         resp = recebeComando();
         if (resp == 'j')
         {
            int flag, flagFin, qtdBar,i,njogadas;
    		   int origem, quantidade=-1;
    		   char cor='-';
    		   char r[3];
    		   tpPeca * peca = NULL;
    		   if( jogo->dado1 == -1 && jogo->dado2 == -1){
                 DAD_Jogar(&jogo->dado1,&jogo->dado2);
           }
    		   if(VerificaJogadaPossivel() == 1) {
               flagFin = verificarFinalizadas(jogo->jogador);
               if (flagFin > 0) {
                  int r, ini1, ini2;
                  while (verificaDados() != 0 && (jogo->dado1 != -1 || jogo->dado2 != -1) && VerificaJogadaPossivel() == 1) {
                     int f = 1;
                     JOG_MostrarTabuleiro();
                     printf("Eh possivel finalizar pecas!\n");
                     if (jogo->jogador == 'B') {
                        printf("Escolha uma casa (19 a 24) para finalizar peca.\n");
                        ini1 = calculaFinalizada(24, jogo->dado1);
                        ini2 = calculaFinalizada(24, jogo->dado2);
                     }
                     if (jogo->jogador == 'P') {
                        printf("Escolha uma casa (1 a 6) para finalizar peca.\n");
                        ini1 = calculaFinalizada(-1, jogo->dado1);
                        ini2 = calculaFinalizada(-1, jogo->dado2);
                     }
                     scanf(" %d", &r);
                     if ((r - 1 > ini1 && r - 1 > ini2) && jogo->dado1 != -1 && jogo->dado2 != -1) {
                        f = 0;
                        printf("ini1:%d, ini2:%d", ini1, ini2);
                        printf("Casa invalida, não é possivel finalizar pecas nessa casa\n");
                        printf("Aperte ENTER para tentar novamente...\n");
                        getchar();
                        recebeComando();
                     } else if (r - 1 > ini1 && jogo->dado1 != -1 && jogo->dado2 == -1) {
                        f = 0;
                        printf("Casa invalida, não é possivel finalizar pecas nessa casa\n");
                        printf("Aperte ENTER para tentar novamente...\n");
                        getchar();
                        recebeComando();
                     } else if (r - 1 > ini2 && jogo->dado2 != -1 && jogo->dado1 == -1) {
                        f = 0;
                        printf("Casa invalida, não é possivel finalizar pecas nessa casa\n");
                        printf("Aperte ENTER para tentar novamente...\n");
                        getchar();
                        recebeComando();
                     }
                     TAB_IrInicioTabuleiro();
                     TAB_AndarTabuleiro(r - 1);
                     TAB_ObterQuantidadePEC(&quantidade);
                     if (quantidade > 0) {
                        TAB_ObterPeca(&peca);
                        PCA_ObterCor(peca, &cor);
                     }
                     if (quantidade == 0) {
                        f = 0;
                        printf("\nCasa vazia!\n");
                        printf("Aperte ENTER para tentar novamente...\n");
                        getchar();
                        recebeComando();
                     } else if (cor != jogo->jogador) {
                        f = 0;
                        printf("\nCasa nao possui pecas da sua cor!\n");
                        printf("Aperte ENTER para tentar novamente...\n");
                        getchar();
                        recebeComando();
                     }
                     PCA_DestruirPeca(&peca);
                     if (f) {
                        int menor;
                        if (jogo->dado1 < jogo->dado2) { menor = jogo->dado1; }
                        else if (jogo->dado1 > jogo->dado2) { menor = jogo->dado2; }
                        else { menor = jogo->dado1; } /* dados iguais */
                        if (menor == jogo->dado1) {
                           if (r - 1 <= ini1) {
                              jogo->dado1 = -1;
                           } else if (r - 1 <= ini2) {
                              jogo->dado2 = -1;
                           }
                        } else {
                           if (r - 1 <= ini2) {
                              jogo->dado2 = -1;
                           } else if (r - 1 <= ini1) {
                              jogo->dado1 = -1;
                           }
                        }
                        finalizarPeca(r - 1);
                     }
                  }
               }
               njogadas = 0;
               while (jogo->dado1 != -1 || jogo->dado2 != -1 && VerificaJogadaPossivel() == 1) {
                  flag = 0;
                  BAR_QuantidadeBarra(jogo->jogador, &qtdBar);
                  if (qtdBar > 0) {
                     JOG_MostrarTabuleiro();
                     printf("Voce possui pecas capturadas na barra!\n");
                     printf("Eh preciso retira-las!\n");
                     if (jogo->jogador == 'B') {
                        flag = RealizaJogada(-1, 1);
                     } else {
                        flag = RealizaJogada(24, 1);
                     }
                     if (flag == 1) { /* Utilizado o valor do dado 1 no movimento */
                        if (jogo->dado1 != jogo->dado2) jogo->dado1 = -1;
                        else { /* Dado duplicado nao acaba com o dado nas duas primeiras jogadas */
                           if (njogadas < 2) njogadas = njogadas + 1;
                           else jogo->dado1 = -1;
                        }
                     } else if (flag == 2) { /* Utilizado o valor do dado 1 no movimento */
                        if (jogo->dado1 != jogo->dado2) jogo->dado2 = -1;
                        else { /* Dado duplicado nao acaba com o dado nas duas primeiras jogadas */
                           if (njogadas < 2) njogadas = njogadas + 1;
                           else jogo->dado2 = -1;
                        }
                     }
                     else {
                        jogo->dado1 = -1 ;
                        jogo->dado2 = -1 ;
                     }

                     BAR_QuantidadeBarra(jogo->jogador, &qtdBar);
                  } else {
                     JOG_MostrarTabuleiro();
                     printf("Casa de origem do movimento:\n");
                     scanf(" %d", &origem);
                     TAB_IrInicioTabuleiro();
                     TAB_AndarTabuleiro(origem - 1);
                     TAB_ObterQuantidadePEC(&quantidade);
                     if (quantidade > 0) {
                        TAB_ObterPeca(&peca);
                        PCA_ObterCor(peca, &cor);
                     }
                     if (quantidade == 0) {
                        printf("\nCasa vazia!\n");
                        printf("Aperte ENTER para tentar novamente...\n");
                        getchar();
                        recebeComando();
                     } else if (cor != jogo->jogador) {
                        printf("\nCasa nao possui pecas da sua cor!\n");
                        printf("Aperte ENTER para tentar novamente...\n");
                        getchar();
                        recebeComando();
                     } else {
                        flag = RealizaJogada(origem, 0);
                     }
                     if (flag == 1) { /* Utilizado o valor do dado 1 no movimento */
                        if (jogo->dado1 != jogo->dado2) jogo->dado1 = -1;
                        else { /* Dado duplicado nao acaba com o dado nas duas primeiras jogadas */
                           if (njogadas < 2) njogadas = njogadas + 1;
                           else jogo->dado1 = -1;
                        }
                     } else if (flag == 2) { /* Utilizado o valor do dado 1 no movimento */
                        if (jogo->dado1 != jogo->dado2) jogo->dado2 = -1;
                        else { /* Dado duplicado nao acaba com o dado nas duas primeiras jogadas */
                           if (njogadas < 2) njogadas = njogadas + 1;
                           else jogo->dado2 = -1;
                        }
                     }
                     PCA_DestruirPeca(&peca);
                  }
               }
            }
            MudarJogador();
    
         }
         else if (resp == 'd')
         {
           dobrarPont();
         }
         else if (resp == 's')
         {
            system("cls");
            printf("Nome do arquivo para salvar as infos do jogo:\n");
            scanf("%s", nomeArq);
            JOG_SalvarJogo( nomeArq , &jogo->jogador );
            printf("Jogo salvo!\n");
            printf("Aperte ENTER para continuar...");
            recebeComando();
         }
         else if (resp == 'f')
         {
            system("cls");
            printf("Deseja mesmo finalizar o jogo?(s/n)");
            resp = recebeComando();
            if (resp == 's')
            {
               JOG_FinalizarJogo();
               printf("\nJogo finalizado\n");
               break;
            }
            else
            {
               printf("\nRetornando ao jogo.\n");
               printf("Aperte ENTER para voltar ...\n");
               recebeComando();
            }
         }
      }
   condT = TAB_IrInicioTabuleiro();
   if (condT == TAB_NaoExiste){
	   return 0;
   }
   JOG_MostrarTabuleiro( );
   JOG_FinalizarJogo() ;
   printf("\nJogo chegou ao fim!\n");
   printf("Aperte ENTER para sair...");
   recebeComando();
   return 0;
}
