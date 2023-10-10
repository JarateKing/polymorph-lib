import os
import random
import time

# Define the source code file and compilation options
source_file = 'simple.cpp'
compile_options = 'g++ -g -O2 -std=gnu++17 -static'

# Define the number of random seeds and the output directory
num_random_seeds = 3
output_dir = 'output/'

# Compile the code with different seeds
for i in range(num_random_seeds):
    seed = str(random.randrange(18446744073709551615)) + 'ull'
    output_exe = f'{output_dir}random{i + 1}.exe'
    compile_command = f'{compile_options} {source_file} -o {output_exe}'
    os.system(compile_command)
    time.sleep(1)

# Compile the code with a fixed seed
fixed_seed = '1234567890ull'
for i in range(num_random_seeds):
    output_exe = f'{output_dir}fixed{i + 1}.exe'
    compile_command = f'{compile_options} -D __POLY_RANDOM_SEED__={fixed_seed} {source_file} -o {output_exe}'
    os.system(compile_command)

# Compile the code with an external seed
for i in range(num_random_seeds):
    seed = str(random.randrange(18446744073709551615)) + 'ull'
    output_exe = f'{output_dir}seeded{i + 1}.exe'
    compile_command = f'{compile_options} -D __POLY_RANDOM_SEED__={seed} {source_file} -o {output_exe}'
    os.system(compile_command)

# Compile code with different types
types_source_file = 'types.cpp'
types_output_exe = f'{output_dir}types.exe'
os.system(f'{compile_options} {types_source_file} -o {types_output_exe}')
