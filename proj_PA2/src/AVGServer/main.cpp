#include "include/avgserver.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h> /* For strncpy */
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>
int main()
{
	int fd;
    struct ifreq ifr;
    std::string scheme ("http://");
    std::string port (":34468");
    std::string url;
    fd = socket(AF_INET, SOCK_DGRAM, 0);

    /* I want to get an IPv4 IP address */
    ifr.ifr_addr.sa_family = AF_INET;

    /* I want an IP address attached to "eth0" */
    strncpy(ifr.ifr_name, "eth0", IFNAMSIZ-1);

    ioctl(fd, SIOCGIFADDR, &ifr);

    close(fd);

    /* Display result */
    std::string ip = inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr);

    url = scheme + ip + port;

    utility::string_t address = U(url);
    uri_builder uri(address);
    auto addr = uri.to_string();

    AVGserver avgserver(addr); 
    std::cout << "Press ENTER to exit." << std::endl;

    std::string line;
    std::getline(std::cin, line);

    return 0;
}
