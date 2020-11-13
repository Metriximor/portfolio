#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _USE_MATH_DEFINES

#include <math.h>
#include <time.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else

#include <GL/glut.h>

#endif

#define RAD(x)          (M_PI*(x)/180)
#define GRAUS(x)        (180*(x)/M_PI)

#define DEBUG 1

#define DELAY_MOVIMENTO        20
#define RAIO_ROTACAO            20

#define LARGURA_BASE            4
#define COMPRIMENTO_BASE        7
#define ALTURA_BASE            1

#define LARGURA_TORRE        2
#define COMPRIMENTO_TORRE    2
#define ALTURA_TORRE            0.5

#define COMPRIMENTO_CANHAO    4
#define RAIO_CANHAO            0.2

#define VELOCIDADE_MAXIMA        50
#define ROTACAO_MAXIMA_RODAS    35

/* VARIAVEIS GLOBAIS */

typedef struct {
	GLboolean q, a, z, x, up, down, left, right;
} Teclas;

typedef struct {
	GLfloat x, y, z;
} Pos;

typedef struct {
	Pos eye, center, up;
	GLfloat fov;
} Camera;


typedef struct {
	GLboolean doubleBuffer;
	GLint delayMovimento;
	Teclas teclas;
	GLuint menu_id;
	GLboolean menuActivo;
	Camera camera;
	GLboolean debug;
	GLboolean ortho;
} Estado;

typedef struct {
	GLfloat x, y;
	GLint pontuacao;
} Raquete;

typedef struct {
	GLfloat x, y;
	GLfloat velocidade;
	GLfloat direccao;
	GLfloat direccaoRodas;
	GLfloat angTorre;
	GLfloat angCanhao;
} Tanque;

typedef struct {
	Tanque tanque;
	GLboolean parado;
} Modelo;

Estado estado;
Modelo modelo;

void inicia_modelo() {
	modelo.tanque.x = 20;
	modelo.tanque.y = 0;
	modelo.tanque.velocidade = 0;
	modelo.tanque.direccao = 0;
	modelo.tanque.direccaoRodas = 0;
	modelo.tanque.angTorre = 0;
	modelo.tanque.angCanhao = 0;

}

/* Inicialização do ambiente OPENGL */
void Init(void) {

	srand((unsigned) time(NULL));

	modelo.parado = GL_FALSE;

	estado.debug = DEBUG;
	estado.menuActivo = GL_FALSE;
	estado.delayMovimento = DELAY_MOVIMENTO;
	estado.camera.eye.x = 40;
	estado.camera.eye.y = 40;
	estado.camera.eye.z = 40;
	estado.camera.center.x = 0;
	estado.camera.center.y = 0;
	estado.camera.center.z = 0;
	estado.camera.up.x = 0;
	estado.camera.up.y = 0;
	estado.camera.up.z = 1;
	estado.ortho = GL_TRUE;
	estado.camera.fov = 60;

	estado.teclas.a = estado.teclas.q = estado.teclas.z = estado.teclas.x = \
  estado.teclas.up = estado.teclas.down = estado.teclas.left = estado.teclas.right = GL_FALSE;

	inicia_modelo();

	glClearColor(0.0, 0.0, 0.0, 0.0);

	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	//glutIgnoreKeyRepeat(GL_TRUE);

}

/*******************************
***   funcoes ajuda   		 ***
*******************************/

GLboolean tanqueEstaAMexer(Modelo modelo) {
	if (modelo.tanque.velocidade != 0) {
		return GL_TRUE;
	}
	return GL_FALSE;
}

/**************************************
***  callbacks de janela/desenho    ***
**************************************/

// CALLBACK PARA REDIMENSIONAR JANELA

void Reshape(int width, int height) {
	// glViewport(botom, left, width, height)
	// define parte da janela a ser utilizada pelo OpenGL

	glViewport(0, 0, (GLint) width, (GLint) height);


	// Matriz Projeccao
	// Matriz onde se define como o mundo e apresentado na janela
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// gluOrtho2D(left,right,bottom,top);
	// projeccao ortogonal 2D, com profundidade (Z) entre -1 e 1
	if (estado.debug)
		printf("Reshape %s\n", (estado.ortho) ? "ORTHO" : "PERSPECTIVE");

	if (estado.ortho) {
		if (width < height)
			glOrtho(-20, 20, -20 * (GLdouble) height / width, 20 * (GLdouble) height / width, -100, 100);
		else
			glOrtho(-20 * (GLdouble) width / height, 20 * (GLdouble) width / height, -20, 20, -100, 100);
	} else
		gluPerspective(estado.camera.fov, (GLfloat) width / height, 1, 100);

	// Matriz Modelview
	// Matriz onde são realizadas as tranformacoes dos modelos desenhados
	glMatrixMode(GL_MODELVIEW);
}


void desenhaPoligono(GLfloat a[], GLfloat b[], GLfloat c[], GLfloat d[], GLfloat cor[]) {

	glBegin(GL_POLYGON);
	glColor3fv(cor);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glVertex3fv(d);
	glEnd();
}


void desenhaCubo() {
	GLfloat vertices[][3] = {{-0.5, -0.5, -0.5},
							 {0.5,  -0.5, -0.5},
							 {0.5,  0.5,  -0.5},
							 {-0.5, 0.5,  -0.5},
							 {-0.5, -0.5, 0.5},
							 {0.5,  -0.5, 0.5},
							 {0.5,  0.5,  0.5},
							 {-0.5, 0.5,  0.5}};

	GLfloat cores[][3] = {{0.0, 1.0, 1.0},
						  {1.0, 0.0, 0.0},
						  {1.0, 1.0, 0.0},
						  {0.0, 1.0, 0.0},
						  {1.0, 0.0, 1.0},
						  {0.0, 0.0, 1.0},
						  {1.0, 1.0, 1.0}};

	desenhaPoligono(vertices[1], vertices[0], vertices[3], vertices[2], cores[0]);
	desenhaPoligono(vertices[2], vertices[3], vertices[7], vertices[6], cores[1]);
	desenhaPoligono(vertices[3], vertices[0], vertices[4], vertices[7], cores[2]);
	desenhaPoligono(vertices[6], vertices[5], vertices[1], vertices[2], cores[3]);
	desenhaPoligono(vertices[4], vertices[5], vertices[6], vertices[7], cores[4]);
	desenhaPoligono(vertices[5], vertices[4], vertices[0], vertices[1], cores[5]);
}


void strokeString(const char *str, double x, double y, double z, double s) {
	int i, n;

	n = strlen(str);
	glPushMatrix();
	glColor3d(0.0, 0.0, 0.0);
	glTranslated(x, y, z);
	glScaled(s, s, s);
	for (i = 0; i < n; i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, (int) str[i]);

	glPopMatrix();

}

void bitmapString(const char *str, double x, double y) {
	int i, n;

	// fonte pode ser:
	// GLUT_BITMAP_8_BY_13
	// GLUT_BITMAP_9_BY_15
	// GLUT_BITMAP_TIMES_ROMAN_10
	// GLUT_BITMAP_TIMES_ROMAN_24
	// GLUT_BITMAP_HELVETICA_10
	// GLUT_BITMAP_HELVETICA_12
	// GLUT_BITMAP_HELVETICA_18
	//
	// int glutBitmapWidth  	(	void *font , int character);
	// devolve a largura de um carácter
	//
	// int glutBitmapLength 	(	void *font , const unsigned char *string );
	// devolve a largura de uma string (soma da largura de todos os caracteres)

	n = strlen(str);
	glRasterPos2d(x, y);
	for (i = 0; i < n; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, (int) str[i]);
}

void bitmapCenterString(const char *str, double x, double y) {
	int i, n;

	n = strlen(str);
	glRasterPos2d(x - glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (const unsigned char *) str) * 0.5, y);
	for (i = 0; i < n; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, (int) str[i]);
}


// ... definicao das rotinas auxiliares de desenho ...


void desenhaTanque(Tanque t) {
	glPushMatrix();
	{
		//Posiciona o tanque no sitio correto
		glTranslatef(t.x, t.y, 0);
		if (tanqueEstaAMexer(modelo)) {
			glRotatef(modelo.tanque.velocidade / 10, 1, 0, 0);
			glRotatef(modelo.tanque.direccaoRodas / 10, 0, 1, 0);
		}
		//Desenha o corpo do tanque
		glPushMatrix();
		{
			glScalef(LARGURA_BASE, COMPRIMENTO_BASE, ALTURA_BASE);
			desenhaCubo();
		}
		glPopMatrix();
		//Cilindros de rotação
		glPushMatrix();
		{
			GLUquadric *quad;
			quad = gluNewQuadric();
			gluQuadricDrawStyle(quad, GLU_FILL);
			gluCylinder(quad, ALTURA_BASE / 2.0, ALTURA_BASE / 2.0, COMPRIMENTO_BASE, 20, 1);
		}
		glPopMatrix();
		//Desenha a torre do tanque
		glPushMatrix();
		{
			glTranslatef(0, 0, ALTURA_BASE);
			glRotatef(t.angTorre, 0, 0, 1);
			glPushMatrix();
			{
				glScalef(LARGURA_TORRE, COMPRIMENTO_TORRE, ALTURA_TORRE);
				desenhaCubo();
			}
			glPopMatrix();
			glRotatef(t.angCanhao, 1, 0, 0);
			glPushMatrix();
			{
				glScalef(RAIO_CANHAO, COMPRIMENTO_CANHAO, RAIO_CANHAO);
				desenhaCubo();
			}
			glPopMatrix();
		}
		glPopMatrix();
	}
	glPopMatrix();
}

void desenhaChao(GLfloat dimensao) {

	glBegin(GL_POLYGON);
	glVertex3f(dimensao, dimensao, 0);
	glVertex3f(-dimensao, dimensao, 0);
	glVertex3f(-dimensao, -dimensao, 0);
	glVertex3f(dimensao, -dimensao, 0);
	glEnd();

}

// Callback de desenho

void Draw(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(estado.camera.eye.x, estado.camera.eye.y, estado.camera.eye.z, \
            estado.camera.center.x, estado.camera.center.y, estado.camera.center.z, \
            estado.camera.up.x, estado.camera.up.y, estado.camera.up.z);

	// ... chamada das rotinas auxiliares de desenho ...


	glColor3f(0.5f, 0.5f, 0.5f);
	desenhaChao(RAIO_ROTACAO + 5);

	glPushMatrix();
	//....
	desenhaTanque(modelo.tanque);

	glPopMatrix();

	glFlush();
	if (estado.doubleBuffer)
		glutSwapBuffers();
}

/*******************************
***   callbacks timer/idle   ***
*******************************/

void Timer(int value) {
	glutTimerFunc(estado.delayMovimento, Timer, 0);
	// ... accoes do temporizador ...

	if (estado.menuActivo || modelo.parado) // sair em caso de o jogo estar parado ou menu estar activo
		return;

	if (estado.teclas.z && modelo.tanque.angTorre >= -180) {
		modelo.tanque.angTorre -= 1;
	}

	if (estado.teclas.x && modelo.tanque.angTorre <= 180) {
		modelo.tanque.angTorre += 1;
	}

	if (estado.teclas.a && modelo.tanque.angCanhao >= 0) {
		modelo.tanque.angCanhao -= 1;
	}

	if (estado.teclas.q && modelo.tanque.angCanhao <= RAIO_ROTACAO) {
		modelo.tanque.angCanhao += 1;
	}

	if (estado.teclas.up && modelo.tanque.velocidade <= VELOCIDADE_MAXIMA) {
		modelo.tanque.velocidade += 1;
	}

	if (estado.teclas.down && modelo.tanque.velocidade >= -VELOCIDADE_MAXIMA / 2.0) {
		modelo.tanque.velocidade -= 1;
	}

	if (estado.teclas.left && tanqueEstaAMexer(modelo) >= -ROTACAO_MAXIMA_RODAS) {
		modelo.tanque.direccaoRodas -= 1;
	}

	if (estado.teclas.right && tanqueEstaAMexer(modelo) <= ROTACAO_MAXIMA_RODAS) {
		modelo.tanque.direccaoRodas += 1;
	}

	modelo.tanque.x += modelo.tanque.velocidade;
	modelo.tanque.velocidade -= 0.1;
	modelo.tanque.direccao += modelo.tanque.direccaoRodas / 3;

	// redesenhar o ecra
	glutPostRedisplay();
}


void imprime_ajuda(void) {
	printf("\n\nDesenho de um quadrado\n");
	printf("h,H - Ajuda \n");
	printf("z,Z - Roda torre para a esquerda\n");
	printf("x,X - Roda torre para a direita\n");
	printf("q,Q - Levantar canhao\n");
	printf("a,A - Baixar canhao\n");
	printf("i,I - Reinicia modelo\n");
	printf("o,O - Alterna entre projecãoo Ortografica e Perspectiva\n");
	printf("f,F - Poligono Fill \n");
	printf("l,L - Poligono Line \n");
	printf("p,P - Poligono Point \n");
	printf("s,S - Inicia/para movimento\n");
	printf("ESC - Sair\n");
}

/*******************************
***  callbacks de teclado    ***
*******************************/

// Callback para interaccao via teclado (carregar na tecla)

void Key(unsigned char key, int x, int y) {
	switch (key) {

		case 27:
			exit(1);
			// ... accoes sobre outras teclas ...

		case 'h' :
		case 'H' :
			imprime_ajuda();
			break;
		case 'i' :
		case 'I' :
			inicia_modelo();
			break;
		case 'o' :
		case 'O' :
			estado.ortho = !estado.ortho;
			Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
			break;
		case 'Q' :
		case 'q' :
			estado.teclas.q = GL_TRUE;
			break;
		case 'A' :
		case 'a' :
			estado.teclas.a = GL_TRUE;
			break;
		case 'Z' :
		case 'z' :
			estado.teclas.z = GL_TRUE;
			break;
		case 'X' :
		case 'x' :
			estado.teclas.x = GL_TRUE;
			break;
		case 'D' :
		case 'd' :
			estado.debug = !estado.debug;
			if (estado.menuActivo || modelo.parado)
				glutPostRedisplay();
			printf("DEBUG is %s\n", (estado.debug) ? "ON" : "OFF");
			break;
		case 'f' :
		case 'F' :
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			break;
		case 'p' :
		case 'P' :
			glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
			break;
		case 'l' :
		case 'L' :
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			break;

			/* case 's' :
			 case 'S' :
						modelo.parado=!modelo.parado;
					break;*/


	}

	if (estado.debug)
		printf("Carregou na tecla %c\n", key);

}

// Callback para interaccao via teclado (largar a tecla)

void KeyUp(unsigned char key, int x, int y) {
	switch (key) {
		// ... accoes sobre largar teclas ...
		case 'q':
		case 'Q':
			estado.teclas.q = GL_FALSE;
			break;
		case 'a':
		case 'A':
			estado.teclas.a = GL_FALSE;
			break;
		case 'z':
		case 'Z':
			estado.teclas.z = GL_FALSE;
			break;
		case 'x':
		case 'X':
			estado.teclas.x = GL_FALSE;
			break;
	}

	if (estado.debug)
		printf("Largou a tecla %c\n", key);
}

// Callback para interaccao via teclas especiais  (carregar na tecla)

void SpecialKey(int key, int x, int y) {
	// ... accoes sobre outras teclas especiais ...
	//    GLUT_KEY_F1 ... GLUT_KEY_F12
	//    GLUT_KEY_UP
	//    GLUT_KEY_DOWN
	//    GLUT_KEY_LEFT
	//    GLUT_KEY_RIGHT
	//    GLUT_KEY_PAGE_UP
	//    GLUT_KEY_PAGE_DOWN
	//    GLUT_KEY_HOME
	//    GLUT_KEY_END
	//    GLUT_KEY_INSERT

	switch (key) {
		case GLUT_KEY_UP:
			estado.teclas.up = GL_TRUE;
			break;
		case GLUT_KEY_DOWN:
			estado.teclas.down = GL_TRUE;
			break;
		case GLUT_KEY_LEFT:
			estado.teclas.left = GL_TRUE;
			break;
		case GLUT_KEY_RIGHT:
			estado.teclas.right = GL_TRUE;
			break;
			// redesenhar o ecra
			//glutPostRedisplay();
	}


	if (estado.debug)
		printf("Carregou na tecla especial %d\n", key);
}

// Callback para interaccao via teclas especiais (largar na tecla)

void SpecialKeyUp(int key, int x, int y) {
	switch (key) {
		case GLUT_KEY_UP:
			estado.teclas.up = GL_FALSE;
			break;
		case GLUT_KEY_DOWN:
			estado.teclas.down = GL_FALSE;
			break;
		case GLUT_KEY_LEFT:
			estado.teclas.left = GL_FALSE;
			break;
		case GLUT_KEY_RIGHT:
			estado.teclas.right = GL_FALSE;
			break;
	}
	if (estado.debug)
		printf("Largou a tecla especial %d\n", key);

}

int main(int argc, char **argv) {
	char str[] = " makefile MAKEFILE Makefile ";
	estado.doubleBuffer = 1;

	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(((estado.doubleBuffer) ? GLUT_DOUBLE : GLUT_SINGLE) | GLUT_RGB | GLUT_DEPTH);
	if (glutCreateWindow("Exemplo") == GL_FALSE)
		exit(1);

	Init();

	imprime_ajuda();

// Registar callbacks do GLUT

	// callbacks de janelas/desenho
	glutReshapeFunc(Reshape);
	glutDisplayFunc(Draw);

	// Callbacks de teclado
	glutKeyboardFunc(Key);
	glutKeyboardUpFunc(KeyUp);
	glutSpecialFunc(SpecialKey);
	glutSpecialUpFunc(SpecialKeyUp);

	// callbacks timer/idle
	glutTimerFunc(estado.delayMovimento, Timer, 0);

	// COMECAR...
	glutMainLoop();
	return 0;
}
