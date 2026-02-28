#include "../Headers/Client/Client.h"
#include <iostream>
using namespace std;

int main() {
    cout << "====================================" << endl;
    cout << "   Smart Home Devices System (By Hazem)        " << endl;
    cout << "====================================" << endl;

    Client client;
    client.setupSystem();
    client.run();
    
    cout << endl << "Turning OFF the System <3" << endl;
    return 0;
}
