#include "gigasecond.h"

namespace gigasecond {

    boost::posix_time::ptime advance(const boost::posix_time::ptime& time) {
        // A gigasecond is 10^9 (1,000,000,000) seconds. 
        // We simply add this duration to the provided time object.
        return time + boost::posix_time::seconds(1000000000);
    }

}  // namespace gigasecond