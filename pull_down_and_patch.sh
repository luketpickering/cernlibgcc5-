#!/bin/bash
    
set -x

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

  wget http://www-zeuthen.desy.de/linear_collider/cernlib/new/cernlib-2005-all-new.tgz
  tar -zxvf cernlib-2005-all-new.tgz
  wget http://www-zeuthen.desy.de/linear_collider/cernlib/new/cernlib.2005.corr.2019.01.21.tgz
  cp cernlib.2005.corr.2019.01.21.tgz cernlib.2005.corr.tgz
  wget http://www-zeuthen.desy.de/linear_collider/cernlib/new/cernlib.2005.install.2019.01.21.tgz
  tar -zxvf cernlib.2005.install.2019.01.21.tgz

  cd -

fi

cp -r .download_cache/* ${1}/
cd ${1}

# patch < ../cernlib.gcc5andup.patch

cd -

set +x
