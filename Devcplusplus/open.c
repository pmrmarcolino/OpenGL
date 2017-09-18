#include "open.h"

Quadrado *InitQuad(Pontos *p){
	
	//quadrado tem 4 pontos.
	p = (Pontos*) malloc (4* sizeof(Pontos));
	
	p[0].x = -0.5;
	p[0].y = -0.5;		
	
	p[1].x =  0.5;
	p[1].y = -0.5;	
		
	p[2].x =  0.5;
	p[2].y =  0.5;
	
	p[3].x = -0.5;
	p[3].y =  0.5;
	
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
				printf("%d quadrado\n\n",l+c);
				
					M[l][c].ponto[0].x += (dist*l);
					M[l][c].ponto[0].y += (dist*l);
					printf("1:%f %f \t", M[l][c].ponto[0].x, M[l][c].ponto[0].y);				
					
					M[l][c].ponto[1].x += (dist*l);
					M[l][c].ponto[1].y += (dist*l);
					printf("2:%f %f\t", M[l][c].ponto[1].x, M[l][c].ponto[1].y);				
					
					M[l][c].ponto[2].x += (dist*c);
					M[l][c].ponto[2].y += (dist*c);
					printf("3:%f %f\t", M[l][c].ponto[2].x, M[l][c].ponto[2].y);				
					
					M[l][c].ponto[3].x += (dist*c);
					M[l][c].ponto[3].y += (dist*c);
					printf("4:%f %f\n", M[l][c].ponto[3].x, M[l][c].ponto[3].y);						
			}
		}
	return M;
}

void Desenha(void){	
	 
	 Pontos *p;
	 Quadrado *quad;
	 Quadrado ** Mat;
	 
	 quad = InitQuad(p);
	 
	 Mat = alocaMat(quad,Mat);
	 	 
	 Mat = preencheMat(Mat,p);

	glClearColor(1,1,1,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	glBegin(GL_QUAD_STRIP);
		for (int i = 0; i<tam; i++){
			for(int j =0; j<tam;j++ ){
				glVertex2f(Mat[i][j].ponto[0].x, Mat[i][j].ponto[0].y);
				glVertex2f(Mat[i][j].ponto[1].x, Mat[i][j].ponto[1].y);
				glVertex2f(Mat[i][j].ponto[2].x, Mat[i][j].ponto[2].y);
				glVertex2f(Mat[i][j].ponto[3].x, Mat[i][j].ponto[3].y);
			}
		}
	glEnd();
	glFlush(); //  for�a as execu��es do GL em um tempo finito pra um buffer
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
	gluOrtho2D(-1,1,-1,1);// posi��o do desenho na tela, centro no caso
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

