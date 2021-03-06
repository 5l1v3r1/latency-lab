#ifndef OMI_LATENCY_RACE_OPTIONS_HPP_
#define OMI_LATENCY_RACE_OPTIONS_HPP_

#include <omi/program/options.hpp>
#include <omi/program/settings.hpp>
#include <omi/match/inputs.hpp>
#include <omi/latency/args.hpp>
#include <omi/latency/race/configuration.hpp>
#include <omi/utility/autotimer.hpp>

//  Options for omi html latency multi run race

namespace omi::latency::race {

struct options {

  //// Member Variables ///////////

    race::configuration report;        // Latency race options
    match::inputs directories;         // Events directories
    std::string path;                  // Html report output path
    bool verbose;                      // Print status to standard out
    autotimer timer;                   // Program timer

  //// Construction //////////////

    // Construct options from args or ini file
    template<typename setting>
    explicit options(const setting &option, bool verbose) : verbose{ verbose }  {
        directories.inbound = option.template required<std::string>(::inbound::directory::option);
        directories.outbound = option.template required<std::string>(::outbound::directory::option);
        report.title = option.template conditional<std::string>(::html::title::option, "Omi");
        report.header = option.template conditional<std::string>(::html::header::option, "Omi Latency Lab");
        report.copyright = option.template conditional<std::string>(::html::copyright::option, "OMI. All rights reserved.");
        report.css = option.template conditional<std::string>(::css::file::option, "omi.css");
        report.period = parse::period(option.template conditional<std::string>(::delta::period::option, "microseconds"));
        report.precision.chart = option.template optional<size_t>(::precision::chart::option);
        report.precision.statistics = option.template optional<size_t>(::precision::statistics::option);
        report.precision.percentiles = option.template optional<size_t>(::precision::percentiles::option);
        path = option.template required<std::string>(::html::report::option);
    }

  //// Interface ////////////////

    // Parse program args into options
    static options parse(int argc, char *argv[], const char *title = "Latency Comparison Report") {
        // Declare options
        boost::program_options::options_description description(title);
        description.add_options()
            (::ini::file::option, boost::program_options::value<std::string>(), ::ini::file::note)
            (::inbound::directory::option, boost::program_options::value<std::string>(), ::inbound::directory::note)
            (::outbound::directory::option, boost::program_options::value<std::string>(), ::outbound::directory::note)
            (::html::title::option, boost::program_options::value<std::string>(), ::html::title::note)
            (::html::header::option, boost::program_options::value<std::string>(), ::html::header::note)
            (::html::copyright::option, boost::program_options::value<std::string>(), ::html::copyright::note)
            (::html::report::option, boost::program_options::value<std::string>(), ::html::report::note)
            (::css::file::option, boost::program_options::value<std::string>(), ::css::file::note) // // make this html::css
            (::delta::period::option, boost::program_options::value<std::string>(), ::delta::period::note)
            (::precision::chart::option, boost::program_options::value<std::string>(), ::precision::chart::note)
            (::precision::statistics::option, boost::program_options::value<std::string>(), ::precision::statistics::note)
            (::precision::percentiles::option, boost::program_options::value<std::string>(), ::precision::percentiles::note)
            (::race::variable::option, boost::program_options::value<std::string>(), ::race::variable::note);
        // If ini file exists, read options from file
        auto args = omi::program::options(argc, argv, description);
        if (args.exists(ini::file::option)) {
            auto ini = omi::program::settings{ args.required<std::string>(ini::file::option) };
            return options{ ini.section("race"), args.verbose() }; // How to make this seamless?
        }

        // Otherwise initialize from program args
        return options{ args, args.verbose() };
    }
};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const options &program) {
    return out << program.report
               << program.timer;
}


}

#endif