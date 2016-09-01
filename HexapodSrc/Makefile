# Makefile
TOP = ../..
include $(TOP)/configure/CONFIG

# Both the following line, and a line in the *.dbd file,
# must be uncommented to use diagnostic debugging messages.
#!USR_CXXFLAGS += -DDEBUG

DBD += devHexapodMotor.dbd

LIBRARY_IOC = HEXAPOD

# Intelligent Motion Systems driver support.
SRCS += devHexapod.cc drvHexapod.cc HexapodRegister.cc


HEXAPOD_LIBS += motor asyn
HEXAPOD_LIBS += $(EPICS_BASE_IOC_LIBS)

include $(TOP)/configure/RULES

