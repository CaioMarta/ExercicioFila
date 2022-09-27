#include<stdio.h>
#include <strings.h>

struct Fila
{
	char elementos[15];
	int comeco;
	int final;
};

void iniciarFila(struct Fila *F);
void inserirFila(struct Fila *F, char c);
void mostrar(struct Fila F);
void removerFila(struct Fila *F);


int main()
{
	struct Fila F;
	int t;
	char op;
	char denominacao[60];
	iniciarFila(&F);
	
	do
	{
	fflush(stdin);
	printf("Informe uma denominacao: ");
	gets(denominacao);
	t = strlen(denominacao);
	for(int i=0; i<t;i++)
	{
		if(denominacao[i] >= 'A' && denominacao[i] <= 'Z')
		{
			inserirFila(&F,denominacao[i]);
		}
	}
	printf("\nAcronimo de %s: ",denominacao);
	removerFila(&F);
	printf("\nDeseja digitar outra denominacao? (S/N)");
	scanf(" %c",&op);
	
	}while(op != 'N');
	return 0;
}


void iniciarFila(struct Fila *F)
{
	F->comeco = 0;
	F->final = -1;
}

void inserirFila(struct Fila *F, char c)
{
	F->final++;
	F->elementos[F->final] = c;
} 

void mostrar(struct Fila F)
{
	int i;
	for(i=F.comeco; i<=F.final; i++)
	{
		printf("%c ", F.elementos[i]);
	}
}

void removerFila(struct Fila *F)
{
	char c;
	while(F->final >= F->comeco)
	{
		c=F->elementos[F->comeco];
		printf("%c", c);
		F->comeco++;
	}
	
} 