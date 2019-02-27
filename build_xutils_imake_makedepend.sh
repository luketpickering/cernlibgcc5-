#!/bin/bash

mkdir -p xorg/imake
cd xorg/imake

wget https://www.x.org/archive/individual/util/imake-1.0.7.tar.gz
tar -zxvf imake-1.0.7.tar.gz

mkdir build
cd build

../imake-1.0.7/configure --prefix=$(readlink -f Linux)
make install

cd ../

echo -e "#!/bin/bash\nexport PATH=$(readlink -f build/Linux/bin):\${PATH}" > setup.sh

cd ../

mkdir makedepend
cd makedepend

wget https://www.x.org/archive/individual/util/makedepend-1.0.5.tar.gz
tar -zxvf makedepend-1.0.5.tar.gz

mkdir build
cd build

../makedepend-1.0.5/configure --prefix=$(readlink -f Linux)

make install

cd ..

echo -e "#!/bin/bash\nexport PATH=$(readlink -f build/Linux/bin):\${PATH}" > setup.sh

cd ..

echo -e "#!/bin/bash\nsource $(readlink -f imake/setup.sh)\nsource $(readlink -f makedepend/setup.sh)" > setup.sh

