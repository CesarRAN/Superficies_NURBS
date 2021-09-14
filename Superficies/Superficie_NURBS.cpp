#include <stdlib.h>
#include "SNURBS.h"
#include <GL/glut.h>
#include <math.h>


SupNURBS::SupNURBS() {

    /*Guardar los valores del arreglo ctrlpoints[][] en el archivo y cargarlo
    en el contructor para inicializar la figura de la curva spline*/

    pointsNumU = 4;
    pointsNumV = 4;

   
}

void SupNURBS::addPoint(GLfloat p_x, GLfloat p_y, GLfloat p_z) {
    ctrlpoints[pointsNumU][pointsNumV][0] = p_x;
    ctrlpoints[pointsNumU][pointsNumV][1] = p_y;
    ctrlpoints[pointsNumU][pointsNumV][2] = p_z;
    pointsNumU++;
}

void SupNURBS::moveSplineC(GLfloat p_x, GLfloat p_y, GLfloat p_z) {

    GLint i, j;
    for (i = 0; i < pointsNumU; i++) {
        for (j = 0; j < pointsNumV; j++) {
            ctrlpoints[i][j][0] = ctrlpoints[i][j][0] + p_x;
            ctrlpoints[i][j][1] = ctrlpoints[i][j][1] + p_y;
            ctrlpoints[i][j][2] = ctrlpoints[i][j][2] + p_z;
        }
    }
}

void SupNURBS::moveSplinePoint(GLfloat p_x, GLfloat p_y, GLfloat p_z, GLint i, GLint j) {
    ctrlpoints[i][j][0] = ctrlpoints[i][j][0] + p_x;
    ctrlpoints[i][j][1] = ctrlpoints[i][j][1] + p_y;
    ctrlpoints[i][j][2] = ctrlpoints[i][j][2] + p_z;
}

void SupNURBS::rotateSplineC(GLint axis, GLfloat angle) {

    switch (axis) {
    case 0:
        for (GLint i = 0; i < pointsNumU; i++) {
            for (GLint j = 0; j < pointsNumV; j++){
                ctrlpoints[i][j][1] = cos(angle) * ctrlpoints[i][j][1] - sin(angle) * ctrlpoints[i][j][2];
                ctrlpoints[i][j][2] = sin(angle) * ctrlpoints[i][j][1] + cos(angle) * ctrlpoints[i][j][2];
             }
        }
        break;
    case 1:
        for (GLint i = 0; i < pointsNumU; i++) {
            for (GLint j = 0; j < pointsNumV; j++) {
                ctrlpoints[i][j][0] = cos(angle) * ctrlpoints[i][j][0] + sin(angle) * ctrlpoints[i][j][2];
                ctrlpoints[i][j][2] = cos(angle) * ctrlpoints[i][j][2] - sin(angle) * ctrlpoints[i][j][0];
            }
        }
        break;
    case 2:
        for (GLint i = 0; i < pointsNumU; i++) {
            for (GLint j = 0; j < pointsNumV; j++) {
                ctrlpoints[i][j][1] = cos(angle) * ctrlpoints[i][j][0] - sin(angle) * ctrlpoints[i][j][1];
                ctrlpoints[i][j][2] = sin(angle) * ctrlpoints[i][j][0] + cos(angle) * ctrlpoints[i][j][1];
            }
        }
    
        break;
    default:
        break;
    }
}

GLfloat* SupNURBS::getctrlpoints(GLint i, GLint j) {
    return ctrlpoints[i][j];
}



GLint SupNURBS::getpoitsNum() {
    return pointsNumU;
}