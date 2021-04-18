#include <iostream>
#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>

#ifdef _WIN32

#define _WIN32_WINNT 0x0A00

#endif

#define ASIO_STANDALONE

using namespace std; //using std namespace 

int main() {
    
    asio::error_code ec;

    asio::io_context context;

    asio::ip::tcp::endpoint endpoint(asio::ip::make_address("127.0.0.1", ec), 80); //IP주소 및 포트 선언

    asio::ip::tcp::socket socket(context);

    socket.connect(endpoint, ec);

    if(!ec) {
    
        cout << "Connected!" << endl; //IP연결
    
    }
    else {

        cout << "주소에 연결하는데 실패하였습니다. : \n" << ec.message() << endl; //예외 상황 처리
    
    }

    return 0;

}
