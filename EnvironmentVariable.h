#ifndef ENVIRONMENTVARIABLE_H_
#define ENVIRONMENTVARIABLE_H_

#include <string>

namespace config {

class EnvironmentVariable final {
private:
    bool defined;
    std::string name;
    std::string value;
public:

    /**
     *
     */
    explicit EnvironmentVariable(std::string const &name);

    /**
     *
     */
    std::string const &GetName() const;

    /**
     * @return the value of the environment variable,
     *         or nullptr if not defined.
     */
    std::string const &GetValue() const;

    /**
     * @return true if the variable has been defined
     *         in the execution environment.
     */
    bool IsDefined() const;

};

}

#endif
