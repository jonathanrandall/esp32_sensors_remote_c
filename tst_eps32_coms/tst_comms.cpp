#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"
#include <iostream>


using namespace httplib;


using namespace std;

// cd build
// make ..
// make

class Esp32Comms
{
public:
    Esp32Comms() = default;
    // Constructor that takes the IP address and initializes httplib::Client
    // Esp32Comms(const std::string &ip) : cli(std::make_shared<httplib::Client>(ip))
    // {
    //     // Additional initialization if needed
    // }

    void connect(const std::string &ip){
        cli=(std::make_shared<httplib::Client>(ip));
    }

    auto get_stuff()
    {
        auto res = cli->Get("/control?var=m&val=100_100");
        // Your connection logic using cli
        // ...
        return res;
    }

private:
    std::shared_ptr<httplib::Client> cli; // Declare a shared pointer to httplib::Client
};


int main(){
    cout << "Hello World!\n";
    // shared_ptr<httplib::Client> *cli2;
    httplib::Client cli("192.168.1.211");
    
    // Esp32Comms esp32("192.168.1.211");
    Esp32Comms esp32;
    
    // HTTPS
    // httplib::Client cli("192.168.1.211");
    
    
    auto res0 = cli.Get("/control?var=e&val=0_0");
    res0->status;
    res0->body;
    cout << "res->status " << res0->status << "\n";
    cout << "res->body " << res0->body << "\n\n";

    esp32.connect("192.168.1.211");
    auto res = esp32.get_stuff();
    res->status;
    res->body;
    cout << "res->status " << res->status << "\n";
    cout << "res->body " << res->body << "\n";
    return 0;
}
