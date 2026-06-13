CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = programa.exe

SOURCES = main.cpp \
	"Capa Presentacion/Presentacion.cpp" \
	"Clases/Funcionario.cpp" \
	"Clases/Lector.cpp" \
	"Clases/Libro.cpp" \
	"Clases/Material.cpp" \
	"Clases/Prestamo.cpp" \
	"Clases/Puntaje.cpp" \
	"Clases/Revista.cpp" \
	"Clases/Usuario.cpp" \
	"DataTypes/DataTypes.cpp" \
	"Manejadores/ManejadorMaterial.cpp" \
	"Manejadores/ManejadorPersona.cpp" \
	"Sistema/Fabrica.cpp" \
	"Sistema/Sistema.cpp"

INCLUDES = -I"." \
	-I"Capa Presentacion" \
	-I"Clases" \
	-I"DataTypes" \
	-I"Manejadores" \
	-I"Sistema"

all:
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SOURCES) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	del /Q $(TARGET) 2>NUL