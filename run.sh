#!/bin/bash

cd src 
mkdir build
cd build
cmake ..
make
./FinancialProgram
