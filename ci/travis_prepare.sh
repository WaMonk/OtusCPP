#!/bin/bash
CWD=$PWD
#
echo "Deb update: "
sudo apt-add-repository universe main
sudo apt-get update
#
echo "Install Modules: "
sudo apt-get install libboost-test-dev build-essential libgtest-dev
#
echo "Configure GTest: "
sudo cd /usr/src/gtest
sudo cmake .
sudo cmake --build . --target install
sudo mv libgtest* /usr/lib/
cd $CWD

echo "Finish."