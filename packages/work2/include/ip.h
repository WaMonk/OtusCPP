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

    const size_t kMinAdrSize = 7;
    const size_t kIpPieceSize = 4;

    class CustomIP {
    public :
        CustomIP() {}
        CustomIP(const char* );
        ~CustomIP() {}

        void print();
        std::string as_string() const;

        bool check_byte(size_t position, uint value) const;
        bool cmp(const CustomIP& rhs) const;
        bool is_equal(const CustomIP& rhs) const;
        uint get_byte(size_t position) const;

        inline bool operator<(const CustomIP& rhs)  { return !cmp(rhs);}
        inline bool operator<=(const CustomIP& rhs) { return is_equal(rhs) || !cmp(rhs);}
        inline bool operator>(const CustomIP& rhs)  { return cmp(rhs);}
        inline bool operator>=(const CustomIP& rhs) { return is_equal(rhs) || cmp(rhs);}
        inline bool operator==(const CustomIP& rhs) { return is_equal(rhs);}

    private:
       
        bool _has_mask = false;
        string _raw{""};
        vector<uint> _pieces = {0,0,0,0};



    };
}
}

#endif // IP_H
