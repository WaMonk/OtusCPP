#ifndef OTUS_W2_IP_H
#define OTUS_W2_IP_H

#include <memory>
#include <vector>
#include <string>

namespace otus {
namespace ip {
    using namespace std;

    class CustomIP;

    using CustomIPSP = shared_ptr<CustomIP>;

    class CustomIP {
    public :
        CustomIP() {}
        CustomIP(const char* );
        ~CustomIP() {}

        void print();
        std::string as_string() const;

        bool operator ==(const CustomIP &b) const;
        bool operator !=(const CustomIP &b) const;
        bool operator >(const CustomIP &b) const;
        bool operator <(const CustomIP &b) const;
        bool operator >=(const CustomIP &b) const;
        bool operator <=(const CustomIP &b) const;

    private:
       
        bool _has_mask = false;
        string _raw{""};
        vector<uint> _pieces = {0,0,0,0};

        const size_t kMinAdrSize = 8;

    };
}
}

#endif // IP_H
