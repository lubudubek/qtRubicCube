#pragma once

#include "cube.h"
#include "VertexData.h"
#include <iostream>
#include "cubic.h"
#include <QOpenGLShaderProgram>

Cube::Cube()
{

}

void Cube::addCubic(std::shared_ptr<Cubic> cubic)
{
    m_cubics.push_back(cubic);
}

void Cube::initCubeGeometry(QOpenGLBuffer& arrayBuf,
                            QOpenGLBuffer& indexBuf)
{
    arrayBuf.bind();
    arrayBuf.allocate(Cubic::getSizeOfVerts());
    indexBuf.bind();
    indexBuf.allocate(Cubic::getSizeOfIndecies());
    std::for_each(m_cubics.begin(), m_cubics.end(), [&](auto& cubic){cubic->BindVerts(arrayBuf, indexBuf);});
}

void Cube::UpdateUniforms(QOpenGLShaderProgram& program)
{
    std::for_each(m_cubics.begin(), m_cubics.end(), [&](auto& cubic){cubic->UpdateUniform(program);});
}
