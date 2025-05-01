#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

/*exercicío 8*/
int palindromo(char poli[], int inicio, int fim) {
  if (inicio >= fim) return 1;
  if (poli[inicio] != poli[fim]) return 0;
  
  return palindromo(poli, inicio + 1, fim - 1);
  }

/*exercicío 9*/
int mdc(int a, int b) {
  return (b == 0) ? a : mdc(b, a % b);
}

/*exercicío 10*/
int multiplicar(int a, int b) {
  if (b == 0) return 0;
  return a + multiplicar(a, b - 1);
}

/*exercicío 11*/
int contarChar(const char *str, char c) {
  if (*str == '\0') return 0;
  return (*str == c) + contarChar(str + 1, c);
}

/*exercicío 12*/
int somaArray(int arr[], int n) {
  if (n == 0) return 0;
  return arr[0] + somaArray(arr + 1, n - 1);
}

/*exercicío 13*/
int ehPrimo(int n, int i) {
  if (n <= 2) return (n == 2);
  if (n % i == 0) return 0;
  if (i * i > n) return 1;
  return ehPrimo(n, i + 1);
}

/*exercicío 14*/
void binario(int n) {
  if (n > 1) binario(n / 2);
  printf("%d", n % 2);
}

/*exercicío 15*/
void imprimirPares(int n) {
  if (n < 0) return;
  imprimirPares(n - 2);
  if (n % 2 == 0) printf("%d ", n);
}

/*exercicío 16*/
void imprimirImpares(int n) {
  if (n <= 0) return;
  imprimirImpares(n - 2);
  if (n % 2 == 1) printf("%d ", n);
}

/*exercicío 17*/
int buscaArray(int arr[], int n, int x) {
  if (n == 0) return 0;
  return (arr[0] == x) || buscaArray(arr + 1, n - 1, x);
}

/*exercicío 18*/
int comprimento(const char *str) {
  return (*str == '\0') ? 0 : 1 + comprimento(str + 1);
}

/*exercicío 19*/
void hanoi(int n, char A, char B, char C) {
  if (n == 1) {
      printf("Mover disco 1 de %c para %c\n", A, C);
      return;
  }
  hanoi(n - 1, A, C, B);
  printf("Mover disco %d de %c para %c\n", n, A, C);
  hanoi(n - 1, B, A, C);
}

/*exercicío 20*/
void permutar(char *str, int l, int r) {
  if (l == r) printf("%s\n", str);
  else {
      for (int i = l; i <= r; i++) {
          char tmp = str[l]; str[l] = str[i]; str[i] = tmp;
          permutar(str, l + 1, r);
          tmp = str[l]; str[l] = str[i]; str[i] = tmp;
      }
  }
}

/*exercicío 21*/
void combinacoes(int arr[], int n, int k, int index, int data[], int i) {
  if (index == k) {
      for (int j = 0; j < k; j++) printf("%d ", data[j]);
      printf("\n");
      return;
  }
  if (i >= n) return;
  data[index] = arr[i];
  combinacoes(arr, n, k, index + 1, data, i + 1);
  combinacoes(arr, n, k, index, data, i + 1);
}

/*exercicío 22*/
void subconjuntos(int arr[], int n, int index, int subset[], int subsize) {
  if (index == n) {
      printf("{");
      for (int i = 0; i < subsize; i++) printf("%d ", subset[i]);
      printf("}\n");
      return;
  }
  subset[subsize] = arr[index];
  subconjuntos(arr, n, index + 1, subset, subsize + 1);
  subconjuntos(arr, n, index + 1, subset, subsize);
}

/*exercicío 23*/
void merge(int arr[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1, n2 = r - m;
  int L[n1], R[n2];
  for (i = 0; i < n1; i++) L[i] = arr[l + i];
  for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
  i = j = 0; k = l;
  while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
  while (i < n1) arr[k++] = L[i++];
  while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {
      int m = (l + r) / 2;
      mergeSort(arr, l, m);
      mergeSort(arr, m + 1, r);
      merge(arr, l, m, r);
  }
}

/*exercicío 24*/
int partition(int arr[], int low, int high) {
  int pivot = arr[high], i = low;
  for (int j = low; j < high; j++) {
      if (arr[j] < pivot) {
          int t = arr[i]; arr[i] = arr[j]; arr[j] = t;
          i++;
      }
  }
  int t = arr[i]; arr[i] = arr[high]; arr[high] = t;
  return i;
}
void quickSort(int arr[], int low, int high) {
  if (low < high) {
      int pi = partition(arr, low, high);
      quickSort(arr, low, pi - 1);
      quickSort(arr, pi + 1, high);
  }
}

/*exercicío 25*/
int buscaBinaria(int arr[], int l, int r, int x) {
  if (l > r) return -1;
  int m = (l + r) / 2;
  if (arr[m] == x) return m;
  if (x < arr[m]) return buscaBinaria(arr, l, m - 1, x);
  return buscaBinaria(arr, m + 1, r, x);
}

/*exercicío 26*/
int expRapida(int x, int n) {
  if (n == 0) return 1;
  int temp = expRapida(x, n / 2);
  return (n % 2 == 0) ? temp * temp : x * temp * temp;
}

/*exercicío 27*/
int contarCaminhos(int x1, int y1, int x2, int y2) {
  if (x1 > x2 || y1 > y2) return 0;
  if (x1 == x2 && y1 == y2) return 1;
  return contarCaminhos(x1 + 1, y1, x2, y2) + contarCaminhos(x1, y1 + 1, x2, y2);
}

/*exercicío 28*/
int seguro(int tab[], int linha, int col, int n) {
  for (int i = 0; i < linha; i++)
      if (tab[i] == col || abs(tab[i] - col) == linha - i)
          return 0;
  return 1;
}
void nRainhas(int tab[], int linha, int n) {
  if (linha == n) {
      for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++)
              printf(tab[i] == j ? "Q " : ". ");
          printf("\n");
      }
      printf("\n");
      return;
  }
  for (int col = 0; col < n; col++) {
      if (seguro(tab, linha, col, n)) {
          tab[linha] = col;
          nRainhas(tab, linha + 1, n);
      }
  }
}

/*exercicío 29*/
int resolverLab(int lab[3][4], int x, int y, int caminho[3][4]) {
  if (x == 2 && y == 3) {
      caminho[x][y] = 1;
      return 1;
  }
  if (x >= 0 && y >= 0 && x < 3 && y < 4 && lab[x][y] == 0 && caminho[x][y] == 0) {
      caminho[x][y] = 1;
      if (resolverLab(lab, x + 1, y, caminho) || resolverLab(lab, x, y + 1, caminho))
          return 1;
      caminho[x][y] = 0;
  }
  return 0;
}

/*exercicío 30*/
void parenteses(char *str, int pos, int n, int abertos, int fechados) {
  if (fechados == n) {
      str[pos] = '\0';
      printf("%s\n", str);
      return;
  }
  if (abertos < n) {
      str[pos] = '(';
      parenteses(str, pos + 1, n, abertos + 1, fechados);
  }
  if (fechados < abertos) {
      str[pos] = ')';
      parenteses(str, pos + 1, n, abertos, fechados + 1);
  }
}

int main() {
int n = 5;
int n2 = 9;
int n3 = 12;
int n4 = 7;
int n5 = 10;
int n6 = 12345;
int x = 3;
char invert[] = "cavalo";
int ord = strlen(invert);
char poli[] = "arara";
int ord2 = strlen(poli);

  
   
   
   
   
   
   

printf("1- %d! = %d\n\n", n, fatorial(n));

printf("2- Soma dos primeiros %d números naturais: %d\n\n", n2, soma(n2));

printf("3- O %d- ésimo número da sequência de Fibonacci é: %d\n\n", n3, fibonacci(n3));

printf("4- %d ^ %d = %d\n\n", x, n4, potenciacao(x, n4));

printf("6- ");
contagemRegressiva(n5);
printf("\n\n");

printf("6- A soma dos dígitos de %d é: %d\n\n", n6, somaDigitos(n6));

inversaoString(invert, 0, ord - 1);
printf("7- String invertida: %s\n\n", invert);

if (palindromo(poli, 0, ord2 - 1)) {
    printf("8- É um palíndromo.\n\n");
} else {
    printf("8- Não é um palíndromo.\n\n");
}

  printf("9. MDC: %d\n\n", mdc(48, 18));

  printf("10. Multiplicação: %d\n\n", multiplicar(4, 5));

  printf("11. Contagem de caracteres: %d\n\n", contarChar("paralelepipedo", 'a'));

  int v[] = {1, 2, 3, 4};
  printf("12. Soma do array: %d\n\n", somaArray(v, 4));

  printf("13. Primo (7): %d\n\n", ehPrimo(7, 2));

  printf("14. Binário de 10: ");
  binario(10);
  printf("\n\n");

  printf("15. Números pares até 6: ");
  imprimirPares(6);
  printf("\n\n");

  printf("16. Números ímpares até 7: ");
  imprimirImpares(7);
  printf("\n\n");

  printf("17. Busca no array (6): %d\n\n", buscaArray((int[]){2,4,6,8}, 4, 6));

  printf("18. Comprimento da string: %d\n\n", comprimento("recursivo"));

  printf("19. Torre de Hanói:\n");
  hanoi(2, 'A', 'B', 'C');
  printf("\n");

  printf("20. Permutações de 'abc':\n");
  char s[] = "abc";
  permutar(s, 0, strlen(s) - 1);
  printf("\n");

  printf("21. Combinações de tamanho 2:\n");
  int data[2];
  combinacoes((int[]){1,2,3}, 3, 2, 0, data, 0);
  printf("\n");

  printf("22. Subconjuntos de {1,2}:\n");
  int subset[10];
  subconjuntos((int[]){1,2}, 2, 0, subset, 0);
  printf("\n");

  int m[] = {5, 3, 8, 1};
  mergeSort(m, 0, 3);
  printf("23. Merge Sort: ");
  for (int i = 0; i < 4; i++) printf("%d ", m[i]);
  printf("\n\n");

  int q[] = {9, 2, 5, 1, 7};
  quickSort(q, 0, 4);
  printf("24. Quick Sort: ");
  for (int i = 0; i < 5; i++) printf("%d ", q[i]);
  printf("\n\n");

  printf("25. Busca Binária (5): %d\n\n", buscaBinaria((int[]){1,3,5,7,9}, 0, 4, 5));

  printf("26. Exponenciação rápida (3^4): %d\n\n", expRapida(3, 4));

  printf("27. Caminhos na matriz (0,0 -> 2,2): %d\n\n", contarCaminhos(0, 0, 2, 2));

  printf("28. Soluções para o problema das 4 rainhas:\n\n");
  int tab[4];
  nRainhas(tab, 0, 4);

  int lab[3][4] = {{0,1,0,0},{0,0,0,1},{1,0,1,0}}, caminho[3][4] = {0};
  printf("29. Caminho em labirinto: ");
  if (resolverLab(lab, 0, 0, caminho)) {
      for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 4; j++)
              printf("%c ", caminho[i][j] ? '*' : lab[i][j] + '0');
          printf("\n\n");
      }
  } else {
      printf("Sem caminho possível.\n\n");
  }

  printf("30. Parênteses válidos (3 pares):\n\n");
  char str[20];
  parenteses(str, 0, 3, 0, 0);
}