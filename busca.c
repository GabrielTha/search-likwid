#include <stdio.h>
#include <time.h>
#include <likwid.h>


void preencheVetor(int X[], int n)
{
	for (int i = 0; i < n; i++)
		X[i] = i;
}



	int linear(int X[], int Y, int n)
	{
		for (int i = 0; i < n; i++)
		{
			if (X[i] == Y)
				return i;
		}

		return -1;
	}

	int binaria(int X[], int Y, int n)
	{
		int inf, sup, meio;
		inf = 0;
		sup = n - 1;
		while (inf <= sup)
		{
			meio = (inf + sup) / 2;
			if (X[meio] == Y)
				return meio;
			else if (X[meio] > Y)
				sup = meio - 1;
			else
				inf = meio + 1;
		}

		return -1;
	}

int main()
{
	int n = 2000000;
	int X[2000000];
	int Y = 1999999;

	preencheVetor(X, n);
	LIKWID_MARKER_INIT;
	LIKWID_MARKER_START("linear");
	printf("Posição em linear: %i\n", linear(X, Y, n));
	LIKWID_MARKER_STOP("linear");
	LIKWID_MARKER_START("binaria");
	printf("Posição em binaria: %i\n", binaria(X, Y, n));
	LIKWID_MARKER_STOP("binaria");

	LIKWID_MARKER_CLOSE;
	return 0;
}
