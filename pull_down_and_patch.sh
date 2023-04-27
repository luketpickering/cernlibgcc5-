#!/bin/bash

set -e

BUILD_DIR=$(readlink -f ${1})

BUILD_ROOT_DIR=$(pwd)

PATCHES_DIR=$(pwd)/patches

if [ -z ${BUILD_DIR} ] || [ -e ${BUILD_DIR} ]; then
  echo "Please pass a new directory to pull-down-and-patch CERNLIB into."
  exit 1
fi

if ! mkdir ${BUILD_DIR}; then
  echo "Failed to make directory ${BUILD_DIR} for new CERNLIB install."
  exit 1
fi

if [ ! -e .download_cache ]; then

  mkdir .download_cache
  cd .download_cache

  wget --no-check-certificate http://www-zeuthen.desy.de/linear_collider/cernlib/new/cernlib-2005-all-new.tgz
  tar -zxvf cernlib-2005-all-new.tgz
fi

cp -r ${BUILD_ROOT_DIR}/.download_cache/* ${BUILD_DIR}/
cd ${BUILD_DIR}

cd ${PATCHES_DIR}/cernlib.2005.corr
tar -zcvf cernlib.2005.corr.tgz 2005
mv cernlib.2005.corr.tgz ${BUILD_DIR}/
cd -


cd ${PATCHES_DIR}/cernlib.2005.install.2023.04.27
cp ./* ${BUILD_DIR}/
cd -


cd -
