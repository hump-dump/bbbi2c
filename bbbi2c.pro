TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    CPBBoneBlackI2C.cpp \
    CPDebugMessage.cpp \
    BBoneBlackBMP085.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    CPBBoneBlackI2C.hpp \
    CPDebugMessage.hpp \
    BBoneBlackBMP085.hpp

CONFIG   += c++11
