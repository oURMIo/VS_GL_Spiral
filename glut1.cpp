#include "stdafx.h"    // подключение стандартного заголовочного файла (делается автоматически, не
#include "GL/glut.h"   // подключение графической библиотеки GLUT (Graphic Library Utility Tools)
#include <math.h>

void spiral(float x, float y, float rmax)
{
	static float start_angle = 0.0; 
	float angle = start_angle;
	float r = 0.0;
	glBegin(GL_LINE_STRIP);
	while (r < rmax)
		{
		
		glColor3f(1.0, r / 100.0, 1.0 - r / 100.0);
		glVertex2f(
			x + r * cos(angle)    + r*0.2 * sin(angle*10.0),
			y + r * sin(angle)    + r*0.2 * cos(angle*10.0));
		
		r += 0.05;
		angle += 0.01;
	}
	glEnd();

	start_angle += 0.001;
}


void spiral1(float x, float y, float rmax)
{
	static float start_angle = 0.0;
	float angle = start_angle;
	float r = 0.0;
	glBegin(GL_LINE_STRIP);
	while (r < rmax)
	{

		glColor3f(1.0, r / 100.0, 1.0 - r / 100.0);
		glVertex2f(
			x + r * cos(angle),
			y + r * sin(angle));

		r += 0.02;
		angle += 0.01;
	}
	glEnd();

	start_angle += 0.001;
}

void display()  /// Отрисовка кадра
{
	glClear(GL_COLOR_BUFFER_BIT); // очистка буфера экрана (служебное действие)
	glClearColor(0, 0, 0.2, 0);    // цвет фона 

	glBegin(GL_TRIANGLES);   // начало рисования отрезка
	glVertex3f(-10, -190, 0.0);     // перечисление вершин отрезка по одной
	glVertex3f(0.0, -200, 0.0);
	glVertex3f(10, -190, 0.0);
	glEnd();                  // конец рисования отрезка (и любой фигуры, начатой glBegin())

	spiral(0.0, 0.0, 150.0);
	spiral1(-150.0, -150.0, 50.0);
	 
	glFlush();               // отправка содержимого буфера на экран (служебное действие) 
	glFinish();              // завершение рисования кадра (служебное действие) 
} 

void reshape(int x, int y)   // Функция-обработчик изменения размера окна windows ("подгонка" системы координат
{
	int H = 500; // Height
	glViewport(0.0, 30, 600, H);
	// Обнуление матриц пересчёта координат
	glMatrixMode(GL_PROJECTION);  // активна матрица проекций
	glLoadIdentity();             // её обнуление  
	glMatrixMode(GL_MODELVIEW);   // активна матрица модели
	glLoadIdentity();             // её обнуление
	// Установка своей прямоугольной системы координат (левая, правая, нижняя, верхняя, ближняя, дальняя границы)
	glOrtho(-200, 200.0, -200, 200.0, -1.0, 1.0);
}

void mouseClick(int button, int state, int x, int y)  // Функция-обработчик нажатия кнопки мыши
{
	if (GLUT_LEFT_BUTTON == button)   {  };
}

void keyboard(unsigned char key, int x, int y)    // Функция-обработчик нажатия однобайтовой клавиши
{
	if ('a' == key)  { };
}

void keyboardSpecial(int key, int x, int y)   // Функция-обработчик нажатия двухбайтовой клавиши
{
	if (GLUT_KEY_LEFT == key) { } ;
	if (GLUT_KEY_RIGHT == key) { };
	if (GLUT_KEY_DOWN == key) { };
	if (GLUT_KEY_UP == key)  {  } ;
}

// Основная программа
int _tmain(int argc, _TCHAR* argv[])
{
	glutInit(&argc, (char**)argv);      // инициализация графики (служебное действие)
	 
    glutInitWindowSize(640, 480);       // установка размера окна
    glutInitWindowPosition(400, 400);   // установка расположения окна

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_ALPHA | GLUT_DEPTH);
    glutCreateWindow("Template - Шаблон");  // создание окна
	

    glutDisplayFunc(display);   // Функция-обработчик приглашения на отрисовку (WM_PAINT в WinAPI)
	glutIdleFunc(display);      // Функция-обработчик сообщения о бездействии  
	glutReshapeFunc(reshape);   // Функция-обработчик изменения размера окна   (WM_SIZE в WinAPI)
	glutMouseFunc(mouseClick);  // Функция-обработчик нажатия кнопки мыши      (WM_LBUTTONDOWN в WinAPI) 
	glutKeyboardFunc(keyboard); // Функция-обработчик нажатия однобайтовой клавиши  (WM_KEYDOWN в WinAPI)
	glutSpecialFunc(keyboardSpecial);  // Функция-обработчик нажатия двухбайтовой клавиши (WM_KEYDOWN в WinAPI)
	
    glutMainLoop();   // запуск основного цикла программы
    return 0;
}

