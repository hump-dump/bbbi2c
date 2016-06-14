TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    CPBBoneBlackI2C.cpp \
    CPDebugMessage.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    CPBBoneBlackI2C.hpp \
    CPDebugMessage.hpp

CONFIG   += c++11
