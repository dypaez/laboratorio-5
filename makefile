CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = programa.exe

SOURCES = main.cpp \
	Presentacion/presentacion.cpp \
	dominio/funcionario.cpp \
	dominio/lector.cpp \
	dominio/libro.cpp \
	dominio/material.cpp \
	dominio/prestamo.cpp \
	dominio/puntaje.cpp \
	dominio/revista.cpp \
	dominio/usuario.cpp \
	DataTypes/datatypes.cpp \
	Manejadores/manejadormaterial.cpp \
	Manejadores/manejadorpersona.cpp \
	Sistema/fabrica.cpp \
	Sistema/sistema.cpp

INCLUDES = -I. \
	-IPresentacion \
	-Idominio \
	-IDataTypes \
	-IManejadores \
	-ISistema

all:
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SOURCES) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	del /Q $(TARGET) 2>NUL
