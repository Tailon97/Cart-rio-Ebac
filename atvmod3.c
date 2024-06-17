#include <stdio.h> //biblioteca de comunica��o com o ususario
#include <stdlib.h> //biblioteca de aloca��a de espa�o em memoria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro(){ //fun��o responsavel por cadastrar os usuarios no sistema
	//inicio cria��o de variaveis / strings
	char arquivo [40];
	char cpf[40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	
	printf("digite o cpf a ser cadastrado: ");//coletando info dos usuarios
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores da strings
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fechar o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consultar(){
	
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen (cpf, "r");
	
	if(file == NULL){
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");	
	}
	while(fgets(conteudo, 200, file) != NULL){
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf ("\n\n");
	}
	system("pause");
}

int deletar(){
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL){
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
}
int main(){
	int opcao=0; //definindo as v�riaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo linguagem
		printf("### C�rtorio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do Menu:\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - deletar nomes\n\n"); //final do menu
		printf("\t4 - Sair do sistema\n\n");
		printf("Opcao: \n\n");
		scanf("%d",&opcao); //armazenando as escolhas do usuario
	
	system("cls"); //apaga tela anterior
	
	
	switch(opcao)//inicio da selecao do menu
	{
		case 1: 
		registro();//chamada de funcoes
		break;
		
		case 2: 
		consultar();
		break;
		
		case 3:
		deletar();
		break;
		
		case 4:
		printf("Obrigado por ultilizar o sistema!\n");
		return 0;
		break;
	
		default: printf("Essa op��o n�o esta disponivel \n");
		system("pause");
		break;
		}	
	}
}
