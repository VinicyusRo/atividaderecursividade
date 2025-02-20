#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int c = 0, o, ir=0;
  printf("Você nasceu:\n\n");
  while(c == 0){
    
    if (ir <= 2){
      printf("Qual ação vocẽ deseja realizar?\n");
      printf("1 - Ir para direita;\n2 - Ir para esquerda;\n3 - Pular;\n4 - Encerrar o jogo.\n");
    scanf("%d", &o);
      if (o == 1){
        printf("Você se movimentou para a direita\n\n");
        ir++;
        o=0;
      }
      else if (o == 2){
        printf("Você se movimentou para a esquerda\n\n");
        ir--;
        o=0;
      }
      else if(o == 3){
        printf("Você pulou\n\n");
        o=0;
      }
      else if(o == 4){
        printf("Você saiu\n\n");
        c++;
      }
      else{
        printf("Opção inválida\n\n");
        o=0;
      }
    }
    else if(ir == 3){
      o = 0;
      printf("\nVocê encontrou um obstáculo!!\n\n");
      printf("Qual ação vocẽ deseja realizar?\n");
      printf("1 - Ir para direita;\n2 - Ir para esquerda;\n3 - Pular;\n4 - Encerrar o jogo\n");
      scanf("%d", &o);

      if (o == 1){
        printf("Opção inválida há um obstáculo na sua frente!!\n\n");
        o=0;
      }
      else if (o == 2){
        printf("Você se movimentou para a esquerda!\n\n");
        ir--;
      }
      else if(o == 3){
        printf("Você pulou!\n\n");
        ir++;
      }
        else if(o == 4){
          printf("Você saiu\n");
          c++;
        }
      else{
        printf("Opção inválida!!\n");
      }
      
    }
    else{
      printf("Você chegou ao final!!\nFim de jogo!!\n\n");
      printf("Você nasceu:\n\n");
      ir=0;
    }
    
    
  }
  return 0;
}



