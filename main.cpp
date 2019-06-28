#include <iostream>
#include <fstream>
#include <memory>
#include "FDFSClient.h"

void ShowError(const std::string &msg, int code){
    if(code == 0) return;
    std::cout << msg << ":" << code << std::endl;
    ::exit(-1);
}

int main()
{
    std::ifstream file_stream("desktop_test.png", std::ios::in | std::ios::binary);
    file_stream.seekg(0, std::ios_base::end);
    int file_size = file_stream.tellg();

    std::shared_ptr<char> buffer(new char[file_size]);
    file_stream.read(buffer.get(), file_size);

    char *remote_file_name = nullptr;
    int remote_name_size = 0;
    CFDFSClient fdfs_client;
    ShowError("client_init", fdfs_client.init("client.conf",6));
    ShowError("upload_file",fdfs_client.fdfs_uploadfile(buffer.get(),"png", file_size, remote_name_size, remote_file_name));
    std::cout << "remote file name: " << remote_file_name << std::endl;
    return 0;
}
