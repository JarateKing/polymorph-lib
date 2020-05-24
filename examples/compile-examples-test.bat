rmdir /S /Q output
mkdir output
compile-examples.py
echo automatically seeded
output\random1.exe
output\random2.exe
output\random3.exe
echo fixed seed
output\fixed1.exe
output\fixed2.exe
output\fixed3.exe
echo externally seeded
output\seeded1.exe
output\seeded2.exe
output\seeded3.exe
echo types
output\types.exe
pause