@echo off

rmdir /S /Q output
mkdir output

echo compiling
compile-examples.py
echo compiled

echo.
echo automatically seeded
output\random1.exe
output\random2.exe
output\random3.exe

echo.
echo fixed seed
output\fixed1.exe
output\fixed2.exe
output\fixed3.exe

echo.
echo externally seeded
output\seeded1.exe
output\seeded2.exe
output\seeded3.exe

echo.
echo types
output\types.exe

pause