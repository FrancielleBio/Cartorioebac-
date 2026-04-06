#include <stdio.h> // biblioteca de comunicação com o usuário (entrada e saída)
#include <stdlib.h> // biblioteca para funções do sistema (ex: system, alocação)
#include <locale.h> // biblioteca para configuração de idioma/região
#include <string.h> // biblioteca para manipulação de strings

int registro() // função responsável por cadastrar usuários no sistema
{
	// início criação de variáveis/string
	char arquivo[40]; // variável que será usada como nome do arquivo
    char cpf[40]; // armazena o CPF digitado pelo usuário
    char nome[40]; // armazena o nome
    char sobrenome[40]; // armazena o sobrenome
    char cargo[40]; // armazena o cargo
    // final de criação de variáveis/string
    
    printf("digite o CPF a ser cadastrado: ");  // solicitando CPF ao usuário
    scanf("%s", cpf);  // armazenando o CPF
    
    strcpy(arquivo, cpf); // copiando o CPF para usar como nome do arquivo
    
    FILE *file; // ponteiro para manipulação de arquivo
    file = fopen(arquivo, "w"); // cria o arquivo (modo escrita)
    fprintf(file,cpf); // grava o CPF no arquivo
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a"); // abre o arquivo para adicionar conteúdo
    fprintf(file, ","); // adiciona separador
    fclose(file); // fecha o arquivo
    
    printf("Digite o Nome a ser cadastrado: "); // solicita nome
    scanf("%s",nome); // armazena o nome
    
    file = fopen(arquivo, "a"); // abre o arquivo novamente
    fprintf(file,nome); // grava o nome no arquivo
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a"); // abre o arquivo
    fprintf(file, ","); // adiciona separador
    fclose(file); // fecha o arquivo
    
    printf("Digite o Sobrenome a ser cadastrado: "); // solicita sobrenome
    scanf("%s",sobrenome); // armazena o sobrenome
    
    file = fopen(arquivo, "a"); // abre o arquivo
    fprintf(file,sobrenome); // grava o sobrenome
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a"); // abre o arquivo
    fprintf(file, ","); // adiciona separador
    fclose(file); // fecha o arquivo
    
    printf("Digite o Cargo a ser cadastrado: "); // solicita cargo
    scanf("%s",cargo); // armazena o cargo
    
    file = fopen(arquivo, "a"); // abre o arquivo
    fprintf(file,cargo); // grava o cargo
    fclose(file); // fecha o arquivo
    
    system("pause"); // pausa o programa para o usuário ver as informações
}

int consulta() // função responsável por consultar dados cadastrados
{
	setlocale(LC_ALL, "Portuguese"); // definindo idioma
	
    char cpf[40]; // armazena o CPF digitado
    char conteudo[200]; // armazena o conteúdo lido do arquivo
    
    printf("Digite o CPF a ser consultado: "); // solicita CPF
    scanf("%s",cpf); // armazena CPF
    
    FILE *file; // ponteiro de arquivo
    file = fopen(cpf, "r"); // abre o arquivo para leitura
    
    if(file == NULL) // verifica se o arquivo não existe
    {
    	printf("Não foi possível abrir o arquivo, não localizado!.\n"); // mensagem de erro
	}
    
    while(fgets(conteudo, 200, file) != NULL) // lê o conteúdo do arquivo linha por linha
    {
    	printf("\nEssas são as informações do usuário: "); // mensagem
    	printf("%s", conteudo); // exibe o conteúdo
    	printf("\n\n"); // espaçamento
	}
    
    system("pause"); // pausa o programa
}

int deletar() // função responsável por deletar um cadastro
{
	char cpf[40]; // armazena o CPF
	
	printf("Digite o CPF a ser deletado: "); // solicita CPF
	scanf("%s", cpf); // armazena CPF
	
	remove("cpf"); // tenta remover o arquivo (OBS: aqui está fixo como "cpf")
	
	FILE  *file; // ponteiro de arquivo
	file = fopen (cpf, "r"); // tenta abrir o arquivo
	
	if (file == NULL) // verifica se o arquivo não existe
	{
	printf("O usuário não se encontra no sistema!. \n"); // mensagem de erro
	system("pause"); // pausa o programa
	}
}

int main() // função principal do programa
{
	int opcao=0; // variável para armazenar a opção do usuário
	int laco=1; // variável de controle do loop
	
	for(laco=1;laco=1;) // loop infinito do sistema
	{
		system("cls"); // limpa a tela
		
		setlocale(LC_ALL, "Portuguese"); // define idioma
    
        printf("### Cartório da EBAC ###\n\n"); // título
        printf("Escolha a opção desejada do menu\n\n"); // instrução
        printf("\t1 - Registrar nomes\n"); // opção 1
        printf("\t2 - Consultar nomes\n"); // opção 2
        printf("\t3 - Deletar nomes\n\n"); // opção 3
        printf("Opçao: "); // entrada

        scanf("%d", &opcao); // lê a opção do usuário
    
        system("cls"); // limpa a tela
        
		switch(opcao) // estrutura de decisão
	    {
	    	case 1: // opção de registro
	    	registro();
	        break; 
	        
	        case 2: // opção de consulta
	        consulta();
			break; 
			
			case 3: // opção de deletar
			deletar();
			break; 
			
			default: // opção inválida
			printf("Está opção não está disponível\n"); 
    	    system("pause");
			break; 	
		}
    }	   
}
