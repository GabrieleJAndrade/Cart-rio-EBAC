#include <stdio.h> //biblioteca de comunica��o com o suporte
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> // bibloteca respons�vel por cuidar das string

int registro()
{
	//inicio da cria��o das vari�veis/string
	char arquivo[40];
	char cpf [40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	//fim da cria��o das vari�veis/string
   
   printf("Digite o CPF a ser cadastrado:  ");// coletando informa��es fo usu�rio
   scanf("%s", cpf);//"%s"refere-se a string
   
   strcpy(arquivo,cpf); //Respons�vel por copiar os valores dos string
   
   
   FILE*file; //cria o arquivo
   file = fopen(arquivo,"w"); // cria o arquivo// "w" escrever
   fprintf(file,cpf); // salvo o valor da var�avel
   fclose(file); // fecha arquivo
   
   file = fopen(arquivo,"a");//criar um arquivo ou abrir um arquivo existente// "A" abre um arquivo no modo de inclus�o (append)
   fprintf(file,",");//escrever um conjunto de dados em um arquivo
   fclose(file);//fechar um arquivo
   
   printf("Digite o nome a ser cadastrado:  ");// coletando informa��es fo usu�rio
   scanf("%s",nome);// ler um conjunto de dados de um arquivo
   
   file = fopen(arquivo,"a");//criar um arquivo ou abrir um arquivo existente // "A" abre um arquivo no modo de inclus�o (append)
   fprintf(file,nome); //escrever um conjunto de dados em um arquivo
   fclose(file); //fechar um arquivo
   
   printf("Digite o sobrenome a ser cadastrado:  ");
   scanf("%s",sobrenome);// ler um conjunto de dados de um arquivo
   
   file = fopen(arquivo,"a");//criar um arquivo ou abrir um arquivo existente // "A" abre um arquivo no modo de inclus�o (append)
   fprintf(file,sobrenome); //escrever um conjunto de dados em um arquivo
   fclose(file); //fechar um arquivo
   
   file = fopen(arquivo,"a");//criar um arquivo ou abrir um arquivo existente // "A" abre um arquivo no modo de inclus�o (append)
   fprintf(file,","); //escrever um conjunto de dados em um arquivo
   fclose(file); //fechar um arquivo
   
   printf("Digite o cargo a ser cadastrado:  ");
   scanf("%s",cargo);// ler um conjunto de dados de um arquivo
   
   file = fopen(arquivo,"a");//criar um arquivo ou abrir um arquivo existente // "A" abre um arquivo no modo de inclus�o (append)
   fprintf(file,cargo); //escrever um conjunto de dados em um arquivo
   fclose(file); //fechar um arquivo
   
   system("pause");	
}

int consulta()
{
   setlocale(LC_ALL,"Portuguese");  // Definindo a linguagem
   
   char cpf[40];
   char conteudo[200];
   
   printf("Digite o CPF a ser consultado:   "); // coletando informa��es fo usu�rio
   scanf("%s",cpf);// ler um conjunto de dados de um arquivo
   
   FILE *file; //cria o arquivo
   file = fopen(cpf,"r");//criar um arquivo ou abrir um arquivo existente
   
   if(file == NULL)
   {
   	    printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n"); // coletando informa��es fo usu�rio
   	    
   }
  while  (fgets(conteudo,200,file) != NULL)
  {
  	printf("\nEssas s�o as informa��es do usu�rio:  ");// coletando informa��es fo usu�rio
  	printf("%s", conteudo);// coletando informa��es fo usu�rio
  	printf("\n\n");// coletando informa��es fo usu�rio
  }

  system("pause");	//pausa para a leitura
}

int deletar()
{
  
  char cpf[40];
  
  printf("Digite o CPF  do usu�rio a ser deletado:  ");// coletando informa��es fo usu�rio
  scanf("%s", cpf);// ler um conjunto de dados de um arquivo
  
  remove(cpf);
  
  FILE *file;//cria o arquivo
  file = fopen(cpf,"r");
  
  if(file == NULL)
  {
  	printf( "O usu�rio n�o se encontra no sistema!.\n");// coletando informa��es fo usu�rio
  	system("pause");	
 	
  }
  while (fgets(cpf,40,file) !=NULL)
  
  {
  	printf("\n Usu�rio deletado com sucesso!\n ");// coletando informa��es fo usu�rio
  	printf("%s",cpf);
  	printf("\n\n");
  }
    system ("pause");
}

int main()
 {
	int opcao=0; // Definindo vari�ves
	int laco=1;
	
	for (laco=1;laco=1;)
  {
	
	  system("cls");// limapr a tela
	
	  setlocale(LC_ALL,"Portuguese");  // Definindo a linguagem

	 printf("    Cart�rio da EBAC   \n\n"); // in�cio do menu
	 printf("Escolha a op��o desejada do menu:\n\n");
	 printf("\t1 - Registrar nomes\n");
	 printf("\t2 - Consultar nomes\n");
	 printf("\t3 - Deletar nomes\n");
	 printf("\t4 - Sair do sistema\n\n");
	 printf("Op��o: "); // fim do menu
	
	 scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
	 system("cls");// responsavel por limpar a tela
	 
	 switch(opcao)//inicio da sele��o do menu
	 {
	 case 1:
	 registro();// chamada de fun��es 
	 break;
                   
	 case 2:
	 consulta();// chamada de fun��es 
 	 break;
 	
 	 case 3:
 	 deletar();// chamada de fun��es 
   	 break;
 	 
 	 case 4:
 	 printf("Obrigado por utilizar o sistema!");
	 return 0; 	
	 break;
 	 	
	 default:
     printf("Essa op��o n�o est� dispon�vel\n");
	 system("pause");
	 break;
	
	 }// fim da sele��o
 }
};
