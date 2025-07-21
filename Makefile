# 定义编译和运行命令
.PHONY: build run clean

build:
	@echo "Building project..."
	cd build && mingw32-make

run: build
	@echo "Running program..."
	cd build && .\Frequency_analyzer.exe

clean:
	@echo "Cleaning build files..."
	if exist build (rmdir /s /q build)