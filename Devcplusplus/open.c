#include "open.h"

#define tam 1

Quadrado** alocaMat(Quadrado **Mat){
   Mat = (Quadrado **) malloc (tam * sizeof (Quadrado*));
   for (int i = 0; i < tam; ++i)
   	 	Mat[i] =(Quadrado *) malloc (tam * sizeof (Quadrado));

	for(int l = 0; l<tam; l++){
		for(int c = 0; c< tam; c++){
			Mat[l][c].ponto = (Pontos*) malloc (4* sizeof(Pontos));
			}
		}
   	
	return Mat;
}

Quadrado ** preencheMat(Quadrado **M){
	
	FILE *arq;
	char aux[3];
	arq = fopen("teste.txt", "rt");
	
	while(!feof(arq)){
	
		for(int l = 0; l<tam; l++){		
			for(int c = 0; c< tam; c++){
				
				printf("passei");
				fgets(aux, 3, arq);

				M[l][c].ponto->x = float(aux[0]);
				M[l][c].ponto->y = float(aux[1]);
				M[l][c].ponto->z = float(aux[2]);
				
				printf("x: %f y: %f z: %f", M[l][c].ponto->x, M[l][c].ponto->y, M[l][c].ponto->z);  	
			}				
		}
	}
	fclose(arq);
	
	return M;
}

void Desenha(void){	
	 Quadrado ** Mat;
	
		 
	 Mat = alocaMat(Mat);
	 	 
	 Mat = preencheMat(Mat);

	glClearColor(1,1,1,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	glBegin(GL_TRIANGLES);
		for (int i = 0; i<tam; i++){
			for(int j =0; j<tam;j++ ){
				glVertex3f(Mat[i][j].ponto->x, Mat[i][j].ponto->y,Mat[i][j].ponto->z);
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

