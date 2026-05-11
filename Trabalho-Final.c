#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#define TF 10
#define TF_INST 5


main ()
{

	// <---------------------- SISTEMA DE GERENCIAMENTO ACADEMIA ------------------------>
	
	// Vetores Inteiros:                             Vetores String:
	int VcodInst[TF_INST],vcpfInst[TF_INST];  char VnomeInst[TF_INST][81],nomeTemp[81];
	int VcodAluno[TF],VcpfAluno[TF];          char VnomeAluno[TF][81];
	// Opção Escolhida/Sub Menu e Variável temporária:
	int op=0,sub_op=0,temp=0;
	// Vetores Float:
	float vValorAula=0,vValor=0;
	// Contadores:
	int n,cont,i=0,TLI=0,pos; // OBS: "pos" == posição do vetor. 
	
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
       switch(op) // Controle de Opções com Switch!
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
	    
	    switch(sub_op)
	    {
	    case 1:
	    printf("\t\t%s%s\n",linha01,linha01);	
	    printf("\t\t|\t\t\t\t%-53s  |\n","CADASTRO DE INSTRUTORES");
	    printf("\t\t%s%s\n",linha01,linha01);
	    printf("\t\t|%86s|\n", " ");
	    printf("\t\t| %-85s|\n", "[REGRA] Nome completo deve conter no máximo 80 caracteres.");
	    printf("\t\t| %-84s |\n","Digite o nome completo do instrutor:");
	    printf("\t\t| [                                                                                  ] |");
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
	         TLI++;
	         printf("\t\t%s%s\n",linha01,linha01);
	         }
	        }
	     break;
	    		
	    case 2:
        	
         break;

        case 3:
        	
         break;
        
        case 4:
        	
         break;
	    
	    } // fechamento Switch-02
    	
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
