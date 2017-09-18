#include <GL/glut.h> // Responsavel por gerenciamento de janelas e tratamento de eventos
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define tam 5

typedef struct ponto{
	float x;
	float y;
}Pontos;

typedef struct quad{
	Pontos *ponto;
}Quadrado;

Quadrado *InitQuad(Pontos *p);
Quadrado** alocaMat(Quadrado *quad , Quadrado **Mat);
Quadrado ** preencheMat(Quadrado **M, Pontos *p);
void Desenha(void);
void Teclado (unsigned char key, int x, int y);
void Inicializa(void);
void Tela(void);
void liberaMatriz(Quadrado ** Mat);
