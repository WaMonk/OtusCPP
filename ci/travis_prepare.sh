#!/bin/bash
CWD=$PWD
#
echo "Deb update: "
sudo apt-add-repository universe main
sudo apt-get update
#
echo "Install Modules: "
sudo apt-get install libboost-test-dev build-essential libgtest-dev cmake
#
echo "Configure GTest: "
cd /usr/src/gtest
sudo cmake .
sudo cmake --build .
sudo cp *.a /usr/lib/
cd $CWD

echo "Finish."