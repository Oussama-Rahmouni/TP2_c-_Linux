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
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Camion_Testeur.o \
	${OBJECTDIR}/ContratException.o \
	${OBJECTDIR}/FonctionsCamion.o \
	${OBJECTDIR}/FonctionsVehicule.o \
	${OBJECTDIR}/FonctionsVehiculePromenade.o \
	${OBJECTDIR}/Proprietaire_Testeur.o \
	${OBJECTDIR}/Vehicule.o \
	${OBJECTDIR}/VehiculePromenade_Testeur.o \
	${OBJECTDIR}/Vehicule_Testeur.o \
	${OBJECTDIR}/gestionImmatriculation.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/vehicule_2.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/vehicule_2.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/vehicule_2 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Camion_Testeur.o: Camion_Testeur.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Camion_Testeur.o Camion_Testeur.cpp

${OBJECTDIR}/ContratException.o: ContratException.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ContratException.o ContratException.cpp

${OBJECTDIR}/FonctionsCamion.o: FonctionsCamion.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FonctionsCamion.o FonctionsCamion.cpp

${OBJECTDIR}/FonctionsVehicule.o: FonctionsVehicule.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FonctionsVehicule.o FonctionsVehicule.cpp

${OBJECTDIR}/FonctionsVehiculePromenade.o: FonctionsVehiculePromenade.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FonctionsVehiculePromenade.o FonctionsVehiculePromenade.cpp

${OBJECTDIR}/Proprietaire_Testeur.o: Proprietaire_Testeur.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Proprietaire_Testeur.o Proprietaire_Testeur.cpp

${OBJECTDIR}/Vehicule.o: Vehicule.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Vehicule.o Vehicule.cpp

${OBJECTDIR}/VehiculePromenade_Testeur.o: VehiculePromenade_Testeur.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VehiculePromenade_Testeur.o VehiculePromenade_Testeur.cpp

${OBJECTDIR}/Vehicule_Testeur.o: Vehicule_Testeur.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Vehicule_Testeur.o Vehicule_Testeur.cpp

${OBJECTDIR}/gestionImmatriculation.o: gestionImmatriculation.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gestionImmatriculation.o gestionImmatriculation.cpp

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
