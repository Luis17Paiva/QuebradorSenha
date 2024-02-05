# Nome do arquivo executável
TARGET = Senha

# Lista de arquivos fonte
SOURCES = teste.c Quebrador-De-Senha.c biblioteca.c

# Lista de arquivos objeto gerados pela compilação
OBJECTS = $(SOURCES:.c=.o)

# Comando de compilação
CC = gcc

# Opções de compilação
CFLAGS = -Wall -g -I\MinGW\lib\gcc\mingw32\6.3.0\include -Wl,--stack,16777216

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS)  -finput-charset=UTF-8 -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
