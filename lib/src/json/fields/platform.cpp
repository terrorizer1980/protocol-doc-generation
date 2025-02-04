#include "platform.hpp"

using namespace protodoc;
namespace commsdsl
{
void to_json(json_obj &j, const commsdsl::Protocol::PlatformsList &platforms)
{
    for (const auto &p : platforms)
        j[p][kKeyFieldName] = p;
}
} // namespace commsdsl
