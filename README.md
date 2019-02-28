# cernlibgcc5-
A patch and build script for building cerlib2005 with gcc5+

Run build_cernlib.sh

This will check dependencies (openmotif Xt gmp csh imake makedepend gfortran) and then
pull down and patch cernlib2005 and attempt to build it. Standalone local versions
of imake and makedepend can be built with the build_xutils_imake_makedepend.sh
script which will also dump a simple env setup script into $(pwd)/xorg

The build should take about 30-40 minutes.
