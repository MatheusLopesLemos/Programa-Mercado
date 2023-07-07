#include <stdio.h>
#include <string.h>

int main(void) {

  char nomesClientes [10][30];
  char sexos[10];
  float valorPorCliente [10];
  float somaValorTotal = 0;
  int comparacaoNomes = 0;
  int numeroMenu = 0;
  char nomeCliente [30];
  char resposta;
  int controle = 0;
  float valorComparacao = 0;
  int qtdMulheres = 0;
  int qtdHomens = 0;
  float valorTotalHomens = 0;
  float valorMedio = 0;
  float menorValor = 0;
  
  //Parte 1

  for(int i = 0; i<3; i++) {

// Digitação nome

    printf("\nDigite seu nome: ");
    scanf("%s", nomesClientes[i]);
    
// Tratamento de nomes iguais
    
    for(int j = 0; j<i; j++) {

      comparacaoNomes = strcmp(nomesClientes[i],nomesClientes[j]);

    while (i!=j && comparacaoNomes == 0) {  

      printf("\nEsse nome já está cadastrado, digite outro: ");
      scanf("%s", nomesClientes[i]);

      j=0;
      
      comparacaoNomes = strcmp(nomesClientes[i],nomesClientes[j]);
    } 
  }
    
// Digitação sexo 
    printf("\nDigite seu sexo (f = feminino, m = masculino): ");
    scanf(" %c", &sexos[i]);

// Tratamento sexo inválido
    
      while(sexos[i] != 'f' && sexos[i] != 'm'){

        printf("\nSexo inválido, digite 'f' ou 'm': ");
        scanf(" %c", &sexos[i]);

      }
// Digitação do valor da compra 
    
    printf("\nDigite o valor total da compra: ");
    scanf("%f", &valorPorCliente[i]);

// Tratamento valor negativo
    
    while(valorPorCliente[i]<0){

      printf("\nO número digitado é negativo, digite um número válido: ");
      scanf("%f", &valorPorCliente[i]);

    }

// Acréscimo quantidade por sexo
    
    if(sexos[i] == 'f'){
      qtdMulheres++;
    }
    if(sexos[i] == 'm'){
      qtdHomens++;

// Cálculo valor total homens
      valorTotalHomens = valorTotalHomens + valorPorCliente[i];
    }

// Cálculo menor valor

  if(menorValor == 0){
    menorValor = valorPorCliente[i];
  } else 
    if(menorValor > valorPorCliente[i]){
    menorValor = valorPorCliente[i];
  }
// Soma valor total
    
    somaValorTotal = somaValorTotal + valorPorCliente[i];
    
    printf("\nSeu cadastro foi realizado.\n");
  }

// Soma valor médio
  
  valorMedio = somaValorTotal / 3;
  
  //Parte 2

  //Menu
do{
  printf("\n-------------------------------------Menu Principal-------------------------------------\n");
  printf("\n -Digite 1 para ver as informações da compra;\n -Digite 2 para ver as informações de todos os produtos cadastrados;\n -Digite 3 para encerrar o programa; \n -Digite Aqui: ");
  scanf("%i", &numeroMenu); 

  switch(numeroMenu){
    
  //Parte 3
    
    case 1: 

 // Pesquisa por um cliente
      
      printf("\n -Digite o nome do cliente: ");
      scanf("%s", nomeCliente);


      for(int i = 0; i<10; i++){
        
        comparacaoNomes = strcmp(nomesClientes[i], nomeCliente); 

         
        if(comparacaoNomes == 0) {

          printf("\n -Nome do cliente: %s\n -O sexo do cliente é: %c\n -O valor total da compra é: %.2f", nomesClientes[i], sexos[i], valorPorCliente[i]);

        controle = 1;
        }   
      } 
// Tratamento cliente não encontrado
    if(controle != 1) {

      printf("\n -Não há compras cadastradas com esse nome.");

    }
      controle = 0;

  // Comando de saída 
      
  printf("\n -Deseja encerrar o programa? ('s' para sim ou 'n' para não): ");
    scanf(" %c", &resposta);
    break;
    
  //Parte 4
    
    case 2: 

  // Digitação do valor da comparação
      
      printf("\n -Digite um valor de comparação: ");
      scanf("%f", &valorComparacao);
      
      for(int i = 0; i<3; i++){ 
        
  // Cálculo valor menor que a comparação
        
        if(valorComparacao > valorPorCliente[i]) {

          printf("\n -O valor de compra %.2f é menor que o valor de comparação.", valorPorCliente[i]);

        }

  // Cálculo valor maior que a comparação
        
        if(valorComparacao < valorPorCliente[i]) {

          printf("\n -O valor de compra %.2f é maior que o valor de comparação.", valorPorCliente[i]);

        }
      } 

  // Prints 
      
      printf("\n -A quantidade de compradoras mulheres é %d.", qtdMulheres);
      printf("\n -O valor total da compra dos homens é %.2f.", valorTotalHomens);
      printf("\n -O valor total das compras é %.2f.", somaValorTotal);
      printf("\n -O valor médio das compras é %.2f.", valorMedio);
      printf("\n -O valor menor das compras %.2f.", menorValor);

  // Comando de saída     
      
      printf("\n -Deseja encerrar o programa? ('s' para sim ou 'n' para não): ");
      scanf(" %c", &resposta);
    break;

    // Comando de saída 
    
    case 3:
      printf("\n -Tem certeza que deseja encerrar o programa? ('s' para sim ou 'n' para não): ");
      scanf(" %c", &resposta);
    break;
  }
  
} while(resposta == 'n');

  printf("\n Programa encerrado.");

  return 0;
}