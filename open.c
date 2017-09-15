
#include <GL/glut.h> // Responsavel por gerenciamento de janelas e tratamento de eventos
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define tam 10

typedef struct ponto{
	float x;
	float y;
}Pontos;

typedef struct quad{
	Pontos *ponto;
}Quadrado;

Quadrado *InitQuad(Pontos *p){
	
	//quadrado tem 4 pontos.
	p = (Pontos*) malloc (4* sizeof(Pontos));
	
	p[0].x = -0.5;
	p[0].y = -0.5;
	//printf("%f %f", p[0].x, p[0].y);			
	
	p[1].x =  0.5;
	p[1].y = -0.5;	
	//printf("%f %f", p[1].x, p[1].y);
	
	p[2].x =  0.5;
	p[2].y =  0.5;
	//printf("%f %f", p[2].x, p[2].y);
	
	p[3].x = -0.5;
	p[3].y =  0.5;
	//printf("%f %f", p[3].x, p[3].y);
	
	Quadrado *q = (Quadrado*) malloc (sizeof(Quadrado));
	q->ponto = p;
	
	return q;  
}

Quadrado** alocaMat(Quadrado *quad , Quadrado **Mat){
   Mat = (Quadrado **) malloc (tam * sizeof (Quadrado*));
   for (int i = 0; i < tam; ++i)
   	 	Mat[i] =(Quadrado *) malloc (tam * sizeof (Quadrado));
   	 	
   	for(int l = 0; l<tam; l++){
		for(int c = 0; c< tam; c++){
			Mat[l][c].ponto = quad->ponto;
			//printf("%f %f ", Mat[l][c].ponto[0].x, Mat[l][c].ponto[0].y);				
		}
	}
	
	return Mat;
}

Quadrado ** preencheMat(Quadrado **M, Pontos *p){
	double dist = pow(pow(abs(p[0].x - p[1].y),2) + abs(pow(abs(p[0].y - p[1].y),2)),1/2);

		for(int l = 0; l<tam; l++){
			for(int c = 0; c< tam; c++){
					M[l][c].ponto[0].x *= (dist*l);
					M[l][c].ponto[0].y *= (dist*l);
					printf("%f %f \t", M[l][c].ponto[0].x, M[l][c].ponto[0].y);				
					
					M[l][c].ponto[1].x *= (dist*l);
					M[l][c].ponto[1].y *= (dist*l);
					printf("%f %f\t", M[l][c].ponto[1].x, M[l][c].ponto[1].y);				
					
					M[l][c].ponto[2].x *= (dist*1);
					M[l][c].ponto[2].y *= (dist*1);
					printf("%f %f\t", M[l][c].ponto[2].x, M[l][c].ponto[2].y);				
					
					M[l][c].ponto[3].x *= (dist*1);
					M[l][c].ponto[3].y *= (dist*1);
					printf("%f %f\n", M[l][c].ponto[3].x, M[l][c].ponto[3].y);						
			}
		}
	return M;
}

void Desenha(void){
	//glClearColor(1,1,1,0);
	//glClear(GL_COLOR_BUFFER_BIT);	
	 
	 Pontos *p;
	 Quadrado *quad;
	 Quadrado **Mat;
	 
	 quad = InitQuad(p);
	//printf("%f %f", quad->ponto[0].x, quad->ponto[0].y);
	 
	 Mat = alocaMat(quad,Mat);
	 //printf("%f", dist);
	 
	 
	 Mat = preencheMat(Mat,p);
	  
	//glBegin(GL_QUADS);
//	glFlush(); //  força as execuções do GL em um tempo finito pra um buffer
//	glutSwapBuffers(); // pra mais de um buffer
}

void Teclado (unsigned char key, int x, int y){
		
	switch(key){
		case 27 :
			exit(0);
			break;
			
		case 'a':
			glutFullScreen();
			break;
		case 'A':
			glutReshapeWindow(x,y);	
		
		case 'w':
			glColor3f(1,1,1);
			glPushAttrib(GL_CURRENT_BIT);
			//glPopAttrib();
			break;		
	}
	
}

void Inicializa(void){
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-1,1,-1,1);// posição do desenho na tela, centro no caso
	glMatrixMode(GL_MODELVIEW);
}

void Tela(void){
	glutInitWindowPosition(100,100);
	glutInitWindowSize(600,600);
	glutCreateWindow("Primeiro Programa");
}

int main(int argc, char *argv[]){
	
	//glutInit(&argc,argv);
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	//Tela();
	
	//glutDisplayFunc(Desenha);
	
	//glutKeyboardFunc(Teclado);

	//Inicializa();
	
	//glutMainLoop();
	Desenha();
	
	return 0;
}

