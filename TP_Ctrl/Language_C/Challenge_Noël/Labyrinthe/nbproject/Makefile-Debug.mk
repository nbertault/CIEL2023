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
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/lib/bdf-font.o \
	${OBJECTDIR}/lib/content-streamer.o \
	${OBJECTDIR}/lib/framebuffer.o \
	${OBJECTDIR}/lib/gpio.o \
	${OBJECTDIR}/lib/graphics.o \
	${OBJECTDIR}/lib/hardware-mapping.o \
	${OBJECTDIR}/lib/led-matrix-c.o \
	${OBJECTDIR}/lib/led-matrix.o \
	${OBJECTDIR}/lib/multiplex-mappers.o \
	${OBJECTDIR}/lib/options-initialize.o \
	${OBJECTDIR}/lib/pixel-mapper.o \
	${OBJECTDIR}/lib/thread.o \
	${OBJECTDIR}/lib/transformer.o \
	${OBJECTDIR}/main.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/labyrinthe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/labyrinthe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/labyrinthe ${OBJECTFILES} ${LDLIBSOPTIONS} -lpthread

${OBJECTDIR}/lib/bdf-font.o: lib/bdf-font.cc
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/bdf-font.o lib/bdf-font.cc

${OBJECTDIR}/lib/content-streamer.o: lib/content-streamer.cc
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/content-streamer.o lib/content-streamer.cc

${OBJECTDIR}/lib/framebuffer.o: lib/framebuffer.cc
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/framebuffer.o lib/framebuffer.cc

${OBJECTDIR}/lib/gpio.o: lib/gpio.cc
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/gpio.o lib/gpio.cc

${OBJECTDIR}/lib/graphics.o: lib/graphics.cc
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/graphics.o lib/graphics.cc

${OBJECTDIR}/lib/hardware-mapping.o: lib/hardware-mapping.c
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/hardware-mapping.o lib/hardware-mapping.c

${OBJECTDIR}/lib/led-matrix-c.o: lib/led-matrix-c.cc
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/led-matrix-c.o lib/led-matrix-c.cc

${OBJECTDIR}/lib/led-matrix.o: lib/led-matrix.cc
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/led-matrix.o lib/led-matrix.cc

${OBJECTDIR}/lib/multiplex-mappers.o: lib/multiplex-mappers.cc
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/multiplex-mappers.o lib/multiplex-mappers.cc

${OBJECTDIR}/lib/options-initialize.o: lib/options-initialize.cc
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/options-initialize.o lib/options-initialize.cc

${OBJECTDIR}/lib/pixel-mapper.o: lib/pixel-mapper.cc
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/pixel-mapper.o lib/pixel-mapper.cc

${OBJECTDIR}/lib/thread.o: lib/thread.cc
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/thread.o lib/thread.cc

${OBJECTDIR}/lib/transformer.o: lib/transformer.cc
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/transformer.o lib/transformer.cc

${OBJECTDIR}/main.o: main.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
