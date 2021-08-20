#include "list.hpp"
#include "../endian.hpp"
#include "../field.hpp"
#include "../types.hpp"

namespace protodoc
{

void to_json(json_obj &j, const commsdsl::ListField &f)
{
    j[kKeyType] = kListType;

    if (f.hasLengthPrefixField())
    {
        if (f.detachedLengthPrefixFieldName().empty())
            to_json(j["lengthField"], f.lengthPrefixField());
        else
            j["lengthField"] = f.detachedLengthPrefixFieldName();
    }
    else if (f.hasElemLengthPrefixField())
    {
        if (f.detachedElemLengthPrefixFieldName().empty())
            to_json(j["lengthField"], f.elemLengthPrefixField());
        else
            j["lengthField"] = f.detachedElemLengthPrefixFieldName();
    }
    else if (f.hasCountPrefixField())
    {
        if (f.detachedCountPrefixFieldName().empty())
            to_json(j["lengthField"], f.countPrefixField());
        else
            j["lengthField"] = f.detachedCountPrefixFieldName();
    }

    j["fixedElemLength"] = f.elemFixedLength();
    j["fixedCount"] = f.fixedCount();

    to_json(j[kKeyFieldField], f.elementField());
}

} // namespace protodoc