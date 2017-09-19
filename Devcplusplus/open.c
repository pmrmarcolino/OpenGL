#include "open.h"

#define tam 1

Pontos *InitQuad(Pontos *p){
	
	//quadrado tem 4 pontos.
	p = (Pontos*) malloc (4* sizeof(Pontos));
	
	p[0].x = -0.1f;
	p[0].y = -0.1f;		
	
	p[1].x =  0.1f;
	p[1].y = -0.1f;	
		
	p[2].x =  0.1f;
	p[2].y =  0.1f;
	
	p[3].x = -0.1f;
	p[3].y =  0.1f;

	
	return p;  
}

Quadrado** alocaMat(Quadrado *quad, Quadrado **Mat){
   Mat = (Quadrado **) malloc (tam * sizeof (Quadrado*));
   for (int i = 0; i < tam; ++i)
   	 	Mat[i] =(Quadrado *) malloc (tam * sizeof (Quadrado));

	for(int l = 0; l<tam; l++){
		for(int c = 0; c< tam; c++){
			Mat[l][c].ponto = quad->ponto;
			}
		}
   	
	return Mat;
}

Quadrado ** preencheMat(Quadrado **M, Pontos *p){
	float dist = pow(pow(abs(p[2].x - p[3].y),2) + abs(pow(abs(p[2].y - p[3].y),2)),1/2);
	int c;
		for(int l = 0; l<tam; l++){
			
			for(c = 0; c< tam; c++){
				printf("\n%d quadrado\n\n",c);
				
				if (c == 0 && l == 0){}		
				else{
					
					M[l][c].ponto[0].x = M[l][c-1].ponto[0].x + dist;
					M[l][c].ponto[0].y = M[l][c].ponto[0].y;				
					printf("x0: %f y0: %f \t", M[l][c].ponto[0].x, M[l][c].ponto[0].y);				
					
					M[l][c].ponto[1].x = M[l][c-1].ponto[1].x + dist;
					M[l][c].ponto[1].y = M[l][c].ponto[1].y;
					printf("x1: %f y0: %f\t", M[l][c].ponto[1].x,M[l][c].ponto[1].y);				
					
					M[l][c].ponto[2].x = M[l][c-1].ponto[2].x + dist;
					M[l][c].ponto[2].y = M[l][c].ponto[2].y;
					printf("x2: %f y0: %f\t", M[l][c].ponto[2].x, M[l][c].ponto[1].y);				
					
					M[l][c].ponto[3].x = M[l][c-1].ponto[3].x + dist;
					M[l][c].ponto[3].y = M[l][c].ponto[3].y;
					printf("x3: %f y0: %f\n", M[l][c].ponto[3].x, M[l][c].ponto[1].y);						
				}
			}
			if (!(c == 0 && l == 0)){
			
				M[l][c].ponto[0].y = M[l-1][c].ponto[0].y + dist;
				M[l][c].ponto[0].x = M[l][c].ponto[0].x;
				printf("y0: %f \t", M[l][c].ponto[0].y);	
				
				M[l][c].ponto[1].y = M[l-1][c].ponto[1].y + dist;
				M[l][c].ponto[1].x = M[l][c].ponto[1].x;
				printf("y1: %f \t", M[l][c].ponto[0].y);	
				
				M[l][c].ponto[2].y = M[l-1][c].ponto[2].y + dist;
				M[l][c].ponto[2].x = M[l][c].ponto[2].x;
				printf("y2: %f \t", M[l][c].ponto[0].y);	
				
				M[l][c].ponto[3].y = M[l-1][c].ponto[3].y + dist;
				M[l][c].ponto[3].x = M[l][c].ponto[3].x;
				printf("y3: %f \t", M[l][c].ponto[0].y);	
			}
		}
	return M;
}

void Desenha(void){	
	 
	 Pontos *p;
	 Quadrado *quad;
	 Quadrado ** Mat;
	 
	 p = InitQuad(p);
	 
	quad = (Quadrado*) malloc (sizeof(Quadrado));
	quad->ponto = p;
	 
	 Mat = alocaMat(quad,Mat);
	 	 
	 Mat = preencheMat(Mat,p);

	glClearColor(1,1,1,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	glBegin(GL_QUADS);
		for (int i = 0; i<tam; i++){
			for(int j =0; j<tam;j++ ){
				glVertex2f(Mat[i][j].ponto[0].x, Mat[i][j].ponto[0].y);
				glVertex2f(Mat[i][j].ponto[1].x, Mat[i][j].ponto[1].y);
				glVertex2f(Mat[i][j].ponto[2].x, Mat[i][j].ponto[2].y);
				glVertex2f(Mat[i][j].ponto[3].x, Mat[i][j].ponto[3].y);
			}
		}
	glEnd();
	glFlush(); //  força as execuções do GL em um tempo finito pra um buffer
	glutSwapBuffers(); // pra mais de um buffer
}

void Teclado (unsigned char key, int x, int y){
		
	switch(key){
		case 27 :
			exit(0);
			//liberaMatriz(Mat);
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
	glutInitWindowSize(1200,600);
	glutCreateWindow("Primeiro Programa");
}

void liberaMatriz(Quadrado ** Mat){
		for (int i = 0; i<tam; i++){
			for(int j =0; j<tam;j++ ){
				free(Mat[i][j].ponto);
			}
		}
		free(Mat);		
}
