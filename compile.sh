sh clean.sh
gcc -c parser.c
gcc -c lexer.c
gcc -o brew main.c parser.o lexer.o
