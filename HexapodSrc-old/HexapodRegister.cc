#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <iocsh.h>
#include "motor.h"
#include "drvHexapod.h"
#include "epicsExport.h"

extern "C"
{

// Hexapod Setup arguments
static const iocshArg setupArg0 = {"Max. controller count", iocshArgInt};
static const iocshArg setupArg1 = {"Polling rate", iocshArgInt};
// Hexapod Config arguments
static const iocshArg configArg0 = {"Card being configured", iocshArgInt};
static const iocshArg configArg1 = {"asyn port name", iocshArgString};
static const iocshArg configArg2 = {"asyn address (GPIB)", iocshArgInt};
// Motor Name Config arguments
static const iocshArg motorArg0 = {"Card number", iocshArgInt};
static const iocshArg motorArg1 = {"Motor name", iocshArgString};

static const iocshArg * const HexapodSetupArgs[2]  = {&setupArg0, &setupArg1};
static const iocshArg * const HexapodConfigArgs[3] = {&configArg0, &configArg1,
                                                     &configArg2};
static const iocshArg * const MotorNameConfigArgs[2]  = {&motorArg0, &motorArg1};

static const iocshFuncDef    setupHexapod = {"HexapodSetup",  2, HexapodSetupArgs};
static const iocshFuncDef   configHexapod = {"HexapodConfig", 3, HexapodConfigArgs};
static const iocshFuncDef configMotorName = {"MotorNameConfig", 2, MotorNameConfigArgs};

static void setupHexapodCallFunc(const iocshArgBuf *args)
{
    HexapodSetup(args[0].ival, args[1].ival);
}


static void configHexapodCallFunc(const iocshArgBuf *args)
{
    HexapodConfig(args[0].ival, args[1].sval, args[2].ival);
}

static void configMotorNameCallFunc(const iocshArgBuf *args)
{
    MotorNameConfig(args[0].ival, args[1].sval);
}

static void HexapodmotorRegister(void)
{
    iocshRegister(&setupHexapod,  setupHexapodCallFunc);
    iocshRegister(&configHexapod, configHexapodCallFunc);
    iocshRegister(&configMotorName, configMotorNameCallFunc);
}

epicsExportRegistrar(HexapodmotorRegister);

} // extern "C"
