//MMO Client Server
#include <iostream>
#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>

#ifdef _WIN32

#define _WIN32_WINNT 0x0A00

#endif

#define ASIO_STANDALONE

using namespace std;

int main() {
    
    asio::error_code ec;

    asio::io_context context;

    asio::ip::tcp::endpoint endpoint(asio::ip::make_address("127.0.0.1", ec), 80);

    asio::ip::tcp::socket socket(context);

    socket.connect(endpoint, ec);

    if(!ec) {
    
        cout << "Connected!" << endl;
    
    }
    else {

        cout << "주소에 연결하는데 실패하였습니다. : \n" << ec.message() << endl;
    
    }

    if(socket.is_open()) {

        std::string sRequest = 
        "GET /index.html HTTP/1.0\r\n" 
        "Host: Phantester.com\r\n" 
        "Connection: close\r\n\r\n";

    socket.write_some(asio::buffer(sRequest.data(), sRequest.size()), ec);

    socket.wait(socket.wait_read);

    size_t bytes = socket.available();
    std::cout << "Bytes Available : " << bytes << std::endl;

    if (bytes > 0) {
        stdd::vector<char> vBuffer(bytes);
        socket.read_some(asio::buffer(vBuffer.data(), vBuffer.size()), ec);

        for(auto c : vBuffer) {
            std::cout << c << endl;
        }
    }

    }

    system("pause");

    return 0;

}
