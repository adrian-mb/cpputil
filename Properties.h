#ifndef CONFIGURATIONFILE_H_
#define CONFIGURATIONFILE_H_

#include <string>
#include <map>

namespace config {

class Properties final {
private:
    std::map<std::string, std::string> properties;

    /**
     *
     */
    bool good;

    /**
     *
     */
    bool IsProperty(std::string const &line) const;

public:

    /**
     *
     */
    Properties(std::string const &filepath);

    /**
     *
     */
    std::string Get(std::string const &key, std::string const &default_value);

    /**
     *
     */
    bool GetBool(std::string const &key, bool default_value);

    /**
     *
     */
    long int GetLong(std::string const &key, long int default_value);

    /**
     * @return true if property with given key is defined.
     */
    bool IsDefined(std::string const &key) const;

    /**
     * @return true if the file could be read completely without errors.
     */
    bool IsGood() const;

};

}

#endif
