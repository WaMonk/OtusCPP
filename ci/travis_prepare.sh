sudo apt-get install libboost-test-dev libgtest-dev build-essential -y
cd /usr/src/gtest
cmake .
cmake --build . --target install
sudo mv libgtest* /usr/lib/
cd "${TRAVIS_BUILD_DIR}"
echo "deb http://archive.ubuntu.com/ubuntu xenial main universe" | sudo tee -a /etc/apt/sources.list
sudo apt-get update -qq