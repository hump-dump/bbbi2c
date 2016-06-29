TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    CPBBoneBlackI2C.cpp \
    CPDebugMessage.cpp \
    BBoneBlackBMP085.cpp \
    BBoneBlackMC5883L.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    CPBBoneBlackI2C.hpp \
    CPDebugMessage.hpp \
    BBoneBlackBMP085.hpp \
    BBoneBlackMC5883L.hpp

CONFIG   += c++11
