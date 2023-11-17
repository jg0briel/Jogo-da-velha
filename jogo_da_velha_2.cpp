#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

//variaveis globais
char jogo[3][3];
int linha, coluna;

//inicialização de matriz
void inicializarMatriz(){
	for(linha = 0; linha < 3; linha++){
		for(coluna = 0; coluna < 3; coluna++)
			jogo[linha][coluna] = ' ';
	}
}

//mostrar matriz na tela;
void imprimir(){
	printf("\n\n\t 0   1   2\n\n");
	for(linha = 0; linha < 3; linha++){
		for(coluna = 0; coluna < 3; coluna++){
			if(coluna == 0){
				printf("\t");
			}
			printf(" %c ", jogo[linha][coluna]);
			if(coluna < 2){
				printf("|");
			}
			if(coluna == 2){
				printf("   %d", linha);
			}
		}
		printf("\n");
		if(linha < 2){
			printf("\t-----------\n");
		}
	}
}

// função vitoria por linha
int ganhouPorLinha(int linha, char vitoria){
	if (jogo[linha][0] == vitoria && 
		jogo[linha][1] == vitoria && 
		jogo[linha][2] == vitoria){
		return 1;
	}else{
		return 0;
	}
	
}

//função para verificar vitoria por linhas
int ganhouPorLinhas(char vitoria){
	int ganhou = 0;
	
	for(linha = 0; linha < 3; linha++){
		ganhou += ganhouPorLinha(linha, vitoria);
	}
	return ganhou;
}

//função para verificar vitoria por coluna;
int ganhouPorColuna(int coluna, char vitoria){
	if (jogo[0][coluna] == vitoria && 
		jogo[1][coluna] == vitoria && 
		jogo[2][coluna] == vitoria){
		return 1;
	}else{
		return 0;
	}
	
}

int ganhouPorColunas(char vitoria){
	int ganhou = 0;
	
	for(coluna = 0; coluna < 3; coluna++){
		ganhou += ganhouPorColuna(coluna, vitoria);
	}
	return ganhou;
}

//função para vitoria pra diagonal princial
int ganhouPorDiag_Princ(char vitoria){
	if (jogo[0][0] == vitoria && 
		jogo[1][1] == vitoria && 
		jogo[2][2] == vitoria){
		return 1;
	}else{
		return 0;
	}
	
}

//função para vitoria pra diagonal secundaria
int ganhouPorDiag_Sec(char vitoria){
	if (jogo[0][2] == vitoria && 
		jogo[1][1] == vitoria && 
		jogo[2][0] == vitoria){
		return 1;
	}else{
		return 0;
	}
	
}

//função para coordenadas validas
int Valida(int linha, int coluna){
	if (linha >= 0 && linha < 3 && 
		coluna >= 0 && coluna < 3 && 
		jogo[linha][coluna == ' ']){
			
		return 1;
	}else{
		return 0;
	}
}

//ler as coordenadas do jogador;
void lerCoordenadas( char jogada){
	int linha, coluna;
	
	printf("Digite a linha e a coluna da sua jogada: ");
	scanf("%d%d", &linha, &coluna);
	
	while(Valida(linha, coluna) == 0){
		printf("Coordenadas Invalidas, digite a linha e a coluna da sua jogada: ");
		scanf("%d%d", &linha, &coluna);
	}
	jogo[linha][coluna] = jogada;
}

//função que retorna a quantidade de possições vazias;
int quantVazias(){
	int quantidade = 0;
	
	for(linha = 0; linha < 3; linha++){
		for(coluna = 0; coluna < 3; coluna++){
			if(jogo[linha][coluna] == ' '){
				quantidade++;
			}
		}
		return quantidade;
	}
}

//jogar com o loop principal do jogo
void jogar(){
	int jogador = 1, vitoriaX = 0, vitoriaO = 0;
	char jogador1 = 'X', jogador2 = 'O';
	
	do{
		
		imprimir();
		if(jogador == 1){
			lerCoordenadas(jogador1);
			jogador++;
			vitoriaX += ganhouPorLinhas(jogador1);
			vitoriaX += ganhouPorColunas(jogador1);
			vitoriaX += ganhouPorDiag_Princ(jogador1);
			vitoriaX += ganhouPorDiag_Sec(jogador1);
		}else{
			lerCoordenadas(jogador2);
			jogador = 1;
			vitoriaO += ganhouPorLinhas(jogador2);
			vitoriaO += ganhouPorColunas(jogador2);
			vitoriaO += ganhouPorDiag_Princ(jogador2);
			vitoriaO += ganhouPorDiag_Sec(jogador2);
		}
	}while(vitoriaX == 0 && vitoriaO == 0 && quantVazias() > 0);
	
	if(vitoriaO == 1){
		printf("\nParabens jogador 2, você vence!!!\n");
	}else if(vitoriaX == 1){
		printf("\nParabens jogador 1, você vence!!!\n");
	}else{
		printf("\nQue pena deu empate!!\n");
	}
}

int main(){
	setlocale(0, "Portuguese");
	int opcao;
	
	do{
		inicializarMatriz();
		jogar();
		
		printf("\nDigite 1 para jogar novamente e 2 para parar:");
		scanf("%d", &opcao);
	}while(opcao == 1);
	
	
	
}
