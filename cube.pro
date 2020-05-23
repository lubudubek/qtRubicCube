QT       += core gui widgets

TARGET = cube
TEMPLATE = app

SOURCES += main.cpp \
    camera.cpp \
    cube.cpp \
    cubefactory.cpp \
    cubic.cpp \
    game.cpp \
    indeciesbuilder.cpp \
    positions.cpp \
    vertices.cpp \
    verticiesdata.cpp

SOURCES += \
    mainwidget.cpp \
    geometryengine.cpp

HEADERS += \
    camera.h \
    cube.h \
    cubefactory.h \
    cubic.h \
    game.h \
    indeciesbuilder.h \
    mainwidget.h \
    geometryengine.h \
    positions.h \
    vertices.h \
    verticiesdata.h

RESOURCES += \
    shaders.qrc \
    textures.qrc

# install
#target.path = $$[QT_INSTALL_EXAMPLES]/opengl/cube
#INSTALLS += target
