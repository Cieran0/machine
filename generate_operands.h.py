#!/usr/bin/python3
import re
import os

# Define a regular expression pattern to match C function declarations
pattern = r'\s*([\w_]+)\s+([\w_]+)\s*\(([^)]*)\)'

# Get a list of files in the current directory
current_directory = os.getcwd()
file_names = [filename for filename in os.listdir(current_directory) if filename.endswith("operands.c")]

# Create a header file (now named "operands.h")
header_file_name = "operands.h"

# Create the operand_arrays.c file
operand_arrays_file_name = "operand_arrays.c"

# Define a dictionary to store function names and declarations by the number of arguments
function_names_by_args = {}
function_declarations_by_args = {}

# Iterate through the list of matching files
for file_name in file_names:
    with open(file_name, "r") as file:
        code = file.read()

    function_declarations = re.finditer(pattern, code)

    # Iterate through the matches and organize function names and declarations by the number of arguments
    for match in function_declarations:
        return_type, function_name, arguments = match.groups()
        arguments = arguments.strip()
        function_declaration = f"{return_type} {function_name}({arguments});"
        num_args = len(arguments.split(','))
        if num_args not in function_names_by_args:
            function_names_by_args[num_args] = []
            function_declarations_by_args[num_args] = []
        function_names_by_args[num_args].append(function_name)
        function_declarations_by_args[num_args].append(function_declaration)

# Calculate the maximum number of arguments
max_args = max(function_names_by_args.keys()) if function_names_by_args else 0

# Write the header file (now named "operands.h") with #pragma once and #include "main.h" at the top, function declarations in the middle
with open(header_file_name, "w") as header_file:
    header_file.write("#pragma once\n")
    header_file.write('#include "main.h"\n\n')

    # Define function declarations in the middle of the header file
    for k in range(1, max_args + 1):
        declarations = function_declarations_by_args.get(k, [])
        header_file.write('\n'.join(declarations))
        header_file.write("\n")

defines = []

# Write the operand_arrays.c file with function names arrays and constants
with open(operand_arrays_file_name, "w") as operand_arrays_file:
    operand_arrays_file.write('#include "operands.h"\n\n')

    constant_counter = 0
    for k in range(1, max_args + 1):
        array_name = f"operands_{k}_args"
        arg_list = ", ".join([f"byte arg{i}" for i in range(1, k + 1)])
        function_names = function_names_by_args.get(k, [])
        indented_function_names = [f"    {name}" for name in function_names]
        operand_arrays_file.write(f"void (*{array_name}[])({arg_list}) = {{\n")
        operand_arrays_file.write(',\n'.join(indented_function_names))
        operand_arrays_file.write("\n};\n")
        
        # Define constants for each function
        for function_name in function_names:
            defines += [(f"#define OP_{function_name.upper()} {constant_counter}\n")]
            constant_counter += 1

with open(header_file_name, "a") as header_file:
    header_file.write("\n")
    for k in range(1, max_args + 1):
        array_name = f"operands_{k}_args"
        arg_list = ", ".join([f"byte arg{i}" for i in range(1, k + 1)])
        s = len(function_names_by_args.get(k, []))
        header_file.write(f"extern void (*{array_name}[{s}])({arg_list});\n")
    for d in defines:
        header_file.write(d)