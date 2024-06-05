#!/bin/bash

clear
read -p "Name of the Directory: " name
mkdir $name || { echo "Exiting Process"; exit 1; }

# copy the template file
touch "$name/aA.cpp"
cp Algorithms\ and\ Templates/template.cpp "$name/aA.cpp"

# move inside directory
cd "$name/" || { echo "Failed to change directory to $name/"; exit 1; }

# create all cpp and in files
touch aB.cpp aC.cpp aD.cpp aE.cpp aF.cpp aG.cpp aH.cpp aI.cpp aJ.cpp

cp aA.cpp aB.cpp
cp aA.cpp aC.cpp
cp aA.cpp aD.cpp
cp aA.cpp aE.cpp
cp aA.cpp aF.cpp
cp aA.cpp aG.cpp
cp aA.cpp aH.cpp
cp aA.cpp aI.cpp
cp aA.cpp aJ.cpp

touch aA.in aB.in aC.in aD.in aE.in aF.in aG.in aH.in aI.in aJ.in

echo "Done! standart: c++ aA.cpp -std=c++20 -o aA && ./aA < aA.in"
