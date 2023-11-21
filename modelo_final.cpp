#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>

// variáveis globais
char jogo[3][3];
int linha, coluna;

// inicialização da matriz
void inicializarMatriz() {
    for (linha = 0; linha < 3; linha++) {
        for (coluna = 0; coluna < 3; coluna++)
            jogo[linha][coluna] = ' ';
    }
}

// mostrar matriz na tela
void imprimir() {
    printf("\n\n\t 1   2   3\n\n");
    for (linha = 0; linha < 3; linha++) {
        for (coluna = 0; coluna < 3; coluna++) {
            if (coluna == 0) {
                printf("\t");
            }
            if (jogo[linha][coluna] == ' ') {
                printf("   ");
            } else {
                printf(" %c ", jogo[linha][coluna]);
            }
            if (coluna < 2) {
                printf("|");
            }
            if (coluna == 2) {
                printf("   %d", linha + 1);
            }
        }
        printf("\n");
        if (linha < 2) {
            printf("\t-----------\n");
        }
    }
}

// função vitoria por linha
int ganhouPorLinha(int linha, char vitoria) {
    if (jogo[linha][0] == vitoria &&
        jogo[linha][1] == vitoria &&
        jogo[linha][2] == vitoria) {
        return 1;
    } else {
        return 0;
    }
}

// função para verificar vitoria por linhas
int ganhouPorLinhas(char vitoria) {
    int ganhou = 0;

    for (linha = 0; linha < 3; linha++) {
        ganhou += ganhouPorLinha(linha, vitoria);
    }
    return ganhou;
}

// função para verificar vitoria por coluna
int ganhouPorColuna(int coluna, char vitoria) {
    if (jogo[0][coluna] == vitoria &&
        jogo[1][coluna] == vitoria &&
        jogo[2][coluna] == vitoria) {
        return 1;
    } else {
        return 0;
    }
}

int ganhouPorColunas(char vitoria) {
    int ganhou = 0;

    for (coluna = 0; coluna < 3; coluna++) {
        ganhou += ganhouPorColuna(coluna, vitoria);
    }
    return ganhou;
}

// função para vitoria para diagonal principal
int ganhouPorDiag_Princ(char vitoria) {
    if (jogo[0][0] == vitoria &&
        jogo[1][1] == vitoria &&
        jogo[2][2] == vitoria) {
        return 1;
    } else {
        return 0;
    }
}

// função para vitoria para diagonal secundária
int ganhouPorDiag_Sec(char vitoria) {
    if (jogo[0][2] == vitoria &&
        jogo[1][1] == vitoria &&
        jogo[2][0] == vitoria) {
        return 1;
    } else {
        return 0;
    }
}

// função para coordenadas válidas
int Valida(int linha, int coluna) {
    if (linha >= 0 && linha < 3 &&
        coluna >= 0 && coluna < 3 &&
        jogo[linha][coluna] == ' ') {

        return 1;
    } else {
        return 0;
    }
}

// ler as coordenadas do jogador
void lerCoordenadas(char jogada) {
    char linhaChar, colunaChar;
    
    do{
	    printf("\nDigite a linha da sua jogada (1 a 3): ");
	
	    // Ler o caractere para a linha como entrada
	    scanf(" %c", &linhaChar);
	
	    // Verificar se o caractere é um dígito
	    while (!isdigit(linhaChar)) {
	        printf("Coordenada Inválida, digite a linha da sua jogada (1 a 3): ");
	        scanf(" %c", &linhaChar);
	    }
	
	    printf("\nDigite a coluna da sua jogada (1 a 3): ");
	
	    // Ler o caractere para a coluna como entrada
	    scanf(" %c", &colunaChar);
	
	    // Verificar se o caractere é um dígito
	    while (!isdigit(colunaChar)) {
	        printf("Coordenada Inválida, digite a coluna da sua jogada (1 a 3): ");
	        scanf(" %c", &colunaChar);
	    }
	
	    // Converter os caracteres para inteiros
	    linha = linhaChar - '0';
	    coluna = colunaChar - '0';
	
	    linha--; // Ajuste do indice do jogador para o ?ndice da matriz
	    coluna--;
	    
	}while (Valida(linha, coluna) == 0);

    jogo[linha][coluna] = jogada;
}

// função que retorna a quantidade de possições vazias
int quantVazias() {
    int quantidade = 0;

    for (linha = 0; linha < 3; linha++) {
        for (coluna = 0; coluna < 3; coluna++) {
            if (jogo[linha][coluna] == ' ') {
                quantidade++;
            }
        }
    }
    return quantidade;
}

// jogar com o loop principal do jogo
void jogar() {
    int jogador = 1, vitoriaX = 0, vitoriaO = 0, contadorX = 0, contadorO = 0;
    char jogador1 = 'X', jogador2 = 'O';

    do {

        imprimir();
        if (jogador == 1) {
            lerCoordenadas(jogador1);
            jogador++;
            vitoriaX += ganhouPorLinhas(jogador1);
            vitoriaX += ganhouPorColunas(jogador1);
            vitoriaX += ganhouPorDiag_Princ(jogador1);
            vitoriaX += ganhouPorDiag_Sec(jogador1);
            
            if (vitoriaX > 0) {
                contadorX++;
			}
			
        } else {
            lerCoordenadas(jogador2);
            jogador = 1;
            vitoriaO += ganhouPorLinhas(jogador2);
            vitoriaO += ganhouPorColunas(jogador2);
            vitoriaO += ganhouPorDiag_Princ(jogador2);
            vitoriaO += ganhouPorDiag_Sec(jogador2);
            
            if (vitoriaX > 0) {
                contadorX++;
			}
        }
    } while (vitoriaX == 0 && vitoriaO == 0 && quantVazias() > 0);

    if (vitoriaX == 1 && contadorX > 0) {
        printf("\nParabéns jogador 1, você venceu!!!\n");
        printf("\nJogador 1 venceu: %d \n", contadorX);
    } else if (vitoriaO == 1 && contadorO > 0) {
        printf("\nParabéns jogador 2, você venceu!!!\n");
        printf("\nJogador 2 venceu: %d\n", contadorO);
    } else {
        printf("\nDeu velha, boa sorte na próxima!!\n");
    }
}

int main() {
    setlocale(0, "Portuguese");
    int opcao;

    do {
        inicializarMatriz();
        jogar();

        printf("\nDigite 1 para jogar novamente e 2 para parar: ");
        scanf("%d", &opcao);
    } while (opcao == 1);

    return 0;
}
