#!/bin/bash
    
set -x

PATCHES_DIR=$(pwd)/patches

if [ -z $1 ] || [ -e $1 ]; then
  echo "Please pass a new directory to pull-down-and-patch CERNLIB into."
  exit 1
fi

if ! mkdir $1; then
  echo "Failed to make directory $1 for new CERNLIB install."
  exit 1
fi

if [ ! -e .download_cache ]; then

  mkdir .download_cache
  cd .download_cache

  # gcc 10 needs further modifications that are not here
  # wget --no-check-certificate http://www-zeuthen.desy.de/linear_collider/cernlib/new/cernlib.2005.corr.2019.01.21.tgz
  # cp cernlib.2005.corr.2019.01.21.tgz cernlib.2005.corr.tgz

  # wget --no-check-certificate http://www-zeuthen.desy.de/linear_collider/cernlib/new/cernlib.2005.install.2019.01.21.tgz
  # tar -zxvf cernlib.2005.install.2019.01.21.tgz

  CACHE_DIR=$(pwd)

  wget --no-check-certificate http://www-zeuthen.desy.de/linear_collider/cernlib/new/cernlib-2005-all-new.tgz
  tar -zxvf cernlib-2005-all-new.tgz

  cd ${PATCHES_DIR}/cernlib.2005.corr
  tar -zcvf cernlib.2005.corr.tgz 2005
  mv cernlib.2005.corr.tgz ${CACHE_DIR}/
  cd -


  cd ${PATCHES_DIR}/cernlib.2005.install.2019.01.21
  cp ./* ${CACHE_DIR}/
  cd -

  cd -

fi

cp -r .download_cache/* ${1}/
cd ${1}

cd -

set +x
