#include "open.h"

int main(int argc, char *argv[]){
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	Tela();
	
	glutDisplayFunc(Desenha);
	
	glutKeyboardFunc(Teclado);

	Inicializa();
	
	glutMainLoop();
	
	return 0;
}

