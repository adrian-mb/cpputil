#include "EnvironmentVariable.h"

#include <string>
#include <cstdlib>

namespace config {

EnvironmentVariable::EnvironmentVariable(std::string const &name) : name(name) {
    char *value = std::getenv(name.c_str());
    if (value != nullptr) {
        this->defined = true;
        this->value = value;
    } else {
        this->defined = false;
    }
}

std::string const &EnvironmentVariable::GetName() const {
    return this->name;
}

std::string const &EnvironmentVariable::GetValue() const {
    return this->value;
}

bool EnvironmentVariable::IsDefined() const {
    return defined;
}

}

