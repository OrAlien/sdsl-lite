#include <chrono>
#include "sdsl/memory_management.hpp"

using namespace std::chrono;

namespace sdsl
{

template<>
void write_mem_log<CSV>(std::ostream& out,const memory_monitor& m)
{
    // write header
    out << "timestamp;memory_usage;event" << std::endl;

    auto first_ts = m.mem_events[0].timestamp;
    for (const auto& event : m.mem_events) {
        out << duration_cast<milliseconds>(event.timestamp-first_ts).count() << ";"
            << event.usage << ";\n";
    }
}

}
