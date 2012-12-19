#include "nvs/nvs.h"
#include <iostream>

using namespace std;

int main (int argc, char *argv[]) {
    NVS *receiver = new NVS;

    // CL parsing for port/baudrate
    string port = "/dev/ttyUSB0";
    int baudrate = 115200;
    switch (argc) {
        case 3:
            istringstream(argv[2]) >> baudrate;
        case 2:
            port = argv[1];
    }

    receiver->Connect(port, baudrate);
    receiver->updRate = 10; // this only happens if you change subscribe settings
    // Because action is done in other threads, need to keep this one alive
    receiver->WaitForCommand();
}