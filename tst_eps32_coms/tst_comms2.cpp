#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"
#include <iostream>
//g++ -o ssl_client tst_comms2.cpp -lssl -lcrypto

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

    auto get_stuff(const std::string &qury)
    {
        //"/control?var=m&val=100_200"
        auto res = cli->Get(qury);
        
        return res;
    }

private:
    // httplib::Client cl2;
    std::shared_ptr<httplib::Client> cli; // Declare a shared pointer to httplib::Client
};


int main(){
    cout << "Hello World!\n";
    // httplib::Client cli("esp32_ip");
    
    Esp32Comms esp32;
    
    

    esp32.connect("192.168.1.211");
    auto res = esp32.get_stuff("/control?var=m&val=200_200");
    res->status;
    res->body;
    cout << "res->status " << res->status << "\n";
    cout << "res->body " << res->body << "\n";

    auto res0 = esp32.get_stuff("/control?var=e&val=0_0");
    res0->status;
    res0->body;
    cout << "res->status " << res0->status << "\n";
    cout << "res->body " << res0->body << "\n\n";
    return 0;
}
