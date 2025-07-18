#include <iostream>
#include <windows.h>
#include <tchar.h>

int main() {
    HANDLE hSerial = CreateFile(
        _T("COM6"),  // 根据实际串口调整
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        0,
        NULL
    );
    if (hSerial == INVALID_HANDLE_VALUE) {
        std::cerr << "无法打开串口" << std::endl;
        return -1;
    }

    DCB dcbSerialParams = { 0 };
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

    if (!GetCommState(hSerial, &dcbSerialParams)) {
        std::cerr << "获取串口状态失败" << std::endl;
        CloseHandle(hSerial);
        return -1;
    }

    dcbSerialParams.BaudRate = CBR_256000;  // 波特率9600
    dcbSerialParams.ByteSize = 8;  // 8位数据位
    dcbSerialParams.StopBits = ONESTOPBIT;  // 1位停止位
    dcbSerialParams.Parity = NOPARITY;  // 无校验位

    if (!SetCommState(hSerial, &dcbSerialParams)) {
        std::cerr << "设置串口状态失败" << std::endl;
        CloseHandle(hSerial);
        return -1;
    }

    COMMTIMEOUTS timeouts = { 0 };
    timeouts.ReadIntervalTimeout = 50;
    timeouts.ReadTotalTimeoutConstant = 50;
    timeouts.ReadTotalTimeoutMultiplier = 10;
    timeouts.WriteTotalTimeoutConstant = 50;
    timeouts.WriteTotalTimeoutMultiplier = 10;

    if (!SetCommTimeouts(hSerial, &timeouts)) {
        std::cerr << "设置串口超时失败" << std::endl;
        CloseHandle(hSerial);
        return -1;
    }

    char buffer[256];
    DWORD bytesRead;
    while (true) {
        if (ReadFile(hSerial, buffer, sizeof(buffer), &bytesRead, NULL)) {
            buffer[bytesRead] = '\0';
            std::cout << buffer;
        }
    }

    CloseHandle(hSerial);
    return 0;
}