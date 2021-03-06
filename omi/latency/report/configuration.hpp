#ifndef OMI_LATENCY_REPORT_CONFIGURATION_HPP_
#define OMI_LATENCY_REPORT_CONFIGURATION_HPP_

#include <string>
#include <optional>

#include <omi/types/period.hpp>

// Configuartion options for omi html latency report

namespace omi::latency::report {

struct configuration {
    std::string title;                          // Report html title
    std::string header;                         // Report header text
    std::string copyright;                      // Copyright text
    omi::period period{ period::unknown };      // Delta time period
    struct precision {
      std::optional<size_t> chart{ 2 };         // Report chart precision
      std::optional<size_t> statistics{ 2 };    // Report statistics precision
      std::optional<size_t> percentiles{ 2 };   // Report percentiles precision
    } precision;
    std::string path;                           // Html report output path
    std::string css;                            // optional link to external css file 
                                                // add note?
};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const configuration &report) {
    return out << "  Title: " << report.title << std::endl
               << "  Header: " << report.header << std::endl
               << "  Period: " << report.period << std::endl;
}


}

#endif