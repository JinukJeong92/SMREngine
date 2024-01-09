# SMR Engine
SMR Engine

# Window
git clone --recurse-submodules https://github.com/JinukJeong92/SMREngine.git
cd SMREngine

# Ubuntu 22
sudo apt-get update
sudo apt-get install -y git
git clone --recurse-submodules https://github.com/JinukJeong92/SMREngine.git

cd SMREngine
cd bin
mkdir bin
cmake ..
make -j8
ls -l
./SMREngine

