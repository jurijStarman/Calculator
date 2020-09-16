
clear
if [ -d build ]; then
echo "Removing build folder"
rm -r build
fi

echo "Creating build folder"
mkdir build
cd build

echo "Running cmake"
cmake ..
make

echo "Running test executable"
./testCalc

