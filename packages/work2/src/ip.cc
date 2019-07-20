#include <ip.h>
#include <iostream>
#include <string>
#include <utils.h>

namespace otus {
namespace ip {

using namespace std;

CustomIP::CustomIP(const char * raw) {
    string sraw{raw};

    if(sraw.size() < kMinAdrSize )
        throw std::invalid_argument("Ip Format is broken: size");

    if(sraw.find('.') == string::npos)
        throw std::invalid_argument("Ip Format is broken: points");        

    _raw = sraw;

    auto v = utils::split(sraw, '.');
    if(v.size() != kIpPieceSize)
        throw std::invalid_argument("Ip Format is broken: size");

    for(size_t i = 0; i < kIpPieceSize; ++i){
        _pieces[i] = stoi(v[i]);
    }
}

void CustomIP::print(){ cout<<as_string()<< endl; }

string CustomIP::as_string() const {
    string retval = "";

    for (size_t i = 0; i < _pieces.size(); ++i){
        retval += to_string(_pieces[i]);
        if(i + 1 != _pieces.size())
            retval += '.';
    }

    return retval;
}

bool CustomIP::check_byte(size_t position, uint value) const {
    if(position > _pieces.size() || position == 0)
        throw std::invalid_argument("Check is broken: wrong position: " + std::to_string(position));

    return _pieces.at(position -1) == value;
}

}}
