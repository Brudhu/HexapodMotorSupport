#ifndef DRVHEXAPOD_H
#define DRVHEXAPOD_H


#include "motordrvCom.h"
#include "asynDriver.h"
#include "asynDriver.h"
#include "asynOctetSyncIO.h"

#define COMM_TIMEOUT 2		/* Timeout in seconds. */
#define POS_RES 0.001		/* CHECK** Position resolution. */

#define EOL_HEXAPOD    "\n"        /* Command End-Of-Line = LF (0x10) */

// Definitions of the MSTA word:
#define STATUS_DIRECTION    (0x0001)
#define STATUS_DONE         (0x0002)
#define STATUS_PLUS_LS      (0x0004)
#define STATUS_HOME_LS      (0x0008)
#define STATUS_POSITION     (0x0020)
#define STATUS_SLIP_STALL   (0x0040)
#define STATUS_HOME         (0x0080)
#define STATUS_PRESENT      (0x0100)
#define STATUS_PROBLEM      (0x0200)
#define STATUS_MOVING       (0x0400)
#define STATUS_GAIN_SUPP    (0x0800)
#define STATUS_COMM_ERR     (0x1000)
#define STATUS_MINUS_LS     (0x2000)
#define STATUS_HOMED        (0x4000)

struct Hexapodcontroller
{
    asynUser *pasynUser;	/* asynUser structure */
    int asyn_address;		/* Use for GPIB or other address with asyn */
    CommStatus status;		/* Controller communication status. */
    double drive_resolution[4];
    bool versionSupport;        /* Track supported Versions - include in Report */
    char asyn_port[80];		/* asyn port name */
};


/* Function prototypes. */
extern RTN_STATUS HexapodSetup(int);
extern RTN_STATUS HexapodConfig(int, const char *, int);

#endif // DRVHEXAPOD_H
