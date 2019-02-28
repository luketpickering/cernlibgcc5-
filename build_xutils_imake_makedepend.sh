#!/bin/bash

if [ "${1}" == "1" ] || [ "${2}" == "1" ]; then

mkdir -p xorg
cd xorg

if [ "${1}" == "1" ]; then

mkdir imake
cd imake

wget https://www.x.org/archive/individual/util/imake-1.0.7.tar.gz
tar -zxvf imake-1.0.7.tar.gz

mkdir build
cd build

../imake-1.0.7/configure --prefix=$(readlink -f Linux)
make install

cd ../

echo -e '#!/bin/bash'"\nexport PATH=$(readlink -f build/Linux/bin):\${PATH}" > setup.sh

cd ../

fi

if [ "${2}" == "1" ]; then

mkdir makedepend
cd makedepend

wget https://www.x.org/archive/individual/util/makedepend-1.0.5.tar.gz
tar -zxvf makedepend-1.0.5.tar.gz

mkdir build
cd build

../makedepend-1.0.5/configure --prefix=$(readlink -f Linux)

make install

cd ..

echo -e '#!/bin/bash'"\nexport PATH=$(readlink -f build/Linux/bin):\${PATH}" > setup.sh

fi

cd ..

echo -e '#!/bin/bash' > xorg_utils_setup.sh

if [ "${2}" == "1" ]; then
  echo "source $(readlink -f imake/setup.sh)" >> xorg_utils_setup.sh
fi

if [ "${2}" == "1" ]; then
  echo "source $(readlink -f makedepend/setup.sh)" >> xorg_utils_setup.sh
fi


fi
