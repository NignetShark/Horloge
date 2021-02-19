//
// Created by paul on 18/02/2021.
//

#include <manager.hpp>
#include <service/animation/fade.hpp>
#include <cstring>
#include "service/ntp/ntp_service.hpp"

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <exception/ntp_exception.hpp>
#include <iostream>
#include <tools/timetools.hpp>
#include <service/animation/wave.hpp>

#define NTP_TIMESTAMP_DELTA 2208988800ull


#define LI(packet)   (uint8_t) ((packet.li_vn_mode & 0xC0) >> 6) // (li   & 11 000 000) >> 6
#define VN(packet)   (uint8_t) ((packet.li_vn_mode & 0x38) >> 3) // (vn   & 00 111 000) >> 3
#define MODE(packet) (uint8_t) ((packet.li_vn_mode & 0x07) >> 0) // (mode & 00 000 111) >> 0


NTPService::NTPService(AnimationService &anim_service) : anim_service(anim_service) {
}

void NTPService::run() {
    bool ok = false;
    time_t txTm;
    LedMatrix m(true);

    for(int i = 0; i < NTP_ATTEMPT; i++) {

        // Start waiting animation
        animation::Wave::get().setup(led_color::YELLOW);
        anim_service.setup(animation::Wave::get(), 0.1, 50);
        anim_service.start();

        try {
            txTm = get_NTP_Time();
            ok = true;
            anim_service.stop();
            break;
        } catch (NTPException exception) {
            anim_service.stop();
            err404(i);
            wait_chrono(10, led_color::YELLOW);
        }
    }

    if(ok) {
        std::cout << "Time " << ctime((const time_t *) &txTm) << std::endl;
        success();
    }

}

void NTPService::err404(unsigned int attempt) {
    LedMatrix m404(true);
    m404.set(attempt, 0, led_color::RED);
    m404.set(4, 3, led_color::RED);
    m404.set(0, 4, led_color::RED);
    m404.set(4, 5, led_color::RED);

    animation::Fade::get().setup(&m404);
    anim_service.setup(animation::Fade::get(), 0.02, 50);
    anim_service.sync_run();

    wait_ms(500);

    m404.clear();
    animation::Fade::get().setup(&m404);
    anim_service.setup(animation::Fade::get(), 0.02, 50);
    anim_service.sync_run();
}

time_t NTPService::get_NTP_Time() {
    /*
     *
     * (C) 2014 David Lettier.
     *
     * http://www.lettier.com/
     *
     * NTP client.
     *
     * Compiled with gcc version 4.7.2 20121109 (Red Hat 4.7.2-8) (GCC).
     */

    int sockfd, n; // Socket file descriptor and the n return result from writing/reading from the socket.

    // Structure that defines the 48 byte NTP packet protocol.

    typedef struct {

        uint8_t li_vn_mode;      // Eight bits. li, vn, and mode.
        // li.   Two bits.   Leap indicator.
        // vn.   Three bits. Version number of the protocol.
        // mode. Three bits. Client will pick mode 3 for client.

        uint8_t stratum;         // Eight bits. Stratum level of the local clock.
        uint8_t poll;            // Eight bits. Maximum interval between successive messages.
        uint8_t precision;       // Eight bits. Precision of the local clock.

        uint32_t rootDelay;      // 32 bits. Total round trip delay time.
        uint32_t rootDispersion; // 32 bits. Max error aloud from primary clock source.
        uint32_t refId;          // 32 bits. Reference clock identifier.

        uint32_t refTm_s;        // 32 bits. Reference time-stamp seconds.
        uint32_t refTm_f;        // 32 bits. Reference time-stamp fraction of a second.

        uint32_t origTm_s;       // 32 bits. Originate time-stamp seconds.
        uint32_t origTm_f;       // 32 bits. Originate time-stamp fraction of a second.

        uint32_t rxTm_s;         // 32 bits. Received time-stamp seconds.
        uint32_t rxTm_f;         // 32 bits. Received time-stamp fraction of a second.

        uint32_t txTm_s;         // 32 bits and the most important field the client cares about. Transmit time-stamp seconds.
        uint32_t txTm_f;         // 32 bits. Transmit time-stamp fraction of a second.

    } ntp_packet;              // Total: 384 bits or 48 bytes.

    // Create and zero out the packet. All 48 bytes worth.

    ntp_packet packet = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    memset(&packet, 0, sizeof(ntp_packet));

    // Set the first byte's bits to 00,011,011 for li = 0, vn = 3, and mode = 3. The rest will be left set to zero.

    *((char *) &packet + 0) = 0x1b; // Represents 27 in base 10 or 00011011 in base 2.

    // Create a UDP socket, convert the host-name to an IP address, set the port number,
    // connect to the server, send the packet, and then read in the return packet.

    struct sockaddr_in serv_addr; // Server address data structure.
    struct hostent *server;      // Server data structure.

    sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); // Create a UDP socket.

    if (sockfd < 0)
        throw NTPException("ERROR opening socket");

    server = gethostbyname(HOST_NAME); // Convert URL to IP.

    if (server == NULL)
        throw NTPException("ERROR, no such host");

    // Zero out the server address structure.

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;

    // Copy the server's IP address to the server address structure.

    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);

    // Convert the port number integer to network big-endian style and save it to the server address structure.

    serv_addr.sin_port = htons(NTP_PORT);

    // Call up the server using its IP address and port number.

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        throw NTPException("ERROR connecting");

    // Send it the NTP packet it wants. If n == -1, it failed.

    n = write(sockfd, (char *) &packet, sizeof(ntp_packet));

    if (n < 0)
        throw NTPException("ERROR writing to socket");

    // Wait and receive the packet back from the server. If n == -1, it failed.

    n = read(sockfd, (char *) &packet, sizeof(ntp_packet));

    if (n < 0)
        throw NTPException("ERROR reading from socket");

    close(sockfd);

    // These two fields contain the time-stamp seconds as the packet left the NTP server.
    // The number of seconds correspond to the seconds passed since 1900.
    // ntohl() converts the bit/byte order from the network's to host's "endianness".

    packet.txTm_s = ntohl(packet.txTm_s); // Time-stamp seconds.
    packet.txTm_f = ntohl(packet.txTm_f); // Time-stamp fraction of a second.

    // Extract the 32 bits that represent the time-stamp seconds (since NTP epoch) from when the packet left the server.
    // Subtract 70 years worth of seconds from the seconds since 1900.
    // This leaves the seconds since the UNIX epoch of 1970.
    // (1900)------------------(1970)**************************************(Time Packet Left the Server)

    return (time_t) (packet.txTm_s - NTP_TIMESTAMP_DELTA);

}

void NTPService::wait_chrono(uint8_t from, color_t color) {
    uint8_t result[DIAL_COUNT];
    uint8_t numbers[3] = {from, 0, 0};
    color_t colors[6] = {color, color, led_color::BLACK, led_color::BLACK, led_color::BLACK,
                         led_color::BLACK};
    LedMatrix m(false);

    while (numbers[0] > 0) {
        m.clear();
        TimeTools::numbers2digits(result, numbers);
        m.digits(result, colors);

        animation::Fade::get().setup(&m);
        anim_service.setup(animation::Fade::get(), 0.025, 25);
        anim_service.sync_run();
        wait_ms(500);

        numbers[0]--;
    }
}

void NTPService::success() {
    animation::Wave::get().setup(led_color::GREEN);
    anim_service.setup(animation::Wave::get(), 0.1, 50);
    anim_service.start();
    wait_ms(5000);
    anim_service.stop();
}



