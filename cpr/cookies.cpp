#include "cpr/cookies.h"

#include "cpr/util.h"

namespace cpr {

Cookies::Cookies(const std::initializer_list<std::pair<const std::string, std::string>>& pairs)
        : map_{pairs} {}

std::string Cookies::GetEncoded() const {
    std::stringstream stream;
    unsigned int counter=0;
    for (const auto& item : map_) {
        stream << cpr::util::urlEncode(item.first) << "=";
        // special case version 1 cookies, which can be distinguished by
        // beginning and trailing quotes
        if (!item.second.empty() && item.second.front() == '"' && item.second.back() == '"') {
            stream << item.second;
        } else {
            stream << item.second; // cpr::util::urlEncode(item.second);
        }
        if (++counter < map_.size()) stream << "; ";
    }
    return stream.str();
}

std::string& Cookies::operator[](const std::string& key) {
    return map_[key];
}

} // namespace cpr
