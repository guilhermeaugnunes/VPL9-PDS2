CXX = g++

CXXFLAGS = -std=c++11 -Wall -Iinclude

TARGET = meu_sistema

SRC_DIR = src
BUILD_DIR = build


SOURCES = main.cpp SistemaDistribuicao.cpp Tarefa.cpp Backlog.cpp Funcionario.cpp \
          Gerente.cpp Desenvolvedor.cpp EngenheiroSoftware.cpp Equipe.cpp \
          FrontEnd.cpp BackEnd.cpp FullStack.cpp


OBJECTS = $(addprefix $(BUILD_DIR)/, $(SOURCES:.cpp=.o))


all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET) $(BUILD_DIR)/*