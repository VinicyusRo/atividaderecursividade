#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fatorial(int n);
int soma(int n);
int fibonacci(int n);
int potenciacao(int x, int y);
void contagemRegressiva(int n);
int somaDigitos(int n)/
void inversaoString(char inver[], int comeco, int fim);

int main(void) {

    return 0;
}

/*exercicío 1*/
int fatorial(int n) {
    if (n == 0 || n == 1) return 1;
  return n * fatorial(n - 1);
}
/*exercicío 2 */
int soma(int n){
  if(n <= 0) return 0;
  return n + soma(n-1);
}
/*exercicío 3*/
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

/*exercicío 4 */
int potenciacao(int x, int y){
  if(y <= 0) return 1;
  return x * potenciacao(x, y-1);
}
/*exercicío 5*/
void contagemRegressiva(int n) {
  if (n < 0) return;
  printf("%d ", n);
  contagemRegressiva(n - 1);
}
/*exercicío 6*/
int somaDigitos(int n) {
  if (n == 0)return 0; 
  else return n % 10 + somaDigitos(n / 10);
}
/*exercicío 7*/
void inversaoString(char inver[], int comeco, int fim) {
  if (comeco >= fim) return;
    
  char temp = inver[comeco];
  inver[comeco] = inver[fim];
  inver[fim] = temp;
  inversaoString(inver, comeco + 1, fim - 1);
}





