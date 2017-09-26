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


