CC = g++
CFLAGS = -Wall
SRC_DIR = src
BUILD_DIR = build
LIB_DIR = lib
HEADER_DIR = headers

# # Danh sách các file object
# OBJS = $(BUILD_DIR)/main.o $(BUILD_DIR)/math_functions.o $(BUILD_DIR)/other_functions.o

# Danh sách các file object
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Tạo file thực thi 'main' từ các file object và thư viện động 'libmath.dll'
main: $(OBJS) $(LIB_DIR)/libmath.dll
	$(CC) $(CFLAGS) -o main $(OBJS) -L$(LIB_DIR) -lmath

# Tạo file object từ file cpp
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER_DIR)

# Tạo thư viện động 'libmath.dll' từ các file object
$(LIB_DIR)/libmath.dll: $(BUILD_DIR)/math_functions.o $(BUILD_DIR)/other_functions.o | $(LIB_DIR)
	$(CC) -shared -o $(LIB_DIR)/libmath.dll $(BUILD_DIR)/math_functions.o $(BUILD_DIR)/other_functions.o -Wl,--out-implib,$(LIB_DIR)/libmath.a

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

clean:
	del /Q $(BUILD_DIR)\*.o main $(LIB_DIR)\*.dll $(LIB_DIR)\*.a
