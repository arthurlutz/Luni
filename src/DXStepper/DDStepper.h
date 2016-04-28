
#ifndef DDStepper_h
#define DDStepper_h

#include <Device/DeviceDriver.h>
#include <Device/LogicalUnitInfo.h>
#include <Framework/ByteOrder.h>

/**
 * This class defines a stepper motor device driver using the asynchronous
 * FirmataStepper library that is standard with Firmata.  The library was
 * renamed AsyncStepper for this use but otherwise it is the exact same code
 * as comes standard with Firmata.
 */
class DDStepper: public DeviceDriver {

public:

  DDStepper(const char *dName, int addrCount);

  int open(int opts, int flags, const char *name);
  int read(int handle, int flags, int reg, int count, byte *buf);
  int write(int handle, int flags, int reg, int count, byte *buf);
  int close(int handle, int flags);

  int processTimerEvent(int lun, int timerIndex, ClientReporter *r);

// Stepper register definitions

enum class REG : int {
    MoveRelative = 0,
    RPMSpeeds = 1,
    PositionEvent = 2
};

private:

  int writeConfigure(int handle, int flags, int reg, int count, byte *buf);
  int writeMoveRelative(int handle, int flags, int reg, int count, byte *buf);
  int writeRPMSpeeds(int handle, int flags, int reg, int count, byte *buf);
  int readRPMSpeeds(int handle, int flags, int reg, int count, byte *buf);
  int readPositionEvent(int handle, int flags, int reg, int count, byte *buf);

};

#endif
