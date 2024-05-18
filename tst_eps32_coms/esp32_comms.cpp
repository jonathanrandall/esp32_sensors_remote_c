#define CPPHTTPLIB_OPENSSL_SUPPORT

//the http library httplib.h file is available from https://github.com/yhirose/cpp-httplib
#include "httplib.h"
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

// g++ -o ssl_client tst_comms2.cpp -lssl -lcrypto

using namespace httplib;

using namespace std;


// mkdir build
// cd build
// cmake ..
// make

class Esp32Comms
{
public:
    Esp32Comms() = default;

    void connect(const std::string &ip)
    {
        cli = (std::make_shared<httplib::Client>(ip));
    }

    auto get_stuff(const std::string &qury)
    {
        ///get_readings
        auto res = cli->Get(qury);

        return res;
    }

private:
    httplib::Client *cl2;
    std::shared_ptr<httplib::Client> cli; // Declare a shared pointer to httplib::Client
};

int main(int argc, char *argv[])
{

    Esp32Comms esp32;
    if (argc < 2)
    {
        cerr << "Usage: " << argv[0] << " <esp32 ip> [output file]\n default outfile is log.csv\n" << endl;
        return 1;
    }

    string esp32_ip = argv[1];
    

    esp32.connect(esp32_ip);

    //define output file
    string out_file = "log.csv"; //default

    if (argc > 2){
        out_file = argv[2];
    }
    
    string message;
    ofstream logfile;

    while (true)
    {
        auto res = esp32.get_stuff("/get_readings");
        if(res->status==200){
            message = res->body;
        } else {
            message = "no data recieved";
        }
        
        cout << "status: " << res->status << "\n";
        cout << "message: " << message << "\n";

        logfile.open(out_file, ios_base::app); // Open in append mode
        if (logfile.is_open()) {
            logfile << message << endl; // Write message to the file
            logfile.close();
        } else {
            cerr << "Unable to open file for writing" << endl;
            return 1; // Exit if unable to open file
        }

        // Sleep until next reading
        this_thread::sleep_for(chrono::seconds(1));
    }

    return 0;
}
