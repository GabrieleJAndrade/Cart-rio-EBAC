#include <stdio.h> //biblioteca de comunicação com o suporte
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> // bibloteca responsável por cuidar das string

int registro()
{
	//inicio da criação das variáveis/string
	char arquivo[40];
	char cpf [40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	//fim da criação das variáveis/string
   
   printf("Digite o CPF a ser cadastrado:  ");// coletando informações fo usuário
   scanf("%s", cpf);//"%s"refere-se a string
   
   strcpy(arquivo,cpf); //Responsável por copiar os valores dos string
   
   
   FILE*file; //cria o arquivo
   file = fopen(arquivo,"w"); // cria o arquivo// "w" escrever
   fprintf(file,cpf); // salvo o valor da varíavel
   fclose(file); // fecha arquivo
   
   file = fopen(arquivo,"a");//criar um arquivo ou abrir um arquivo existente// "A" abre um arquivo no modo de inclusão (append)
   fprintf(file,",");//escrever um conjunto de dados em um arquivo
   fclose(file);//fechar um arquivo
   
   printf("Digite o nome a ser cadastrado:  ");// coletando informações fo usuário
   scanf("%s",nome);// ler um conjunto de dados de um arquivo
   
   file = fopen(arquivo,"a");//criar um arquivo ou abrir um arquivo existente // "A" abre um arquivo no modo de inclusão (append)
   fprintf(file,nome); //escrever um conjunto de dados em um arquivo
   fclose(file); //fechar um arquivo
   
   printf("Digite o sobrenome a ser cadastrado:  ");
   scanf("%s",sobrenome);// ler um conjunto de dados de um arquivo
   
   file = fopen(arquivo,"a");//criar um arquivo ou abrir um arquivo existente // "A" abre um arquivo no modo de inclusão (append)
   fprintf(file,sobrenome); //escrever um conjunto de dados em um arquivo
   fclose(file); //fechar um arquivo
   
   file = fopen(arquivo,"a");//criar um arquivo ou abrir um arquivo existente // "A" abre um arquivo no modo de inclusão (append)
   fprintf(file,","); //escrever um conjunto de dados em um arquivo
   fclose(file); //fechar um arquivo
   
   printf("Digite o cargo a ser cadastrado:  ");
   scanf("%s",cargo);// ler um conjunto de dados de um arquivo
   
   file = fopen(arquivo,"a");//criar um arquivo ou abrir um arquivo existente // "A" abre um arquivo no modo de inclusão (append)
   fprintf(file,cargo); //escrever um conjunto de dados em um arquivo
   fclose(file); //fechar um arquivo
   
   system("pause");	
}

int consulta()
{
   setlocale(LC_ALL,"Portuguese");  // Definindo a linguagem
   
   char cpf[40];
   char conteudo[200];
   
   printf("Digite o CPF a ser consultado:   "); // coletando informações fo usuário
   scanf("%s",cpf);// ler um conjunto de dados de um arquivo
   
   FILE *file; //cria o arquivo
   file = fopen(cpf,"r");//criar um arquivo ou abrir um arquivo existente
   
   if(file == NULL)
   {
   	    printf("Não foi possível abrir o arquivo, não localizado!.\n"); // coletando informações fo usuário
   	    
   }
  while  (fgets(conteudo,200,file) != NULL)
  {
  	printf("\nEssas são as informações do usuário:  ");// coletando informações fo usuário
  	printf("%s", conteudo);// coletando informações fo usuário
  	printf("\n\n");// coletando informações fo usuário
  }

  system("pause");	//pausa para a leitura
}

int deletar()
{
  
  char cpf[40];
  
  printf("Digite o CPF  do usuário a ser deletado:  ");// coletando informações fo usuário
  scanf("%s", cpf);// ler um conjunto de dados de um arquivo
  
  remove(cpf);
  
  FILE *file;//cria o arquivo
  file = fopen(cpf,"r");
  
  if(file == NULL)
  {
  	printf( "O usuário não se encontra no sistema!.\n");// coletando informações fo usuário
  	system("pause");	
 	
  }
  while (fgets(cpf,40,file) !=NULL)
  
  {
  	printf("\n Usuário deletado com sucesso!\n ");// coletando informações fo usuário
  	printf("%s",cpf);
  	printf("\n\n");
  }
    system ("pause");
}

int main()
 {
	int opcao=0; // Definindo variáves
	int laco=1;
	
	for (laco=1;laco=1;)
  {
	
	  system("cls");// limapr a tela
	
	  setlocale(LC_ALL,"Portuguese");  // Definindo a linguagem

	 printf("    Cartório da EBAC   \n\n"); // início do menu
	 printf("Escolha a opção desejada do menu:\n\n");
	 printf("\t1 - Registrar nomes\n");
	 printf("\t2 - Consultar nomes\n");
	 printf("\t3 - Deletar nomes\n");
	 printf("\t4 - Sair do sistema\n\n");
	 printf("Opção: "); // fim do menu
	
	 scanf("%d", &opcao); //armazenando a escolha do usuário
	
	 system("cls");// responsavel por limpar a tela
	 
	 switch(opcao)//inicio da seleção do menu
	 {
	 case 1:
	 registro();// chamada de funções 
	 break;
                   
	 case 2:
	 consulta();// chamada de funções 
 	 break;
 	
 	 case 3:
 	 deletar();// chamada de funções 
   	 break;
 	 
 	 case 4:
 	 printf("Obrigado por utilizar o sistema!");
	 return 0; 	
	 break;
 	 	
	 default:
     printf("Essa opção não está disponível\n");
	 system("pause");
	 break;
	
	 }// fim da seleção
 }
};
