#!/usr/bin/python3
import re
import os

# Define a regular expression pattern to match C function declarations
pattern = r'\s*([\w_]+)\s+([\w_]+)\s*\(([^)]*)\)'

# Get a list of files in the current directory
current_directory = os.getcwd()
file_names = [filename for filename in os.listdir(current_directory) if filename.endswith("_operands.c")]

# Create a header file
header_file_name = "operands.h"
with open(header_file_name, "w") as header_file:
    header_file.write("#pragma once\n")
    header_file.write('#include "main.h"\n')

    # Iterate through the list of matching files
    for file_name in file_names:
        with open(file_name, "r") as file:
            code = file.read()

        function_declarations = re.finditer(pattern, code)

        # Iterate through the matches and write function information to the header file
        for match in function_declarations:
            return_type, function_name, arguments = match.groups()
            arguments = arguments.strip()
            function_info = f"{return_type} {function_name}({arguments});"
            header_file.write(function_info + "\n")
