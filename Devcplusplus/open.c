#include "open.h"

#define linha 6
#define coluna 5
GLfloat angle, deslocamentoX, deslocamentoY, deslocamentoZ, fAspect;

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

/*void Anima(int value){
	if(++angulo > 360.f){
		angulo = 0.0f;
	}
	glutPostRedisplay();
	glutTimerFunc(60,Anima,1);
}*/

void GerenciaMouse(int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON)
		if(state == GLUT_DOWN)
			if (angle >= 10 ) angle-=5;
	if (button == GLUT_RIGHT_BUTTON)
		if(state == GLUT_DOWN)
			if(angle <= 130) angle +=5;
			
	Inicializa();
	glutPostRedisplay();
}


void Desenha(void){	
	 Triangulo ** Mat;
		 
	 Mat = alocaMat(Mat);
	 	 
	 Mat = preencheMat(Mat);

	imprimeMat(Mat);
		
	 glClearColor(1,1,1,0);
	 glClear(GL_COLOR_BUFFER_BIT);
	 glPushAttrib(GL_ALL_ATTRIB_BITS);
	 glEnable(GL_POLYGON_OFFSET_FILL); // para poder alterar o tipo de linha
	 glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	 //glutWireCube(50);
	
	
	glLineWidth(10);
	//glRotatef(angulo,0,1,0);

	for (int i = 0; i< linha; i++){
		glColor3f(0,0,0);
		glBegin(GL_QUADS);	
			glNormal3f(Mat[i][0].ponto->x, Mat[i][0].ponto->y,Mat[i][0].ponto->z);	// Normal da face
			glVertex3f(Mat[i][1].ponto->x, Mat[i][1].ponto->y,Mat[i][1].ponto->z);
			glVertex3f(Mat[i][2].ponto->x, Mat[i][2].ponto->y,Mat[i][2].ponto->z);
			glVertex3f(Mat[i][3].ponto->x, Mat[i][3].ponto->y,Mat[i][3].ponto->z);
			glVertex3f(Mat[i][4].ponto->x, Mat[i][4].ponto->y,Mat[i][4].ponto->z);
		glEnd();
	}

	
	glPopAttrib();
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
 
 
  gluPerspective(angle,fAspect,0.5,500);
  glOrtho(-65.0,65.0,-65.0,65.0,-400.0,400.0);
  //gluPerspective(60,fAspect,0.5,500); n funfou
  
  glMatrixMode(GL_MODELVIEW);
  
  glLoadIdentity();
  gluLookAt(50,60,150,0,0,0,0,1,0);
	
  //gluLookAt(0+deslocamentoX,0+deslocamentoY,150+deslocamentoZ,0+deslocamentoX,0+deslocamentoY,0+deslocamentoZ,0,1,0);


}

void TeclasEspeciais(unsigned char key, int x, int y){

	switch(key){
	
		case GLUT_KEY_UP:
			deslocamentoY -= 2;
			break;
		case GLUT_KEY_DOWN:
			deslocamentoX += 2;
			break;
		case GLUT_KEY_LEFT:
			deslocamentoX +=2;
			break;
		case GLUT_KEY_RIGHT:
			deslocamentoX -=2;
			break;
		case GLUT_KEY_PAGE_UP:
			deslocamentoZ -=2;
			break;
		case GLUT_KEY_PAGE_DOWN:
			deslocamentoZ +=2;
			break;
	}
	Inicializa();
	glutPostRedisplay();
}

void Tela(void){
	glutInitWindowPosition(100,100);
	glutInitWindowSize(1200,600);
	glutCreateWindow("Cube");
}


