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
}Triangulo;

Triangulo** alocaMat( Triangulo **Mat);
Triangulo ** preencheMat(Triangulo **M);
void Desenha(void);
void Teclado (unsigned char key, int x, int y);
void TeclasEspeciais(unsigned char key, int x, int y);
void Inicializa(void);
void Tela(void);
void PreencheZero(Triangulo ** Mat);
void imprimeMat (Triangulo ** Mat);
void Anima(int value);
void GerenciaMouse(int button, int state, int x, int y);

