# uncomment these if running from default project location
# Path to ChibiOS
CHIBIOS    = convex/ChibiOS_2.6.2
# Path to convex
CONVEX     = convex/convex/cortex

# uncomment to use the optional code like the smart motor library
CONVEX_OPT  = yes

# User C code files
VEXUSERSRC = vexuser.c bcamsc-lib/libbcamsc/array_utils.c

# Uncomment and add/modify user include files
VEXUSERINC = vexuser.h bcamsc-lib/libbcamsc/array_utils.h

