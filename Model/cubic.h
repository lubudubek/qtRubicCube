#ifndef CUBIC_H
#define CUBIC_H

#include "VertexData.h"
#include <QOpenGLBuffer>
#include <qmatrix4x4.h>

class QOpenGLShaderProgram;

class Cubic
{
public:
    Cubic(std::array<VertexData, 24>&& verts,
          std::array<GLushort, 34>&& indecies,
          QMatrix4x4&& initMatrix);
    void BindVerts(QOpenGLBuffer& arrayBuf, QOpenGLBuffer& indexBuf);
    void UpdateUniform(QOpenGLShaderProgram& program);
    static int getSizeOfVerts();
    static int getSizeOfIndecies();

private:
    std::array<VertexData, 24> m_vertecies;
    std::array<GLushort, 34> m_indecies;
    QMatrix4x4 m_transformMatrix;
};

#endif // CUBIC_H
