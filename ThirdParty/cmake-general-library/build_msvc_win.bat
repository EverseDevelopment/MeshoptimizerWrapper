:: create new build directory
rmdir build
mkdir build
cd build

cmake ../ -DCMAKE_GENERATOR_PLATFORM=x64 -DBOOST_ROOT_PATH="c:/local/boost_1_68_0"
cmake --build . --target install --config Release

cd ..
pause