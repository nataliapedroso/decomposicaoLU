#include<stdio.h>
#include<stdlib.h>
void imprimir(double **M, int dim)
{
	int i, j;
	for(i=0; i<dim; i++)
	{
		for(j=0; j<dim+1; j++)
			printf(" %.2f\t", M[i][j]);
		printf("\n");
	}
	printf("\n");
}
void leitura(double **M, int dim, FILE*ler)
{
	int i, j;
	double a;

	for(i=0; i<dim; i++)
		M[i]=malloc((dim+1)*sizeof(double));

	i=j=0;
	while(fscanf(ler, "%.1f", &a)!=EOF)
	{
		M[i][j]=a;
		j++;
		if(j==dim+1)
		{
			j=0;
			i++;
		}
	}
}
void decompLU(double **M, int dim)
{
	double **L, **U;
	int i, j, k, oper;
	float soma1, soma2;

	U=malloc(dim*sizeof(double*));
	L=malloc(dim*sizeof(double*));

	oper=0;

	for(i=0; i<dim; i++)
	{
		L[i]=malloc((dim)*sizeof(double));
		L[i][0]=M[i][0];
	}

	i=0;

	for(j=0; j<dim; j++)
	{
		U[i]=malloc((dim)*sizeof(double));
		if(i==j)
		{
			U[i][j]=1.0;
			i++;
			oper++;
		}
		U[0][j]=M[0][j]/L[0][0];
		oper++;
	}

	soma1=0;
	soma2=0;

	for(i=1; i<dim; i++)
	{
		for(j=1; j<dim; j++)
		{
			for(k=0; k<j-1; k++)
			{
				soma1=soma1+U[k][i]*L[i][k];
				L[i][j]=M[i][j]-soma1;
				oper++;
			}
		}
		for(j=i+1; j<dim; j++)
		{
			for(k=0; k<i-1; k++)
			{
				soma2=soma2+U[k][j]*L[i][k];
				oper++;
			}
			U[i][j]=(M[i][j]-soma2)/L[i][i];
			oper++;
		}
	}

	printf("\n A matriz L é: \n");
	imprimir(L, dim);
	printf("\n A matriz U é: \n");
	imprimir(U, dim);

	printf("\n Número de operações: %d \n", oper);
}


