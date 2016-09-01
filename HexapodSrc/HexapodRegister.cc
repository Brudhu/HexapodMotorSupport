#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <iocsh.h>
#include "motor.h"
#include "drvHexapod.h" //#include "drvPIE517.h"
#include "epicsExport.h"

extern "C"
{

// Hexapod Setup arguments
//static const iocshArg setupArg0 = {"Max. controller count", iocshArgInt};
static const iocshArg setupArg0 = {"Polling rate", iocshArgInt};
// Hexapod Config arguments
static const iocshArg configArg0 = {"Card being configured", iocshArgInt};
static const iocshArg configArg1 = {"asyn port name", iocshArgString};
static const iocshArg configArg2 = {"asyn address (GPIB)", iocshArgInt};

static const iocshArg * const HexapodSetupArgs[1]  = {&setupArg0};
static const iocshArg * const HexapodConfigArgs[3] = {&configArg0, &configArg1,
                                                     &configArg2};

static const iocshFuncDef  setupHexapod = {"HexapodSetup",  1, HexapodSetupArgs};
static const iocshFuncDef configHexapod = {"HexapodConfig", 3, HexapodConfigArgs};

static void setupHexapodCallFunc(const iocshArgBuf *args)
{
    HexapodSetup(args[0].ival);
}


static void configHexapodCallFunc(const iocshArgBuf *args)
{
    HexapodConfig(args[0].ival, args[1].sval, args[2].ival);
}


static void HexapodmotorRegister(void)
{
    iocshRegister(&setupHexapod,  setupHexapodCallFunc);
    iocshRegister(&configHexapod, configHexapodCallFunc);
}

epicsExportRegistrar(HexapodmotorRegister);

} // extern "C"
