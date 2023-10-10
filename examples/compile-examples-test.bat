@echo off
rem This batch script deletes the 'output' directory, compiles examples using 'compile-examples.py',
rem and then runs various executable files.

rem Delete the 'output' directory if it exists and create a new one.
rmdir /S /Q output
mkdir output

echo Compiling...
rem Call the 'compile-examples.py' script to compile the examples.
python compile-examples.py
echo Compilation completed.

echo.
echo Automatically seeded examples:
rem Run the executable files for automatically seeded examples.
output\random1.exe
output\random2.exe
output\random3.exe

echo.
echo Fixed seed examples:
rem Run the executable files for examples with a fixed seed.
output\fixed1.exe
output\fixed2.exe
output\fixed3.exe

echo.
echo Externally seeded examples:
rem Run the executable files for externally seeded examples.
output\seeded1.exe
output\seeded2.exe
output\seeded3.exe

echo.
echo Types example:
rem Run the executable file for the 'types' example.
output\types.exe

pause
