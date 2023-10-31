default:
		./generate_operands.h.py
		gcc *.c -Iinclude/ -o main -lraylib -lGL -lm -lpthread -ldl -lrt -lX11