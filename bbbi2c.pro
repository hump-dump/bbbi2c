TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    CPDebugMessage.cpp \
    BBoneBlackBMP085.cpp \
    BBoneBlackMC5883L.cpp \
    BBoneBlackI2C/CPBBoneBlackI2C.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    CPDebugMessage.hpp \
    BBoneBlackBMP085.hpp \
    BBoneBlackMC5883L.hpp \
    BBoneBlackI2C/CPBBoneBlackI2C.hpp

CONFIG   += c++11
