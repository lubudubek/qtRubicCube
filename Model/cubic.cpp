#include "cubic.h"
#include "VertexData.h"
#include <QOpenGLShaderProgram>

Cubic::Cubic(std::array<VertexData, 24>&& verts,
             std::array<GLushort, 34>&& indecies,
             QMatrix4x4&& initMatrix):
    m_vertecies(verts),
    m_indecies(indecies),
    m_transformMatrix(initMatrix)
{

}

void Cubic::BindVerts(QOpenGLBuffer &arrayBuf, QOpenGLBuffer& indexBuf)
{
    arrayBuf.write(0, &m_vertecies, sizeof(m_vertecies));
    indexBuf.write(0, &m_indecies, sizeof(m_indecies));
}

void Cubic::UpdateUniform(QOpenGLShaderProgram& program)
{
    program.setUniformValue("CubicTransformMatrix_0", m_transformMatrix);
}

int Cubic::getSizeOfVerts()
{
    return sizeof(m_vertecies);
}

int Cubic::getSizeOfIndecies()
{
    return sizeof(m_indecies);
}
