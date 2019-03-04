#ifndef CPR_SSLOPTIONS_H
#define CPR_SSLOPTIONS_H

#include <string>

namespace cpr {

class VerifySsl {
  public:
    VerifySsl() {}
    VerifySsl(bool verify, const std::string &cacert="");

    operator bool() const;
    const std::string& get_cacert() const { return cacert_; }

  private:
    bool verify_ = true;
    std::string cacert_ = "";
};

} // namespace cpr

#endif
