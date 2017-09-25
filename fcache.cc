
#include <iostream>
#include <fstream>
#include <fcntl.h>    /* For O_RDWR */
#include <unistd.h>   /* For open(), creat() */
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

class MyFile {
public:
    MyFile(int fileid, int size)
    : fid_(fileid)
    , sz_(size)
    //, fd_(open(("file_"+std::to_string(fileid)).c_str(), O_RDWR | O_CREAT | O_SYNC, 0664))
    {
        f_.open("file_"+std::to_string(fileid), ios::in | ios::out | ios::app | ios::binary);
        data_ = (char *)malloc(size);
        memset(data_, fileid, size);
    }

    void get_data(char **buf) {
        f_.seekg(0, ios::beg);
        f_.read(*buf, sz_);
    }

    void flush_data() {
       f_.write(data_, sz_);
       f_.flush();
    }

    ~MyFile() {
        delete data_;
        f_.close();
    }

private:
    int fid_;
    int sz_;
    int fd_;
    char *data_;
    std::fstream f_;

};

int main() {

    std::vector<MyFile *> files;
    for (auto i = 0; i < 10; i++) {
        files.push_back(new MyFile(i, 1024));
        files[i]->flush_data();
    }
    char *buf = (char *)malloc(1024);
    for (auto i = 0; i< 10; i++) {
        files[i]->get_data(&buf);
        assert(*buf == (char)i);
    }
    delete buf;

}


