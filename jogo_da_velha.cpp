#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// função vitoria por linha
int ganhouPorLinha(char jogo[3][3], int linha, char vitoria){
	if (jogo[linha][0] == vitoria && 
		jogo[linha][1] == vitoria && 
		jogo[linha][2] == vitoria){
		return 1;
	}else{
		return 0;
	}
	
}

//função para verificar vitoria por linhas
int ganhouPorLinhas(char jogo[3][3], int linha, char vitoria){
	int ganhou = 0;
	
	for(linha = 0; linha < 3; linha++){
		ganhou += ganhouPorLinha(jogo, linha, vitoria);
	}
	return ganhou;
}

//função para verificar vitoria por coluna;
int ganhouPorColuna(char jogo[3][3], int coluna, char vitoria){
	if (jogo[0][coluna] == vitoria && 
		jogo[1][coluna] == vitoria && 
		jogo[2][coluna] == vitoria){
		return 1;
	}else{
		return 0;
	}
	
}

int ganhouPorColunas(char jogo [3][3], int coluna, char vitoria){
	int ganhou = 0;
	
	for(coluna = 0; coluna < 3; coluna++){
		ganhou += ganhouPorColuna(jogo, coluna, vitoria);
	}
	return ganhou;
}

//função para vitoria pra diagonal princial
int ganhouPorDiag_Princ(char jogo[3][3], char vitoria){
	if (jogo[0][0] == vitoria && 
		jogo[1][1] == vitoria && 
		jogo[2][2] == vitoria){
		return 1;
	}else{
		return 0;
	}
	
}

//função para vitoria pra diagonal secundaria
int ganhouPorDiag_Sec(char jogo[3][3], char vitoria){
	if (jogo[0][2] == vitoria && 
		jogo[1][1] == vitoria && 
		jogo[2][0] == vitoria){
		return 1;
	}else{
		return 0;
	}
	
}

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
	
	while(1){
	
		//Ler os dados formecidos pelo usuário (a jogada dele);
		do{
			printf("\nDigite a linha e a coluna desejada: ");
			scanf("%d %d", &linha_jogador, &coluna_jogador);
		}while(linha_jogador < 0 || linha_jogador > 2 
			|| coluna_jogador < 0 || coluna_jogador > 2
			|| jogo[linha_jogador][coluna_jogador] != ' ');
		
		//Salvar o local que foi ocupado na matriz;
		jogo[linha_jogador][coluna_jogador] = 'O';
		
		//Verificar se o jogador venceu;
		if (ganhouPorLinhas(jogo, linha_jogador, 'O') || 
			ganhouPorColunas(jogo, coluna_jogador, 'O') || 
			ganhouPorDiag_Princ(jogo, 'O') || ganhouPorDiag_Sec(jogo, 'O')){
			
			printf("Você vence, parabens!!\n");
			break;
			}
		
		//Jogada da maquina;
		do {
	        linha = rand() % 3;
	        coluna = rand() % 3;
	    } while (jogo[linha][coluna] != ' ');
	        
	    //Salvar o local ocupado na matriz;
	    jogo[linha][coluna] = 'X';
		
		//Verificar se a maquina venceu;
		if (ganhouPorLinhas(jogo, linha, 'X') || 
			ganhouPorColunas(jogo, coluna, 'X') || 
			ganhouPorDiag_Princ(jogo, 'X') || 
			ganhouPorDiag_Sec(jogo, 'X')){
				
			printf("A máquina venceu! Tente novamente.\n");
			break;
		}
	}
}
