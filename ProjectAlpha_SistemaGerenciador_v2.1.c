#include <stdio.h>
#include <locale.h>
#include <string.h>
#define TF 100
#define TF_INST 10


main ()
{

	// <---------------------- SISTEMA DE GERENCIAMENTO - ACADEMIA ---------------------->
	
	// Vetores Inteiros:                             Vetores String:
	int VcodInst[TF_INST];                    char VnomeInst[TF_INST][61],nomeTemp[61],vModalidade[TF][61]; 
	int VcodAluno[TF];                        char VnomeAluno[TF][61],VcpfAluno[TF][12],cpfTemp[12]; 
	
	// Parte 3 - Modalidade:                  // Extras:
	int VcodMod[TF];                              char Vef[2], yes[]="s",no[]="n"; // Usado no loop verificador não está funcionando (Atualizar);
	
	// Cadastro Alunos - Data:
	int dia[TF],mes[TF],ano[TF];
	
	// Opção Escolhida/Sub Menu e Variável temporária:
	int op=0,sub_op=0,temp=0,Rep_loop=0;
	
	// Vetores Float:
	float vValorAula[TF],vValor[TF];
	
	// Contadores:
	int n,i=0,cont_inst=0,cont_alunos=0,TLI=0,TL=0,TLA=0,pos,limite=0,TLM=0; // OBS: "pos" == posição do vetor. 
	
	// <--------------------------------------------------------------------------------->
	
	// Separação de linhas:
	char linha01[] = "============================================";
	char linha02[] = "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"; // <-- Atualizado para versão em for!
	
	setlocale(LC_ALL,"Portuguese"); // <-- Define a linguagem local em Português.
	
	printf("\t\t%s%s\n" ,linha01,linha01);                                         // \n quebra linha, \t adiciona tabulação.
	printf("\t\t|%86s|\n", " ");                                            
	printf("\t\t| %23s%-62s|\n", " ","PROJECT ALPHA - SISTEMA DE GERENCIAMENTO");  // Utilizado "largura de campo" 
	printf("\t\t|%86s|\n", " ");                                                   // Exemplo: %-40s
	printf("\t\t%s%s\n" ,linha01,linha01);                                         // %  -> inicia a formatação
	printf("\t\t|%86s|\n", " ");                                                   // -  -> alinhamento à esquerda
	printf("\t\t| %-84s |\n","[1] - Gestão de Cadastros");                         // 40 -> define a largura do campo em 40 caracteres
	printf("\t\t| %-84s |\n","[2] - Gestão de Exclusões");                         // s  -> indica uma string
	printf("\t\t| %-84s |\n","[3] - Lançamentos");                                 // Usado para alinhar a interface no terminal.
	printf("\t\t| %-84s |\n","[4] - Emissão de Relatório");
	printf("\t\t| %-84s |\n","[5] - Finalizar");
	printf("\t\t|%86s|\n", " ");
	printf("\t\t%s%s\n" ,linha01,linha01);  
	printf("\t\t| %-85s|", "Digite a opção desejada: [ ]");
    printf("%s%s%s",linha02,linha02,linha02);                                       // Utilizado: \b < -- Volta o cursor em 1 caractere.
    scanf("%1d", &temp);                                                           // Aceita somente 1 dígito de número inteiro. ( %1d ) 
    
    if(temp>0 && temp<=5) // <-- (IF-01) Validação de "temp".
    { op = temp;
      temp = 0;
    }                     // fechamento (IF-01)
    else
    {
    printf("\t\t|%86s|\n", " ");     
    printf("\t\t| %-85s|\n", "[!] Opção inválida!! ");
    printf("\t\t| %-85s|\n", "[!] Caso uma opção inválida seja informada novamente, o sistema será encerrado.");
    printf("\t\t|%86s|\n", " ");     
    printf("\t\t| %-85s|", "Digite a opção desejada: [ ]");
    printf("%s%s%s",linha02,linha02,linha02);                               
    scanf("%1d", &op);               
    }
    
    
    printf("\t\t%s%s\n" ,linha01,linha01); 
    
    while(op>=1 && op<=4) //Repetição de Menu (While-01)
    {
       switch(op) // <-- MENU PRINCIPAL - Controle de Opções com (Switch-01)!
       {
        case 1:                                          
    	printf("\t\t|\t\t\t\t %-53s |\n","MÓDULO DE CADASTROS");                                                
    	printf("\t\t%s%s\n" ,linha01,linha01);  
    	printf("\t\t| %-84s |\n","Selecione uma das operações disponíveis:");
    	printf("\t\t|%86s|\n", " ");
    	printf("\t\t| %-84s |\n","[1] Cadastro de Instrutores");                 
	    printf("\t\t| %-84s |\n","[2] Cadastro de Alunos");                  
	    printf("\t\t| %-84s |\n","[3] Cadastro de Modalidades");                         
	    printf("\t\t| %-84s |\n","[4] Retornar ao Menu Principal");
	    printf("\t\t|%86s|\n", " ");
	    printf("\t\t| %-85s|","Digite a opção desejada: [ ]");
	    printf("%s%s%s",linha02,linha02,linha02);
	    scanf("%d", &sub_op);
	    
	    while(sub_op>=1 && sub_op<=3) //Repetição de Menu (While-01)
	    {
	    
	    switch(sub_op) // <-- SUB MENU (Switch-02)!
	    {
	      case 1:
	     // <----------------------------------- CADASTRO DE INSTRUTORES [COMEÇO AQUI] ------------------------------------------->
	      printf("\t\t%s%s\n",linha01,linha01);	
	      printf("\t\t|\t\t\t\t%-53s  |\n","CADASTRO DE INSTRUTORES");
	      printf("\t\t%s%s\n",linha01,linha01);
	      printf("\t\t|%86s|\n", " ");
	      printf("\t\t| %-85s|\n","NOME COMPLETO");
	      printf("\t\t| %-85s|\n", "[REGRA] Nome completo deve conter no máximo 60 caracteres.");
	      printf("\t\t| %-84s |\n","Digite o nome completo do Instrutor:");
	      printf("\t\t| [                                                            ]                       |");
	      for(i = 0; i < 85; i++)
	      {
          printf("\b");
          }
	      fflush(stdin);
		  gets(nomeTemp);
		  pos=0;
		  
		while(pos<TLI && stricmp(nomeTemp,VnomeInst[pos]) !=0)
		pos++;
		if(pos<TLI)
		    {
		    printf("\t\t|%86s|\n", " ");
			printf("\t\t| %-85s|\n", "[!] Instrutor já cadastrado tente novamente.");
			printf("\t\t%s%s\n",linha01,linha01);	
	     	}
		else // Inserir os dados do instrutor nos vetores:
			{
			 strcpy(VnomeInst[TLI],nomeTemp);
			 
	         printf("\t\t|%86s|\n", " ");
	         printf("\t\t| %-85s|\n","MATRÍCULA");
	         printf("\t\t| %-85s|\n", "[REGRA] Matrícula deve conter no máximo 4 dígitos.");
	         printf("\t\t| %-84s |","Digite a Matrícula do Instrutor: [    ]");
	         for(i = 0; i < 52; i++)
	         {
             printf("\b");
             }
	         scanf("%d", &temp);
	         pos=0;
	         while(pos < TLI && temp != VcodInst[pos])
	         pos++;
	         if(pos<TLI)
	         {
	         printf("\t\t|%86s|\n", " ");
			 printf("\t\t| %-85s|\n", "[!] Matrícula já utilizada tente novamente.");
		     printf("\t\t%s%s\n",linha01,linha01);	
	         }
	         else
			 {
			 VcodInst[TLI] = temp;
			 temp = 0;
			 cont_inst++; // <-- Se precisar, esse é o contador de cadastros de instrutores.
	         TLI++;       // <-- Implementa TLI para próxima posição do vetor!!
	         printf("\t\t%s%s\n",linha01,linha01);
	         
	         	printf("\t\t| %-67s REGISTRO: [%4.4d] |","CADASTRO CONCLUíDO COM SUCESSO!",TLI); //<-- Utilizado TLI invés de cont_inst.
	         	printf("\n\t\t|%86s|", " ");
	         	printf("\n\t\t| %-s","Nome do Instrutor: ");
	         	
	         	// Exibição com caixa fixa:
	            // printf("[%-64.64s]",VnomeInst[TLI-1]);   // <-- [Negativo = esquerda(largura total . imprimir no máximo 64 chars)S = String]
	            
	            printf("[%s]%*s|",VnomeInst[TLI-1],64-strlen(VnomeInst[TLI-1]), " ");     // 64 == Quantidade de Espaços - Qt. de Chars
	            printf("\n");
	            printf("\t\t| %-10s [%4.4d] %67s|\n","Matrícula:",VcodInst[TLI-1], " ");  // <-- Isso é perfeição! 
	            printf("\t\t%s%s\n",linha01,linha01);
	         }
	        }
	     // <----------------------------------- CADASTRO DE INSTRUTORES [FIM AQUI] ------------------------------------------->
	     break;

		
	    case 2:
	    // <----------------------------------- CADASTRO DE ALUNOS [AQUI] ------------------------------------------->
	    
	    // Zerando contadores:
	    limite=0; 
	    Rep_loop=0;
	    cont_alunos=0;
	    
	    printf("\t\t%s%s\n",linha01,linha01);
	    printf("\t\t| %-85s|\n", "[REGRA] Limite de 100 Cadastros.");
        printf("\t\t| %-85s|","Digite o número de alunos que você deseja cadastrar: [   ]");
        
        for(i = 0; i<32; i++)
        {
        printf("\b");
        }
        
        scanf("%d", &Rep_loop); // RECEBE QUANTAS VEZES IRÁ REPETIR O CADASTRO!
        
        // <------------------------------------- IF DE VERIFICAÇÃO: ---------------------------------------->
        
        // Verifica se excedeu limite (1 Tentativa):
        if(Rep_loop>TF)
        {
        	printf("\t\t%s%s%s\n",linha01,linha01);
        	printf("\t\t| %-85s|\n","[!] Limite excedido, tente novamente.");
        	printf("\t\t| %-85s|\n","[!] 1 tentativa restante.");
        	printf("\t\t%s%s%s\n",linha01,linha01);
	        printf("\t\t| %-85s|\n", "[REGRA] Limite de 100 Cadastros.");
            printf("\t\t| %-85s|","Digite o número de alunos que você deseja cadastrar: [   ]");
        
         for(i = 0; i<32; i++)
         {
          printf("\b");
         }
        
        scanf("%d", &Rep_loop);
        
         if(Rep_loop>TF)
         {
         limite++; // Serve para parar o while de cadastro.
         printf("\t\t%s%s\n",linha01,linha01);
         }
         
        }
        strcpy(Vef,yes); // Pra não bugar while! Vef = SIM (entra no while).
        
        // <-------------------------------- WHILE COM REPETIÇÃO DE CADASTRO: ------------------------------------------->
        
	   	while(TLA<TF && limite==0 && cont_alunos<Rep_loop && stricmp(Vef,no) !=0)
	    {
	         printf("\t\t%s%s\n",linha01,linha01);	
	         printf("\t\t|\t\t\t\t%-53s  |\n","CADASTRO DE ALUNOS");
	         printf("\t\t%s%s\n",linha01,linha01);
	         
	    // <-------------------------------- ENTRADA DO CPF: ------------------------------------------->
	          printf("\t\t|%86s|\n", " ");
	          printf("\t\t| %-85s|\n","CPF DO ALUNO");
	          printf("\t\t| %-85s|\n", "[REGRA] CPF deve conter exatamente 11 dígitos.");
	          printf("\t\t| %-84s |","Digite somente os números do CPF: [           ]");
	       for(i = 0; i < 51; i++)
	       {
              printf("\b");
           }
           
           fflush(stdin);
		   gets(cpfTemp);
           pos=0;
           
           while(pos<TLA && stricmp(cpfTemp,VcpfAluno[pos]) !=0) // Vai rodar até encontrar (string) == (string_da_posição) 
	         pos++;
	         
	         if(pos<TLA) //OBS: se posição for igual a TLA <-- Não encontrou o valor.
	         {
	         	printf("\t\t|%86s|\n", " ");
			    printf("\t\t| %-85s|\n", "[!] CPF já cadastrado tente novamente.");
			    printf("\t\t%s%s\n",linha01,linha01);
	         }
         else
	 {   // Else-01
	         strcpy(VcpfAluno[TLA],cpfTemp);	         
	         	        	    
	     // <-------------------------------- ENTRADA DO NOME: ------------------------------------------->
	         printf("\t\t|%86s|\n", " ");
	         printf("\t\t| %-85s|\n","NOME COMPLETO");
	         printf("\t\t| %-85s|\n", "[1. REGRA] Não utilize caracteres especiais (ç, ã, acentos)."); // Não consegue printar corretamente muito problema se deixar.
	         printf("\t\t| %-85s|\n", "[2. REGRA] Nome completo deve conter no máximo 60 caracteres.");
	         printf("\t\t| %-84s |\n","Digite o nome completo do Aluno:");
	         printf("\t\t| [                                                            ]                       |");
	    for(i = 0; i < 85; i++)
	    {
             printf("\b");
        }
	         fflush(stdin);
		     gets(nomeTemp);
	      	 pos=0;
		while(pos<TLA && stricmp(nomeTemp,VnomeAluno[pos]) !=0)
		pos++;
		
		 if(pos<TLA)
		    {
		    printf("\t\t|%86s|\n", " ");
			printf("\t\t| %-85s|\n", "[!] Aluno já cadastrado tente novamente.");
			printf("\t\t%s%s\n",linha01,linha01);	
	     	}
		 else // Inserir os dados do aluno nos vetores:
			{
				strcpy(VnomeAluno[TLA],nomeTemp); //Recebe nome temporário.
				
		     // <----------------------------- ENTRADA DATA DE VENCIMENTO (MENSALIDADE): ------------------------------->
				printf("\t\t| %85s|\n", " ");
				printf("\t\t| %-85s|\n","VENCIMENTO DA MENSALIDADE");
				printf("\t\t| %-85s|\n","[REGRA] Seguir conforme calendário 14/05/2026, somente números.");
				printf("\t\t| %-84s |","Digite a data do vencimento: [        ]");
		    for(i=0; i < 56;i++)
			    {
				  printf("\b");
				}
		       scanf("%2d%2d%4d", &dia[TLA],&mes[TLA],&ano[TLA]);
					
		     // <----------------------------- VALIDAÇÃO DA DATA: ------------------------------->		
				while(dia[TLA] <= 0 || dia[TLA] > 31 || mes[TLA] <= 0 || mes[TLA] > 12 || ano[TLA] < 2026)	
				{
					printf("\t\t| %85s|\n", " ");
					printf("\t\t| %-85s|\n","[!] Data de vencimento inválida.");
                    printf("\t\t| %-85s|\n","[REGRA] Dia: 1-31 | Mês: 1-12 | Ano: >= 2026.");
					printf("\t\t| %85s|\n", " ");
					printf("\t\t| %-85s|\n","VENCIMENTO DA MENSALIDADE");
					printf("\t\t| %-85s|\n","[REGRA] Seguir conforme calendário 14/05/2026, somente números.");
					printf("\t\t| %-84s |","Digite a data do vencimento: [        ]");
		       		  for(i=0; i < 56;i++)
			          {
				         printf("\b");
			          }
		            scanf("%2d%2d%4d", &dia[TLA],&mes[TLA],&ano[TLA]);	
					
				}
			 
		     // <-------------------------------- ENTRADA VALOR DA MENSALIDADE: -------------------------------------->
		        printf("\t\t| %85s|\n", " ");
		        printf("\t\t| %-85s|\n","PAINEL DE OFERTAS");
		        printf("\t\t| %-85s|\n","[1] Plano Gold - Anual - de R$800,00 por R$500,00");
		        printf("\t\t| %-85s|\n","[2] Plano Prata - Trimestral - de R$240,00 por R$199,90");
		        printf("\t\t| %-85s|\n","[3] Plano Bronze - Mensal - por R$80,00");
		        printf("\t\t| %-85s|\n","Ou pagamento personalizado.");
		        printf("\t\t|%86s|\n", " ");
		        printf("\t\t| %-85s|\n","[1. REGRA] Aceito apenas valores de R$10,00 até R$500,00");
				printf("\t\t| %-85s|\n","[2. REGRA] Somente números.");
				printf("\t\t| %-84s |","Digite o valor da mensalidade: [      ]");
				
		    for(i=0; i < 54;i++)
			    {
				  printf("\b");
				}
		       scanf("%f", &vValor[TLA]);
			 
			 
			 // <-------------------------------- ENTRADA DA MATRÍCULA: -------------------------------------->
	         printf("\t\t|%86s|\n", " ");
	         printf("\t\t| %-85s|\n","MATRÍCULA");
	         printf("\t\t| %-85s|\n", "[REGRA] Matrícula deve conter no máximo 4 dígitos.");
	         printf("\t\t| %-84s |","Digite a Matrícula do Aluno: [    ]");
	         for(i = 0; i < 56; i++)
	         {
             printf("\b");
             }
	         scanf("%d", &temp);
	         
	         pos=0;
	         
	         while(pos < TLA && temp != VcodAluno[pos])
	         pos++;
	         if(pos<TLA)
	         {
	         printf("\t\t|%86s|\n", " ");
			 printf("\t\t| %-85s|\n", "[!] Matrícula já utilizada tente novamente.");
		     printf("\t\t%s%s\n",linha01,linha01);	
	         }
	         else
			 {
			 VcodAluno[TLA] = temp;
			 temp = 0;
			 cont_alunos++; // <-- Se precisar, esse é o contador de cadastros de alunos.
	         TLA++;       // <-- Implementa TLA para próxima posição do vetor!!
	         printf("\t\t%s%s\n",linha01,linha01);
	         
	         // <-------------------------------- REGISTRO DE CADASTRO [COMEÇO:] -------------------------------------->
	         
	         	printf("\t\t| %-67s REGISTRO: [%4.4d] |","CADASTRO CONCLUíDO COM SUCESSO!",TLA); //<-- Utilizado TLA invés de cont_alunos.
	         	printf("\n\t\t|%86s|", " ");
	         	printf("\n\t\t| %-s","Nome do Aluno: ");
	         	
	         	// Exibição com caixa fixa:
	            // printf("[%-68.68s]",VnomeAluno[TLA-1]);   // <-- [Negativo = esquerda(largura total . imprimir no máximo 68 chars)S = String]
	            
	            printf("[%s]%*s|",VnomeAluno[TLA-1],68-strlen(VnomeAluno[TLA-1]), " ");     // 68 == Quantidade de Espaços - Qt. de Chars
	            	            
	            printf("\n\t\t| %-s","CPF: "); // Aqui ficou 81 <--
	            printf("[%.3s.%.3s.%.3s-%.2s]%*s|",VcpfAluno[TLA-1],VcpfAluno[TLA-1]+3,VcpfAluno[TLA-1]+6,VcpfAluno[TLA-1]+9,75-strlen(VcpfAluno[TLA-1]), " ");     // 65 == Quantidade de Espaços - Qt. de Chars
	            printf("\n\t\t|%86s|", " "); // Acima: %.3s imprimi somente 3 chars.
	            printf("\n\t\t| %-10s [%4.4d] %67s|\n","Matrícula:",VcodAluno[TLA-1], " ");  // 
	            printf("\t\t| %-10s [%2.2d/%2.2d/%4.4d] %52s|","Data de vencimento:",dia[TLA-1],mes[TLA-1],ano[TLA-1], " ");  
	            printf("\n\t\t|%86s|", " "); // Acima Reserva 2 espaços e imprimi 2 espaços em int.
	            
	            printf("\n\t\t| %-10s [R$%6.2f] %61s|","Mensalidade:",vValor[TLA-1], " ");  
	            
	            if(vValor[TLA-1] == 500)
	            {
					printf("\n\t\t| %-85s|", "Plano escolhido: [GOLD ANUAL]");;  
	                printf("\n\t\t|%86s|", " ");
	            }
	            else if(vValor[TLA-1] == 199.90)
	            {
	            	printf("\n\t\t| %-85s|", "Plano escolhido: [PRATA TRIMENSAL]");;  
	                printf("\n\t\t|%86s|", " ");
	            }
	            else if(vValor[TLA-1] == 80)
	            {
	            	printf("\n\t\t| %-85s|", "Plano escolhido: [BRONZE MENSAL]");;  
	                printf("\n\t\t|%86s|", " ");
	            }
	            else
	            {
	            	printf("\n\t\t| %-85s|", "Plano escolhido: [PERSONALIZADO]");;  
	                printf("\n\t\t|%86s|", " ");
	            }
	            
	            
	            printf("\n\t\t%s%s\n",linha01,linha01);
	            
	            // <-------------------------------- REGISTRO DE CADASTRO [FINAL ACIMA] -------------------------------------->
	            
	            
	                if(cont_alunos==Rep_loop) // Validação de números de cadastros realizados.
	                {
	                 printf("\t\t| %-85s|\n", "[REGRA] Digite [s] para continuar ou [n] para encerrar.");
	                 printf("\t\t| %-85s|","Deseja continuar? [ ]");
	                 for(i = 0;i < 67;i++)
	                 {
	                  printf("\b");
	                 }	 
	            
				      fflush(stdin);
	                  gets(Vef);	                  
	                  
	                  if(stricmp(Vef,no) ==0) // Se resposta for igual a não encerra o loop -->(quant de cadastros desejado).
	                  {
	                  Rep_loop=0;
	                  }
	                  
	                else // Pergunta e reinicia loop de quant.
	                {
	                	cont_alunos = 0;
	                	Rep_loop=0;
	                    printf("\t\t%s%s%s\n",linha01,linha01);
	                    printf("\t\t| %-85s|\n", "[REGRA] Limite de 100 Cadastros.");
                        printf("\t\t| %-85s|","Digite o número de alunos que você deseja cadastrar: [   ]");
        
                         for(i = 0; i<32; i++)
                         {
                          printf("\b");
                         }
        
                        scanf("%d", &Rep_loop);
        
                      
        
        
                        // <--------------------------------- IF DE VERIFICAÇÃO (REPETIÇÃO - 2): ------------------------------------->
        
                      // Verifica se excedeu limite (1 Tentativa):
                      if(Rep_loop>TF)
                      {
        	             printf("\t\t%s%s%s\n",linha01,linha01);
                         printf("\t\t| %-85s|\n","[!] Limite excedido, tente novamente.");
                       	 printf("\t\t| %-85s|\n","[!] 1 tentativa restante.");
        	             printf("\t\t%s%s%s\n",linha01,linha01);
	                     printf("\t\t| %-85s|\n", "[REGRA] Limite de 100 Cadastros.");
                         printf("\t\t| %-85s|","Digite o número de alunos que você deseja cadastrar: [   ]");
        
                          for(i = 0; i<32; i++)
                          {
                             printf("\b");
                          }
        
                        scanf("%d", &Rep_loop);
        
                       if(Rep_loop>TF)
                        {
                         limite++; // Serve para parar o while de cadastro.
                         printf("\t\t%s%s\n",linha01,linha01);
                        }
         
                      }
	                }
	                   if(stricmp(Vef,yes) !=0 && stricmp(Vef,no) !=0)
	                   {
	              
                        printf("\t\t| %-85s|\n", "[!] Opção inválida!! ");
                        printf("\t\t| %-85s|\n", "[!] Caso uma opção inválida seja informada novamente, o sistema será encerrado.");
                        printf("\t\t|%86s|\n", " ");     
                    
                        printf("\t\t%s%s\n",linha01,linha01);
	            
	                    printf("\t\t| %-85s|\n", "[REGRA] Digite [s] para continuar ou [n] para encerrar.");
	                    printf("\t\t| %-85s|","Deseja continuar? [ ]");
	                   
					    for(i = 0;i < 67;i++)
	                    {
	                      printf("\b");
	                    }	 
	            
				        fflush(stdin);
	                    gets(Vef);
	            	
	                   }
	            
	                  printf("\t\t%s%s\n",linha01,linha01);
                    } // <-- If Verificador de cont.
	         } // <-- Else-01
	        } // <-- Else-02
    } // Fechamento <-- Else-03 No caso foi feito ao contrario então sim esse seria o else-01
	    }   // <-- Fechamento do While 
	     // <----------------------------------- CADASTRO DE ALUNOS [FIM AQUI] ------------------------------------------->
        break;

        case 3:
        // <----------------------------------- CADASTRO DE MODALIDADE [COMEÇO AQUI] ------------------------------------->
        	
        	printf("\t\t%s%s\n",linha01,linha01);	
	        printf("\t\t|\t\t\t\t%-53s  |\n","CADASTRO DE MODALIDADE");
	        printf("\t\t%s%s\n",linha01,linha01);
	        
	         // <------------------------------- CÓDIGO DA MODALIDADE: -------------------------------------->
	        
            printf("\t\t|%86s|\n", " ");
            printf("\t\t| %-85s|\n","CÓDIGO DA MODALIDADE");
        	printf("\t\t| %-85s|\n", "[REGRA] O código deve conter no máximo 2 dígitos.");
	        printf("\t\t| %-84s |","Digite o código da modalidade: [  ]");
	           for(i = 0;i < 54;i++)
	                 {
	                  printf("\b");
	                 }	
	                 scanf("%d", &temp);
	                 
	           pos=0;     
	     while(pos < TLM && temp != VcodMod[pos])
	           pos++;
	     
	     if(pos<TLM)
	     {
	     	    printf("\t\t|%86s|\n", " ");
			    printf("\t\t| %-85s|\n", "[!] Código já cadastrado tente novamente.");
			    printf("\t\t%s%s\n",linha01,linha01);
	     }
	     else 
		 {
	     	VcodMod[TLM] = temp;
	     	temp = 0;
	     
	         // <------------------------------- NOME DA MODALIDADE: -------------------------------------->
	                 
	     
	         printf("\t\t|%86s|\n", " ");
	         printf("\t\t| %-85s|\n","NOME DA MODALIDADE");
	         printf("\t\t| %-85s|\n", "[1. REGRA] Não utilize caracteres especiais (ç, ã, acentos)."); // Não consegue printar corretamente muito problema se deixar.
	         printf("\t\t| %-85s|\n", "[2. REGRA] Modalidade deve conter no máximo 60 caracteres.");
	         printf("\t\t| %-84s |\n","Digite o nome da Modalidade:");
	         printf("\t\t| [                                                            ]                       |");
	           for(i = 0; i < 85; i++)
	           {
                 printf("\b");
               }
	           fflush(stdin);
		       gets(nomeTemp);
        	
        	pos=0;
        	while(pos < TLM && stricmp(nomeTemp,vModalidade[pos]) !=0)
	        pos++;
        	if(pos < TLM)
        	{
        		printf("\t\t|%86s|\n", " ");
			    printf("\t\t| %-85s|\n", "[!] Modalidade já cadastrada, tente novamente.");
			    printf("\t\t%s%s\n",linha01,linha01);
        	}
        	else
        	{
        	strcpy(vModalidade[TLM],nomeTemp);
        	
             // <------------------------------- VALOR DA MODALIDADE: -------------------------------------->
        	
			  printf("\t\t|%86s|\n", " ");
			  printf("\t\t| %-85s|\n","VALOR DA AULA");
	          printf("\t\t| %-85s|\n","[1. REGRA] Aceito apenas valores de R$50,00 até R$300,00");
			  printf("\t\t| %-85s|\n","[2. REGRA] Somente números.");
	          printf("\t\t| %-84s |","Digite o valor da aula: [R$      ]");
	            for(i = 0;i < 59; i++)
				{
                 printf("\b");
                }
				scanf("%f", &vValorAula[TLM]);
				
				while(vValorAula[TLM]<50 || vValorAula[TLM]>300) // Verifica se é menor que R$50,00 ou R$300,00;
				{
					printf("\t\t|%86s|\n", " ");
				 	printf("\t\t| %-85s|\n","[!] Limite excedido, tente novamente.");
				 	printf("\t\t| %-85s|\n","[1. REGRA] Aceito apenas valores de R$50,00 até R$300,00");
			        printf("\t\t| %-85s|\n","[2. REGRA] Somente números.");
	                printf("\t\t| %-84s |","Digite o valor da aula: [R$      ]");
	                  for(i = 0;i < 59; i++)
				      {
                        printf("\b");
                      }
				      scanf("%f", &vValorAula[TLM]);
				 	
				}
				
				TLM++;
				printf("\t\t%s%s\n",linha01,linha01);
	
             // <----------------------------------- REGISTRO DE MODALIDADE: ----------------------------------->
             
             	printf("\t\t| %-68s REGISTRO: [%3.3d] |","CADASTRO CONCLUíDO COM SUCESSO!",TLM); 
             	printf("\n\t\t|%86s|", " ");
            
                printf("\n\t\t| %-12s[%s]%*s|","Modalidade: ",vModalidade[TLM-1],71-strlen(vModalidade[TLM-1]), " ");
                printf("\n\t\t| %-12s[%2.2d]%69s|","Código: ",VcodMod[TLM-1], " ");
                printf("\n\t\t| %-10s [R$%6.2f] %59s|","Valor da aula:",vValorAula[TLM-1], " "); 
		        printf("\n\t\t%s%s\n" ,linha01,linha01);
				
        	} // Else2-M -> Entrada após Verificação de String-Mod!
        } // Else-1-M -> Entrada após Verificação de Cod-Mod!
        
        // <----------------------------------- CADASTRO DE MODALIDADE [FINAL] ------------------------------------->
         break;
        
        case 4:
        	// CASE DE SAÍDA (NÃO INSERIR CÓDIGO [AQUI]);
         break;
	    
	    } // fechamento Switch-02
	                                           
		// <----------------------------------- REPETIÇÃO SUB MENU (CADASTRO) [COMEÇO:] ---------------------------------------->  
		
    	 printf("\t\t|\t\t\t\t %-53s |\n","MÓDULO DE CADASTROS");                                                
    	 printf("\t\t%s%s\n" ,linha01,linha01);  
    	 printf("\t\t| %-84s |\n","Selecione uma das operações disponíveis:");
    	 printf("\t\t|%86s|\n", " ");
    	 printf("\t\t| %-84s |\n","[1] Cadastro de Instrutores");                 
	     printf("\t\t| %-84s |\n","[2] Cadastro de Alunos");                  
	     printf("\t\t| %-84s |\n","[3] Cadastro de Modalidades");                         
	     printf("\t\t| %-84s |\n","[4] Retornar ao Menu Principal");
	     printf("\t\t|%86s|\n", " ");
	     printf("\t\t| %-85s|","Digite a opção desejada: [ ]");
	     printf("%s%s%s",linha02,linha02,linha02);
	     scanf("%d", &sub_op);
	    
        } // fechamento While Repetição Sub Menu <-- CADASTROS!
        // <----------------------------------- REPETIÇÃO SUB MENU (CADASTRO) [FINAL] -------------------------------------------> 
        break;
    		
        case 2:
        
		printf("\t\t|\t\t\t\t %-53s |\n","MÓDULO DE EXCLUSÃO");                                                
    	printf("\t\t%s%s\n" ,linha01,linha01);  
    	printf("\t\t| %-84s |\n","Selecione uma das operações disponíveis:");
    	printf("\t\t|%86s|\n", " ");
    	printf("\t\t| %-84s |\n","[1] Exclusão de Instrutores");                 
	    printf("\t\t| %-84s |\n","[2] Exclusão de Alunos");                  
	    printf("\t\t| %-84s |\n","[3] Exclusão de Modalidades");    
		printf("\t\t| %-84s |\n","[4] Exclusão de Lançamentos");      
	    printf("\t\t| %-84s |\n","[5] Retornar ao Menu Principal");
	    printf("\t\t|%86s|\n", " ");
	    printf("\t\t| %-85s|","Digite a opção desejada: [ ]");
	    printf("%s%s%s",linha02,linha02,linha02);
	    scanf("%d", &sub_op);
		
		while(sub_op >=1 && sub_op <=4)
		{
		switch(sub_op) // SUB MENU [2] <-- MÓDULO DE EXCLUSÃO:
		{
		    case 1:
		  	
		  	
		  	
		  	break;
			
			case 2:
		 // <-------------------------------- EXCLUSÃO DE ALUNOS [COMEÇO]: ------------------------------------------->
		 
		  	 printf("\t\t%s%s\n",linha01,linha01);	
	         printf("\t\t|\t\t\t\t%-53s  |\n","EXCLUSÃO DE ALUNOS");
	         printf("\t\t%s%s\n",linha01,linha01);
	         
	     // <---------------------------------------- PESQUISAR CPF: ----------------------------------------------->
	          printf("\t\t|%86s|\n", " ");
	          printf("\t\t| %-85s|\n", "PESQUISAR CADASTRO:");
	          printf("\t\t| %-85s|\n", "[REGRA] CPF deve conter exatamente 11 dígitos.");
	          printf("\t\t| %-84s |","Digite somente os números do CPF: [           ]");
	            for(i = 0; i < 51; i++)
	            {
                  printf("\b");
                }
           
           fflush(stdin);
		   gets(cpfTemp);
           pos=0;
           
           // <-------------------------------------- VALIDAÇÃO DO CPF: ------------------------------------------->
           
           while(pos<TLA && stricmp(cpfTemp,VcpfAluno[pos]) !=0) // Vai rodar até encontrar (string) == (string_da_posição) 
	         pos++;
	         
	         if(pos<TLA) //OBS: Se for menor encontrou o cadastrado.
	         {
	         	
	         	printf("\t\t%s%s\n",linha01,linha01);
	         	printf("\t\t| %-67s REGISTRO: [%4.4d] |\n","CADASTRO ENCONTRADO!",pos+1); // <--- VERIFICAR SE REGISTRO ESTÁ CORRETO (pos+1)
			    
			    printf("\t\t|%86s|\n", " ");
			    printf("\t\t| %-s","Nome do Aluno: "); // <-- aqui é 16
			    printf("[%s]%*s|",VnomeAluno[pos],68-strlen(VnomeAluno[pos]), " "); // 68 é o total depois da subtração dos chars do printf acima.
			    printf("\n\t\t| %-s","CPF: ");
			    printf("[%.3s.%.3s.%.3s-%.2s]%*s|",VcpfAluno[pos],VcpfAluno[pos]+3,VcpfAluno[pos]+6,VcpfAluno[pos]+9,75-strlen(VcpfAluno[pos]), " ");
			    printf("\n");
			    printf("\t\t%s%s\n",linha01,linha01);
			    
			   // <-------------------------------------- VALIDAÇÃO DE EXCLUSÃO: ---------------------------------------->
			   
			     printf("\t\t| %-85s|\n", "[AVISO] Esta ação removerá permanentemente o cadastro do aluno.");
			     printf("\t\t|%86s|\n", " ");
			     printf("\t\t| %-85s|\n", "[CONFIRMAÇÃO] Por segurança, informe novamente o CPF do aluno.");
	             printf("\t\t| %-84s |","Digite somente os números do CPF: [           ]");
	               for(i = 0; i < 51; i++)
	               {
                     printf("\b");
                   }
           
                 fflush(stdin);
		         gets(cpfTemp);
			    
			    if(stricmp(cpfTemp,VcpfAluno[pos]) ==0)
			    {
			    
			    	for(i=pos;i < TLA-1;i++) // Começa da posição encontrada e desloca tudo para trás | TLA-1 pra não acessar cadastro não existente
					{			      			      
			      		strcpy(VcpfAluno[i],VcpfAluno[i+1]);          // | No caso a próxima posição sobreescreve a anterior;
			      			  									      // | Começa do número (pos) encontrado;
			      		strcpy(VnomeAluno[i],VnomeAluno[i+1]);        // |(i+1) vai até antes da última posição, porque vou precisar pegar a próxima.
			      												
			      		vValor[i] = vValor[i+1];						
			      
			      		VcodAluno[i] = VcodAluno[i+1];
			      
			      		dia[i] = dia[i+1];
				  		mes[i] = mes[i+1];
				  		ano[i] = ano[i+1];			      			      
			      
			        }
			    
			      TLA=TLA-1; // Diminui a quantidade total de alunos cadastrados.
			      
			      printf("\t\t%s%s\n",linha01,linha01);
	         	  printf("\t\t| %-85s|\n", "[SUCESSO] Exclusão do aluno realizada com sucesso!");
	         	  printf("\t\t%s%s\n",linha01,linha01);
			      
			   } // Fechamento IF-02-EX (Verificação de segurança)
			   
			   else { // <-- Errou CPF NA VERIFICAÇÃO 
			   	printf("\t\t%s%s\n",linha01,linha01);
	         	printf("\t\t| %-85s|\n", "[!] Falha na confirmação de segurança. Exclusão cancelada.");
	         	printf("\t\t%s%s\n",linha01,linha01);
			   } 
			   
	         } // Fechamento IF-01-EX
	         else //OBS: se posição for igual a TLA <-- Não encontrou o valor.
	         {
	         	printf("\t\t%s%s\n",linha01,linha01);
	         	printf("\t\t| %-85s|\n", "[!] Cadastro do aluno não encontrado.");
	         	printf("\t\t%s%s\n",linha01,linha01);
	         	
	         }
		  	// <-------------------------------- EXCLUSÃO DE ALUNOS [FIM]: ------------------------------------------->
		  	break;
		  	
		  	case 3:
		  	
		  	
		  	break;
		  	
		  	case 4:
		  	
		  	
		  	break;
			
			case 5:
		  	// CASE DE SAÍDA (NÃO INSERIR CÓDIGO [AQUI]);
		  	break;
			
		}
		
		 // <------------------------------ REPETIÇÃO MÓDULO DE EXCLUSÃO [COMEÇO AQUI] ----------------------------------->  
		 
			printf("\t\t|\t\t\t\t %-53s |\n","MÓDULO DE EXCLUSÃO");                                                
    		printf("\t\t%s%s\n" ,linha01,linha01);  
    		printf("\t\t| %-84s |\n","Selecione uma das operações disponíveis:");
    		printf("\t\t|%86s|\n", " ");
    		printf("\t\t| %-84s |\n","[1] Exclusão de Instrutores");                 
	   	    printf("\t\t| %-84s |\n","[2] Exclusão de Alunos");                  
	   		printf("\t\t| %-84s |\n","[3] Exclusão de Modalidades");    
			printf("\t\t| %-84s |\n","[4] Exclusão de Lançamentos");      
	    	printf("\t\t| %-84s |\n","[5] Retornar ao Menu Principal");
	    	printf("\t\t|%86s|\n", " ");
	    	printf("\t\t| %-85s|","Digite a opção desejada: [ ]");
	    	printf("%s%s%s",linha02,linha02,linha02);
	    	scanf("%d", &sub_op);
	    	
		}
		// <---------------------------------- REPETIÇÃO MÓDULO DE EXCLUSÃO [FIM] ---------------------------------------->
         break;

        case 3:
        	
         break;
        
        case 4:
        	
         break;
        
        case 5: 
		// Sessão finalizada - Sistema Offline.
         break;




    	
    	
    	
    	
    	
    	
    	
    	
    	
    	
       } // fechamento do Switch-01
       
    // <---------------------------------- REPETIÇÃO MENU PRINCIPAL [AQUI] ---------------------------------------->  
     printf("\t\t|%86s|\n", " "); 
     printf("\t\t%s%s\n",linha01,linha01);
	 printf("\t\t|\t\t\t      %-54s   |\n","PROJECT ALPHA - MENU PRINCIPAL");
	 printf("\t\t%s%s\n",linha01,linha01);                                    
	 printf("\t\t|%86s|\n", " ");                                                
	 printf("\t\t| %-84s |\n","[1] - Gestão de Cadastros");                      
	 printf("\t\t| %-84s |\n","[2] - Gestão de Exclusões");                      
 	 printf("\t\t| %-84s |\n","[3] - Lançamentos");                              
	 printf("\t\t| %-84s |\n","[4] - Emissão de Relatório");
	 printf("\t\t| %-84s |\n","[5] - Finalizar");
	 printf("\t\t|%86s|\n", " ");
	 printf("\t\t%s%s\n" ,linha01,linha01);  
	 printf("\t\t| %-85s|", "Digite a opção desejada: [ ]");
     printf("%s%s%s",linha02,linha02,linha02);                                   
     scanf("%1d", &temp);                                                        
    
    if(temp>0 && temp<=5) // <-- (IF-01.1) Validação de "temp".
    { op = temp;
      temp = 0;
    }                     // fechamento (IF-01.1)
    else
    {
    printf("\t\t|%86s|\n", " ");     
    printf("\t\t| %-85s|\n", "[!] Opção inválida!! ");
    printf("\t\t| %-85s|\n", "[!] Caso uma opção inválida seja informada novamente, o sistema será encerrado.");
    printf("\t\t|%86s|\n", " ");     
    printf("\t\t| %-85s|", "Digite a opção desejada: [ ]");
    printf("%s%s%s",linha02,linha02,linha02);                               
    scanf("%1d", &op);               
    }
    printf("\t\t%s%s\n" ,linha01,linha01); 
      
    } // fechamento While-01
	      printf("\t\t%s%s\n",linha01,linha01);	
	      printf("\t\t| %24s%-59s  |\n", " ","[OFFLINE] Sessão finalizada com sucesso.");
	      printf("\t\t%s%s\n",linha01,linha01);
} // Fechamento Main() 
