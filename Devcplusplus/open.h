#include <GL/glut.h> // Responsavel por gerenciamento de janelas e tratamento de eventos
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>

typedef struct ponto{
	float x;
	float y;
	float z;
}Pontos;

typedef struct quad{
	Pontos *ponto;
}Quadrado;

Quadrado** alocaMat( Quadrado **Mat);
Quadrado ** preencheMat(Quadrado **M);
void Desenha(void);
void Teclado (unsigned char key, int x, int y);
void Inicializa(void);
void Tela(void);
void liberaMatriz(Quadrado ** Mat);
