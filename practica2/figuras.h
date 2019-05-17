#include "Main.h"


class CFiguras {
	public:

	float tizq3, tder3;
	float tizq5, tder5;
	float tizq12, tder12;

	void cuartoInt(GLuint text, GLuint text2, GLuint text3, GLuint text4);
	void cono(float altura, float radio, int resolucion, GLuint text);		
	void planoSolid(GLfloat text);
	void planoTrans(GLfloat text);
	void planoAnim3(GLuint text);
	void planoAnim5(GLuint text);
	void planoAnim12(GLuint text);
	void piezaJenga(GLuint text);
	void esfera(GLfloat radio, int meridianos, int paralelos, GLuint text);
	void prisma(float altura, float largo, float profundidad, GLuint text);//Funcíon creacion prisma

	void prisma2 (GLuint text, GLuint text2, GLuint text3, GLuint text4);
	void cilindro(float radio, float altura, int resolucion, GLuint text);	//Funcíon creacion cilindro


};
