#
# Makefile - build rand
#
# (c) 2018 gdifiore <difioregabe@gmail.com>
#      

VERSION = 1.0.0
PKGNAME = io.github.gdifiore.rand
CC = gcc
TARGET = rand

all : $(TARGET)

$(TARGET) : src/main.c
	$(CC) src/main.c -o $(TARGET)
	@echo Successfully built $(TARGET)
