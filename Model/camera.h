#ifndef CAMERA_H
#define CAMERA_H
#include <QMatrix4x4>
#include <QObject>

class Camera : public QObject
{
    Q_OBJECT
public:
    explicit Camera();
    QMatrix4x4& getCurrentMatrix();
    void setWindowSize(int w, int h);
    void setAngleX(float angle);
    void setAngleY(float angle);
    void setFov(float angle);
    void setZNear(float value);
    void setZFar(float value);
    void setZTranslation(float value);
    void recalculateMatrix();

signals:

public slots:
    void onAngleXChanged(float);
    void onAngleYChanged(float);
    void onFovChanged(float);
    void onZNearChanged(float);
    void onZFarChanged(float);
    void onZTranslationChanged(float);

private:
    QMatrix4x4 getPerspectiveMatrix();
    QMatrix4x4 getTransformMatrix();

private:
    float m_zNear {2.0}, m_zFar {30.0}, m_fov {45.0};
    QMatrix4x4 m_perspective;
    QMatrix4x4 m_transform;
    QMatrix4x4 m_cameraMatrix;

    float m_aspect;
    float m_width {1.0}, m_height {1.0};
    float m_angleX {15.0}, m_angleY {30.0};
    float m_zTranslation {-15.0};
};

#endif // CAMERA_H
