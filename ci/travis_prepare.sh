CWD=$PWD

echo "Install Modules: "
sudo apt-get install libboost-test-dev libgtest-dev build-essential -y

echo "Configure GTest: "
cd /usr/src/gtest
cmake .
cmake --build . --target install
sudo mv libgtest* /usr/lib/
cd $CWD

echo "Deb update: "
echo "deb http://archive.ubuntu.com/ubuntu xenial main universe" | sudo tee -a /etc/apt/sources.list
sudo apt-get update -qq