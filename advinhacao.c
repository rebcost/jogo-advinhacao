/*
    Autor: Felýpë Costa
    Estudante de Eng. Computação - Faculdade do Amazonas de Ensino, Pesquisa e Inovação (FAMEPI)

    Descrição:

    Esse projeto tem como objetivo desenvolver um jogo de adivinhação em que 
    o computador sorteia um número entre 1 e 99. O jogador dever acertar na menor quantidade
    de tentativas possíveis para conseguir alcançar uma maior pontuação.

    O jogador pode escolher entre três níveis:
        1 - Fácil
        2 - Médio
        3 - Difícil
    
    De acordo com dificuldade escolhida é atribuida uma quantidade de tentativas. 
    
    Vence o jogo se acertar o número sorteado. Senão é gamer over.

    Enjoy the game.

    Obs: Esse projeto foi desenvolvido utilizando com referência o livro 
    - Introdução à programação em C: Os primeiros passos de um desenvolvedor do autor Maurício Aniche.
    Acrescentei o meu conhecimento da Linguagem e adaptei algumas estruturas do código original.


 */


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NIVEL_FACIL 20
#define NIVEL_MEDIO 15
#define NIVEL_DIFICIL 6


void head(){
    system("clear");
    printf("         *** BEM-VINDO AO JOGO DE ADVINHAÇÃO ***                \n ");
    printf("\n\n");
    printf("                            P /_\\ P                             \n");
    printf("                         /_\\_|_|_/_\\                           \n");
    printf("                      n_n | ||. .|| | n_n                        \n");
    printf("                      |_|_|nnnn nnnn|_|_|                        \n");
    printf("                     |\" \" | |_| |\" \" |                       \n");
    printf("                     |_____| ' _ ' |_____|                       \n");
    printf("                          \\__|_|__/                             \n");
    printf("\n\n");
}

int numero_secreto(){
    /* Função retorna um número aletório entre 1 até 100 */
    srand(time(NULL));
    int numerosecreto = (rand() % 100);
    return numerosecreto;
}

int chutar_numero(){
    int chute;
    printf("Qual eh seu chute (1-99): ");
    scanf("%d",&chute);
    return chute;
}

void testar_num_secreto(int num){
    printf("%d\n", num);
}

void mostrar_resultado(int acertou, double pontos){
    system("clear");
    if(acertou){
        printf("             OOOOOOOOOOO               \n");
		printf("         OOOOOOOOOOOOOOOOOOO           \n");
		printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
		printf("    OOOOOO      OOOOO      OOOOOO      \n");
		printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
		printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
		printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
		printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
		printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
		printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
		printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
		printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
		printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
		printf("         OOOOOO         OOOOOO         \n");
		printf("             OOOOOOOOOOOO              \n");
        printf("\nParabéns você acertou!!!\n");
        printf("Você fez %.2lf pontos!\n", pontos);
    }else{
        printf("       \\|/ ____ \\|/    \n");   
        printf("        @~/ ,. \\~@      \n");   
        printf("       /_( \\__/ )_\\    \n");   
        printf("          \\__U_/        \n");

        printf("Você perdeu tente novamente!!! \n\n");
    } 
    
}

int escolherNivel(){
    int nivel;
    int totalTentativas;
    printf("Qual nível de dificuldade (1)Fácil (2)Médio (3)Difícil\n\n");
    printf("Escolha a dificuldade: ");
    scanf("%d",&nivel);

    switch (nivel){
    case 1:
        return totalTentativas = NIVEL_FACIL;
    case 2:
        return totalTentativas = NIVEL_MEDIO;
    case 3:
        return totalTentativas = NIVEL_DIFICIL;
    default:
        printf("Escolha apenas entre os valores (1), (2), (3)\n");
        return totalTentativas = -1;        
    }

}

void fimJogo(){
    system("clear");
    printf("GAMER OVER! \n");
}

int main(int argc, char const *argv[]){
    // Declaração de Variaveis     
    int chute;
    int numerosecreto;    
    int totalTentativas;
    int acertou;
    int cont;

    // Define a quantidade de pontos
    double pontos = 1000;    

   
    do{      
    
        head(); // Exibe o cabeçalho do jogo 

        do{
            totalTentativas = escolherNivel();
        } while (totalTentativas == -1);       
                   
        numerosecreto = numero_secreto();

        //testar_num_secreto(numerosecreto);

        for(int i=1; i<=totalTentativas; i++){

            // Verifica se o número informado é maior que número máximo permitido
            do{
                chute = chutar_numero();
                if(chute > 99){
                    printf("Você deve chutar um número entre (1 - 99)\n");
                }else break;                                                    
            } while (1);
            
            printf("-> Tentativa %d de %d\n",i, totalTentativas);
                    
            // Verifica se o número informado é negativo
            if(chute < 0){
                printf("Você não pode chutar número negativos!\n");
                i--;            
                continue;
            } 

            // Verifica se acertou, foi maior ou menor         
            acertou = chute == numerosecreto;
            int maior = chute > numerosecreto;            

            if (acertou)         
                break;

            if (maior){
                printf("Seu chute foi maior que o número secreto! \n");
            }else{
                printf("Seu chute foi menor que o número secreto\n");
            }            
            
            // Calcula a quantidade de pontos
            double pontosperdidos = abs((chute - numerosecreto)) / 2.0;
            pontos -= pontosperdidos;
        
        }

        // Exibe o Resultado do jogo
        mostrar_resultado(acertou, pontos);

        // Continuação do jogo
        printf("\n Você deseja continuar (1)-SIM (0)-NÃO\n");
        scanf("%d",&cont); 

        if(cont == 0)
            break;

    } while (1);
    
    fimJogo();

    return 0;
}
