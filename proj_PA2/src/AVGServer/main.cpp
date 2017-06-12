#include "include/avgserver.h"

int main()
{
    utility::string_t address = U("http://172.17.0.3:34468");
    uri_builder uri(address);
    auto addr = uri.to_string();


    AVGserver avgserver(addr); 
    std::cout << "Press ENTER to exit." << std::endl;

    std::string line;
    std::getline(std::cin, line);

    return 0;
}
