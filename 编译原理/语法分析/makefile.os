# =============================================================================
# Filename: makefile.dep
# Author: luozi
# Date: 2024-05-23
# Description: This makefile file is used to import the paths to each folder
# 
# Copyright (c) 2024, xx-luozi-xx
# All rights reserved.
#
# Version: 1.0.0
# =============================================================================


# Detect the operating system
ifeq ($(OS), Windows_NT) # windows
    MKDIR = if not exist "$(1)" mkdir "$(1)"
    RMDIR = powershell.exe -Command "Remove-Item -Recurse -Force $(1)"
    RM = powershell.exe -Command "Remove-Item -Force $(1)"
else  # Unix like
    MKDIR = mkdir -p "$(1)"
    RMDIR = rm -rf
    RM = rm -f
endif