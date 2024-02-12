// incluindo bibliotecas para utilizar recursos para o código.
// stdio:habilita a entrada e a saída de dados.
// stdlib:habilita a alocação de memória.
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <windows.h>

/*TAMANHO DOS CONJUNTOS:
essa função o usuário define a quantidade de elementos que cada
conjunto irá ter.*/
int num_elementos() {
  int n;

  printf("Quantos elementos possui o conjunto:");
  scanf("%d", &n);

  return n;
}

/*ADICIONAR ELEMENTOS:
Ao entrar o número de elemtos do conjunto e o vetor que
corresponde ao conjunto, a função utiliza um for para conter a quantidade
de elementos que será adicionada para evitar a ultrapassagem do limite de
dimensionamento, visto que pode causar resusltados imprevisíveis devido a
atribuição de dados em regiões não delimitadas.*/

void elementos(int n, int grupo[]) {
  int i,e,rodada=0,v;
  
  do{
      printf("Digite o elemento que deseja adicionar ao conjunto:");
      scanf("%d", &e);
      v=0;
        
      for(i=0; i<rodada; i++){
         if((e == grupo[i])){
            break;
         }else{
            v++;
          }
       } 
    
       if(v==rodada){ 
          grupo[i]=e;
          rodada++;
        }else{
         printf("Elemento repetido!!\n");
        }
    
  }while(rodada<n);
  
}

// UNIÃO:
int uniao(int grupoA[], int grupoB[], int qntdA, int qntdB) {
  int i, ia, ib, v;

  printf("A U B = { ");

  for (i = 0; i < qntdA; i++) {
    printf("%d ", grupoA[i]);
  }

  for (ib = 0; ib < qntdB; ib++) {
    v = 0;
    for (ia = 0; ia < qntdA; ia++) {

      if (grupoA[ia] == grupoB[ib]) {
        v++;
      }
    }
    if (v == 0) {
      printf("%d ", grupoB[ib]);
    }
  }

  printf("}");
  return 0;
}

// INTERCESSÃO:
void intercessao(int grupoA[], int grupoB[], int qntdA, int qntdB) {
  int ia, ib;

  printf("A ∩ B = { ");

  for (ib = 0; ib < qntdB; ib++) {

    for (ia = 0; ia < qntdA; ia++) {

      if (grupoA[ia] == grupoB[ib]) {

        printf("%d ", grupoB[ib]);
      }
    }
  }

  printf("}");
}

// DIFERENÇA(A-B)
void dif_AB(int grupoA[], int grupoB[], int qntdA, int qntdB) {
  int ia, ib, v;

  printf("A - B = { ");

  for (ia = 0; ia < qntdA; ia++) {
    v = 0;
    for (ib = 0; ib < qntdB; ib++) {

      if (grupoA[ia] == grupoB[ib]) {
        v++;
      }
    }
    if (v == 0) {
      printf("%d ", grupoA[ia]);
    }
  }

  printf("}");
}

// DIFERENÇA(B-A)
void dif_BA(int grupoA[], int grupoB[], int qntdA, int qntdB) {
  int ia, ib, v;

  printf(" B - A = { ");

  for (ib = 0; ib < qntdB; ib++) {
    v = 0;
    for (ia = 0; ia < qntdA; ia++) {

      if (grupoA[ia] == grupoB[ib]) {
        v++;
      }
    }
    if (v == 0) {
      printf("%d ", grupoB[ib]);
    }
  }

  printf("}");
}

// DIFERENÇA SIMETRICA:
void dif_simetrica(int grupoA[], int grupoB[], int qntdA, int qntdB) {
  int ia, ib, v;

  printf("(A ∆ B) = { ");

  for (ia = 0; ia < qntdA; ia++) {
    v = 0;
    for (ib = 0; ib < qntdB; ib++) {

      if (grupoA[ia] == grupoB[ib]) {
        v++;
      }
    }
    if (v == 0) {
      printf("%d ", grupoA[ia]);
    }
  }

  for (ib = 0; ib < qntdB; ib++) {
    v = 0;
    for (ia = 0; ia < qntdA; ia++) {

      if (grupoA[ia] == grupoB[ib]) {
        v++;
      }
    }
    if (v == 0) {
      printf("%d ", grupoB[ib]);
    }
  }

  printf("}");
}

// PRODUTO CARTESIANO
void prod_cartesiano(int grupoA[], int grupoB[], int qntdA, int qntdB) {
  int ia, ib;

  printf("(A x B) = ");

  for (ia = 0; ia < qntdA; ia++) {

    for (ib = 0; ib < qntdB; ib++) {
      printf("{%d, %d} ", grupoA[ia], grupoB[ib]);
    }
  }
}

// MENU:
int lerOpcao() {
  int op;
  printf("\n\nESCOLHA A OPERAÇÃO QUE DESEJA FAZER:\n");
  printf("1-União de conjuntos (A U B)\n");
  printf("2-Intercessão de conjuntos (A ∩ B)\n");
  printf("3-Diferença(A-B)\n");
  printf("4-Diferença(B-A)\n");
  printf("5-Diferença Simétrica (A ∆ B)\n");
  printf("6-Produto Cartesiano (A x B)\n");
  printf("0-Sair\n");
  printf("Informe sua opção: ");
  scanf("%d", &op);
  // VALIDAR a opção entre 0, 1 e 2
  return op;
}

// FUNÇÃO PRINCIPAL:
int main() 
{
SetConsoleOutputCP(65001);
  // Definir o tamanho do conjunto A
  int tamanhoA, tamanhoB;

  printf("CONJUNTO A\n");

  tamanhoA = num_elementos();
  int conjuntoA[tamanhoA];

  // Adicionar elementos em A
  elementos(tamanhoA, conjuntoA);

  // Definir o tamanho do conjunto B

  printf("\n-------------------------------------------------------------------"
         "---------\n");
  printf("\nCONJUNTO B\n");

  tamanhoB = num_elementos();
  int conjuntoB[tamanhoB];

  // Adicionar elementos em B
  elementos(tamanhoB, conjuntoB);

  printf("\n-------------------------------------------------------------------"
         "---------");

  int opcao;

  do {
    opcao = lerOpcao();

    switch (opcao) {
    case 1:
      uniao(conjuntoA, conjuntoB, tamanhoA, tamanhoB);

      break;

    case 2:
      intercessao(conjuntoA, conjuntoB, tamanhoA, tamanhoB);
      break;

    case 3:
      dif_AB(conjuntoA, conjuntoB, tamanhoA, tamanhoB);
      break;

    case 4:
      dif_BA(conjuntoA, conjuntoB, tamanhoA, tamanhoB);
      break;

    case 5:
      dif_simetrica(conjuntoA, conjuntoB, tamanhoA, tamanhoB);
      break;

    case 6:
      prod_cartesiano(conjuntoA, conjuntoB, tamanhoA, tamanhoB);
      break;
    }

  } while (opcao > 0);

  return 0;
}
