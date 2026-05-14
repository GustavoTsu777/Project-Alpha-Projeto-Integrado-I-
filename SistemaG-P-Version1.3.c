#include <stdio.h>
#include <locale.h>
#include <string.h>
#define TF 100
#define TF_INST 10


main ()
{

	// <---------------------- SISTEMA DE GERENCIAMENTO ACADEMIA ------------------------>
	
	// Vetores Inteiros:                             Vetores String:
	int VcodInst[TF_INST],vcpfInst[TF_INST];  char VnomeInst[TF_INST][61],nomeTemp[61],vModalidade[61]; 
	int VcodAluno[TF],VcpfAluno[TF];          char VnomeAluno[TF][61];
	// Parte 3 - Modalidade:                  // Extras:
	int VcodMod;                              char Vef[2], yes[]="s",no[]="n"; // Usado no loop verificador não está funcionando (Atualizar);
	
	
	
	// Opção Escolhida/Sub Menu e Variável temporária:
	int op=0,sub_op=0,temp=0,Rep_loop=0;
	// Vetores Float:
	float vValorAula=0,vValor=0;
	// Contadores:
	int n,i=0,cont_inst=0,cont_alunos=0,TLI=0,TL=0,pos; // OBS: "pos" == posição do vetor. 
	
	// <--------------------------------------------------------------------------------->
	
	// Separação de linhas:
	char linha01[] = "============================================";
	char linha02[] = "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"; // <-- Atualizado para versão em for!
	
	setlocale(LC_ALL,"Portuguese"); // <-- Define a linguagem local em Português.
	printf("\t\t%s%s\n" ,linha01,linha01);                                      // \n quebra linha, \t adiciona tabulação.
	printf("\t\t|%86s|\n", " ");                                            
	printf("\t\t|\t\t\t %-61s |\n","SISTEMA DE GERENCIAMENTO PROJECT ALPHA");   // Utilizado "largura de campo" (field width)
	printf("\t\t|%86s|\n", " ");                                                // Exemplo: %-40s
	printf("\t\t%s%s\n" ,linha01,linha01);                                      // %  -> inicia a formatação
	printf("\t\t|%86s|\n", " ");                                                // -  -> alinhamento à esquerda
	printf("\t\t| %-84s |\n","[1] - Gestão de Cadastros");                      // 40 -> define a largura do campo em 40 caracteres
	printf("\t\t| %-84s |\n","[2] - Gestão de Exclusões");                      // s  -> indica uma string
	printf("\t\t| %-84s |\n","[3] - Lançamentos");                              // Usado para alinhar e organizar textos/interface no console.
	printf("\t\t| %-84s |\n","[4] - Emissão de Relatório");
	printf("\t\t| %-84s |\n","[5] - Finalizar");
	printf("\t\t|%86s|\n", " ");
	printf("\t\t%s%s\n" ,linha01,linha01);  
	printf("\t\t| %-85s|", "Digite a opção desejada: [ ]");
    printf("%s%s%s",linha02,linha02,linha02);                                   // Utilizado: \b < -- Volta o cursor em 1 caractere.
    scanf("%1d", &temp);                                                        // Aceita somente 1 dígito de número inteiro. ( %1d ) 
    
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
			 
	         printf("\t\t%s%s\n",linha01,linha01);
	         printf("\t\t| %-85s|\n", "[REGRA] Matrícula deve conter exatamente 4 dígitos.");
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
	    Rep_loop=0;
	    cont_alunos=0;
	    
	    printf("\t\t%s%s%s\n",linha01,linha01);
	    printf("\t\t| %-85s|\n", "[REGRA] Limite de 100 Cadastros.");
        printf("\t\t| %-85s|","Digite o número de alunos que você deseja cadastrar: [   ]");
        
        for(i = 0; i<32; i++)
        {
        printf("\b");
        }
        
        scanf("%d", &Rep_loop); // RECEBE QUANTAS VEZES IRÁ REPETIR O CADASTRO!
        
        // <------------------------------------- IF DE VERIFICAÇÃO: ---------------------------------------->
        
        // Verifica se excedeu limite:
        if(Rep_loop>100)
        {
        	printf("\t\t%s%s%s\n",linha01,linha01);
        	printf("\t\t| %-85s|\n","[!] Limite excedido, tente novamente.");
        	printf("\t\t%s%s%s\n",linha01,linha01);
	        printf("\t\t| %-85s|\n", "[REGRA] Limite de 100 Cadastros.");
            printf("\t\t| %-85s|","Digite o número de alunos que você deseja cadastrar: [   ]");
        
         for(i = 0; i<32; i++)
         {
          printf("\b");
         }
        
        scanf("%d", &Rep_loop);
        }
        
        strcpy(Vef,yes); // Pra não bugar while! Vef = SIM (entra no while).
        
        // <-------------------------------- WHILE COM REPETIÇÃO DE CADASTRO: ------------------------------------------->
        
	   	while(cont_alunos<Rep_loop && stricmp(Vef,no) !=0)
	    {
	         printf("\t\t%s%s\n",linha01,linha01);	
	         printf("\t\t|\t\t\t\t%-53s  |\n","CADASTRO DE ALUNOS");
	         printf("\t\t%s%s\n",linha01,linha01);
	         printf("\t\t|%86s|\n", " ");
	         printf("\t\t| %-85s|\n", "[REGRA] Nome completo deve conter no máximo 60 caracteres.");
	         printf("\t\t| %-84s |\n","Digite o nome completo do Aluno:");
	         printf("\t\t| [                                                            ]                       |");
	    for(i = 0; i < 85; i++)
	    {
             printf("\b");
        }
	         fflush(stdin);
		     gets(nomeTemp);
	      	 pos=0;
		while(pos<TL && stricmp(nomeTemp,VnomeAluno[pos]) !=0)
		pos++;
		if(pos<TL)
		    {
		    printf("\t\t|%86s|\n", " ");
			printf("\t\t| %-85s|\n", "[!] Aluno já cadastrado tente novamente.");
			printf("\t\t%s%s\n",linha01,linha01);	
	     	}
		else // Inserir os dados do aluno nos vetores:
			{
			 strcpy(VnomeAluno[TL],nomeTemp);
			 
	         printf("\t\t%s%s\n",linha01,linha01);
	         printf("\t\t| %-85s|\n", "[REGRA] Matrícula deve conter exatamente 4 dígitos.");
	         printf("\t\t| %-84s |","Digite a Matrícula do Aluno: [    ]");
	         for(i = 0; i < 56; i++)
	         {
             printf("\b");
             }
	         scanf("%d", &temp);
	         pos=0;
	         while(pos < TL && temp != VcodAluno[pos])
	         pos++;
	         if(pos<TL)
	         {
	         printf("\t\t|%86s|\n", " ");
			 printf("\t\t| %-85s|\n", "[!] Matrícula já utilizada tente novamente.");
		     printf("\t\t%s%s\n",linha01,linha01);	
	         }
	         else
			 {
			 VcodAluno[TL] = temp;
			 temp = 0;
			 cont_alunos++; // <-- Se precisar, esse é o contador de cadastros de alunos.
	         TL++;       // <-- Implementa TL para próxima posição do vetor!!
	         printf("\t\t%s%s\n",linha01,linha01);
	         
	         	printf("\t\t| %-67s REGISTRO: [%4.4d] |","CADASTRO CONCLUíDO COM SUCESSO!",TL); //<-- Utilizado TL invés de cont_alunos.
	         	printf("\n\t\t|%86s|", " ");
	         	printf("\n\t\t| %-s","Nome do Aluno: ");
	         	
	         	// Exibição com caixa fixa:
	            // printf("[%-68.68s]",VnomeAluno[TLI-1]);   // <-- [Negativo = esquerda(largura total . imprimir no máximo 68 chars)S = String]
	            
	            printf("[%s]%*s|",VnomeAluno[TL-1],68-strlen(VnomeAluno[TL-1]), " ");     // 68 == Quantidade de Espaços - Qt. de Chars
	            printf("\n");
	            printf("\t\t| %-10s [%4.4d] %67s|\n","Matrícula:",VcodAluno[TL-1], " ");  // <-- Isso é perfeição! 
	            printf("\t\t%s%s\n",linha01,linha01);
	            
	                if(cont_alunos==Rep_loop)
	                {
	                 printf("\t\t| %-85s|\n", "[REGRA] Digite [s] para continuar ou [n] para encerrar.");
	                 printf("\t\t| %-85s|","Deseja continuar? [ ]");
	                 for(i = 0;i < 67;i++)
	                 {
	                  printf("\b");
	                 }	 
	            
				      fflush(stdin);
	                  gets(Vef);
	                if(stricmp(Vef,no) ==0)
	                {
	                Rep_loop=0;
	                }
	                else
	                {
	                	Rep_loop=0;
	                    printf("\t\t%s%s%s\n",linha01,linha01);
	                    printf("\t\t| %-85s|\n", "[REGRA] Limite de 100 Cadastros.");
                        printf("\t\t| %-85s|","Digite o número de alunos que você deseja cadastrar: [   ]");
        
                         for(i = 0; i<32; i++)
                         {
                          printf("\b");
                         }
        
                        scanf("%d", &Rep_loop);
        
                        if(Rep_loop>100)
                        {
        	                printf("\t\t%s%s%s\n",linha01,linha01);
                           	printf("\t\t| %-85s|\n","[!] Limite excedido, tente novamente.");
              	            printf("\t\t%s%s%s\n",linha01,linha01);
	                          printf("\t\t| %-85s|\n", "[REGRA] Limite de 100 Cadastros.");
                              printf("\t\t| %-85s|","Digite o número de alunos que você deseja cadastrar: [   ]");
        
                              for(i = 0; i<32; i++)
                              {
                                printf("\b");
                              }
        
                              scanf("%d", &Rep_loop);
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
	        
	    }   // <-- Fechamento do While 
	     // <----------------------------------- CADASTRO DE ALUNOS [FIM AQUI] ------------------------------------------->
        break;

        case 3:
        /* RASCUNHO:
			printf("\t\t%s%s",linha01,linha01);
        	printf("\t\t| %-85s|","CADASTRO DE MODALIDADE");
        
        	for(i = 0; i < 64; i++)
        	{
        	printf("\b");
            }
        	scanf("%d", &temp);
        	
        	//VERIFICADOR AQUI!!!
        	
        	TLM <-- NO caso TL de Modalidade;
        	
        	//REPETE LEITOR + 2 Vef; */
        	
        	printf("\t\t%s%s\n",linha01,linha01);	
	        printf("\t\t|\t\t\t\t%-53s  |\n","CADASTRO DE MODALIDADE");
	        printf("\t\t%s%s\n",linha01,linha01);

        	printf("\t\t| %-85s|\n", "[REGRA] O código deve conter no máximo 2 dígitos.");
	        printf("\t\t| %-84s |","Digite o código da modalidade: [  ]");
	           for(i = 0;i < 54;i++)
	                 {
	                  printf("\b");
	                 }	
	                 scanf("%d", &VcodMod);
	                 
	    // <--------------------------------------------------------------------------------------------------->
	                 
	                 
	        printf("\t\t%s%s\n",linha01,linha01);
	        printf("\t\t|%86s|\n", " ");
	         printf("\t\t| %-85s|\n", "[REGRA] Modalidade deve conter no máximo 60 caracteres.");
	         printf("\t\t| %-84s |\n","Digite o nome da Modalidade:");
	         printf("\t\t| [                                                            ]                       |");
	           for(i = 0; i < 85; i++)
	           {
                printf("\b");
               }
	           fflush(stdin);
		       gets(nomeTemp);
        	
        	
        	
         break;
        
        case 4:
        	
         break;
	    
	    } // fechamento Switch-02
	                                           
		// <----------------------------------- REPETIÇÃO SUB MENU [AQUI] ------------------------------------------->  
		
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
	    
        } // fechamento While Repetição Sub Menu <-- Cadastros!
        break;
    		
        case 2:
        	
         break;

        case 3:
        	
         break;
        
        case 4:
        	
         break;
        
        case 5:
        	
         break;




    	
    	
    	
    	
    	
    	
    	
    	
    	
    	
       } // fechamento do Switch-01
    // <----------------------------------- REPETIÇÃO MENU [AQUI] ------------------------------------------->  
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
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
