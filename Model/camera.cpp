#include "camera.h"

Camera::Camera()
{

}

QMatrix4x4 &Camera::getCurrentMatrix()
{
    return m_cameraMatrix;
}

void Camera::recalculateMatrix()
{
    m_aspect = m_width / m_height;
    m_perspective.setToIdentity();
    m_perspective.perspective(m_fov, m_aspect, m_zNear, m_zFar);

    const QVector3D& rotationXAxis = {1.0, 0.0, 0.0};
    const QVector3D& rotationYAxis = {0.0, 1.0, 0.0};

    qDebug() << "angle set";
    QQuaternion rotation;
    rotation = QQuaternion::fromAxisAndAngle(rotationXAxis, m_angleX);
    rotation *= QQuaternion::fromAxisAndAngle(rotationYAxis, m_angleY);
//! [6]
    // Calculate model view transformation
    QMatrix4x4 matrix;
    matrix.translate(0.0, 0.0, m_zTranslation);
    matrix.rotate(rotation);
    m_transform = matrix;

    m_cameraMatrix = m_perspective * m_transform;
}

void Camera::onAngleXChanged(float angle)
{
    setAngleX(angle);
    recalculateMatrix();
}

void Camera::onAngleYChanged(float angle)
{
    setAngleY(angle);
    recalculateMatrix();
}

void Camera::onFovChanged(float angle)
{
    setFov(angle);
    recalculateMatrix();
}

void Camera::onZNearChanged(float value)
{
    setZNear(value);
    recalculateMatrix();
}

void Camera::onZFarChanged(float value)
{
    setZFar(value);
    recalculateMatrix();
}

void Camera::onZTranslationChanged(float value)
{
    setZTranslation(value);
    recalculateMatrix();
}



QMatrix4x4 Camera::getPerspectiveMatrix()
{
    return m_perspective;
}

QMatrix4x4 Camera::getTransformMatrix()
{
    return m_transform;
}

void Camera::setWindowSize(int w, int h)
{
    m_width = float(w);
    m_height = float(h ? h : 1);
}

void Camera::setAngleX(float angle)
{
    m_angleX = angle;
}

void Camera::setAngleY(float angle)
{
    m_angleY = angle;
}

void Camera::setFov(float angle)
{
    m_fov = angle;
}

void Camera::setZFar(float value)
{
    m_zFar = value;
}

void Camera::setZTranslation(float value)
{
    m_zTranslation = value;
}

void Camera::setZNear(float value)
{
    m_zNear = value;
}
