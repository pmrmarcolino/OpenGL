#include "open.h"

#define linha 6
#define coluna 5

Triangulo** alocaMat(Triangulo **Mat){
   Mat = (Triangulo **) malloc (linha * sizeof (Triangulo*));
   
    for (int j = 0; j < linha; j++)
   	 	Mat[j] = (Triangulo *) malloc (coluna * sizeof (Triangulo)); 
	
	for (int j = 0; j < linha; j++)
		for (int i = 0 ; i <coluna; i++ )
   	 	   Mat[j][i].ponto = (Pontos *) malloc (sizeof (Pontos)); 
	
	return Mat;
}

Triangulo ** preencheMat(Triangulo **M){
	
	FILE *arq;
	arq = fopen("test.txt", "r");
	
	if (arq == NULL){
            printf("nao abriu");
    }
	else{
    		for(int l = 0; l < linha; l++){		
    			for(int c = 0; c < coluna; c++){		
    				fscanf(arq,"%f, %f, %f\n", &M[l][c].ponto->x, &M[l][c].ponto->y, &M[l][c].ponto->z);		
				}				
    		}
    }
	fclose(arq);
	
	return M;
}

void imprimeMat (Triangulo ** Mat){

	for (int j = 0; j < linha; j++)
		for (int i = 0 ; i <coluna; i++ )
   	 	   printf("x: %f y: %f z: %f\n",Mat[j][i].ponto->x,Mat[j][i].ponto->y,Mat[j][i].ponto->z); 
	
}

void Desenha(void){	
	 Triangulo ** Mat;
		 
	 Mat = alocaMat(Mat);
	 	 
	 Mat = preencheMat(Mat);

	imprimeMat(Mat);
		
	 glClearColor(1,1,1,0);
	 glClear(GL_COLOR_BUFFER_BIT);
	 glColor3f(1,0,0);
	 
	 glutWireCube(50);
	
	for (int i = 0; i< linha; i++){
		glBegin(GL_QUADS);
			glNormal3f(Mat[i][0].ponto->x, Mat[i][0].ponto->y,Mat[i][0].ponto->z);	// Normal da face
			glVertex3f(Mat[i][1].ponto->x, Mat[i][1].ponto->y,Mat[i][1].ponto->z);
			glVertex3f(Mat[i][2].ponto->x, Mat[i][2].ponto->y,Mat[i][2].ponto->z);
			glVertex3f(Mat[i][3].ponto->x, Mat[i][3].ponto->y,Mat[i][3].ponto->z);
			glVertex3f(Mat[i][4].ponto->x, Mat[i][4].ponto->y,Mat[i][4].ponto->z);
		glEnd();
	}
		
	
	glFlush(); //  força as execuções do GL em um tempo finito pra um buffer
	glutSwapBuffers(); // pra mais de um buffer
}

void Teclado (unsigned char key, int x, int y){
		
	switch(key){
		case 27 :
			exit(0);
			break;
	}
}

void Inicializa(void){
	
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
 
  glOrtho(-65.0,65.0,-65.0,65.0,-400.0,400.0);
  
  glMatrixMode(GL_MODELVIEW);
  
  glLoadIdentity();
  gluLookAt(40,60,100,0,0,0,0,1,0);
}

void Tela(void){
	glutInitWindowPosition(100,100);
	glutInitWindowSize(1200,600);
	glutCreateWindow("Cube");
}


