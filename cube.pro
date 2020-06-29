QT       += core gui widgets

TARGET = cube
TEMPLATE = app

SOURCES += main.cpp \
    MgrView/mgrview.cpp \
    Model/camera.cpp \
    Model/cube.cpp \
    Model/cubefactory.cpp \
    Model/cubic.cpp \
    Model/game.cpp \
    Model/indeciesbuilder.cpp \
    Model/positions.cpp \
    Model/vertices.cpp \
    View/mainwidget.cpp \
    View/mainwindow.cpp \
    startup.cpp \
    verticiesdata.cpp

HEADERS += \
    MgrView/mgrview.h \
    Model/VertexData.h \
    Model/camera.h \
    Model/cube.h \
    Model/cubefactory.h \
    Model/cubic.h \
    Model/game.h \
    Model/indeciesbuilder.h \
    Model/positions.h \
    Model/vertices.h \
    View/mainwidget.h \
    View/mainwindow.h \
    startup.h \
    verticiesdata.h

RESOURCES += \
    shaders.qrc \
    textures.qrc

# install
#target.path = $$[QT_INSTALL_EXAMPLES]/opengl/cube
#INSTALLS += target

FORMS += \
    View/mainwindow.ui
