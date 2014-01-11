#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=clang
CCC=clang++
CXX=clang++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=CLang-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1787047461/Action.o \
	${OBJECTDIR}/_ext/1787047461/ClientConnectionFactory.o \
	${OBJECTDIR}/_ext/1787047461/Connection.o \
	${OBJECTDIR}/_ext/1787047461/ConnectionFactory.o \
	${OBJECTDIR}/_ext/1787047461/EPoll.o \
	${OBJECTDIR}/_ext/1787047461/Listener.o \
	${OBJECTDIR}/_ext/1787047461/MessageParser.o \
	${OBJECTDIR}/_ext/1787047461/Select.o \
	${OBJECTDIR}/_ext/1787047461/SelectCallBack.o \
	${OBJECTDIR}/_ext/1787047461/SelectCallBackOne.o \
	${OBJECTDIR}/_ext/1787047461/ServerConnectionFactory.o \
	${OBJECTDIR}/_ext/1787047461/SocketMessage.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libCppSocket.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libCppSocket.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libCppSocket.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/_ext/1787047461/Action.o: ../../Source/Action.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1787047461
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1787047461/Action.o ../../Source/Action.cpp

${OBJECTDIR}/_ext/1787047461/ClientConnectionFactory.o: ../../Source/ClientConnectionFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1787047461
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1787047461/ClientConnectionFactory.o ../../Source/ClientConnectionFactory.cpp

${OBJECTDIR}/_ext/1787047461/Connection.o: ../../Source/Connection.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1787047461
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1787047461/Connection.o ../../Source/Connection.cpp

${OBJECTDIR}/_ext/1787047461/ConnectionFactory.o: ../../Source/ConnectionFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1787047461
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1787047461/ConnectionFactory.o ../../Source/ConnectionFactory.cpp

${OBJECTDIR}/_ext/1787047461/EPoll.o: ../../Source/EPoll.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1787047461
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1787047461/EPoll.o ../../Source/EPoll.cpp

${OBJECTDIR}/_ext/1787047461/Listener.o: ../../Source/Listener.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1787047461
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1787047461/Listener.o ../../Source/Listener.cpp

${OBJECTDIR}/_ext/1787047461/MessageParser.o: ../../Source/MessageParser.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1787047461
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1787047461/MessageParser.o ../../Source/MessageParser.cpp

${OBJECTDIR}/_ext/1787047461/Select.o: ../../Source/Select.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1787047461
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1787047461/Select.o ../../Source/Select.cpp

${OBJECTDIR}/_ext/1787047461/SelectCallBack.o: ../../Source/SelectCallBack.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1787047461
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1787047461/SelectCallBack.o ../../Source/SelectCallBack.cpp

${OBJECTDIR}/_ext/1787047461/SelectCallBackOne.o: ../../Source/SelectCallBackOne.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1787047461
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1787047461/SelectCallBackOne.o ../../Source/SelectCallBackOne.cpp

${OBJECTDIR}/_ext/1787047461/ServerConnectionFactory.o: ../../Source/ServerConnectionFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1787047461
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1787047461/ServerConnectionFactory.o ../../Source/ServerConnectionFactory.cpp

${OBJECTDIR}/_ext/1787047461/SocketMessage.o: ../../Source/SocketMessage.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1787047461
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1787047461/SocketMessage.o ../../Source/SocketMessage.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libCppSocket.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
