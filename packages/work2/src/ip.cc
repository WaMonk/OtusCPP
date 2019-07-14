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

    for(size_t i = 0; i < v.size(); ++i){
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

        bool CustomIP::operator ==(const CustomIP &b) const {
            cout<<"=="<<endl;
            return false;}
        bool CustomIP::operator !=(const CustomIP &b) const {
            cout<<"!="<<endl;
            return false;}
        bool CustomIP::operator >(const CustomIP &b) const {
            cout<<">"<<endl;
            return false;}
        bool CustomIP::operator <(const CustomIP &b) const {
            cout<<"<"<<endl;
            return false;}
        bool CustomIP::operator >=(const CustomIP &b) const {
            cout<<">="<<endl;
            return false;}
        bool CustomIP::operator <=(const CustomIP &b) const {
            cout<<"<="<<endl;
            return false;}


}}
