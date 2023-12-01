CC = g++
CFLAGS = -Wall
SRC_DIR = src
BUILD_DIR = build
LIB_DIR = lib
HEADER_DIR = header

# Danh sách các file object
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Tạo file thực thi 'main' từ các file object và thư viện động 'libmyLib.dll'
main: $(OBJS) | $(LIB_DIR)/libmyLib.dll
	$(CC) $(CFLAGS) -o main $(OBJS) -L$(LIB_DIR) -lmyLib

# Tạo file object từ file cpp
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER_DIR)

# Tạo thư viện động 'libmyLib.dll' từ các file object
$(LIB_DIR)/libmyLib.dll: $(OBJS) | $(LIB_DIR)
	$(CC) -shared -o $(LIB_DIR)/libmyLib.dll $(OBJS) 

$(BUILD_DIR):
	if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)

$(LIB_DIR):
	if not exist $(LIB_DIR) mkdir $(LIB_DIR)

clean:
	del /Q $(BUILD_DIR)\*.o main $(LIB_DIR)\*.dll 