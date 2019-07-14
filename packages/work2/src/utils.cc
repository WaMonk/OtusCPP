#include <utils.h>

namespace otus {
    namespace utils {
    using namespace std;
          
    vector<string> split(const string& data, const char chr) {

            vector<string> retval;

            string::size_type start = 0;
            string::size_type stop = data.find_first_of(chr);
            while(stop != string::npos)
            {
                retval.push_back(data.substr(start, stop - start));

                start = stop + 1;
                stop = data.find_first_of(chr, start);
            }

            retval.push_back(data.substr(start));
            return retval;
          }
    }
}