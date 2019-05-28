BUILD = build
BIN = bin
TARGET = bin/test
SRCDIR = src
SRCFILES = $(shell find $(SRCDIR) -type f -name "*.cpp")
OBJ=$(patsubst $(SRCDIR)/%,$(BUILD)/%,$(SRCFILES:.cpp=.o))
TESTOBJ=$(patsubst $(SRCDIR)/%,$(TEST)/%,$(SRCFILES:.cpp=.o))
LIBS =
CC = g++
INC = -I include -std=c++17

ALL: $(TARGET)

$(TARGET): $(OBJ)
	@echo " Linking...";
	@echo " $(CC) $^ -o $(TARGET) $(LIBS) ";
	$(CC) $^ -o $(TARGET) $(LIBS) $(INC) 

$(BUILD)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILD)
	@mkdir -p $(BIN)
	$(CC)  $(LIBS) $(INC) -c $^ -o $@

.PHONY: clean

clean:
	@echo "Cleaning..."
	@echo " $(RM)  $(BUILD) $(BIN)"
	$(RM) -r $(BUILD) $(BIN)
