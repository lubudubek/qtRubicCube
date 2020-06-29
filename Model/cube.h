#ifndef CUBE_H
#define CUBE_H

#include <vector>
#include <memory>

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

class Cubic;
class QOpenGLShaderProgram;


class Cube : public QObject
{
    Q_OBJECT
public:
    Cube();
    void addCubic(std::shared_ptr<Cubic> cubic);

public slots:
    void initCubeGeometry(QOpenGLBuffer& arrayBuf,
                          QOpenGLBuffer& indexBuf);
    void UpdateUniforms(QOpenGLShaderProgram& program);
private:
    std::vector<std::shared_ptr<Cubic>> m_cubics;

};

#endif // CUBE_H
