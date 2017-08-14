#include "Properties.h"

#include <string>
#include <sstream>
#include <fstream>
#include <regex>
#include <ios>

namespace config {

Properties::Properties(std::string const &path) {
    std::ifstream file(path);
    std::string line;

    while ((this->good = file.good()) && std::getline(file, line)) {
        std::stringstream s(line);
        std::string key;
        std::string value;

        if (IsProperty(line)) {
            std::getline(s, key, '=');
            std::getline(s, value);

            properties[key] = value;
        }
    }
}

std::string Properties::Get(std::string const &key,
                            std::string const &default_value) {
    return IsDefined(key) ? properties[key] : default_value;
}

bool Properties::GetBool(std::string const &key, bool default_value) {
    bool parsed;
    if (IsDefined(key)) {
        std::istringstream(properties[key]) >> std::boolalpha >> parsed;
    } else {
        parsed = default_value;
    }
    return parsed;
}

long int Properties::GetLong(std::string const &key, long int default_value) {
    return IsDefined(key) ? std::stol(properties[key]) : default_value;
}

bool Properties::IsDefined(std::string const &key) const {
    return properties.find(key) != properties.end();
}

bool Properties::IsGood() const {
    return this->good;
}

bool Properties::IsProperty(std::string const &line) const {
    return std::regex_match(line, std::regex("^[^=]*=[^=]*$"));
}

}
