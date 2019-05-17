//Semestre 2019 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	  		López Galindo Ana Ruth		    ******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"
#include "cmodel/CModel.h"

CFiguras bardas;
CFiguras fig1;
CFiguras fig2;


//Constructores de métodos en código
void display();
void Reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);
void MouseMotion(int x, int y);
//void animacion();
void sillaA();

void mesa1();
void arbol();
//void interpolation();
//void keyframes();
//void initKeyFrames();

//Divisores de frecuencia planos animados
int divider3 = 0, steps3 = 0;
int divider5 = 0, steps5 = 0;
int divider12 = 0, steps12 = 0;

//Animación objetos que rotan
double spin = 0;
double spinsky = 0;
double spind = 0;

//Luz global y de cuarto
bool luz0 = false, luz1 = true;

//Luces arbol Encender y apagar
bool luz2 = false, luz3 = false;

//Cambia cámara
bool swCamera = false;

//Constante Pi
const double PI = 3.1415926535897;

//Variables de camara
Camera g_camera;
bool g_fps_mode = true;
int g_viewport_width = 0;
int g_viewport_height = 0;

// Parámetros de movimiento
const float g_translation_speed = 0.3;
const float g_rotation_speed = PI / 180 * 0.3;

// Para los conos del arbol
float angulo = 0;
float rad = 0;

//Parametros keyframes
float posX = 0, posY = 0, posZ = 0, rotX = 0, rotY = 0, rotZ = 0;
float posX1 = 0, posY1 = 0, posZ1 = 0, rotX1 = 0, rotY1 = 0, rotZ1 = 0;
float posX2 = 0, posY2 = 0, posZ2 = 0, rotX2 = 0, rotY2 = 0, rotZ2 = 0;
float posX3 = 0, posY3 = 0, posZ3 = 0, rotX3 = 0, rotY3 = 0, rotZ3 = 0;
float posX4 = 0, posY4 = 0, posZ4 = 0, rotX4 = 0, rotY4 = 0, rotZ4 = 0;
float posX5 = 0, posY5 = 0, posZ5 = 0, rotX5 = 0, rotY5 = 0, rotZ5 = 0;

#define MAX_FRAMES 1000
int i_max_steps = 30;
int i_curr_steps = 0;

//typedef struct _frame {
//	//Variables para guardar Key Frames
//	float posX;
//	float posY;
//	float posZ;
//	float incX;
//	float incY;
//	float incZ;
//	float rotX;
//	float rotY;
//	float rotZ;
//	float rotincX;
//	float rotincY;
//	float rotincZ;
//
//	float posX1;
//	float posY1;
//	float posZ1;
//	float incX1;
//	float incY1;
//	float incZ1;
//	float rotX1;
//	float rotY1;
//	float rotZ1;
//	float rotincX1;
//	float rotincY1;
//	float rotincZ1;
//
//	float posX2;
//	float posY2;
//	float posZ2;
//	float incX2;
//	float incY2;
//	float incZ2;
//	float rotX2;
//	float rotY2;
//	float rotZ2;
//	float rotincX2;
//	float rotincY2;
//	float rotincZ2;
//
//	float posX3;
//	float posY3;
//	float posZ3;
//	float incX3;
//	float incY3;
//	float incZ3;
//	float rotX3;
//	float rotY3;
//	float rotZ3;
//	float rotincX3;
//	float rotincY3;
//	float rotincZ3;
//
//	float posX4;
//	float posY4;
//	float posZ4;
//	float incX4;
//
//	float incY4;
//	float incZ4;
//	float rotX4;
//	float rotY4;
//	float rotZ4;
//	float rotincX4;
//	float rotincY4;
//	float rotincZ4;
//
//	float posX5;
//	float posY5;
//	float posZ5;
//	float incX5;
//	float incY5;
//	float incZ5;
//	float rotX5;
//	float rotY5;
//	float rotZ5;
//	float rotincX5;
//	float rotincY5;
//	float rotincZ5;
//
//}FRAME;

//FRAME KeyFrame[MAX_FRAMES];
//int FrameIndex = 0;
//bool play = false;
//int playIndex = 0;

//Parametros material 0
GLfloat Ambient[]= { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat Shininess[] = { 7.0 };

//Parámetros luz 0 blanca
GLfloat light_ambient0[] = { 0.1, 0.1, 0.1, 1 };
GLfloat light_diffuse0[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light_specular0[] = { 0.5, 0.5, 0.5, 1.0 };
GLfloat light_position0[] = { 0, 0, 1, 0 };

//Parámetros luz 1 azul
GLfloat light_ambient1[] = { 0, 0.05, 0.1, 1 };
GLfloat light_diffuse1[] = { 0, 0.5, 1.0, 1.0 };
GLfloat light_specular1[] = { 0.5, 0.5, 0.5, 1.0 };
GLfloat light_position1[] = { 1.0, 2.5, 0.0, 0 };

// Parametros luz 2 Foco 1
GLfloat focoAmbient[] = { 0.1f, 0.0829f, 0.0829f, 1.0f };
GLfloat focoDiffuse[] = { 1.0f, 0.829f, 0.829f, 1.0f };
GLfloat focoSpecular[] = { 0.5, 0.5, 0.5, 1.0 };
//Posiciones de los focos
GLfloat foco1Position[] = { 1.0f, 0.0f, 0.0f, 1.0f };

//Parametros luz 3 foco 2
GLfloat foco2Ambient[] = { 0.078f, 0.0568f, 0.0113f, 1.0f };
GLfloat foco2Diffuse[] = { 0.780392f, 0.568627f, 0.113725f, 1.0f };
GLfloat foco2Specular[] = { 0.992157, 0.941176, 0.807843, 1.0 };
//Posiciones de los focos
GLfloat foco2Position[] = { 0.0f, 1.0f, -1.0f, 1.0f };

//Parametros material Arbol
GLfloat mat_ambient[] = { 0, 0, 0.5, 0 };
GLfloat mat_diffuse[] = { 0.4, 0.5, 0.4, 1.0 };
GLfloat mat_specular[] = { 0.04, 0.7, 0.04, 1.0 };
GLfloat mat_shininess[] = { 7.0 };

//Texturas
CTexture esfera1;


CTexture t_pared;
CTexture t_vidrio;
CTexture t_piso;
CTexture t_techo;
CTexture landscape;
CTexture skydome;
CTexture t_dragon;
CTexture sillaMadera;
CTexture silla2Madera;
CTexture silla3Madera;
CTexture t_madera;
CTexture t_vg1;
CTexture t_vg2;
CTexture t_vg3;
CTexture t_dod;
CTexture t_puerta;
CTexture t_poster1;
CTexture t_poster2;
CTexture t_poster3;
CTexture t_poster4;
CTexture t_poster5;
CTexture t_poster6;
CTexture t_posterj;

//Figuras
CFiguras cuarto;
CFiguras plano;
CFiguras planoTrans;
CFiguras plAnim3;
CFiguras plAnim5;
CFiguras plAnim12;
CFiguras cielo;
CFiguras paisaje;
CFiguras silla1;
CFiguras silla2;
CFiguras silla3;
CFiguras obj;

//Modelos
CModel mesa;
CModel cab1;
CModel cab2;
CModel cab3;
CModel char1;
CModel lamp1;
CModel lampT;



CTexture text1;
CTexture text2;

CTexture refri;
CTexture refri2;

CTexture CabeceraColchon;
CTexture Cabecera;
CTexture ColorMuebleChocolate;
CTexture SabanaColchon;


CTexture pisoMadera;
CTexture ParedBlanca;


void InitGL(GLvoid) {

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_TEXTURE_2D);
	glShadeModel (GL_SMOOTH);

	//Luz 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position0);

	//Luz 1
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular1);

	//Configuracion Primer foco
	glLightfv(GL_LIGHT2, GL_AMBIENT, focoAmbient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, focoDiffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, focoSpecular);


	//Configuracion Segundo foco
	glLightfv(GL_LIGHT3, GL_AMBIENT, foco2Ambient);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, foco2Diffuse);
	glLightfv(GL_LIGHT3, GL_SPECULAR, foco2Specular);

	//Habilitamos iluminación
	glEnable(GL_LIGHTING);

	glEnable (GL_COLOR_MATERIAL);

	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	//Texturas con transparencia
	esfera1.LoadTGA("esfera1.tga");//esferas
	esfera1.BuildGLTexture();
	esfera1.ReleaseImage();

	t_dragon.LoadTGA("Texturas/t_dragon.tga");
	t_dragon.BuildGLTexture();
	t_dragon.ReleaseImage();

	landscape.LoadTGA("Texturas/t_glass.tga ");
	landscape.BuildGLTexture();
	landscape.ReleaseImage();

	t_vidrio.LoadTGA("Texturas/t_glass.tga");
	t_vidrio.BuildGLTexture();
	t_vidrio.ReleaseImage();

	//Texturas sin transparencia
	skydome.LoadTGA("Texturas/skydome.tga");
	skydome.BuildGLTexture();
	skydome.ReleaseImage();

	t_pared.LoadTGA("Texturas/t_pared.tga");
	t_pared.BuildGLTexture();
	t_pared.ReleaseImage();

	t_piso.LoadTGA("Texturas/t_piso.tga");
	t_piso.BuildGLTexture();
	t_piso.ReleaseImage();

	t_techo.LoadTGA("Texturas/t_techo.tga");
	t_techo.BuildGLTexture();
	t_techo.ReleaseImage();


	sillaMadera.LoadTGA("Texturas/textura_madera.tga");
	sillaMadera.BuildGLTexture();
	sillaMadera.ReleaseImage();

	silla2Madera.LoadTGA("Texturas/textura_mad.tga");
	silla2Madera.BuildGLTexture();
	silla2Madera.ReleaseImage();

	silla3Madera.LoadTGA("Texturas/textura_mad2.tga");
	silla3Madera.BuildGLTexture();
	silla3Madera.ReleaseImage();

	t_madera.LoadTGA("Texturas/t_madera.tga");
	t_madera.BuildGLTexture();
	t_madera.ReleaseImage();

	t_vg1.LoadTGA("Texturas/t_vg1.tga");
	t_vg1.BuildGLTexture();
	t_vg1.ReleaseImage();

	t_vg2.LoadTGA("Texturas/t_vg2.tga");
	t_vg2.BuildGLTexture();
	t_vg2.ReleaseImage();

	t_vg3.LoadTGA("Texturas/t_vg3.tga");
	t_vg3.BuildGLTexture();
	t_vg3.ReleaseImage();

	t_dod.LoadTGA("Texturas/t_dod.tga");
	t_dod.BuildGLTexture();
	t_dod.ReleaseImage();

	t_puerta.LoadTGA("Texturas/t_puerta.tga");
	t_puerta.BuildGLTexture();
	t_puerta.ReleaseImage();

	t_poster1.LoadTGA("Texturas/t_poster1.tga");
	t_poster1.BuildGLTexture();
	t_poster1.ReleaseImage();
	
	t_poster2.LoadTGA("Texturas/t_poster2.tga");
	t_poster2.BuildGLTexture();
	t_poster2.ReleaseImage();

	t_poster3.LoadTGA("Texturas/t_poster3.tga");
	t_poster3.BuildGLTexture();
	t_poster3.ReleaseImage();

	t_poster4.LoadTGA("Texturas/t_poster4.tga");
	t_poster4.BuildGLTexture();
	t_poster4.ReleaseImage();

	t_poster5.LoadTGA("Texturas/t_poster5.tga");
	t_poster5.BuildGLTexture();
	t_poster5.ReleaseImage();

	t_poster6.LoadTGA("Texturas/t_poster6.tga");
	t_poster6.BuildGLTexture();
	t_poster6.ReleaseImage();

	t_posterj.LoadTGA("Texturas/t_posterj.tga");
	t_posterj.BuildGLTexture();
	t_posterj.ReleaseImage();



	refri.LoadTGA("texturas/refri.tga");
	refri.BuildGLTexture();
	refri.ReleaseImage();

	CabeceraColchon.LoadTGA("Muebles/CabeceraColchon.tga");
	CabeceraColchon.BuildGLTexture();
	CabeceraColchon.ReleaseImage();

	Cabecera.LoadTGA("Muebles/Cabecera.tga");
	Cabecera.BuildGLTexture();
	Cabecera.ReleaseImage();

	ColorMuebleChocolate.LoadTGA("Muebles/ColorMuebleChocolate.tga");
	ColorMuebleChocolate.BuildGLTexture();
	ColorMuebleChocolate.ReleaseImage();

	SabanaColchon.LoadTGA("Muebles/SabanaColchon.tga");
	SabanaColchon.BuildGLTexture();
	SabanaColchon.ReleaseImage();

	pisoMadera.LoadTGA("Texturas/pisomadera.tga");
	pisoMadera.BuildGLTexture();
	pisoMadera.ReleaseImage();

	ParedBlanca.LoadTGA("Texturas/ParedBlanca.tga");
	ParedBlanca.BuildGLTexture();
	ParedBlanca.ReleaseImage();



	//Modelos
	mesa._3dsLoad("Modelos/mesa.3ds");
	mesa.VertexNormals();

	cab1._3dsLoad("Modelos/Pac_Man.3ds");
	cab1.VertexNormals();

	cab2._3dsLoad("Modelos/Mace.3ds");
	cab2.VertexNormals();

	cab3._3dsLoad("Modelos/hotrod3.3ds");
	cab3.VertexNormals();

	char1._3dsLoad("Modelos/sunnvfashi.3ds");
	char1.VertexNormals();

	lamp1._3dsLoad("Modelos/Lamp.3ds");
	lamp1.VertexNormals();

	lampT._3dsLoad("Modelos/LampT.3ds");
	lampT.VertexNormals();

	//
	////Iniciar variables de KeyFrames
	//initKeyFrames();

}
//
//void interpolation() {
//	KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;
//	KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;
//	KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;
//	KeyFrame[playIndex].rotincX = (KeyFrame[playIndex + 1].rotX - KeyFrame[playIndex].rotX) / i_max_steps;
//	KeyFrame[playIndex].rotincY = (KeyFrame[playIndex + 1].rotY - KeyFrame[playIndex].rotY) / i_max_steps;
//	KeyFrame[playIndex].rotincZ = (KeyFrame[playIndex + 1].rotZ - KeyFrame[playIndex].rotZ) / i_max_steps;
//
//	KeyFrame[playIndex].incX1 = (KeyFrame[playIndex + 1].posX1 - KeyFrame[playIndex].posX1) / i_max_steps;
//	KeyFrame[playIndex].incY1 = (KeyFrame[playIndex + 1].posY1 - KeyFrame[playIndex].posY1) / i_max_steps;
//	KeyFrame[playIndex].incZ1 = (KeyFrame[playIndex + 1].posZ1 - KeyFrame[playIndex].posZ1) / i_max_steps;
//	KeyFrame[playIndex].rotincX1 = (KeyFrame[playIndex + 1].rotX1 - KeyFrame[playIndex].rotX1) / i_max_steps;
//	KeyFrame[playIndex].rotincY1 = (KeyFrame[playIndex + 1].rotY1 - KeyFrame[playIndex].rotY1) / i_max_steps;
//	KeyFrame[playIndex].rotincZ1 = (KeyFrame[playIndex + 1].rotZ1 - KeyFrame[playIndex].rotZ1) / i_max_steps;
//
//	KeyFrame[playIndex].incX2 = (KeyFrame[playIndex + 1].posX2 - KeyFrame[playIndex].posX2) / i_max_steps;
//	KeyFrame[playIndex].incY2 = (KeyFrame[playIndex + 1].posY2 - KeyFrame[playIndex].posY2) / i_max_steps;
//	KeyFrame[playIndex].incZ2 = (KeyFrame[playIndex + 1].posZ2 - KeyFrame[playIndex].posZ2) / i_max_steps;
//	KeyFrame[playIndex].rotincX2 = (KeyFrame[playIndex + 1].rotX2 - KeyFrame[playIndex].rotX2) / i_max_steps;
//	KeyFrame[playIndex].rotincY2 = (KeyFrame[playIndex + 1].rotY2 - KeyFrame[playIndex].rotY2) / i_max_steps;
//	KeyFrame[playIndex].rotincZ2 = (KeyFrame[playIndex + 1].rotZ2 - KeyFrame[playIndex].rotZ2) / i_max_steps;
//
//	KeyFrame[playIndex].incX3 = (KeyFrame[playIndex + 1].posX3 - KeyFrame[playIndex].posX3) / i_max_steps;
//	KeyFrame[playIndex].incY3 = (KeyFrame[playIndex + 1].posY3 - KeyFrame[playIndex].posY3) / i_max_steps;
//	KeyFrame[playIndex].incZ3 = (KeyFrame[playIndex + 1].posZ3 - KeyFrame[playIndex].posZ3) / i_max_steps;
//	KeyFrame[playIndex].rotincX3 = (KeyFrame[playIndex + 1].rotX3 - KeyFrame[playIndex].rotX3) / i_max_steps;
//	KeyFrame[playIndex].rotincY3 = (KeyFrame[playIndex + 1].rotY3 - KeyFrame[playIndex].rotY3) / i_max_steps;
//	KeyFrame[playIndex].rotincZ3 = (KeyFrame[playIndex + 1].rotZ3 - KeyFrame[playIndex].rotZ3) / i_max_steps;
//
//	KeyFrame[playIndex].incX4 = (KeyFrame[playIndex + 1].posX4 - KeyFrame[playIndex].posX4) / i_max_steps;
//	KeyFrame[playIndex].incY4 = (KeyFrame[playIndex + 1].posY4 - KeyFrame[playIndex].posY4) / i_max_steps;
//	KeyFrame[playIndex].incZ4 = (KeyFrame[playIndex + 1].posZ4 - KeyFrame[playIndex].posZ4) / i_max_steps;
//	KeyFrame[playIndex].rotincX4 = (KeyFrame[playIndex + 1].rotX4 - KeyFrame[playIndex].rotX4) / i_max_steps;
//	KeyFrame[playIndex].rotincY4 = (KeyFrame[playIndex + 1].rotY4 - KeyFrame[playIndex].rotY4) / i_max_steps;
//	KeyFrame[playIndex].rotincZ4 = (KeyFrame[playIndex + 1].rotZ4 - KeyFrame[playIndex].rotZ4) / i_max_steps;
//
//	KeyFrame[playIndex].incX5 = (KeyFrame[playIndex + 1].posX5 - KeyFrame[playIndex].posX5) / i_max_steps;
//	KeyFrame[playIndex].incY5 = (KeyFrame[playIndex + 1].posY5 - KeyFrame[playIndex].posY5) / i_max_steps;
//	KeyFrame[playIndex].incZ5 = (KeyFrame[playIndex + 1].posZ5 - KeyFrame[playIndex].posZ5) / i_max_steps;
//	KeyFrame[playIndex].rotincX5 = (KeyFrame[playIndex + 1].rotX5 - KeyFrame[playIndex].rotX5) / i_max_steps;
//	KeyFrame[playIndex].rotincY5 = (KeyFrame[playIndex + 1].rotY5 - KeyFrame[playIndex].rotY5) / i_max_steps;
//	KeyFrame[playIndex].rotincZ5 = (KeyFrame[playIndex + 1].rotZ5 - KeyFrame[playIndex].rotZ5) / i_max_steps;
//
//}
//
//void initKeyFrames() {
//	FrameIndex = 0;
//	posX = 0, posY = 0, posZ = 0, rotX = 0, rotY = 0, rotZ = 0;
//	posX1 = 0, posY1 = 0, posZ1 = 0, rotX1 = 0, rotY1 = 0, rotZ1 = 0;
//	posX2 = 0, posY2 = 0, posZ2 = 0, rotX2 = 0, rotY2 = 0, rotZ2 = 0;
//	posX3 = 0, posY3 = 0, posZ3 = 0, rotX3 = 0, rotY3 = 0, rotZ3 = 0;
//	posX4 = 0, posY4 = 0, posZ4 = 0, rotX4 = 0, rotY4 = 0, rotZ4 = 0;
//	posX5 = 0, posY5 = 0, posZ5 = 0, rotX5 = 0, rotY5 = 0, rotZ5 = 0;
//
//	for (int i = 0; i < MAX_FRAMES; i++) {
//		KeyFrame[i].posX = 0;
//		KeyFrame[i].posY = 0;
//		KeyFrame[i].posZ = 0;
//		KeyFrame[i].incX = 0;
//		KeyFrame[i].incY = 0;
//		KeyFrame[i].incZ = 0;
//		KeyFrame[i].rotX = 0;
//		KeyFrame[i].rotY = 0;
//		KeyFrame[i].rotZ = 0;
//		KeyFrame[i].rotincX = 0;
//		KeyFrame[i].rotincY = 0;
//		KeyFrame[i].rotincZ = 0;
//
//		KeyFrame[i].posX1 = 0;
//		KeyFrame[i].posY1 = 0;
//		KeyFrame[i].posZ1 = 0;
//		KeyFrame[i].incX1 = 0;
//		KeyFrame[i].incY1 = 0;
//		KeyFrame[i].incZ1 = 0;
//		KeyFrame[i].rotX1 = 0;
//		KeyFrame[i].rotY1 = 0;
//		KeyFrame[i].rotZ1 = 0;
//		KeyFrame[i].rotincX1 = 0;
//		KeyFrame[i].rotincY1 = 0;
//		KeyFrame[i].rotincZ1 = 0;
//
//		KeyFrame[i].posX2 = 0;
//		KeyFrame[i].posY2 = 0;
//		KeyFrame[i].posZ2 = 0;
//		KeyFrame[i].incX2 = 0;
//		KeyFrame[i].incY2 = 0;
//		KeyFrame[i].incZ2 = 0;
//		KeyFrame[i].rotX2 = 0;
//		KeyFrame[i].rotY2 = 0;
//		KeyFrame[i].rotZ2 = 0;
//		KeyFrame[i].rotincX2 = 0;
//		KeyFrame[i].rotincY2 = 0;
//		KeyFrame[i].rotincZ2 = 0;
//
//		KeyFrame[i].posX3 = 0;
//		KeyFrame[i].posY3 = 0;
//		KeyFrame[i].posZ3 = 0;
//		KeyFrame[i].incX3 = 0;
//		KeyFrame[i].incY3 = 0;
//		KeyFrame[i].incZ3 = 0;
//		KeyFrame[i].rotX3 = 0;
//		KeyFrame[i].rotY3 = 0;
//		KeyFrame[i].rotZ3 = 0;
//		KeyFrame[i].rotincX3 = 0;
//		KeyFrame[i].rotincY3 = 0;
//		KeyFrame[i].rotincZ3 = 0;
//
//		KeyFrame[i].posX4 = 0;
//		KeyFrame[i].posY4 = 0;
//		KeyFrame[i].posZ4 = 0;
//		KeyFrame[i].incX4 = 0;
//		KeyFrame[i].incY4 = 0;
//		KeyFrame[i].incZ4 = 0;
//		KeyFrame[i].rotX4 = 0;
//		KeyFrame[i].rotY4 = 0;
//		KeyFrame[i].rotZ4 = 0;
//		KeyFrame[i].rotincX4 = 0;
//		KeyFrame[i].rotincY4 = 0;
//		KeyFrame[i].rotincZ4 = 0;
//
//		KeyFrame[i].posX5 = 0;
//		KeyFrame[i].posY5 = 0;
//		KeyFrame[i].posZ5 = 0;
//		KeyFrame[i].incX5 = 0;
//		KeyFrame[i].incY5 = 0;
//		KeyFrame[i].incZ5 = 0;
//		KeyFrame[i].rotX5 = 0;
//		KeyFrame[i].rotY5 = 0;
//		KeyFrame[i].rotZ5 = 0;
//		KeyFrame[i].rotincX5 = 0;
//		KeyFrame[i].rotincY5 = 0;
//		KeyFrame[i].rotincZ5 = 0;
//		
//	}
//
//}



void sillaA() {
	glPushMatrix();
	//Respaldo
	glPushMatrix();
	glTranslatef(0.0, 5.0, 0.0);
	glScalef(0.5, 10, 0.5);
	silla1.prisma2(sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.5, 5.0, 0.0);
	glScalef(0.5, 10, 0.5);
	silla1.prisma2(sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.2, 5.5, 0.0);
	glScalef(4.1, 0.5, 0.5);
	silla1.prisma2(sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.2, 8.5, 0.0);
	glScalef(4.1, 0.5, 0.5);
	silla1.prisma2(sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.2, 9.5, 0.0);
	glScalef(4.1, 0.5, 0.5);
	silla1.prisma2(sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.2, 7.0, 0.0);
	glScalef(0.5, 2.5, 0.5);
	silla1.prisma2(sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.2, 7.0, 0.0);
	glScalef(0.5, 2.5, 0.5);
	silla1.prisma2(sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.3, 7.0, 0.0);
	glScalef(0.5, 2.5, 0.5);
	silla1.prisma2(sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex);
	glPopMatrix();

	// Base
	glPushMatrix();
	glTranslatef(-2.25, 4.5, -2.5);
	glScalef(5.0, 0.3, 4.5);
	silla1.prisma2(sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex);
	glPopMatrix();

	// Soportes Laterales
	glPushMatrix();
	glTranslatef(0, 1.5, -2.25);
	glScalef(0.5, 0.5, 4.0);
	silla1.prisma2(sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.5, 1.5, -2.25);
	glScalef(0.5, 0.5, 4.0);
	silla1.prisma2(sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex);
	glPopMatrix();

	//Patas frontales
	glPushMatrix();
	glTranslatef(0.0, 2.25, -4.4);
	glScalef(0.5, 4.5, 0.5);
	silla1.prisma2(sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.5, 2.25, -4.4);
	glScalef(0.5, 4.5, 0.5);
	silla1.prisma2(sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex);
	glPopMatrix();

	//Respaldo delantero y trasero
	glPushMatrix();
	glTranslatef(-2.2, 2.5, -4.5);
	glScalef(4.1, 0.5, 0.5);
	silla1.prisma2(sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-2.2, 4.2, -4.5);
	glScalef(4.1, 0.5, 0.5);
	silla1.prisma2(sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-2.2, 2.5, 0.0);
	glScalef(4.1, 0.5, 0.5);
	silla1.prisma2(sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex, sillaMadera.GLindex);
	glPopMatrix();

	glPopMatrix();

}


void mesa1() {
	//Base
	glPushMatrix();
	glTranslatef(-2.25, 4.5, -2.5);
	glScalef(5.0, 0.5, 4.5);
	silla1.prisma2(t_madera.GLindex, t_madera.GLindex, t_madera.GLindex, t_madera.GLindex);
	glPopMatrix();

	//Patas frontales
	glPushMatrix();
	glTranslatef(-0.1, 2.5, -4.4);
	glScalef(0.3, 4.0, 0.3);
	silla1.prisma2(t_madera.GLindex, t_madera.GLindex, t_madera.GLindex, t_madera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.4, 2.5, -4.4);
	glScalef(0.3, 4.0, 0.3);
	silla1.prisma2(t_madera.GLindex, t_madera.GLindex, t_madera.GLindex, t_madera.GLindex);
	glPopMatrix();

	//Patas traseras
	glPushMatrix();
	glTranslatef(-0.1, 2.5, -0.6);
	glScalef(0.3, 4.0, 0.3);
	silla1.prisma2(t_madera.GLindex, t_madera.GLindex, t_madera.GLindex, t_madera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.4, 2.5, -0.6);
	glScalef(0.3, 4.0, 0.3);
	silla1.prisma2(t_madera.GLindex, t_madera.GLindex, t_madera.GLindex, t_madera.GLindex);
	glPopMatrix();
}

void arbol() {
	glPushMatrix();

	//Cono Superior
	glPushMatrix();
	glTranslatef(0, 15, 0);
	glRotatef(-90, 1, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.139, 0.69, 0.19);
	glVertex3f(0, 0, 0);
	for (angulo = 0; angulo <= 360; angulo += 18) {
		//Convertimos de grados a radianes
		rad = angulo * 3.14 / 180;
		glVertex3f(1 * cos(angulo * 3.14 / 180), 1 * sin(rad), 0);
	}
	glEnd();

	glBegin(GL_TRIANGLES);
	for (angulo = 0; angulo <= 360; angulo += 18) {
		glVertex3f(0, 0, 3);
		rad = angulo * 3.14 / 180;
		glVertex3f(1 * cos(rad), 1 * sin(rad), 0);
		rad = (angulo * 2) * 3.14 / 180;
		glVertex3f(1 * cos(rad), 1 * sin(rad), 0);
	}
	glEnd();
	glPopMatrix();

	//Otro cono
	glPushMatrix();
	glTranslatef(0, 11, 0);
	glRotatef(-90, 1, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.139, 0.69, 0.19);
	glVertex3f(0, 0, 0);
	for (angulo = 0; angulo <= 360; angulo += 18) {
		//Convertimos de grados a radianes
		rad = angulo * 3.14 / 180;
		glVertex3f(3 * cos(angulo * 3.14 / 180), 3 * sin(rad), 0);
	}
	glEnd();

	glBegin(GL_TRIANGLES);
	for (angulo = 0; angulo <= 360; angulo += 18) {
		glVertex3f(0, 0, 4);
		rad = angulo * 3.14 / 180;
		glVertex3f(3 * cos(rad), 3 * sin(rad), 0);
		rad = (angulo * 2) * 3.14 / 180;
		glVertex3f(3 * cos(rad), 3 * sin(rad), 0);
	}
	glEnd();
	glPopMatrix();

	//Otro cono
	glPushMatrix();
	glTranslatef(0, 7, 0);
	glRotatef(-90, 1, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.139, 0.69, 0.19);
	glVertex3f(0, 0, 0);
	for (angulo = 0; angulo <= 360; angulo += 18) {
		//Convertimos de grados a radianes
		rad = angulo * 3.14 / 180;
		glVertex3f(5 * cos(angulo * 3.14 / 180), 5 * sin(rad), 0);
	}
	glEnd();

	glBegin(GL_TRIANGLES);
	for (angulo = 0; angulo <= 360; angulo += 18) {
		glVertex3f(0, 0, 5);
		rad = angulo * 3.14 / 180;
		glVertex3f(5 * cos(rad), 5 * sin(rad), 0);
		rad = (angulo * 2) * 3.14 / 180;
		glVertex3f(5 * cos(rad), 5 * sin(rad), 0);
	}
	glEnd();
	glPopMatrix();

	//Uno mas
	glPushMatrix();
	glTranslatef(0, 2, 0);
	glRotatef(-90, 1, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.139, 0.69, 0.19);
	glVertex3f(0, 0, 0);
	for (angulo = 0; angulo <= 360; angulo += 18) {
		//Convertimos de grados a radianes
		rad = angulo * 3.14 / 180;
		glVertex3f(7 * cos(angulo * 3.14 / 180), 7 * sin(rad), 0);
	}
	glEnd();

	glBegin(GL_TRIANGLES);
	for (angulo = 0; angulo <= 360; angulo += 18) {
		glVertex3f(0, 0, 6);
		rad = angulo * 3.14 / 180;
		glVertex3f(7 * cos(rad), 7 * sin(rad), 0);
		rad = (angulo * 2) * 3.14 / 180;
		glVertex3f(7 * cos(rad), 7 * sin(rad), 0);
	}
	glEnd();
	glPopMatrix();

	//Tronco
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glRotatef(-90, 1, 0, 0);
	glColor3f(0.5f, 0.35f, 0.05f);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0, 0, 0);
	for (angulo = 0; angulo <= 360; angulo += 18) {
		//Convertimos de grados a radianes
		rad = angulo * 3.14 / 180;
		glVertex3f(2 * cos(rad), 2 * sin(rad), 0);
	}
	glEnd();

	// 
	angulo = 0;
	glBegin(GL_QUAD_STRIP);
	glVertex3f(2 * cos(rad), 2 * sin(rad), 0);
	glVertex3f(2 * cos(rad), 2 * sin(rad), 2);
	for (angulo = 30; angulo <= 360; angulo += 18) {

		rad = angulo * 3.14 / 180;
		glVertex3f(2 * cos(rad), 2 * sin(rad), 0);
		glVertex3f(2 * cos(rad), 2 * sin(rad), 2);

	}
	glEnd();
	glPopMatrix();

	//Focos de adorno no son luces interactivas
	glPushMatrix();
	glTranslatef(4, 6, 0);
	glColor3f(1.0, 1.0, 0.0);
	glutSolidSphere(0.5, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4, 6.5, -2);
	glColor3f(0.5, 0.2, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2, 10, -2);
	glColor3f(1.0, 0.0, 1.0);
	glutSolidSphere(0.5, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.5, 10, 1);
	glColor3f(0.0, 1.0, 1.0);
	glutSolidSphere(0.5, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 6.0f, -4.0);
	glColor3f(1, 0.25, 0.25);
	glutSolidSphere(0.5, 10, 10);
	glPopMatrix();

	glColor3f(1, 1, 1);

	glPopMatrix();
}

void refrigerador(GLuint textura1, GLuint textura2)  //refri
{

	GLfloat vertice[8][3] = {
		{ 0.0 ,0.0, 0.0 },    //Coordenadas Vértice 0 V0
	{ 1.0 ,0.0, 0.0 },    //Coordenadas Vértice 1 V1
	{ 1.0 ,1.0, 0.0 },    //Coordenadas Vértice 2 V2
	{ 0.0 ,1.0, 0.0 },    //Coordenadas Vértice 3 V3
	{ 0.0 ,0.0, 1.0 },    //Coordenadas Vértice 4 V4
	{ 1.0 ,0.0, 1.0 },    //Coordenadas Vértice 5 V5
	{ 1.0 ,1.0, 1.0 },    //Coordenadas Vértice 6 V6
	{ 0.0 ,1.0, 1.0 },    //Coordenadas Vértice 7 V7
	};


	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.215f, 0.025f); glVertex3fv(vertice[4]);
	glTexCoord2f(0.785, 0.025f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.785, 0.975); glVertex3fv(vertice[6]);
	glTexCoord2f(0.215f, 0.975); glVertex3fv(vertice[7]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();


	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();


	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();


	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();


	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();
}

void camamatri(GLuint textura1, GLuint textura2, GLuint textura3)
{

	GLfloat vertice[8][3] = {
		{ 0.1 ,0.5, 0.1 },    //Coordenadas Vértice 0 V0  inicia cama
	{ 1.9 ,0.5, 0.1 },    //Coordenadas Vértice 1 V1
	{ 1.9 ,0.6, 0.1 },    //Coordenadas Vértice 2 V2
	{ 0.1 ,0.6, 0.1 },    //Coordenadas Vértice 3 V3
	{ 0.1 ,0.5, 3.9 },    //Coordenadas Vértice 4 V4
	{ 1.9 ,0.5, 3.9 },    //Coordenadas Vértice 5 V5
	{ 1.9 ,0.6, 3.9 },    //Coordenadas Vértice 6 V6
	{ 0.1 ,0.6, 3.9 },    //Coordenadas Vértice 7 V7      termina cama
	};


	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.05f, 0.02f); glVertex3fv(vertice[4]);//00
	glTexCoord2f(0.962f, 0.02f); glVertex3fv(vertice[5]);//10
	glTexCoord2f(0.962f, 0.98); glVertex3fv(vertice[6]);//11
	glTexCoord2f(0.05f, 0.98); glVertex3fv(vertice[7]);//01
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.945, 0.935); glVertex3fv(vertice[3]);
	glTexCoord2f(0.945, 0.14); glVertex3fv(vertice[2]);
	glTexCoord2f(0.05, 0.14); glVertex3fv(vertice[6]);
	glTexCoord2f(0.05, 0.935); glVertex3fv(vertice[7]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();


	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();


	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();


	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	//patas
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(0.2, -0.5, 0.2);
	fig1.cilindro(0.2, 0.5, 20, textura1);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(0.2, -0.5, 3.8);
	fig1.cilindro(0.2, 0.5, 20, textura1);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(1.8, -0.5, 0.2);
	fig1.cilindro(0.2, 0.5, 20, textura1);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(1.8, -0.5, 3.8);
	fig1.cilindro(0.2, 0.5, 20, textura1);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//cabecera
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(0.9, 1.0, 0.0);
	fig1.prisma(0.4, 1.6, 0.2, textura1);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(0.15, 0.5, 0.0);
	fig1.cilindro(0.15, 0.85, 20, textura1);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(1.85, 0.5, 0.0);
	fig1.cilindro(0.15, 0.85, 20, textura1);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//base
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(1.0, 0.25, 2.0);
	fig1.prisma(0.5, 2, 4, textura1);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//cojines
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(0.65, 0.6, 0.4);
	fig1.prisma(0.1, 0.5, 0.3, textura3);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(1.4, 0.6, 0.4);
	fig1.prisma(0.1, 0.5, 0.3, textura3);
	glEnable(GL_LIGHTING);
	glPopMatrix();

}


//
//void keyframes() {
//	FrameIndex = 0;
//
//	//Animar pieza 0
//	//Keyframe 0
//	KeyFrame[FrameIndex].posX = 0;
//	KeyFrame[FrameIndex].posY = 0;
//	KeyFrame[FrameIndex].posZ = 0;
//	KeyFrame[FrameIndex].rotX = 0;
//	KeyFrame[FrameIndex].rotY = 0;
//	KeyFrame[FrameIndex].rotZ = 0;
//
//	KeyFrame[FrameIndex].posX1 = 0;
//	KeyFrame[FrameIndex].posY1 = 0;
//	KeyFrame[FrameIndex].posZ1 = 0;
//	KeyFrame[FrameIndex].rotX1 = 0;
//	KeyFrame[FrameIndex].rotY1 = 0;
//	KeyFrame[FrameIndex].rotZ1 = 0;
//
//	KeyFrame[FrameIndex].posX2 = 0;
//	KeyFrame[FrameIndex].posY2 = 0;
//	KeyFrame[FrameIndex].posZ2 = 0;
//	KeyFrame[FrameIndex].rotX2 = 0;
//	KeyFrame[FrameIndex].rotY2 = 0;
//	KeyFrame[FrameIndex].rotZ2 = 0;
//
//	KeyFrame[FrameIndex].posX3 = 0;
//	KeyFrame[FrameIndex].posY3 = 0;
//	KeyFrame[FrameIndex].posZ3 = 0;
//	KeyFrame[FrameIndex].rotX3 = 0;
//	KeyFrame[FrameIndex].rotY3 = 0;
//	KeyFrame[FrameIndex].rotZ3 = 0;
//
//	KeyFrame[FrameIndex].posX4 = 0;
//	KeyFrame[FrameIndex].posY4 = 0;
//	KeyFrame[FrameIndex].posZ4 = 0;
//	KeyFrame[FrameIndex].rotX4 = 0;
//	KeyFrame[FrameIndex].rotY4 = 0;
//	KeyFrame[FrameIndex].rotZ4 = 0;
//
//	KeyFrame[FrameIndex].posX5 = 0;
//	KeyFrame[FrameIndex].posY5 = 0;
//	KeyFrame[FrameIndex].posZ5 = 0;
//	KeyFrame[FrameIndex].rotX5 = 0;
//	KeyFrame[FrameIndex].rotY5 = 0;
//	KeyFrame[FrameIndex].rotZ5 = 0;
//	FrameIndex++;
//
//	//Keyframe 1
//	KeyFrame[FrameIndex].posX = 0.15;
//	KeyFrame[FrameIndex].posY = 0;
//	KeyFrame[FrameIndex].posZ = 0;
//	KeyFrame[FrameIndex].rotX = 0;
//	KeyFrame[FrameIndex].rotY = 0;
//	KeyFrame[FrameIndex].rotZ = 0;
//
//	KeyFrame[FrameIndex].posX1 = 0;
//	KeyFrame[FrameIndex].posY1 = 0;
//	KeyFrame[FrameIndex].posZ1 = 0;
//	KeyFrame[FrameIndex].rotX1 = 0;
//	KeyFrame[FrameIndex].rotY1 = 0;
//	KeyFrame[FrameIndex].rotZ1 = 0;
//
//	KeyFrame[FrameIndex].posX2 = 0;
//	KeyFrame[FrameIndex].posY2 = 0;
//	KeyFrame[FrameIndex].posZ2 = 0;
//	KeyFrame[FrameIndex].rotX2 = 0;
//	KeyFrame[FrameIndex].rotY2 = 0;
//	KeyFrame[FrameIndex].rotZ2 = 0;
//
//	KeyFrame[FrameIndex].posX3 = 0;
//	KeyFrame[FrameIndex].posY3 = 0;
//	KeyFrame[FrameIndex].posZ3 = 0;
//	KeyFrame[FrameIndex].rotX3 = 0;
//	KeyFrame[FrameIndex].rotY3 = 0;
//	KeyFrame[FrameIndex].rotZ3 = 0;
//
//	KeyFrame[FrameIndex].posX4 = 0;
//	KeyFrame[FrameIndex].posY4 = 0;
//	KeyFrame[FrameIndex].posZ4 = 0;
//	KeyFrame[FrameIndex].rotX4 = 0;
//	KeyFrame[FrameIndex].rotY4 = 0;
//	KeyFrame[FrameIndex].rotZ4 = 0;
//
//	KeyFrame[FrameIndex].posX5 = 0;
//	KeyFrame[FrameIndex].posY5 = 0;
//	KeyFrame[FrameIndex].posZ5 = 0;
//	KeyFrame[FrameIndex].rotX5 = 0;
//	KeyFrame[FrameIndex].rotY5 = 0;
//	KeyFrame[FrameIndex].rotZ5 = 0;
//	FrameIndex++;
//
//	//Keyframe 2
//	KeyFrame[FrameIndex].posX = 0.15;
//	KeyFrame[FrameIndex].posY = 0.06;
//	KeyFrame[FrameIndex].posZ = 0;
//	KeyFrame[FrameIndex].rotX = 0;
//	KeyFrame[FrameIndex].rotY = 90;
//	KeyFrame[FrameIndex].rotZ = 0;
//
//	KeyFrame[FrameIndex].posX1 = 0;
//	KeyFrame[FrameIndex].posY1 = 0;
//	KeyFrame[FrameIndex].posZ1 = 0;
//	KeyFrame[FrameIndex].rotX1 = 0;
//	KeyFrame[FrameIndex].rotY1 = 0;
//	KeyFrame[FrameIndex].rotZ1 = 0;
//
//	KeyFrame[FrameIndex].posX2 = 0;
//	KeyFrame[FrameIndex].posY2 = 0;
//	KeyFrame[FrameIndex].posZ2 = 0;
//	KeyFrame[FrameIndex].rotX2 = 0;
//	KeyFrame[FrameIndex].rotY2 = 0;
//	KeyFrame[FrameIndex].rotZ2 = 0;
//
//	KeyFrame[FrameIndex].posX3 = 0;
//	KeyFrame[FrameIndex].posY3 = 0;
//	KeyFrame[FrameIndex].posZ3 = 0;
//	KeyFrame[FrameIndex].rotX3 = 0;
//	KeyFrame[FrameIndex].rotY3 = 0;
//	KeyFrame[FrameIndex].rotZ3 = 0;
//
//	KeyFrame[FrameIndex].posX4 = 0;
//	KeyFrame[FrameIndex].posY4 = 0;
//	KeyFrame[FrameIndex].posZ4 = 0;
//	KeyFrame[FrameIndex].rotX4 = 0;
//	KeyFrame[FrameIndex].rotY4 = 0;
//	KeyFrame[FrameIndex].rotZ4 = 0;
//
//	KeyFrame[FrameIndex].posX5 = 0;
//	KeyFrame[FrameIndex].posY5 = 0;
//	KeyFrame[FrameIndex].posZ5 = 0;
//	KeyFrame[FrameIndex].rotX5 = 0;
//	KeyFrame[FrameIndex].rotY5 = 0;
//	KeyFrame[FrameIndex].rotZ5 = 0;
//	FrameIndex++;
//
//	//Keyframe 3
//	KeyFrame[FrameIndex].posX = 0;
//	KeyFrame[FrameIndex].posY = 0.06;
//	KeyFrame[FrameIndex].posZ = 0;
//	KeyFrame[FrameIndex].rotX = 0;
//	KeyFrame[FrameIndex].rotY = 90;
//	KeyFrame[FrameIndex].rotZ = 0;
//
//	KeyFrame[FrameIndex].posX1 = 0;
//	KeyFrame[FrameIndex].posY1 = 0;
//	KeyFrame[FrameIndex].posZ1 = 0;
//	KeyFrame[FrameIndex].rotX1 = 0;
//	KeyFrame[FrameIndex].rotY1 = 0;
//	KeyFrame[FrameIndex].rotZ1 = 0;
//
//	KeyFrame[FrameIndex].posX2 = 0;
//	KeyFrame[FrameIndex].posY2 = 0;
//	KeyFrame[FrameIndex].posZ2 = 0;
//	KeyFrame[FrameIndex].rotX2 = 0;
//	KeyFrame[FrameIndex].rotY2 = 0;
//	KeyFrame[FrameIndex].rotZ2 = 0;
//
//	KeyFrame[FrameIndex].posX3 = 0;
//	KeyFrame[FrameIndex].posY3 = 0;
//	KeyFrame[FrameIndex].posZ3 = 0;
//	KeyFrame[FrameIndex].rotX3 = 0;
//	KeyFrame[FrameIndex].rotY3 = 0;
//	KeyFrame[FrameIndex].rotZ3 = 0;
//
//	KeyFrame[FrameIndex].posX4 = 0;
//	KeyFrame[FrameIndex].posY4 = 0;
//	KeyFrame[FrameIndex].posZ4 = 0;
//	KeyFrame[FrameIndex].rotX4 = 0;
//	KeyFrame[FrameIndex].rotY4 = 0;
//	KeyFrame[FrameIndex].rotZ4 = 0;
//
//	KeyFrame[FrameIndex].posX5 = 0;
//	KeyFrame[FrameIndex].posY5 = 0;
//	KeyFrame[FrameIndex].posZ5 = 0;
//	KeyFrame[FrameIndex].rotX5 = 0;
//	KeyFrame[FrameIndex].rotY5 = 0;
//	KeyFrame[FrameIndex].rotZ5 = 0;
//	FrameIndex++;
//
//	//Keyframe 4
//	KeyFrame[FrameIndex].posX = 0;
//	KeyFrame[FrameIndex].posY = 0.02;
//	KeyFrame[FrameIndex].posZ = 0;
//	KeyFrame[FrameIndex].rotX = 0;
//	KeyFrame[FrameIndex].rotY = 90;
//	KeyFrame[FrameIndex].rotZ = 0;
//
//	KeyFrame[FrameIndex].posX1 = 0;
//	KeyFrame[FrameIndex].posY1 = 0;
//	KeyFrame[FrameIndex].posZ1 = 0;
//	KeyFrame[FrameIndex].rotX1 = 0;
//	KeyFrame[FrameIndex].rotY1 = 0;
//	KeyFrame[FrameIndex].rotZ1 = 0;
//
//	KeyFrame[FrameIndex].posX2 = 0;
//	KeyFrame[FrameIndex].posY2 = 0;
//	KeyFrame[FrameIndex].posZ2 = 0;
//	KeyFrame[FrameIndex].rotX2 = 0;
//	KeyFrame[FrameIndex].rotY2 = 0;
//	KeyFrame[FrameIndex].rotZ2 = 0;
//
//	KeyFrame[FrameIndex].posX3 = 0;
//	KeyFrame[FrameIndex].posY3 = 0;
//	KeyFrame[FrameIndex].posZ3 = 0;
//	KeyFrame[FrameIndex].rotX3 = 0;
//	KeyFrame[FrameIndex].rotY3 = 0;
//	KeyFrame[FrameIndex].rotZ3 = 0;
//
//	KeyFrame[FrameIndex].posX4 = 0;
//	KeyFrame[FrameIndex].posY4 = 0;
//	KeyFrame[FrameIndex].posZ4 = 0;
//	KeyFrame[FrameIndex].rotX4 = 0;
//	KeyFrame[FrameIndex].rotY4 = 0;
//	KeyFrame[FrameIndex].rotZ4 = 0;
//
//	KeyFrame[FrameIndex].posX5 = 0;
//	KeyFrame[FrameIndex].posY5 = 0;
//	KeyFrame[FrameIndex].posZ5 = 0;
//	KeyFrame[FrameIndex].rotX5 = 0;
//	KeyFrame[FrameIndex].rotY5 = 0;
//	KeyFrame[FrameIndex].rotZ5 = 0;
//	FrameIndex++;
//
//	//Animar pieza 1
//	//Keyframe 5
//	KeyFrame[FrameIndex].posX = 0;
//	KeyFrame[FrameIndex].posY = 0.02;
//	KeyFrame[FrameIndex].posZ = 0;
//	KeyFrame[FrameIndex].rotX = 0;
//	KeyFrame[FrameIndex].rotY = 90;
//	KeyFrame[FrameIndex].rotZ = 0;
//
//	KeyFrame[FrameIndex].posX1 = -0.15;
//	KeyFrame[FrameIndex].posY1 = 0;
//	KeyFrame[FrameIndex].posZ1 = 0;
//	KeyFrame[FrameIndex].rotX1 = 0;
//	KeyFrame[FrameIndex].rotY1 = 0;
//	KeyFrame[FrameIndex].rotZ1 = 0;
//
//	KeyFrame[FrameIndex].posX2 = 0;
//	KeyFrame[FrameIndex].posY2 = 0;
//	KeyFrame[FrameIndex].posZ2 = 0;
//	KeyFrame[FrameIndex].rotX2 = 0;
//	KeyFrame[FrameIndex].rotY2 = 0;
//	KeyFrame[FrameIndex].rotZ2 = 0;
//
//	KeyFrame[FrameIndex].posX3 = 0;
//	KeyFrame[FrameIndex].posY3 = 0;
//	KeyFrame[FrameIndex].posZ3 = 0;
//	KeyFrame[FrameIndex].rotX3 = 0;
//	KeyFrame[FrameIndex].rotY3 = 0;
//	KeyFrame[FrameIndex].rotZ3 = 0;
//
//	KeyFrame[FrameIndex].posX4 = 0;
//	KeyFrame[FrameIndex].posY4 = 0;
//	KeyFrame[FrameIndex].posZ4 = 0;
//	KeyFrame[FrameIndex].rotX4 = 0;
//	KeyFrame[FrameIndex].rotY4 = 0;
//	KeyFrame[FrameIndex].rotZ4 = 0;
//
//	KeyFrame[FrameIndex].posX5 = 0;
//	KeyFrame[FrameIndex].posY5 = 0;
//	KeyFrame[FrameIndex].posZ5 = 0;
//	KeyFrame[FrameIndex].rotX5 = 0;
//	KeyFrame[FrameIndex].rotY5 = 0;
//	KeyFrame[FrameIndex].rotZ5 = 0;
//	FrameIndex++;
//
//	//Keyframe 6
//	KeyFrame[FrameIndex].posX = 0;
//	KeyFrame[FrameIndex].posY = 0.02;
//	KeyFrame[FrameIndex].posZ = 0;
//	KeyFrame[FrameIndex].rotX = 0;
//	KeyFrame[FrameIndex].rotY = 90;
//	KeyFrame[FrameIndex].rotZ = 0;
//
//	KeyFrame[FrameIndex].posX1 = -0.15;
//	KeyFrame[FrameIndex].posY1 = 0.18;
//	KeyFrame[FrameIndex].posZ1 = 0;
//	KeyFrame[FrameIndex].rotX1 = 0;
//	KeyFrame[FrameIndex].rotY1 = 0;
//	KeyFrame[FrameIndex].rotZ1 = 0;
//
//	KeyFrame[FrameIndex].posX2 = 0;
//	KeyFrame[FrameIndex].posY2 = 0;
//	KeyFrame[FrameIndex].posZ2 = 0;
//	KeyFrame[FrameIndex].rotX2 = 0;
//	KeyFrame[FrameIndex].rotY2 = 0;
//	KeyFrame[FrameIndex].rotZ2 = 0;
//
//	KeyFrame[FrameIndex].posX3 = 0;
//	KeyFrame[FrameIndex].posY3 = 0;
//	KeyFrame[FrameIndex].posZ3 = 0;
//	KeyFrame[FrameIndex].rotX3 = 0;
//	KeyFrame[FrameIndex].rotY3 = 0;
//	KeyFrame[FrameIndex].rotZ3 = 0;
//
//	KeyFrame[FrameIndex].posX4 = 0;
//	KeyFrame[FrameIndex].posY4 = 0;
//	KeyFrame[FrameIndex].posZ4 = 0;
//	KeyFrame[FrameIndex].rotX4 = 0;
//	KeyFrame[FrameIndex].rotY4 = 0;
//	KeyFrame[FrameIndex].rotZ4 = 0;
//
//	KeyFrame[FrameIndex].posX5 = 0;
//	KeyFrame[FrameIndex].posY5 = 0;
//	KeyFrame[FrameIndex].posZ5 = 0;
//	KeyFrame[FrameIndex].rotX5 = 0;
//	KeyFrame[FrameIndex].rotY5 = 0;
//	KeyFrame[FrameIndex].rotZ5 = 0;
//	FrameIndex++;
//
//	//Keyframe 7
//	KeyFrame[FrameIndex].posX = 0;
//	KeyFrame[FrameIndex].posY = 0.02;
//	KeyFrame[FrameIndex].posZ = 0;
//	KeyFrame[FrameIndex].rotX = 0;
//	KeyFrame[FrameIndex].rotY = 90;
//	KeyFrame[FrameIndex].rotZ = 0;
//
//	KeyFrame[FrameIndex].posX1 = 0;
//	KeyFrame[FrameIndex].posY1 = 0.18;
//	KeyFrame[FrameIndex].posZ1 = 0;
//	KeyFrame[FrameIndex].rotX1 = 0;
//	KeyFrame[FrameIndex].rotY1 = 0;
//	KeyFrame[FrameIndex].rotZ1 = 0;
//
//	KeyFrame[FrameIndex].posX2 = 0;
//	KeyFrame[FrameIndex].posY2 = 0;
//	KeyFrame[FrameIndex].posZ2 = 0;
//	KeyFrame[FrameIndex].rotX2 = 0;
//	KeyFrame[FrameIndex].rotY2 = 0;
//	KeyFrame[FrameIndex].rotZ2 = 0;
//
//	KeyFrame[FrameIndex].posX3 = 0;
//	KeyFrame[FrameIndex].posY3 = 0;
//	KeyFrame[FrameIndex].posZ3 = 0;
//	KeyFrame[FrameIndex].rotX3 = 0;
//	KeyFrame[FrameIndex].rotY3 = 0;
//	KeyFrame[FrameIndex].rotZ3 = 0;
//
//	KeyFrame[FrameIndex].posX4 = 0;
//	KeyFrame[FrameIndex].posY4 = 0;
//	KeyFrame[FrameIndex].posZ4 = 0;
//	KeyFrame[FrameIndex].rotX4 = 0;
//	KeyFrame[FrameIndex].rotY4 = 0;
//	KeyFrame[FrameIndex].rotZ4 = 0;
//
//	KeyFrame[FrameIndex].posX5 = 0;
//	KeyFrame[FrameIndex].posY5 = 0;
//	KeyFrame[FrameIndex].posZ5 = 0;
//	KeyFrame[FrameIndex].rotX5 = 0;
//	KeyFrame[FrameIndex].rotY5 = 0;
//	KeyFrame[FrameIndex].rotZ5 = 0;
//	FrameIndex++;
//
//	//Keyframe 8
//	KeyFrame[FrameIndex].posX = 0;
//	KeyFrame[FrameIndex].posY = 0.02;
//	KeyFrame[FrameIndex].posZ = 0;
//	KeyFrame[FrameIndex].rotX = 0;
//	KeyFrame[FrameIndex].rotY = 90;
//	KeyFrame[FrameIndex].rotZ = 0;
//
//	KeyFrame[FrameIndex].posX1 = 0;
//	KeyFrame[FrameIndex].posY1 = 0.16;
//	KeyFrame[FrameIndex].posZ1 = 0;
//	KeyFrame[FrameIndex].rotX1 = 0;
//	KeyFrame[FrameIndex].rotY1 = 0;
//	KeyFrame[FrameIndex].rotZ1 = 0;
//
//	KeyFrame[FrameIndex].posX2 = 0;
//	KeyFrame[FrameIndex].posY2 = 0;
//	KeyFrame[FrameIndex].posZ2 = 0;
//	KeyFrame[FrameIndex].rotX2 = 0;
//	KeyFrame[FrameIndex].rotY2 = 0;
//	KeyFrame[FrameIndex].rotZ2 = 0;
//
//	KeyFrame[FrameIndex].posX3 = 0;
//	KeyFrame[FrameIndex].posY3 = 0;
//	KeyFrame[FrameIndex].posZ3 = 0;
//	KeyFrame[FrameIndex].rotX3 = 0;
//	KeyFrame[FrameIndex].rotY3 = 0;
//	KeyFrame[FrameIndex].rotZ3 = 0;
//
//	KeyFrame[FrameIndex].posX4 = 0;
//	KeyFrame[FrameIndex].posY4 = 0;
//	KeyFrame[FrameIndex].posZ4 = 0;
//	KeyFrame[FrameIndex].rotX4 = 0;
//	KeyFrame[FrameIndex].rotY4 = 0;
//	KeyFrame[FrameIndex].rotZ4 = 0;
//
//	KeyFrame[FrameIndex].posX5 = 0;
//	KeyFrame[FrameIndex].posY5 = 0;
//	KeyFrame[FrameIndex].posZ5 = 0;
//	KeyFrame[FrameIndex].rotX5 = 0;
//	KeyFrame[FrameIndex].rotY5 = 0;
//	KeyFrame[FrameIndex].rotZ5 = 0;
//	FrameIndex++;
//
//	//Animar pieza 2
//	//Keyframe 9
//	KeyFrame[FrameIndex].posX = 0;
//	KeyFrame[FrameIndex].posY = 0.02;
//	KeyFrame[FrameIndex].posZ = 0;
//	KeyFrame[FrameIndex].rotX = 0;
//	KeyFrame[FrameIndex].rotY = 90;
//	KeyFrame[FrameIndex].rotZ = 0;
//
//	KeyFrame[FrameIndex].posX1 = 0;
//	KeyFrame[FrameIndex].posY1 = 0.16;
//	KeyFrame[FrameIndex].posZ1 = 0;
//	KeyFrame[FrameIndex].rotX1 = 0;
//	KeyFrame[FrameIndex].rotY1 = 0;
//	KeyFrame[FrameIndex].rotZ1 = 0;
//
//	KeyFrame[FrameIndex].posX2 = 0.15;
//	KeyFrame[FrameIndex].posY2 = 0;
//	KeyFrame[FrameIndex].posZ2 = 0;
//	KeyFrame[FrameIndex].rotX2 = 0;
//	KeyFrame[FrameIndex].rotY2 = 0;
//	KeyFrame[FrameIndex].rotZ2 = 0;
//
//	KeyFrame[FrameIndex].posX3 = 0;
//	KeyFrame[FrameIndex].posY3 = 0;
//	KeyFrame[FrameIndex].posZ3 = 0;
//	KeyFrame[FrameIndex].rotX3 = 0;
//	KeyFrame[FrameIndex].rotY3 = 0;
//	KeyFrame[FrameIndex].rotZ3 = 0;
//
//	KeyFrame[FrameIndex].posX4 = 0;
//	KeyFrame[FrameIndex].posY4 = 0;
//	KeyFrame[FrameIndex].posZ4 = 0;
//	KeyFrame[FrameIndex].rotX4 = 0;
//	KeyFrame[FrameIndex].rotY4 = 0;
//	KeyFrame[FrameIndex].rotZ4 = 0;
//
//	KeyFrame[FrameIndex].posX5 = 0;
//	KeyFrame[FrameIndex].posY5 = 0;
//	KeyFrame[FrameIndex].posZ5 = 0;
//	KeyFrame[FrameIndex].rotX5 = 0;
//	KeyFrame[FrameIndex].rotY5 = 0;
//	KeyFrame[FrameIndex].rotZ5 = 0;
//	FrameIndex++;
//
//	//Keyframe 10
//	KeyFrame[FrameIndex].posX = 0;
//	KeyFrame[FrameIndex].posY = 0.02;
//	KeyFrame[FrameIndex].posZ = 0;
//	KeyFrame[FrameIndex].rotX = 0;
//	KeyFrame[FrameIndex].rotY = 90;
//	KeyFrame[FrameIndex].rotZ = 0;
//
//	KeyFrame[FrameIndex].posX1 = 0;
//	KeyFrame[FrameIndex].posY1 = 0.16;
//	KeyFrame[FrameIndex].posZ1 = 0;
//	KeyFrame[FrameIndex].rotX1 = 0;
//	KeyFrame[FrameIndex].rotY1 = 0;
//	KeyFrame[FrameIndex].rotZ1 = 0;
//
//	KeyFrame[FrameIndex].posX2 = 0.15;
//	KeyFrame[FrameIndex].posY2 = 0.3;
//	KeyFrame[FrameIndex].posZ2 = 0;
//	KeyFrame[FrameIndex].rotX2 = 0;
//	KeyFrame[FrameIndex].rotY2 = 0;
//	KeyFrame[FrameIndex].rotZ2 = 0;
//
//	KeyFrame[FrameIndex].posX3 = 0;
//	KeyFrame[FrameIndex].posY3 = 0;
//	KeyFrame[FrameIndex].posZ3 = 0;
//	KeyFrame[FrameIndex].rotX3 = 0;
//	KeyFrame[FrameIndex].rotY3 = 0;
//	KeyFrame[FrameIndex].rotZ3 = 0;
//
//	KeyFrame[FrameIndex].posX4 = 0;
//	KeyFrame[FrameIndex].posY4 = 0;
//	KeyFrame[FrameIndex].posZ4 = 0;
//	KeyFrame[FrameIndex].rotX4 = 0;
//	KeyFrame[FrameIndex].rotY4 = 0;
//	KeyFrame[FrameIndex].rotZ4 = 0;
//
//	KeyFrame[FrameIndex].posX5 = 0;
//	KeyFrame[FrameIndex].posY5 = 0;
//	KeyFrame[FrameIndex].posZ5 = 0;
//	KeyFrame[FrameIndex].rotX5 = 0;
//	KeyFrame[FrameIndex].rotY5 = 0;
//	KeyFrame[FrameIndex].rotZ5 = 0;
//	FrameIndex++;
//
//	//Keyframe 11
//	KeyFrame[FrameIndex].posX = 0;
//	KeyFrame[FrameIndex].posY = 0.02;
//	KeyFrame[FrameIndex].posZ = 0;
//	KeyFrame[FrameIndex].rotX = 0;
//	KeyFrame[FrameIndex].rotY = 90;
//	KeyFrame[FrameIndex].rotZ = 0;
//
//	KeyFrame[FrameIndex].posX1 = 0;
//	KeyFrame[FrameIndex].posY1 = 0.16;
//	KeyFrame[FrameIndex].posZ1 = 0;
//	KeyFrame[FrameIndex].rotX1 = 0;
//	KeyFrame[FrameIndex].rotY1 = 0;
//	KeyFrame[FrameIndex].rotZ1 = 0;
//
//	KeyFrame[FrameIndex].posX2 = 0;
//	KeyFrame[FrameIndex].posY2 = 0.3;
//	KeyFrame[FrameIndex].posZ2 = 0;
//	KeyFrame[FrameIndex].rotX2 = 0;
//	KeyFrame[FrameIndex].rotY2 = 0;
//	KeyFrame[FrameIndex].rotZ2 = 0;
//
//	KeyFrame[FrameIndex].posX3 = 0;
//	KeyFrame[FrameIndex].posY3 = 0;
//	KeyFrame[FrameIndex].posZ3 = 0;
//	KeyFrame[FrameIndex].rotX3 = 0;
//	KeyFrame[FrameIndex].rotY3 = 0;
//	KeyFrame[FrameIndex].rotZ3 = 0;
//
//	KeyFrame[FrameIndex].posX4 = 0;
//	KeyFrame[FrameIndex].posY4 = 0;
//	KeyFrame[FrameIndex].posZ4 = 0;
//	KeyFrame[FrameIndex].rotX4 = 0;
//	KeyFrame[FrameIndex].rotY4 = 0;
//	KeyFrame[FrameIndex].rotZ4 = 0;
//
//	KeyFrame[FrameIndex].posX5 = 0;
//	KeyFrame[FrameIndex].posY5 = 0;
//	KeyFrame[FrameIndex].posZ5 = 0;
//	KeyFrame[FrameIndex].rotX5 = 0;
//	KeyFrame[FrameIndex].rotY5 = 0;
//	KeyFrame[FrameIndex].rotZ5 = 0;
//	FrameIndex++;
//
//	//Keyframe 12
//	KeyFrame[FrameIndex].posX = 0;
//	KeyFrame[FrameIndex].posY = 0.02;
//	KeyFrame[FrameIndex].posZ = 0;
//	KeyFrame[FrameIndex].rotX = 0;
//	KeyFrame[FrameIndex].rotY = 90;
//	KeyFrame[FrameIndex].rotZ = 0;
//
//	KeyFrame[FrameIndex].posX1 = 0;
//	KeyFrame[FrameIndex].posY1 = 0.16;
//	KeyFrame[FrameIndex].posZ1 = 0;
//	KeyFrame[FrameIndex].rotX1 = 0;
//	KeyFrame[FrameIndex].rotY1 = 0;
//	KeyFrame[FrameIndex].rotZ1 = 0;
//
//	KeyFrame[FrameIndex].posX2 = 0;
//	KeyFrame[FrameIndex].posY2 = 0.28;
//	KeyFrame[FrameIndex].posZ2 = 0;
//	KeyFrame[FrameIndex].rotX2 = 0;
//	KeyFrame[FrameIndex].rotY2 = 0;
//	KeyFrame[FrameIndex].rotZ2 = 0;
//
//	KeyFrame[FrameIndex].posX3 = 0;
//	KeyFrame[FrameIndex].posY3 = 0;
//	KeyFrame[FrameIndex].posZ3 = 0;
//	KeyFrame[FrameIndex].rotX3 = 0;
//	KeyFrame[FrameIndex].rotY3 = 0;
//	KeyFrame[FrameIndex].rotZ3 = 0;
//
//	KeyFrame[FrameIndex].posX4 = 0;
//	KeyFrame[FrameIndex].posY4 = 0;
//	KeyFrame[FrameIndex].posZ4 = 0;
//	KeyFrame[FrameIndex].rotX4 = 0;
//	KeyFrame[FrameIndex].rotY4 = 0;
//	KeyFrame[FrameIndex].rotZ4 = 0;
//
//	KeyFrame[FrameIndex].posX5 = 0;
//	KeyFrame[FrameIndex].posY5 = 0;
//	KeyFrame[FrameIndex].posZ5 = 0;
//	KeyFrame[FrameIndex].rotX5 = 0;
//	KeyFrame[FrameIndex].rotY5 = 0;
//	KeyFrame[FrameIndex].rotZ5 = 0;
//	FrameIndex++;
//
//	//Animar pieza 3
//	//Keyframe 13
//	KeyFrame[FrameIndex].posX = 0;
//	KeyFrame[FrameIndex].posY = 0.02;
//	KeyFrame[FrameIndex].posZ = 0;
//	KeyFrame[FrameIndex].rotX = 0;
//	KeyFrame[FrameIndex].rotY = 90;
//	KeyFrame[FrameIndex].rotZ = 0;
//
//	KeyFrame[FrameIndex].posX1 = 0;
//	KeyFrame[FrameIndex].posY1 = 0.16;
//	KeyFrame[FrameIndex].posZ1 = 0;
//	KeyFrame[FrameIndex].rotX1 = 0;
//	KeyFrame[FrameIndex].rotY1 = 0;
//	KeyFrame[FrameIndex].rotZ1 = 0;
//
//	KeyFrame[FrameIndex].posX2 = 0;
//	KeyFrame[FrameIndex].posY2 = 0.28;
//	KeyFrame[FrameIndex].posZ2 = 0;
//	KeyFrame[FrameIndex].rotX2 = 0;
//	KeyFrame[FrameIndex].rotY2 = 0;
//	KeyFrame[FrameIndex].rotZ2 = 0;
//
//	KeyFrame[FrameIndex].posX3 = 0.15;
//	KeyFrame[FrameIndex].posY3 = 0;
//	KeyFrame[FrameIndex].posZ3 = 0;
//	KeyFrame[FrameIndex].rotX3 = 0;
//	KeyFrame[FrameIndex].rotY3 = 0;
//	KeyFrame[FrameIndex].rotZ3 = 0;
//
//	KeyFrame[FrameIndex].posX4 = 0;
//	KeyFrame[FrameIndex].posY4 = 0;
//	KeyFrame[FrameIndex].posZ4 = 0;
//	KeyFrame[FrameIndex].rotX4 = 0;
//	KeyFrame[FrameIndex].rotY4 = 0;
//	KeyFrame[FrameIndex].rotZ4 = 0;
//
//	KeyFrame[FrameIndex].posX5 = 0;
//	KeyFrame[FrameIndex].posY5 = 0;
//	KeyFrame[FrameIndex].posZ5 = 0;
//	KeyFrame[FrameIndex].rotX5 = 0;
//	KeyFrame[FrameIndex].rotY5 = 0;
//	KeyFrame[FrameIndex].rotZ5 = 0;
//	FrameIndex++;
//
//	//Keyframe 14
//	KeyFrame[FrameIndex].posX = 0;
//	KeyFrame[FrameIndex].posY = 0.02;
//	KeyFrame[FrameIndex].posZ = 0;
//	KeyFrame[FrameIndex].rotX = 0;
//	KeyFrame[FrameIndex].rotY = 90;
//	KeyFrame[FrameIndex].rotZ = 0;
//
//	KeyFrame[FrameIndex].posX1 = 0;
//	KeyFrame[FrameIndex].posY1 = 0.16;
//	KeyFrame[FrameIndex].posZ1 = 0;
//	KeyFrame[FrameIndex].rotX1 = 0;
//	KeyFrame[FrameIndex].rotY1 = 0;
//	KeyFrame[FrameIndex].rotZ1 = 0;
//
//	KeyFrame[FrameIndex].posX2 = 0;
//	KeyFrame[FrameIndex].posY2 = 0.28;
//	KeyFrame[FrameIndex].posZ2 = 0;
//	KeyFrame[FrameIndex].rotX2 = 0;
//	KeyFrame[FrameIndex].rotY2 = 0;
//	KeyFrame[FrameIndex].rotZ2 = 0;
//
//	KeyFrame[FrameIndex].posX3 = 0.15;
//	KeyFrame[FrameIndex].posY3 = 0.18;
//	KeyFrame[FrameIndex].posZ3 = -0.04;
//	KeyFrame[FrameIndex].rotX3 = 0;
//	KeyFrame[FrameIndex].rotY3 = 0;
//	KeyFrame[FrameIndex].rotZ3 = 0;
//
//	KeyFrame[FrameIndex].posX4 = 0;
//	KeyFrame[FrameIndex].posY4 = 0;
//	KeyFrame[FrameIndex].posZ4 = 0;
//	KeyFrame[FrameIndex].rotX4 = 0;
//	KeyFrame[FrameIndex].rotY4 = 0;
//	KeyFrame[FrameIndex].rotZ4 = 0;
//
//	KeyFrame[FrameIndex].posX5 = 0;
//	KeyFrame[FrameIndex].posY5 = 0;
//	KeyFrame[FrameIndex].posZ5 = 0;
//	KeyFrame[FrameIndex].rotX5 = 0;
//	KeyFrame[FrameIndex].rotY5 = 0;
//	KeyFrame[FrameIndex].rotZ5 = 0;
//	FrameIndex++;
//
//	//Keyframe 15
//	KeyFrame[FrameIndex].posX = 0;
//	KeyFrame[FrameIndex].posY = 0.02;
//	KeyFrame[FrameIndex].posZ = 0;
//	KeyFrame[FrameIndex].rotX = 0;
//	KeyFrame[FrameIndex].rotY = 90;
//	KeyFrame[FrameIndex].rotZ = 0;
//
//	KeyFrame[FrameIndex].posX1 = 0;
//	KeyFrame[FrameIndex].posY1 = 0.16;
//	KeyFrame[FrameIndex].posZ1 = 0;
//	KeyFrame[FrameIndex].rotX1 = 0;
//	KeyFrame[FrameIndex].rotY1 = 0;
//	KeyFrame[FrameIndex].rotZ1 = 0;
//
//	KeyFrame[FrameIndex].posX2 = 0;
//	KeyFrame[FrameIndex].posY2 = 0.28;
//	KeyFrame[FrameIndex].posZ2 = 0;
//	KeyFrame[FrameIndex].rotX2 = 0;
//	KeyFrame[FrameIndex].rotY2 = 0;
//	KeyFrame[FrameIndex].rotZ2 = 0;
//
//	KeyFrame[FrameIndex].posX3 = 0;
//	KeyFrame[FrameIndex].posY3 = 0.18;
//	KeyFrame[FrameIndex].posZ3 = -0.04;
//	KeyFrame[FrameIndex].rotX3 = 0;
//	KeyFrame[FrameIndex].rotY3 = 0;
//	KeyFrame[FrameIndex].rotZ3 = 0;
//
//	KeyFrame[FrameIndex].posX4 = 0;
//	KeyFrame[FrameIndex].posY4 = 0;
//	KeyFrame[FrameIndex].posZ4 = 0;
//	KeyFrame[FrameIndex].rotX4 = 0;
//	KeyFrame[FrameIndex].rotY4 = 0;
//	KeyFrame[FrameIndex].rotZ4 = 0;
//
//	KeyFrame[FrameIndex].posX5 = 0;
//	KeyFrame[FrameIndex].posY5 = 0;
//	KeyFrame[FrameIndex].posZ5 = 0;
//	KeyFrame[FrameIndex].rotX5 = 0;
//	KeyFrame[FrameIndex].rotY5 = 0;
//	KeyFrame[FrameIndex].rotZ5 = 0;
//	FrameIndex++;
//
//	//Keyframe 16
//	KeyFrame[FrameIndex].posX = 0;
//	KeyFrame[FrameIndex].posY = 0.02;
//	KeyFrame[FrameIndex].posZ = 0;
//	KeyFrame[FrameIndex].rotX = 0;
//	KeyFrame[FrameIndex].rotY = 90;
//	KeyFrame[FrameIndex].rotZ = 0;
//
//	KeyFrame[FrameIndex].posX1 = 0;
//	KeyFrame[FrameIndex].posY1 = 0.16;
//	KeyFrame[FrameIndex].posZ1 = 0;
//	KeyFrame[FrameIndex].rotX1 = 0;
//	KeyFrame[FrameIndex].rotY1 = 0;
//	KeyFrame[FrameIndex].rotZ1 = 0;
//
//	KeyFrame[FrameIndex].posX2 = 0;
//	KeyFrame[FrameIndex].posY2 = 0.28;
//	KeyFrame[FrameIndex].posZ2 = 0;
//	KeyFrame[FrameIndex].rotX2 = 0;
//	KeyFrame[FrameIndex].rotY2 = 0;
//	KeyFrame[FrameIndex].rotZ2 = 0;
//
//	KeyFrame[FrameIndex].posX3 = 0;
//	KeyFrame[FrameIndex].posY3 = 0.16;
//	KeyFrame[FrameIndex].posZ3 = -0.04;
//	KeyFrame[FrameIndex].rotX3 = 0;
//	KeyFrame[FrameIndex].rotY3 = 0;
//	KeyFrame[FrameIndex].rotZ3 = 0;
//
//	KeyFrame[FrameIndex].posX4 = 0;
//	KeyFrame[FrameIndex].posY4 = 0;
//	KeyFrame[FrameIndex].posZ4 = 0;
//	KeyFrame[FrameIndex].rotX4 = 0;
//	KeyFrame[FrameIndex].rotY4 = 0;
//	KeyFrame[FrameIndex].rotZ4 = 0;
//
//	KeyFrame[FrameIndex].posX5 = 0;
//	KeyFrame[FrameIndex].posY5 = 0;
//	KeyFrame[FrameIndex].posZ5 = 0;
//	KeyFrame[FrameIndex].rotX5 = 0;
//	KeyFrame[FrameIndex].rotY5 = 0;
//	KeyFrame[FrameIndex].rotZ5 = 0;
//	FrameIndex++;
//
//	//Animacion pieza 4
//	//Keyframe 17
//	KeyFrame[FrameIndex].posX = 0;
//	KeyFrame[FrameIndex].posY = 0.02;
//	KeyFrame[FrameIndex].posZ = 0;
//	KeyFrame[FrameIndex].rotX = 0;
//	KeyFrame[FrameIndex].rotY = 90;
//	KeyFrame[FrameIndex].rotZ = 0;
//
//	KeyFrame[FrameIndex].posX1 = 0;
//	KeyFrame[FrameIndex].posY1 = 0.16;
//	KeyFrame[FrameIndex].posZ1 = 0;
//	KeyFrame[FrameIndex].rotX1 = 0;
//	KeyFrame[FrameIndex].rotY1 = 0;
//	KeyFrame[FrameIndex].rotZ1 = 0;
//
//	KeyFrame[FrameIndex].posX2 = 0;
//	KeyFrame[FrameIndex].posY2 = 0.28;
//	KeyFrame[FrameIndex].posZ2 = 0;
//	KeyFrame[FrameIndex].rotX2 = 0;
//	KeyFrame[FrameIndex].rotY2 = 0;
//	KeyFrame[FrameIndex].rotZ2 = 0;
//
//	KeyFrame[FrameIndex].posX3 = 0;
//	KeyFrame[FrameIndex].posY3 = 0.16;
//	KeyFrame[FrameIndex].posZ3 = -0.04;
//	KeyFrame[FrameIndex].rotX3 = 0;
//	KeyFrame[FrameIndex].rotY3 = 0;
//	KeyFrame[FrameIndex].rotZ3 = 0;
//
//	KeyFrame[FrameIndex].posX4 = 0.15;
//	KeyFrame[FrameIndex].posY4 = 0;
//	KeyFrame[FrameIndex].posZ4 = 0;
//	KeyFrame[FrameIndex].rotX4 = 0;
//	KeyFrame[FrameIndex].rotY4 = 0;
//	KeyFrame[FrameIndex].rotZ4 = 0;
//
//	KeyFrame[FrameIndex].posX5 = 0;
//	KeyFrame[FrameIndex].posY5 = 0;
//	KeyFrame[FrameIndex].posZ5 = 0;
//	KeyFrame[FrameIndex].rotX5 = 0;
//	KeyFrame[FrameIndex].rotY5 = 0;
//	KeyFrame[FrameIndex].rotZ5 = 0;
//	FrameIndex++;
//
//	//Keyframe 18
//	KeyFrame[FrameIndex].posX = 0;
//	KeyFrame[FrameIndex].posY = 0.02;
//	KeyFrame[FrameIndex].posZ = 0;
//	KeyFrame[FrameIndex].rotX = 0;
//	KeyFrame[FrameIndex].rotY = 90;
//	KeyFrame[FrameIndex].rotZ = 0;
//
//	KeyFrame[FrameIndex].posX1 = 0;
//	KeyFrame[FrameIndex].posY1 = 0.16;
//	KeyFrame[FrameIndex].posZ1 = 0;
//	KeyFrame[FrameIndex].rotX1 = 0;
//	KeyFrame[FrameIndex].rotY1 = 0;
//	KeyFrame[FrameIndex].rotZ1 = 0;
//
//	KeyFrame[FrameIndex].posX2 = 0;
//	KeyFrame[FrameIndex].posY2 = 0.28;
//	KeyFrame[FrameIndex].posZ2 = 0;
//	KeyFrame[FrameIndex].rotX2 = 0;
//	KeyFrame[FrameIndex].rotY2 = 0;
//	KeyFrame[FrameIndex].rotZ2 = 0;
//
//	KeyFrame[FrameIndex].posX3 = 0;
//	KeyFrame[FrameIndex].posY3 = 0.16;
//	KeyFrame[FrameIndex].posZ3 = -0.04;
//	KeyFrame[FrameIndex].rotX3 = 0;
//	KeyFrame[FrameIndex].rotY3 = 0;
//	KeyFrame[FrameIndex].rotZ3 = 0;
//
//	KeyFrame[FrameIndex].posX4 = 0.15;
//	KeyFrame[FrameIndex].posY4 = 0.36;
//	KeyFrame[FrameIndex].posZ4 = 0;
//	KeyFrame[FrameIndex].rotX4 = 0;
//	KeyFrame[FrameIndex].rotY4 = 0;
//	KeyFrame[FrameIndex].rotZ4 = 0;
//
//	KeyFrame[FrameIndex].posX5 = 0;
//	KeyFrame[FrameIndex].posY5 = 0;
//	KeyFrame[FrameIndex].posZ5 = 0;
//	KeyFrame[FrameIndex].rotX5 = 0;
//	KeyFrame[FrameIndex].rotY5 = 0;
//	KeyFrame[FrameIndex].rotZ5 = 0;
//	FrameIndex++;
//
//	//Keyframe 19
//	KeyFrame[FrameIndex].posX = 0;
//	KeyFrame[FrameIndex].posY = 0.02;
//	KeyFrame[FrameIndex].posZ = 0;
//	KeyFrame[FrameIndex].rotX = 0;
//	KeyFrame[FrameIndex].rotY = 90;
//	KeyFrame[FrameIndex].rotZ = 0;
//
//	KeyFrame[FrameIndex].posX1 = 0;
//	KeyFrame[FrameIndex].posY1 = 0.16;
//	KeyFrame[FrameIndex].posZ1 = 0;
//	KeyFrame[FrameIndex].rotX1 = 0;
//	KeyFrame[FrameIndex].rotY1 = 0;
//	KeyFrame[FrameIndex].rotZ1 = 0;
//
//	KeyFrame[FrameIndex].posX2 = 0;
//	KeyFrame[FrameIndex].posY2 = 0.28;
//	KeyFrame[FrameIndex].posZ2 = 0;
//	KeyFrame[FrameIndex].rotX2 = 0;
//	KeyFrame[FrameIndex].rotY2 = 0;
//	KeyFrame[FrameIndex].rotZ2 = 0;
//
//	KeyFrame[FrameIndex].posX3 = 0;
//	KeyFrame[FrameIndex].posY3 = 0.16;
//	KeyFrame[FrameIndex].posZ3 = -0.04;
//	KeyFrame[FrameIndex].rotX3 = 0;
//	KeyFrame[FrameIndex].rotY3 = 0;
//	KeyFrame[FrameIndex].rotZ3 = 0;
//
//	KeyFrame[FrameIndex].posX4 = 0;
//	KeyFrame[FrameIndex].posY4 = 0.36;
//	KeyFrame[FrameIndex].posZ4 = 0;
//	KeyFrame[FrameIndex].rotX4 = 0;
//	KeyFrame[FrameIndex].rotY4 = -90;
//	KeyFrame[FrameIndex].rotZ4 = 0;
//
//	KeyFrame[FrameIndex].posX5 = 0;
//	KeyFrame[FrameIndex].posY5 = 0;
//	KeyFrame[FrameIndex].posZ5 = 0;
//	KeyFrame[FrameIndex].rotX5 = 0;
//	KeyFrame[FrameIndex].rotY5 = 0;
//	KeyFrame[FrameIndex].rotZ5 = 0;
//	FrameIndex++;
//
//	//Keyframe 20
//	KeyFrame[FrameIndex].posX = 0;
//	KeyFrame[FrameIndex].posY = 0.02;
//	KeyFrame[FrameIndex].posZ = 0;
//	KeyFrame[FrameIndex].rotX = 0;
//	KeyFrame[FrameIndex].rotY = 90;
//	KeyFrame[FrameIndex].rotZ = 0;
//
//	KeyFrame[FrameIndex].posX1 = 0;
//	KeyFrame[FrameIndex].posY1 = 0.16;
//	KeyFrame[FrameIndex].posZ1 = 0;
//	KeyFrame[FrameIndex].rotX1 = 0;
//	KeyFrame[FrameIndex].rotY1 = 0;
//	KeyFrame[FrameIndex].rotZ1 = 0;
//
//	KeyFrame[FrameIndex].posX2 = 0;
//	KeyFrame[FrameIndex].posY2 = 0.28;
//	KeyFrame[FrameIndex].posZ2 = 0;
//	KeyFrame[FrameIndex].rotX2 = 0;
//	KeyFrame[FrameIndex].rotY2 = 0;
//	KeyFrame[FrameIndex].rotZ2 = 0;
//
//	KeyFrame[FrameIndex].posX3 = 0;
//	KeyFrame[FrameIndex].posY3 = 0.16;
//	KeyFrame[FrameIndex].posZ3 = -0.04;
//	KeyFrame[FrameIndex].rotX3 = 0;
//	KeyFrame[FrameIndex].rotY3 = 0;
//	KeyFrame[FrameIndex].rotZ3 = 0;
//
//	KeyFrame[FrameIndex].posX4 = -0.04;
//	KeyFrame[FrameIndex].posY4 = 0.34;
//	KeyFrame[FrameIndex].posZ4 = 0;
//	KeyFrame[FrameIndex].rotX4 = 0;
//	KeyFrame[FrameIndex].rotY4 = -90;
//	KeyFrame[FrameIndex].rotZ4 = 0;
//
//	KeyFrame[FrameIndex].posX5 = 0;
//	KeyFrame[FrameIndex].posY5 = 0;
//	KeyFrame[FrameIndex].posZ5 = 0;
//	KeyFrame[FrameIndex].rotX5 = 0;
//	KeyFrame[FrameIndex].rotY5 = 0;
//	KeyFrame[FrameIndex].rotZ5 = 0;
//	FrameIndex++;
//
//	//Animar pieza 5
//	//Keyframe 21
//	KeyFrame[FrameIndex].posX = 0;
//	KeyFrame[FrameIndex].posY = 0.02;
//	KeyFrame[FrameIndex].posZ = 0;
//	KeyFrame[FrameIndex].rotX = 0;
//	KeyFrame[FrameIndex].rotY = 90;
//	KeyFrame[FrameIndex].rotZ = 0;
//
//	KeyFrame[FrameIndex].posX1 = 0;
//	KeyFrame[FrameIndex].posY1 = 0.16;
//	KeyFrame[FrameIndex].posZ1 = 0;
//	KeyFrame[FrameIndex].rotX1 = 0;
//	KeyFrame[FrameIndex].rotY1 = 0;
//	KeyFrame[FrameIndex].rotZ1 = 0;
//
//	KeyFrame[FrameIndex].posX2 = 0;
//	KeyFrame[FrameIndex].posY2 = 0.28;
//	KeyFrame[FrameIndex].posZ2 = 0;
//	KeyFrame[FrameIndex].rotX2 = 0;
//	KeyFrame[FrameIndex].rotY2 = 0;
//	KeyFrame[FrameIndex].rotZ2 = 0;
//
//	KeyFrame[FrameIndex].posX3 = 0;
//	KeyFrame[FrameIndex].posY3 = 0.16;
//	KeyFrame[FrameIndex].posZ3 = -0.04;
//	KeyFrame[FrameIndex].rotX3 = 0;
//	KeyFrame[FrameIndex].rotY3 = 0;
//	KeyFrame[FrameIndex].rotZ3 = 0;
//
//	KeyFrame[FrameIndex].posX4 = -0.04;
//	KeyFrame[FrameIndex].posY4 = 0.34;
//	KeyFrame[FrameIndex].posZ4 = 0;
//	KeyFrame[FrameIndex].rotX4 = 0;
//	KeyFrame[FrameIndex].rotY4 = -90;
//	KeyFrame[FrameIndex].rotZ4 = 0;
//
//	KeyFrame[FrameIndex].posX5 = 0;
//	KeyFrame[FrameIndex].posY5 = 0;
//	KeyFrame[FrameIndex].posZ5 = 0.07;
//	KeyFrame[FrameIndex].rotX5 = 0;
//	KeyFrame[FrameIndex].rotY5 = 0;
//	KeyFrame[FrameIndex].rotZ5 = 0;
//	FrameIndex++;
//
//	//Keyframe 22
//	KeyFrame[FrameIndex].posX = 0;
//	KeyFrame[FrameIndex].posY = 0.02;
//	KeyFrame[FrameIndex].posZ = 0;
//	KeyFrame[FrameIndex].rotX = 0;
//	KeyFrame[FrameIndex].rotY = 90;
//	KeyFrame[FrameIndex].rotZ = 0;
//
//	KeyFrame[FrameIndex].posX1 = 0;
//	KeyFrame[FrameIndex].posY1 = 0.16;
//	KeyFrame[FrameIndex].posZ1 = 0;
//	KeyFrame[FrameIndex].rotX1 = 0;
//	KeyFrame[FrameIndex].rotY1 = 0;
//	KeyFrame[FrameIndex].rotZ1 = 0;
//
//	KeyFrame[FrameIndex].posX2 = 0;
//	KeyFrame[FrameIndex].posY2 = 0.28;
//	KeyFrame[FrameIndex].posZ2 = 0;
//	KeyFrame[FrameIndex].rotX2 = 0;
//	KeyFrame[FrameIndex].rotY2 = 0;
//	KeyFrame[FrameIndex].rotZ2 = 0;
//
//	KeyFrame[FrameIndex].posX3 = 0;
//	KeyFrame[FrameIndex].posY3 = 0.16;
//	KeyFrame[FrameIndex].posZ3 = -0.04;
//	KeyFrame[FrameIndex].rotX3 = 0;
//	KeyFrame[FrameIndex].rotY3 = 0;
//	KeyFrame[FrameIndex].rotZ3 = 0;
//
//	KeyFrame[FrameIndex].posX4 = -0.04;
//	KeyFrame[FrameIndex].posY4 = 0.34;
//	KeyFrame[FrameIndex].posZ4 = 0;
//	KeyFrame[FrameIndex].rotX4 = 0;
//	KeyFrame[FrameIndex].rotY4 = -90;
//	KeyFrame[FrameIndex].rotZ4 = 0;
//
//	KeyFrame[FrameIndex].posX5 = 0;
//	KeyFrame[FrameIndex].posY5 = 0.14;
//	KeyFrame[FrameIndex].posZ5 = 0.07;
//	KeyFrame[FrameIndex].rotX5 = 0;
//	KeyFrame[FrameIndex].rotY5 = 0;
//	KeyFrame[FrameIndex].rotZ5 = 0;
//	FrameIndex++;
//
//	//Keyframe 23
//	KeyFrame[FrameIndex].posX = 0;
//	KeyFrame[FrameIndex].posY = 0.02;
//	KeyFrame[FrameIndex].posZ = 0;
//	KeyFrame[FrameIndex].rotX = 0;
//	KeyFrame[FrameIndex].rotY = 90;
//	KeyFrame[FrameIndex].rotZ = 0;
//
//	KeyFrame[FrameIndex].posX1 = 0;
//	KeyFrame[FrameIndex].posY1 = 0.16;
//	KeyFrame[FrameIndex].posZ1 = 0;
//	KeyFrame[FrameIndex].rotX1 = 0;
//	KeyFrame[FrameIndex].rotY1 = 0;
//	KeyFrame[FrameIndex].rotZ1 = 0;
//
//	KeyFrame[FrameIndex].posX2 = 0;
//	KeyFrame[FrameIndex].posY2 = 0.28;
//	KeyFrame[FrameIndex].posZ2 = 0;
//	KeyFrame[FrameIndex].rotX2 = 0;
//	KeyFrame[FrameIndex].rotY2 = 0;
//	KeyFrame[FrameIndex].rotZ2 = 0;
//
//	KeyFrame[FrameIndex].posX3 = 0;
//	KeyFrame[FrameIndex].posY3 = 0.16;
//	KeyFrame[FrameIndex].posZ3 = -0.04;
//	KeyFrame[FrameIndex].rotX3 = 0;
//	KeyFrame[FrameIndex].rotY3 = 0;
//	KeyFrame[FrameIndex].rotZ3 = 0;
//
//	KeyFrame[FrameIndex].posX4 = -0.04;
//	KeyFrame[FrameIndex].posY4 = 0.34;
//	KeyFrame[FrameIndex].posZ4 = 0;
//	KeyFrame[FrameIndex].rotX4 = 0;
//	KeyFrame[FrameIndex].rotY4 = -90;
//	KeyFrame[FrameIndex].rotZ4 = 0;
//
//	KeyFrame[FrameIndex].posX5 = 0;
//	KeyFrame[FrameIndex].posY5 = 0.12;
//	KeyFrame[FrameIndex].posZ5 = 0;
//	KeyFrame[FrameIndex].rotX5 = 0;
//	KeyFrame[FrameIndex].rotY5 = 0;
//	KeyFrame[FrameIndex].rotZ5 = 0;
//	FrameIndex++;
//
//}

void display ( void ) {
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	//Dos camaras
	if (!swCamera) g_camera.Refresh();
	else gluLookAt(-5, 1.2, -0.4, -5.9, 1, -0.2, 0, 1, 0);
		
	glPushMatrix();

		//Luz blanca
		if (luz0) glEnable(GL_LIGHT0);
		else glDisable(GL_LIGHT0);

		//muebles
		//refri

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(-7.5, 0, -4);
		glRotatef(90, 0, 1, 0);
		glScaled(1.00, 2.0, 1.0);
		refrigerador(refri.GLindex, refri2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glDisable(GL_LIGHTING);
		glPushMatrix();//Cama 1

		glTranslatef(1.5, 0, -3);
		glRotatef(90, 0.0, 1.0, 0.0);
		glPushMatrix();// Cama
		glRotatef(90, 1.0, 0.0, 0.0);
		bardas.prisma(2, 4, 0.25, Cabecera.GLindex);
		glPopMatrix();

		glPushMatrix();//Patas
		glTranslatef(-1.5, 0.5, -0.5);
		//glRotatef(90, 1.0, 0.0, 0.0);
		bardas.prisma(1, .5,.5 , Cabecera.GLindex);
		glPopMatrix();

		glPushMatrix();//Patas
		glTranslatef(-1.5, 0.5, 0.5);
		//glRotatef(90, 1.0, 0.0, 0.0);
		bardas.prisma(1, .5, .5, Cabecera.GLindex);
		glPopMatrix();

		glPushMatrix();//Patas
		glTranslatef(1.5, 0.5, -0.5);
		//glRotatef(90, 1.0, 0.0, 0.0);
		bardas.prisma(1, .5, .5, Cabecera.GLindex);
		glPopMatrix();

		glPushMatrix();//Patas
		glTranslatef(1.5, 0.5, 0.5);
		//glRotatef(90, 1.0, 0.0, 0.0);
		bardas.prisma(1, .5, .5, Cabecera.GLindex);
		glPopMatrix();

		glPushMatrix();//Cabecera
		glTranslatef(2.0, 1, 0);
		glRotatef(90, 0.0, 1.0, 0.0);
		bardas.prisma(2.0, 2, 0.25, Cabecera.GLindex);
		glPopMatrix();

		glPushMatrix();//Colchon
		glTranslatef(0, 0.80, 0);
		glRotatef(90, 1.0, 0.0, 0.0);
		bardas.prisma(1.85, 3.85, .5, SabanaColchon.GLindex);
		glPopMatrix();

		glPushMatrix();//Cobija
		glTranslatef(0, 1.1, 0);
		glRotatef(90, 1.0, 0.0, 0.0);
		bardas.prisma(1.85, 3.85, 0.05, CabeceraColchon.GLindex);
		glPopMatrix();

		glPushMatrix();//Almohada
		glTranslatef(1.5, 1.2, 0);
		glRotatef(90, 1.0, 0.0, 0.0);
		bardas.prisma(1.8, 0.65, 0.1, SabanaColchon.GLindex);
		glPopMatrix();


		glPopMatrix();




		//Cielo
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glRotated(spinsky, 0, 1, 0);
		cielo.esfera(240, 50, 50, skydome.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//Landscape
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glRotated(90, 0, 1, 0);
		paisaje.esfera(160, 50, 50, landscape.GLindex);
		glDisable(GL_BLEND);
		glDisable(GL_ALPHA_TEST);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//Dragón
		glPushMatrix();
		glRotatef(-1.3*spind, 0, 1, 0);
		glTranslatef(0, 60, -120);
		glScalef(20, 20, 1);
		glDisable(GL_LIGHTING);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		plAnim3.planoAnim3(t_dragon.GLindex);
		glDisable(GL_BLEND);
		glDisable(GL_ALPHA_TEST);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//Ventana 1
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(5, 1.5, 4.99);
		glRotatef(180, 0, 1, 0);
		glScalef(3, 2, 1);
		planoTrans.planoTrans(t_vidrio.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		//Ventana 1
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(5, 1.5, 4.99);
		glRotatef(180, 0, 1, 0);
		glScalef(3, 2, 1);
		planoTrans.planoTrans(t_vidrio.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		////Ventana 1.1
		//glPushMatrix();
		//glDisable(GL_LIGHTING);
		//glTranslatef(-2, 1.5, -4.99);
		//glRotatef(180, 0, 0, 0);
		//glScalef(3, 2, 1);
		//planoTrans.planoTrans(t_vidrio.GLindex);
		//glEnable(GL_LIGHTING);
		//glPopMatrix();

		//Ventana 3
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(-5, 1.5, -4.99);
		glScalef(3, 2, 1);
		planoTrans.planoTrans(t_vidrio.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//Ventana 4
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(-7.49, 1.5, 0.5);
		glRotatef(90, 0, 1, 0);
		glScalef(3, 2, 1);
		planoTrans.planoTrans(t_vidrio.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//Ventana 5
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(-7.49, 1.5, -2.5);
		glRotatef(90, 0, 1, 0);
		glScalef(3, 2, 1);
		planoTrans.planoTrans(t_vidrio.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//Luz azul
		glPushMatrix();
		glRotatef(2*spin, 0, 1, 0);
		glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
		glTranslatef(0, 2.5, 0);
		if (luz1) glEnable(GL_LIGHT1);
		else glDisable(GL_LIGHT1);
		glPopMatrix();

		//Cuarto de juegos
		glPushMatrix();
		glEnable(GL_COLOR_MATERIAL);
		glMaterialfv(GL_FRONT, GL_AMBIENT, Ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, Diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, Specular);
		glTranslatef(0, 1.5, 0);
		glScalef(15, 3, 10);
		cuarto.cuartoInt(ParedBlanca.GLindex, pisoMadera.GLindex, t_techo.GLindex,0);
		glDisable(GL_COLOR_MATERIAL);
		glPopMatrix();

		//Puerta
		glPushMatrix();
		glEnable(GL_COLOR_MATERIAL);
		glMaterialfv(GL_FRONT, GL_AMBIENT, Ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, Diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, Specular);
		glTranslatef(7.49, 1.125, 3);
		glRotatef(-90, 0, 1, 0);
		glScalef(2, 2.25, 1);
		plano.planoSolid(t_puerta.GLindex);
		glDisable(GL_COLOR_MATERIAL);
		glPopMatrix();

		//Puerta 1
		glPushMatrix();
		glEnable(GL_COLOR_MATERIAL);
		glMaterialfv(GL_FRONT, GL_AMBIENT, Ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, Diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, Specular);
		glTranslatef(0, 1.125, 5.01);
		glRotatef(-180, 0, 1, 0);
		glScalef(2, 2.25, 1);
		plano.planoSolid(t_puerta.GLindex);
		glDisable(GL_COLOR_MATERIAL);
		glPopMatrix();


		

		//Lampara techo modelo
		glPushMatrix();
		glDisable(GL_COLOR_MATERIAL);
		glTranslatef(0, 2.8, 0);
		glScalef(0.002, 0.001, 0.002);
		lampT.GLrender(NULL, 4, 1.0);
		glPopMatrix();

		//Mesa modelo
		glPushMatrix();
		glDisable(GL_COLOR_MATERIAL);
		glTranslatef(3.5, .8, -4.5);
		glScalef(0.0009, 0.0009, .0009);
		mesa.GLrender(NULL, 4, 1.0);
		glPopMatrix();

		//Lampara modelo
		glPushMatrix();
		glDisable(GL_COLOR_MATERIAL);
		glTranslatef(3.5, .8, -4.5);
		glRotatef(90, 0, 1, 0);
		glScalef(0.002, 0.002, 0.002);
		lamp1.GLrender(NULL, 4, 1.0);
		glPopMatrix();


		//Mesa
		glPushMatrix();
		glEnable(GL_COLOR_MATERIAL);
		glMaterialfv(GL_FRONT, GL_AMBIENT, Ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, Diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, Specular);
		glTranslatef(-5, -0.1, -1);
		glRotatef(90, 0, 1, 0);
		glScalef(0.35, 0.2, 0.35);
		mesa1();
		glDisable(GL_COLOR_MATERIAL);
		glPopMatrix();

		//Silla A
		glPushMatrix();
		glEnable(GL_COLOR_MATERIAL);
		glMaterialfv(GL_FRONT, GL_AMBIENT, Ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, Diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, Specular);
		glTranslatef(-3.5, 0, -0.5);
		glRotatef(90, 0, 1, 0);
		glScalef(0.12, 0.12, 0.12);
		sillaA();
		glDisable(GL_COLOR_MATERIAL);
		glPopMatrix();

		//Arbol
		glPushMatrix();
		glTranslatef(6, 0, 0.5);
		//Luces arbol
		glPushMatrix();
		glRotatef(2 * spin, 0, 1, 0);
		glLightfv(GL_LIGHT2, GL_POSITION, foco1Position);
		glLightfv(GL_LIGHT3, GL_POSITION, foco2Position);
		//Foco 1 habilitador
		if (luz2) glEnable(GL_LIGHT2);
		else glDisable(GL_LIGHT2);
		//Foco 2 habilitador
		if (luz3) glEnable(GL_LIGHT3);
		else glDisable(GL_LIGHT3);
		glPopMatrix();
		//Dibujar arbol
		glPushMatrix();
		glEnable(GL_COLOR_MATERIAL);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
		glScalef(0.15, 0.15, 0.15);
		arbol();
		glDisable(GL_COLOR_MATERIAL);
		glPopMatrix();
		glPopMatrix();
		
	glPopMatrix();

	//animacion();
	//spin += 0.5;
	//spind += 0.1;
	//spinsky += 0.01;

	glutSwapBuffers ( );

}
//
//void animacion() {
//		
//		//Animación plano 3 frames
//		divider3++;
//		if (divider3 > 12) {
//			divider3 = 0;
//			switch (steps3) {
//			case 0:
//				plAnim3.tizq3 = 0;
//				plAnim3.tder3 = 0.3333;
//				break;
//			case 1:
//				plAnim3.tizq3 = 0.3333;
//				plAnim3.tder3 = 0.6666;
//				break;
//			case 2:
//				plAnim3.tizq3 = 0.6666;
//				plAnim3.tder3 = 1;
//				break;
//			case 3:
//				plAnim3.tizq3 = 0.3333;
//				plAnim3.tder3 = 0.6666;
//				break;
//			default:
//				break;
//			}
//			steps3++;
//			if (steps3 > 3) {
//				steps3 = 0;
//			}
//		}
//
//		//Animación plano 5 frames
//		divider5++;
//		if (divider5 > 13) {
//			divider5 = 0;
//			switch (steps5) {
//			case 0:
//				plAnim5.tizq5 = 0;
//				plAnim5.tder5 = 0.2;
//				break;
//			case 1:
//				plAnim5.tizq5 = 0.2;
//				plAnim5.tder5 = 0.4;
//				break;
//			case 2:
//				plAnim5.tizq5 = 0.4;
//				plAnim5.tder5 = 0.6;
//				break;
//			case 3:
//				plAnim5.tizq5 = 0.6;
//				plAnim5.tder5 = 0.8;
//				break;
//			case 4:
//				plAnim5.tizq5 = 0.8;
//				plAnim5.tder5 = 1;
//				break;
//			default:
//				break;
//			}
//			steps5++;
//			if (steps5 > 4) {
//				steps5 = 0;
//			}
//		}
//
//		//Animación plano 12 frames
//		divider12++;
//		if (divider12 > 16) {
//			divider12 = 0;
//			switch (steps12) {
//			case 0:
//				plAnim12.tizq12 = 0;
//				plAnim12.tder12 = 0.0833;
//				break;
//			case 1:
//				plAnim12.tizq12 = 0.0835;
//				plAnim12.tder12 = 0.1667;
//				break;
//			case 2:
//				plAnim12.tizq12 = 0.1669;
//				plAnim12.tder12 = 0.25;
//				break;
//			case 3:
//				plAnim12.tizq12 = 0.2502;
//				plAnim12.tder12 = 0.3333;
//				break;
//			case 4:
//				plAnim12.tizq12 = 0.3335;
//				plAnim12.tder12 = 0.4167;
//				break;
//			case 5:
//				plAnim12.tizq12 = 0.4169;
//				plAnim12.tder12 = 0.5;
//				break;
//			case 6:
//				plAnim12.tizq12 = 0.5002;
//				plAnim12.tder12 = 0.5833;
//				break;
//			case 7:
//				plAnim12.tizq12 = 0.5835;
//				plAnim12.tder12 = 0.6667;
//				break;
//			case 8:
//				plAnim12.tizq12 = 0.6669;
//				plAnim12.tder12 = 0.75;
//				break;
//			case 9:
//				plAnim12.tizq12 = 0.7502;
//				plAnim12.tder12 = 0.8333;
//				break;
//			case 10:
//				plAnim12.tizq12 = 0.8335;
//				plAnim12.tder12 = 0.9167;
//				break;
//			case 11:
//				plAnim12.tizq12 = 0.9169;
//				plAnim12.tder12 = 1;
//				break;
//			default:
//				break;
//			}
//			steps12++;
//			if (steps12 > 11) {
//				steps12 = 0;
//			}
//		}

//		//Animacion keyframes
//		if (play) {
//			if (i_curr_steps >= i_max_steps) {
//				playIndex++;
//				if (playIndex > FrameIndex - 2) {
//					playIndex = 0;
//					play = false;
//				} else {
//					i_curr_steps = 0;
//					interpolation();
//				}
//			} else {
//				posX += KeyFrame[playIndex].incX;
//				posY += KeyFrame[playIndex].incY;
//				posZ += KeyFrame[playIndex].incZ;
//				rotX += KeyFrame[playIndex].rotincX;
//				rotY += KeyFrame[playIndex].rotincY;
//				rotZ += KeyFrame[playIndex].rotincZ;
//
//				posX1 += KeyFrame[playIndex].incX1;
//				posY1 += KeyFrame[playIndex].incY1;
//				posZ1 += KeyFrame[playIndex].incZ1;
//				rotX1 += KeyFrame[playIndex].rotincX1;
//				rotY1 += KeyFrame[playIndex].rotincY1;
//				rotZ1 += KeyFrame[playIndex].rotincZ1;
//
//				posX2 += KeyFrame[playIndex].incX2;
//				posY2 += KeyFrame[playIndex].incY2;
//				posZ2 += KeyFrame[playIndex].incZ2;
//				rotX2 += KeyFrame[playIndex].rotincX2;
//				rotY2 += KeyFrame[playIndex].rotincY2;
//				rotZ2 += KeyFrame[playIndex].rotincZ2;
//
//				posX3 += KeyFrame[playIndex].incX3;
//				posY3 += KeyFrame[playIndex].incY3;
//				posZ3 += KeyFrame[playIndex].incZ3;
//				rotX3 += KeyFrame[playIndex].rotincX3;
//				rotY3 += KeyFrame[playIndex].rotincY3;
//				rotZ3 += KeyFrame[playIndex].rotincZ3;
//
//				posX4 += KeyFrame[playIndex].incX4;
//				posY4 += KeyFrame[playIndex].incY4;
//				posZ4 += KeyFrame[playIndex].incZ4;
//				rotX4 += KeyFrame[playIndex].rotincX4;
//				rotY4 += KeyFrame[playIndex].rotincY4;
//				rotZ4 += KeyFrame[playIndex].rotincZ4;
//
//				posX5 += KeyFrame[playIndex].incX5;
//				posY5 += KeyFrame[playIndex].incY5;
//				posZ5 += KeyFrame[playIndex].incZ5;
//				rotX5 += KeyFrame[playIndex].rotincX5;
//				rotY5 += KeyFrame[playIndex].rotincY5;
//				rotZ5 += KeyFrame[playIndex].rotincZ5;
//
//				i_curr_steps++;
//			}
//	}
//
//}

void Reshape(int w, int h) {
	g_viewport_width = w;
	g_viewport_height = h;

	glViewport(0, 0, (GLsizei)w, (GLsizei)h); //set the viewport to the current window specifications
	glMatrixMode(GL_PROJECTION); //set the matrix to projection

	glLoadIdentity();
	gluPerspective(75, (GLfloat)w / (GLfloat)h, 0.1, 1024); //set the perspective (angle of sight, width, height, ,depth)
	glMatrixMode(GL_MODELVIEW); //set the matrix back to model
}

void keyboard ( unsigned char key, int x, int y ) {
	switch ( key ) {

	case 27: //ESC para salir
			exit(0);
			break;

		case 'w':   //Movimientos de camara
		case 'W':
			g_camera.Move(g_translation_speed);
			break;

		case 's':
		case 'S':
			g_camera.Move(-g_translation_speed);
			break;

		case 'a':
		case 'A':
			g_camera.Strafe(g_translation_speed);
			break;

		case 'd':
		case 'D':
			g_camera.Strafe(-g_translation_speed);
			break;

		case ' ': //Moverse hacia arriba
			g_camera.Fly(g_translation_speed);
			break;

		case 'c': //Moverse hacia abajo
		case 'C':
			g_camera.Fly(-g_translation_speed);
			break;

		case 'u': //Conmutar luces
		case 'U':
			luz0 = !luz0;
			break;

		case 'i':
		case 'I':
			luz1 = !luz1;
			break;

		case 'o':
		case 'O':
			luz2 = !luz2;
			break;

		case 'p':
		case 'P':
			luz3 = !luz3;
			break;

		//case 'k': //Cargar keyframes
		//case 'K':
		//	keyframes();
		//	break;

		//case 'l': //Reproducir keyframes
		//case 'L':
		//	if (play == false && (FrameIndex > 1)) {
		//	posX = KeyFrame[0].posX;
		//	posY = KeyFrame[0].posY;
		//	posZ = KeyFrame[0].posZ;
		//	rotX = KeyFrame[0].rotX;
		//	rotY = KeyFrame[0].rotY;
		//	rotZ = KeyFrame[0].rotZ;

		//	posX1 = KeyFrame[0].posX1;
		//	posY1 = KeyFrame[0].posY1;
		//	posZ1 = KeyFrame[0].posZ1;
		//	rotX1 = KeyFrame[0].rotX1;
		//	rotY1 = KeyFrame[0].rotY1;
		//	rotZ1 = KeyFrame[0].rotZ1;

		//	posX2 = KeyFrame[0].posX2;
		//	posY2 = KeyFrame[0].posY2;
		//	posZ2 = KeyFrame[0].posZ2;
		//	rotX2 = KeyFrame[0].rotX2;
		//	rotY2 = KeyFrame[0].rotY2;
		//	rotZ2 = KeyFrame[0].rotZ2;

		//	posX3 = KeyFrame[0].posX3;
		//	posY3 = KeyFrame[0].posY3;
		//	posZ3 = KeyFrame[0].posZ3;
		//	rotX3 = KeyFrame[0].rotX3;
		//	rotY3 = KeyFrame[0].rotY3;
		//	rotZ3 = KeyFrame[0].rotZ3;

		//	posX4 = KeyFrame[0].posX4;
		//	posY4 = KeyFrame[0].posY4;
		//	posZ4 = KeyFrame[0].posZ4;
		//	rotX4 = KeyFrame[0].rotX4;
		//	rotY4 = KeyFrame[0].rotY4;
		//	rotZ4 = KeyFrame[0].rotZ4;

		//	posX5 = KeyFrame[0].posX5;
		//	posY5 = KeyFrame[0].posY5;
		//	posZ5 = KeyFrame[0].posZ5;
		//	rotX5 = KeyFrame[0].rotX5;
		//	rotY5 = KeyFrame[0].rotY5;
		//	rotZ5 = KeyFrame[0].rotZ5;

		//	interpolation();

		//	play = true;
		//	playIndex = 0;
		//	i_curr_steps = 0;

		//	} else play = false;
		//	break;

		//case '*': //Reset keyframes
		//	initKeyFrames();
		//	break;

		case '1': //Pantalla completa
			glutFullScreen();
			break;

		case '2': //Ventana
			glutReshapeWindow(500, 500);
			glutPositionWindow(50, 50);
			break;

		case '3': //Controles estilo fps
			g_fps_mode = !g_fps_mode;

			if (g_fps_mode) {
				glutSetCursor(GLUT_CURSOR_NONE);
				glutWarpPointer(g_viewport_width / 2, g_viewport_height / 2);
			}
			else {
				glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
			}
			break;

		case '4': //Cambiar cámara
			swCamera = !swCamera;
			break;

		default:
			break;
  }

  glutPostRedisplay();
}

void MouseMotion(int x, int y)
{
	// This variable is hack to stop glutWarpPointer from triggering an event callback to Mouse(...)
	// This avoids it being called recursively and hanging up the event loop
	static bool just_warped = false;

	if (just_warped) {
		just_warped = false;
		return;
	}

	if (g_fps_mode) {
		int dx = x - g_viewport_width / 2;
		int dy = y - g_viewport_height / 2;

		if (dx) {
			g_camera.RotateYaw(g_rotation_speed*dx);
		}

		if (dy) {
			g_camera.RotatePitch(-g_rotation_speed*dy);
		}

		glutWarpPointer(g_viewport_width / 2, g_viewport_height / 2);

		just_warped = true;
	}
}

int main ( int argc, char** argv ) {   // Main Function

  glutInit(&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize(500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition(0, 0);	//Posicion de la Ventana
  glutCreateWindow("Proyecto Final"); // Nombre de la Ventana
  glutFullScreen( );         // Full Screen
  InitGL();						// Parametros iniciales de la aplicacion
  glutDisplayFunc( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc( Reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutSetCursor(GLUT_CURSOR_NONE);
  glutMotionFunc(MouseMotion);
  glutPassiveMotionFunc(MouseMotion);
  glutKeyboardFunc(keyboard);
  glutIdleFunc(display);

  glutMainLoop( );

  return 0;
}
