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

#define DEBUG               0
#define LARGURA_CAMPO       400
#define ALTURA_CAMPO        200
#define LARGURA_RAQUETES    10
#define ALTURA_RAQUETES     50
#define LINHA_SERVICO       50
#define VELOCIDADE_BOLA     8
#define VELOCIDADE_RAQUETES 15
#define TAMANHO_BOLA        10
#define DELAY_MOVIMENTO     30
#define DELAY_TECLAS        20

/* VARIAVEIS GLOBAIS */

typedef struct {
    GLboolean q;
    GLboolean a;
    GLboolean p;
    GLboolean l;
} Teclas;

typedef struct {
    GLboolean doubleBuffer;
    GLboolean menuActivo;
    GLboolean debug;
    Teclas teclas;
    GLint delayMovimento;
    GLint delayTeclas;
    GLuint menu_vel_bola_id;
    GLuint menu_tam_bola_id;
    GLuint menu_vel_raq_id;
    GLuint menu_tam_raq_id;
    GLuint menu_id;
} Estado;

typedef struct {
    GLint pontuacao;
    GLfloat x;
    GLfloat y;
} Raquete;

typedef struct {
    GLint velocidade;
    GLint tamanho;
    GLfloat x;
    GLfloat y;
    GLfloat direccao;   //Em radianos
} Bola;

typedef struct {
    Raquete jogador1;
    Raquete jogador2;
    Bola bola;
    GLint alturaRaquetes;
    GLint velocidadeRaquetes;
    GLint servico;
    GLboolean parado;
} Modelo;

Estado estado;
Modelo modelo;

void inicia_jogo() {

    modelo.servico = (modelo.servico == 2) ? 1 : 2;

    modelo.jogador1.x = LINHA_SERVICO + LARGURA_RAQUETES * .5;
    modelo.jogador2.x = LARGURA_CAMPO - (LINHA_SERVICO + LARGURA_RAQUETES * .5);
    modelo.jogador1.y = modelo.jogador2.y = ALTURA_CAMPO * .5;
    modelo.bola.x = LARGURA_CAMPO * .5;
    modelo.bola.y = ALTURA_CAMPO * .5;

    modelo.bola.direccao = RAD(rand() % 120 - 60.0);
    if (modelo.servico == 2)
        modelo.bola.direccao = M_PI - modelo.bola.direccao;

    if (modelo.bola.direccao < 0)
        modelo.bola.direccao += 2 * M_PI;

}

/* Inicialização do ambiente OPENGL */
void Init() {

    srand((unsigned) time(NULL));

    modelo.bola.velocidade = VELOCIDADE_BOLA;
    modelo.bola.tamanho = TAMANHO_BOLA;
    modelo.alturaRaquetes = ALTURA_RAQUETES;
    modelo.velocidadeRaquetes = VELOCIDADE_RAQUETES;
    modelo.servico = 2;
    modelo.jogador1.pontuacao = 0;
    modelo.jogador2.pontuacao = 0;
    modelo.parado = GL_FALSE;

    estado.menuActivo = GL_FALSE;
    estado.delayMovimento = DELAY_MOVIMENTO;
    estado.delayTeclas = DELAY_TECLAS;

    estado.teclas.a = estado.teclas.q = estado.teclas.l = estado.teclas.p = GL_FALSE;

    inicia_jogo();

    glClearColor(0.0, 0.0, 0.0, 0.0);

    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);

    glutIgnoreKeyRepeat(GL_TRUE);

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
    gluOrtho2D(0, LARGURA_CAMPO, 0, ALTURA_CAMPO);

    // Matriz Modelview
    // Matriz onde são realizadas as tranformacoes dos modelos desenhados
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void strokeString(const char *str, double x, double y, double z, double s) {
    int i, n;

    n = (int) strlen(str);
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

    n = (int) strlen(str);
    glRasterPos2d(x, y);
    for (i = 0; i < n; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, (int) str[i]);
}

void bitmapCenterString(const char *str, double x, double y) {
    int i, n;

    n = (int) strlen(str);
    glRasterPos2d(x - glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (const unsigned char *) str) * 0.5, y);
    for (i = 0; i < n; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, (int) str[i]);
}


void desenha_campo(int p1, int p2) {
    char str[255];

    glLineWidth(3);
    glLineStipple(2, 0xFF00);

    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(LARGURA_CAMPO * .5, 0);
    glVertex2f(LARGURA_CAMPO * .5, ALTURA_CAMPO);
    glEnd();
    glDisable(GL_LINE_STIPPLE);

    sprintf_s(str, 255, "%d", p1);
    bitmapString(str, LARGURA_CAMPO * .4, ALTURA_CAMPO * .9);
    sprintf_s(str, 255, "%d", p2);
    bitmapString(str, LARGURA_CAMPO * .6, ALTURA_CAMPO * .9);

    if (estado.debug) {
        sprintf_s(str, 255, "ang:%.1f*PI\n x:%.1f\n y:%.1f ", modelo.bola.direccao / M_PI, modelo.bola.x,
                  modelo.bola.y);
        bitmapCenterString(str, LARGURA_CAMPO * .5, ALTURA_CAMPO * .1);
    }

}


void desenha_raquete(Raquete raq) {
    glBegin(GL_POLYGON);
    glVertex2f(raq.x - LARGURA_RAQUETES * .5, raq.y - modelo.alturaRaquetes * .5);
    glVertex2f(raq.x + LARGURA_RAQUETES * .5, raq.y - modelo.alturaRaquetes * .5);
    glVertex2f(raq.x + LARGURA_RAQUETES * .5, raq.y + modelo.alturaRaquetes * .5);
    glVertex2f(raq.x - LARGURA_RAQUETES * .5, raq.y + modelo.alturaRaquetes * .5);
    glEnd();
}


void desenha_bola(Bola bola) {
    GLint i;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(bola.x, bola.y);
    for (i = 0; i <= 16; i++)
        glVertex2f(bola.x + bola.tamanho / 2 * cos((double) i * 2 * M_PI / 16),
                   bola.y + bola.tamanho / 2 * sin((double) i * 2 * M_PI / 16));
    glEnd();
}


// ... definicao das rotinas auxiliares de desenho ...

// Callback de desenho

void Draw(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // ... chamada das rotinas auxiliares de desenho ...

    desenha_campo(modelo.jogador1.pontuacao, modelo.jogador2.pontuacao);

    glColor3f(1.0f, 0.0f, 0.0f);
    desenha_raquete(modelo.jogador1);

    glColor3f(0.0f, 0.0f, 1.0f);
    desenha_raquete(modelo.jogador2);

    glColor3f(1.0f, 1.0f, 0.0f);
    desenha_bola(modelo.bola);

    if (modelo.parado) {
        glColor3f(0.7, 0.7, 0.7);
        bitmapCenterString("Jogo Parado. Use o menu para continuar.", LARGURA_CAMPO * .5, ALTURA_CAMPO * .5);
    }


    glFlush();
    if (estado.doubleBuffer)
        glutSwapBuffers();
}

/**
 * @param direcao EM RADIANOS
 * @return a direção invertida no eixo X
 */
GLfloat flip_x(GLfloat direcao) {
    if(direcao < M_PI) {
        return M_PI - direcao;
    } else {
        return 2*M_PI - direcao + M_PI;
    }
}

GLfloat flip_y(GLfloat direcao) {
    return 2*M_PI - direcao;
}

GLboolean equals(GLfloat a, GLfloat b, GLfloat delta) {
    return fabsf(a - b) < delta;
}

void recentrar_bola() {
    modelo.bola.x = LARGURA_CAMPO / 2.0;
    modelo.bola.y = ALTURA_CAMPO / 2.0;
    modelo.bola.direccao = RAD(rand() % 120 - 60.0);
    if (modelo.servico == 2)
        modelo.bola.direccao = M_PI - modelo.bola.direccao;

    if (modelo.bola.direccao < 0)
        modelo.bola.direccao += 2 * M_PI;
}

/*******************************
***   callbacks timer/idle   ***
*******************************/

void Timer(int value) {
    glutTimerFunc(estado.delayMovimento, Timer, 0);
    // ... accoes do temporizador ...

    if (estado.menuActivo || modelo.parado) // sair em caso de o jogo estar parado ou menu estar activo
        return;

    // movimenta bola
    modelo.bola.x += modelo.bola.velocidade * cos(modelo.bola.direccao);
    modelo.bola.y += modelo.bola.velocidade * sin(modelo.bola.direccao);

    // testa fim de ponto
    if(modelo.bola.x >= LARGURA_CAMPO) {
        ++modelo.jogador1.pontuacao;
        recentrar_bola();
    }

    if(modelo.bola.x <= 0) {
        ++modelo.jogador2.pontuacao;
        recentrar_bola();
    }

    // testa colisão paredes
    if(modelo.bola.x >= LARGURA_CAMPO || modelo.bola.x <= 0) {
        modelo.bola.direccao = flip_x(modelo.bola.direccao);
    }

    double raio_bola = modelo.bola.tamanho/2.0;
    if(modelo.bola.y <= raio_bola || modelo.bola.y >= ALTURA_CAMPO - raio_bola) {
        modelo.bola.direccao = flip_y(modelo.bola.direccao);
    }

    // testa colisão raquete 1
    GLint meia_altura_raquetes = modelo.alturaRaquetes / 2;
    if(equals(modelo.bola.x, modelo.jogador1.x, LARGURA_RAQUETES)) {
        if(modelo.bola.y <= (modelo.jogador1.y + meia_altura_raquetes)
        && modelo.bola.y >= (modelo.jogador1.y - meia_altura_raquetes)) {
            modelo.bola.direccao = flip_x(modelo.bola.direccao);
            modelo.bola.x = modelo.jogador1.x + LARGURA_RAQUETES;
        }
    }

    // testa colisão raquete 2
    if(equals(modelo.bola.x, modelo.jogador2.x, LARGURA_RAQUETES)) {
        if(modelo.bola.y <= (modelo.jogador2.y + meia_altura_raquetes)
        && modelo.bola.y >= (modelo.jogador2.y - meia_altura_raquetes)) {
            modelo.bola.direccao = flip_x(modelo.bola.direccao);
            modelo.bola.x = modelo.jogador2.x - LARGURA_RAQUETES;
        }
    }

    // redesenhar o ecra
    glutPostRedisplay();
}


void TimerTeclas(int value) {
    glutTimerFunc(estado.delayTeclas, TimerTeclas, 0);
    // ... accoes das teclas ...

    if (estado.menuActivo || modelo.parado)
        return;

    if (estado.teclas.a /*&& condicao*/) {
        if (modelo.jogador1.y > (modelo.alturaRaquetes / 2.0)) {
            modelo.jogador1.y -= modelo.velocidadeRaquetes;
        }
    }
    if (estado.teclas.q /*&& condicao*/) {
        if (modelo.jogador1.y < ALTURA_CAMPO - (modelo.alturaRaquetes / 2.0)) {
            modelo.jogador1.y += modelo.velocidadeRaquetes;
        }
    }
    if (estado.teclas.l /*&& condicao*/) {
        if (modelo.jogador2.y > (modelo.alturaRaquetes / 2.0)) {
            modelo.jogador2.y -= modelo.velocidadeRaquetes;
        }
    }
    if (estado.teclas.p /*&& condicao*/) {
        if (modelo.jogador2.y < ALTURA_CAMPO - (modelo.alturaRaquetes / 2.0)) {
            modelo.jogador2.y += modelo.velocidadeRaquetes;
        }
    }

    // ´não necessita redesenhar o ecra, é feito no Timer de animação
}

void imprime_ajuda(void) {
    printf("\n\nDesenho de um quadrado\n");
    printf("h,H - Ajuda \n");
    printf("q,Q - Jogador 1 cima\n");
    printf("a,A - Jogador 1 baixo\n");
    printf("P,p - Jogador 2 cima\n");
    printf("L,l - Jogador 2 baixo\n");
    printf("D,d - Debug On/OFF\n");
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
            inicia_jogo();
            break;
        case 'Q' :
        case 'q' :
            estado.teclas.q = GL_TRUE;
            break;
        case 'A' :
        case 'a' :
            estado.teclas.a = GL_TRUE;
            break;
        case 'P' :
        case 'p' :
            estado.teclas.p = GL_TRUE;
            break;
        case 'L' :
        case 'l' :
            estado.teclas.l = GL_TRUE;
            break;
        case 'D' :
        case 'd' :
            estado.debug = !estado.debug;
            if (estado.menuActivo || modelo.parado)
                glutPostRedisplay();
            printf("DEBUG is %s\n", (estado.debug) ? "ON" : "OFF");
            break;

    }

    if (estado.debug)
        printf("Carregou na tecla %c\n", key);

}

// Callback para interaccao via teclado (largar a tecla)

void KeyUp(unsigned char key, int x, int y) {
    switch (key) {
        // ... accoes sobre largar teclas ...

        case 'Q' :
        case 'q' :
            estado.teclas.q = GL_FALSE;
            break;
        case 'A' :
        case 'a' :
            estado.teclas.a = GL_FALSE;
            break;
        case 'P' :
        case 'p' :
            estado.teclas.p = GL_FALSE;
            break;
        case 'L' :
        case 'l' :
            estado.teclas.l = GL_FALSE;
            break;

    }

    if (estado.debug)
        printf("Largou a tecla %c\n", key);
}

// Callback para interaccao via teclas especiais  (carregar na tecla)

/*void SpecialKey(int key, int x, int y)
{
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

  // redesenhar o ecra
  //glutPostRedisplay();
  }


  if(estado.debug)
    printf("Carregou na tecla especial %d\n",key);
}/*/

// Callback para interaccao via teclas especiais (largar na tecla)

/*void SpecialKeyUp(int key, int x, int y)
{

  if(estado.debug)
    printf("Largou a tecla especial %d\n",key);

}/*/

void MenuStatus(int status, int x, int y) {
    /* status => GLUT_MENU_IN_USE, GLUT_MENU_NOT_IN_USE
       x,y    => coordenadas do ponteiro quando se entra no menu
    */

    if (status == GLUT_MENU_IN_USE) {
        estado.menuActivo = GL_TRUE;
    } else {
        estado.menuActivo = GL_FALSE;

    }

    if (estado.debug)
        printf("MenuStatus status:%d coord:%d %d\n", status, x, y);

}

void menu(int opcao) {

    switch (opcao) {
        case 0 :
            exit(1);
            break;
            // velocidade bola
        case 1 :
            if (modelo.bola.velocidade > 2)
                modelo.bola.velocidade -= 2;
            break;
        case 2 :
            if (modelo.bola.velocidade < 16)
                modelo.bola.velocidade += 2;
            break;
            // tamanho bola
        case 3 :
            if (modelo.bola.tamanho > 5)
                modelo.bola.tamanho--;
            break;
        case 4 :
            if (modelo.bola.tamanho < 15)
                modelo.bola.tamanho++;
            break;
            // velocidade raquete
        case 5 :
            if (modelo.velocidadeRaquetes > 10)
                modelo.velocidadeRaquetes -= 5;
            break;
        case 6 :
            if (modelo.velocidadeRaquetes < 30)
                modelo.velocidadeRaquetes += 5;
            break;
            // tamanho raquete
        case 7 :
            if (modelo.alturaRaquetes > 30)
                modelo.alturaRaquetes -= 10;
            break;
        case 8 :
            if (modelo.velocidadeRaquetes < 100)
                modelo.alturaRaquetes += 10;
            break;
        case 9 :
            modelo.parado = !modelo.parado;
            if (modelo.parado) {
                glutChangeToMenuEntry(1, "Comecar", 9);
                glutPostRedisplay();
            } else {
                glutChangeToMenuEntry(1, "Parar", 9);
            }
            break;
    }

}

void cria_menu() {

    // funçoes de manipulação de menus
    // id=glutCreateMenu(menu)  - cria um menu tratado pela funcao menu e devolve o id
    // glutDestroyMenu(id)      - destroi o menu identificado por id
    // id=glutGetMenu()         - devolve o id do menu actual
    // glutSetMenu(id)          - torna actual o menu com o id
    //
    // glutAddMenuEntry("texto", valor) -  adiciona uma entrada ao menu actual
    // glutChangeToMenuEntry(item, "novo texto", novo_valor)
    //                                  -  altera a entrada item(1,2,3..) do menu actual
    // glutAddSubMenu("texto", id)      -  adiciona o submenu id ao menu actual
    // glutChangeToSubMenu(item, "novo texto", novo_id)
    //                                  -  altera a entrada submenu item(1,2,3..) do menu actual
    // glutRemoveMenuItem(item)         - apaga a entrada item(1,2,3...)
    //
    // glutAttachMenu(botao)            - associa o menu actual ao botao
    // glutDetachMenu(botao)            - desassocia o menu associado ao botao GLUT_RIGHT_BUTTON
    // botao = GLUT_LEFT_BUTTON, GLUT_MIDDLE_BUTTON ou GLUT_RIGHT_BUTTON

/* DEFINIR MENUS */
    estado.menu_vel_bola_id = glutCreateMenu(menu); // regista função que trata do menu
    glutAddMenuEntry("Diminuir", 1);
    glutAddMenuEntry("Aumentar", 2);

    estado.menu_tam_bola_id = glutCreateMenu(menu); // regista função que trata do menu
    glutAddMenuEntry("Diminuir", 3);
    glutAddMenuEntry("Aumentar", 4);

    estado.menu_vel_raq_id = glutCreateMenu(menu); // regista função que trata do menu
    glutAddMenuEntry("Diminuir", 5);
    glutAddMenuEntry("Aumentar", 6);

    estado.menu_tam_raq_id = glutCreateMenu(menu); // regista função que trata do menu
    glutAddMenuEntry("Diminuir", 7);
    glutAddMenuEntry("Aumentar", 8);

    estado.menu_id = glutCreateMenu(menu); // regista função que trata do menu
    glutAddMenuEntry("Parar", 9);

    // adicionar submenus
    glutAddSubMenu("Velocidade da bola", estado.menu_vel_bola_id);
    glutAddSubMenu("Tamanho da bola", estado.menu_tam_bola_id);
    glutAddSubMenu("Velocidade da raquete", estado.menu_vel_raq_id);
    glutAddSubMenu("Altura da raquete", estado.menu_tam_raq_id);

    glutAddMenuEntry("Sair", 0);

    glutAttachMenu(GLUT_RIGHT_BUTTON); // Agarrar menu actual ao botão

}


int main(int argc, char **argv) {
    estado.doubleBuffer = GL_TRUE;

    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(LARGURA_CAMPO, ALTURA_CAMPO);
    glutInitDisplayMode(((estado.doubleBuffer) ? GLUT_DOUBLE : GLUT_SINGLE) | GLUT_RGB);
    if (glutCreateWindow("Ping-Pong") == GL_FALSE)
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
    //glutSpecialFunc(SpecialKey);
    //glutSpecialUpFunc(SpecialKeyUp);

    // callbacks timer/idle
    glutTimerFunc(estado.delayMovimento, Timer, 0);
    glutTimerFunc(estado.delayTeclas, TimerTeclas, 0);

    //Menus
    cria_menu();
    glutMenuStatusFunc(MenuStatus);

    // COMECAR...
    glutMainLoop();

    return 0;
}
