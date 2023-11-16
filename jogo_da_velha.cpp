#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(){
	setlocale(0, "Portuguese");
	
	printf("Bem vindo ao jogo da velha, boa sorte e bom jogo!!! ");
	
	//Determinar as variaveis;
	int linha, coluna;
	int linha_jogador, coluna_jogador;
	char jogo[3][3];
	int jogador = 1;
	
	//Construção da matriz;
	for(linha = 0; linha <= 2; linha++){
		for(coluna = 0; coluna <= 2; coluna++){
			jogo[linha][coluna] = ' ';
		}
	}
	
	//Monstrar a matriz para o usuario;
	printf("\n\n\t 0     1     2\n\n");
	
	for(linha = 0; linha <= 2; linha++){
		for(coluna = 0; coluna <= 2; coluna++){
			if(coluna == 0)
				printf("\t");
			printf(" %c ", jogo[linha][coluna]);
			if(coluna < 2){
				printf(" | ");
			} if(coluna == 2)
				printf("  %d", linha);
		}
		if(linha < 2){
			printf("\n\t----------------");
		}
		printf("\n");
	}
	
	//Ler os dados formecidos pelo usuário (a jogada dele);
	do{
		printf("\nDigite a linha e a coluna desejada: ");
		scanf("%d %d", &linha_jogador, &coluna_jogaodor)
	} while(linha_jogador < 0 || linha_jogador > 2 || 
			coluna_jogador < 0 || coluna_jogador > 2
			|| jogo[linha_jogador][coluna_jogador] != ' ');
	
	//Salvar o local que foi ocupado na matriz;
	if(jogador == 1){
		jogo[linha_jogador][coluna_jogador] = 'O';
		jogador++;
	}else{
		jogo[linha_jogador][coluna_jogador] = 'X';
		jogador = 1;
	}
	
	// Confirmar se alguém ganhou por linha;
	
	
	// Confirmar se alguém ganhou por coluna;
	
	// Confirmar se alguém ganhou na diagonal principal;
	
	// Confirmar se alguém ganhou na diagonal secundaria;
	
	
}
