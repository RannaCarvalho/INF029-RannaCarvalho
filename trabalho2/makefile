# Nome do executável
PROG = programa

# Arquivos fonte
SRC = trabalho2.c mainTeste.c

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra

# Regra padrão
all: $(PROG)

# Como gerar o executável
$(PROG): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(PROG)

# Limpar arquivos gerados
clean:
	rm -f $(PROG)
