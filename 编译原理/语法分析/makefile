# =============================================================================
# Filename: Makefile
# Author: luozi
# Date: 2024-05-23
# Description: This Makefile is used to build and manage the se_lab_240523-2.(1) project.
#              It includes targets for compiling, linking, and cleaning the project.
#              The project consists of several source files and dependencies.
#				
#              All cpp files located in the "./src/cpp/main" folder are generated with an .exe binary 
#			   in the "./bin" directory. 
#			   Other cpp files should be placed directly in the "./src/cpp" directory. 
#			   All .h files should be placed in the "./src/h" directory. 
#			   "./src" and its subdirectories should contain only .cpp and .h files.
# 
# Copyright (c) 2024, xx-luozi-xx
# All rights reserved.
#
# Version: 1.0.0
#
# Targets:
#   - all: Builds the entire project
#   - dir: Creates the "build" folder
#   - clean: Removes all generated files
#
# Dependencies:
#   - gcc (version 6.3.0 or later)
#   - make (version 4.4.1 or later)
# =============================================================================

# 导入路径
include makefile.dep
# 导入跨平台监测
include makefile.os

# 编译器
CC= g++
# 编译器标志

CFLAGS = -MMD -MP -c -Wall -O2 -I$(H_DIR) 
LDFLAGS = -Wall 

# 可执行文件名称
TARGET_SRC = $(wildcard $(SRC_DIR)/main/*.cpp)
TARGET = $(TARGET_SRC:$(SRC_DIR)/main/%.cpp=$(BIN_DIR)/%)
TARGET_OBJ = $(TARGET_SRC:$(SRC_DIR)/main/%.cpp=$(OBJ_DIR)/main/%.o)

# 找到所有的 .cpp 文件
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
# 将 .cpp 文件的列表转换为 .o 文件的列表
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
# 每个.o文件的依赖表文件
DEPS = $(OBJECTS:.o=.d) $(TARGET_OBJ:.o=.d)

# 默认目标
all: dirs $(TARGET) 


# 创建文件夹目标
dirs:
	$(call MKDIR,$(BIN_DIR))
	$(call MKDIR,$(OBJ_DIR))
	$(call MKDIR,$(OBJ_DIR)/main)


# 链接目标
$(BIN_DIR)/%: $(OBJECTS) $(OBJ_DIR)/main/%.o
	$(CC) $^ -o $@ $(LDFLAGS)

# 从 .cpp 生成 .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $< -o $@ $(CFLAGS)
$(OBJ_DIR)/main/%.o: $(SRC_DIR)/main/%.cpp
	$(CC) $< -o $@ $(CFLAGS)

-include $(DEPS)

# 清理目标
clean:
	$(RM) $(BIN_DIR)/*.exe
	$(RM) $(OBJ_DIR)/*.o
	$(RM) $(OBJ_DIR)/*.d
	$(RMDIR) $(OBJ_DIR)
.PHONY: all clean dirs
.PRECIOUS: $(OBJ_DIR)/%.o $(OBJ_DIR)/main/%.o