#include "open.h"

int main(int argc, char *argv[]){
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	
	Tela();
	
	glutDisplayFunc(Desenha);
	
	glutKeyboardFunc(Teclado);
	
	glutKeyboardFunc(TeclasEspeciais);
	
	glutMouseFunc(GerenciaMouse);
	
	glutMouseFunc(GerenciaMovim);

	Inicializa();
	
	glutMainLoop();
	
	return 0;
}


