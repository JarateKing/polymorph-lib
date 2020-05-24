import os
import random
import time

# default seed, wait in between for different seed
os.system('g++ -g -O2 -std=gnu++17 -static simple.cpp -o output/random1.exe')
time.sleep(1)
os.system('g++ -g -O2 -std=gnu++17 -static simple.cpp -o output/random2.exe')
time.sleep(1)
os.system('g++ -g -O2 -std=gnu++17 -static simple.cpp -o output/random3.exe')

# fixed seed
os.system('g++ -g -O2 -std=gnu++17 -D __POLY_RANDOM_SEED__=1234567890ull -static simple.cpp -o output/fixed1.exe')
os.system('g++ -g -O2 -std=gnu++17 -D __POLY_RANDOM_SEED__=1234567890ull -static simple.cpp -o output/fixed2.exe')
os.system('g++ -g -O2 -std=gnu++17 -D __POLY_RANDOM_SEED__=1234567890ull -static simple.cpp -o output/fixed3.exe')

# external seed
os.system('g++ -g -O2 -std=gnu++17 -D __POLY_RANDOM_SEED__=' + str(random.randrange(18446744073709551615)) + 'ull -static simple.cpp -o output/seeded1.exe')
os.system('g++ -g -O2 -std=gnu++17 -D __POLY_RANDOM_SEED__=' + str(random.randrange(18446744073709551615)) + 'ull -static simple.cpp -o output/seeded2.exe')
os.system('g++ -g -O2 -std=gnu++17 -D __POLY_RANDOM_SEED__=' + str(random.randrange(18446744073709551615)) + 'ull -static simple.cpp -o output/seeded3.exe')

# different types
os.system('g++ -g -O2 -std=gnu++17 -static types.cpp -o output/types.exe')