//*************************************************************************************************
//**                                Autor: André Menezes da Silva                                **
//**                                Autor: Ezequiel Losekann                                     **
//**                                Autor: Jean Emílio Wilhelm                                   **
//*************************************************************************************************
//**              Função: Agenda para a prova de Laboratório de Algorítmos II - G2               **
//*************************************************************************************************
//**                          Arquivo alterado em 04 de novembro de 2016                         **
//**                     Aula de Laboratório de Algorítmos - Segundo Semestre                    **
//*************************************************************************************************
//*************************************************************************************************
#include <stdio.h>
#include <string.h>

//criacao da estrutura usada
typedef struct 
{ 
	int COD; 
	char Nome[50]; 
	char Telefone[50];
	char Endereco[50]; 		 
} Registro; 


//inicia a funcao principal
void main()
{
	//declaração das variaveis
	int COD = 0, Controle[50] = {0}, i;
	
	//cria um ponteiro do tipo da estrutura
	Registro * Agenda[5];
	
	
	//inicia o looping para controle de menu
	while(1)
	{
		//declara a variavel responsavel pela opção do usuário
		int Opcao = 0;
		
		printf("Entre com um comando:");
		//solicita ao usuario que escolha uma das opcoes abaixo
		printf("\n\n1:Criar novo registro\n2:Buscar registro\n3:Apagar registro\n4:Creditos\n5:Sair do programa\n\nOpcao: ");
		scanf("%d",&Opcao);
		fflush(stdin);
		
		//inicia o switch para avaliar a opcao escolhida
		switch(Opcao)
		{
			//caso Opcao seja 1
			case 1:
				{
					//limpa a tela
					system("cls");
					printf("CADASTRO DE REGISTROS\n");
					
					//impede que o usuario cadastre novos registros caso nao tenha espaco
					if(COD >= 5)
					{
						system("cls");
						printf("ERRO!");
						printf("\n\nNAO HA MAIS ESPACO NA SUA AGENDA. EXCLUA CONTATOS PARA LIBERAR ESPACOS\n");
						system("pause");
						system("cls");
					}
					
					//caso tenha espaço
					else
					{
						//utilizacao de um vetor para controlar quais registros tem informacao e quais nao tem
						for(i=0;i<2;i++)
						{
							//caso o controle = 0, eh porque nao tem registros
							if(Controle[i] == 0)
							{
								//passa ao codigo o valor em que Controle = 0
								COD = i;
								break;
							}
						}
						
						//alocação do ponteiro dinamicamente
						Agenda[COD] = (struct Registro *)calloc(sizeof(Registro),1);
						
						//solicita informações ao usuário
						printf("\nRegistro: %d\n", COD);
						Agenda[COD]->COD = COD;
						printf("Entre com o nome: ");
						gets(&Agenda[COD]->Nome);
						fflush(stdin);
						printf("Entre com seu telefone: ");
						gets(&Agenda[COD]->Telefone);
						fflush(stdin);
						printf("Entre com sua endereco: ");
						gets(&Agenda[COD]->Endereco);
						fflush(stdin);
						printf("\n\n");
						system("pause");
						system("cls");
						
						//coloca o vetor de controle = 1
						Controle[COD] = 1;
						
						//incrementa o CODIGO para controlar o vetor de ponteiros
						COD++;
					}
					
				}                        
			break;
			//caso Opcao seja 2
			case 2:
				{
					//inicia o looping para controle
					while(1)
					{
						//limpa a tela
						system("cls");
						//declaracao das variaveis 
						int codE, Temp, Outra;
					
						//caso o usuario informe um registro invalido
						if(Outra==3)
						printf("PARA VOLTAR DIGITE 666\n");
						printf("\nBUSCAR POR REGISTROS\n");
						
						//usuario informa o registro que deseja buscar
						printf("\nEntre com o registro desejado: ");
						scanf("%d",&codE);
						fflush(stdin);
						
						//caso o usuário queira sair da opcao
						if(codE==666)
						{
							system("cls");
							Outra = 0;
							break;
						}
						
						//caso o usuario informe um numero invalido ou que nao seja utilizado
						else if(codE>COD-1 || codE < 0 || Controle[codE] == 0)
						{
							printf("\n\tNUMERO INVALIDO, DIGITE UM NUMERO VALIDO!\n\n");
							Outra = 3;
						}
				
						//caso o usuario digite uma informação válida
						else
						{
							//imprime as informacoes do registro encontrado
							printf("\nRegistro: %d\n",Agenda[codE]->COD);
							printf("Nome: %s\n",Agenda[codE]->Nome);
							printf("Telefone: %s\n",Agenda[codE]->Telefone);
							printf("Endereco: %s\n\n",Agenda[codE]->Endereco);
							system("pause");
							system("cls");
							Outra = 0;
							break;
						}
						system("pause");
						system("cls");
					}
				}
			break;
			//caso Opcao seja 3
			case 3:
				{
					//inicia looping
					while(1)
					{	
						//declaracao das variaveis
						int codA, i, A = -1, outra;
						
						//limpa a tela
						system("cls");
												
						//caso o usuário escolha um registro inválido
						if(outra==3)
						//exibe mensagem na tela
						printf("PARA VOLTAR DIGITE 666\n");
						printf("\nAPAGAR REGISTROS\n");
						printf("\nDigite o codigo do registro a ser apagado: ");
						scanf("%d",&codA);
						fflush(stdin);
						
						//caso o usuario queira sair da opcao
						if(codA == 666)
							{
								system("cls");
								outra = 0;
								break;
							}
						
						//caso o usuario informe um numero invalido ou que nao seja utilizado
						else if(codA > COD-1 || codA < 0 || Controle[codA] == 0)
							{
								//exibe mensagem na tela
								printf("\n\tNUMERO INVALIDO, DIGITE UM NUMERO VALIDO!\n\n");
								outra = 3;
								printf("\n\n");
								system("pause");
								system("cls");
							}
						
						//condicional caso o usuario digite um registro valido
						else
							{
								//libera o registro
								free(Agenda[codA]);	
								//posiciona o vetor de controle do codigo em 0 para poder receber outros cadastros
								Controle[codA] = 0;
								COD--;
								printf("\n\n");
								system("pause");
								system("cls");
								break;
						}
					}
				}
			break;
			//caso Opcao seja 4
			case 4:
				{
					//limpa a tela
					system("cls");
					//exibe os creditos dos desenvolvedores na tela
					printf("CREDITOS");
					printf("\n\nPrograma desenvolvido pelos alunos:");
					printf("\n\nAndre Menezes da Silva");
					printf("\nEzequiel Losekann");
					printf("\nJean Emilio Wilhelm\n\n");
					system("pause");
					system("cls");
				}
			break;
			//caso Opcao seja 5
			case 5:
				{
					//limpa a tela
					system("cls");
					//exibe mensagem na tela
					printf("VOCE ESCOLHEU SAIR DO PROGRAMA\n");
					system("pause");
				}
			break;
			//caso Opcao seja invalida
			default:
				{
					//limpa a tela
					system("cls");
					//exibe mensagem na tela
					printf("\nOPCAO INVALIDA!!! DIGITE NOVAMENTE!");
				}
		}
		
		//caso Opcao seja sair do programa
		if(Opcao == 5)
			{
				//sai do programa
				break;
			}
	}
}
