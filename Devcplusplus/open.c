#include "open.h"

#define tam 1

Triangulo** alocaMat(Triangulo **Mat){
   Mat = (Triangulo **) malloc (tam * sizeof (Triangulo*));
   
   for (int i = 0; i < tam; ++i){
       for (int j; j <tam; j++){
   	 	   Mat[i][j].ponto =(Pontos*) malloc (sizeof(Pontos));
      }
	}
	return Mat;
}

void PreencheZero(Triangulo ** Mat){
 	for(int l = 0; l<tam; l++){
		for(int c = 0; c< tam ; c++){
			printf("x:%f y:%f z:%f\n", Mat[l][c].ponto->x, Mat[l][c].ponto->y ,Mat[l][c].ponto->z);
			
		}
	}
     
}


Triangulo ** preencheMat(Triangulo **M){
	
	FILE *arq;
	float x,y,z;
	arq = fopen("test.txt", "r");
	
	if (arq == NULL){
            printf("nao abriu");
    }
	else{
    		for(int l = 0; l < tam; l++){		
    			for(int c = 0; c < tam; c++){
    				
    				fscanf(arq,"%f %f %f\n", &M[l][c].ponto->x, &M[l][c].ponto->y, &M[l][c].ponto->z);		
    				printf("x: %f y: %f z: %f", M[l][c].ponto->x, M[l][c].ponto->y, M[l][c].ponto->z);  	
    			}				
    		}
    }
	fclose(arq);
	
	return M;
}

void Desenha(void){	
	 Triangulo ** Mat;
		 
	 Mat = alocaMat(Mat);
	 	 
	 Mat = preencheMat(Mat);

	PreencheZero(Mat);

	 glClearColor(1,1,1,0);
	 glClear(GL_COLOR_BUFFER_BIT);
	 glColor3f(1,0,0);
	 glBegin(GL_TRIANGLES);
	
	for (int i = 0; i<tam; i++){
	    for(int j =0; j<tam; j++ ){
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


