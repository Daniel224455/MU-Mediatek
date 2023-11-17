#include <PiPei.h>

#include <Library/IoLib.h>
#include <Library/PcdLib.h>
#include <Library/PlatformPrePiLib.h>

#include "PlatformUtils.h"

VOID PlatformInitialize(VOID)
{
  // Initialize GIC
  MmioWrite32(GICR_WAKER_CURRENT_CPU, (MmioRead32(GICR_WAKER_CURRENT_CPU) & ~GIC_WAKER_PROCESSORSLEEP));

  // Enable Frame Buffer Writes
  MmioWrite32(0x19030000, 0x1281);
}
