#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Registro
struct fila {
	int inicio;
	int final;
	int numElementos;
	char elementos[MAX];
};

typedef struct fila Fila;

// Protótipos
Fila *criar(int *deuCerto);
void destruir(Fila *f);
void insere(Fila *f, char x, int *deuCerto);
int cheia(Fila *f);

// Função principal
int main() {
	Fila *f;
	int deuCerto;
	
	f = criar(&deuCerto);

	if (deuCerto == 0) {
		puts("Deu Ruim");
		exit(-1);
	}
	
	insere(f, 'a', &deuCerto);
	insere(f, 'b', &deuCerto);
	insere(f, 'c', &deuCerto);
	insere(f, 'd', &deuCerto);
	insere(f, 'e', &deuCerto);
	insere(f, 'f', &deuCerto);
	insere(f, 'g', &deuCerto);
	insere(f, 'h', &deuCerto);
	insere(f, 'i', &deuCerto);
	insere(f, 'j', &deuCerto);

	for (int i = 0; i < MAX; i++) {
		printf("%c ", f->elementos[i]);
	}

	destruir(f);

	return 0;
}






// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- Funções auxiliares -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

Fila *criar(int *deuCerto) {
	Fila *f;
	f = (Fila *) malloc(sizeof(Fila));

	if (f == NULL) *deuCerto = 0;
	else {
		*deuCerto = 1;
		f->inicio = 0;
		f->final = 0;
		f->numElementos = 0;
	}

	return f;
}

void insere(Fila *f, char x, int *deuCerto) {
	if (cheia(f)) {
		*deuCerto = 0;
	}
	else {
		*deuCerto = 1;
		f->numElementos = f->numElementos + 1;
		f->elementos[f->final] = x;
		
		if (f->final == MAX - 1)
			f->final = 0;
		else
			f->final = f->final + 1;
	}
}

int cheia(Fila *f) {
	return (f->numElementos == MAX);
}

int vazia(Fila *f) {
	return (f->numElementos == 0);
}

void destruir(Fila *f) {
	if (f != NULL) free(f);
}
