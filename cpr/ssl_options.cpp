#include "cpr/ssl_options.h"

namespace cpr {

VerifySsl::VerifySsl(bool verify, const std::string &cacert) : verify_{verify}, cacert_(cacert) {}

VerifySsl::operator bool() const {
    return verify_;
}

} // namespace cpr
