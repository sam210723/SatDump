#include "core/plugin.h"
#include "logger.h"
#include "core/module.h"

#include "gk2a/xrit/module_gk2a_xrit_data_decoder.h"
#include "gk2a/xrit/module_gk2a_uhrit_cadu_extractor.h"

class GK2ASupport : public satdump::Plugin
{
public:
    std::string getID()
    {
        return "gk2a_support";
    }

    void init()
    {
        satdump::eventBus->register_handler<RegisterModulesEvent>(registerPluginsHandler);
    }

    static void registerPluginsHandler(const RegisterModulesEvent &evt)
    {
        REGISTER_MODULE_EXTERNAL(evt.modules_registry, gk2a::xrit::GK2AxRITDataDecoderModule);
        REGISTER_MODULE_EXTERNAL(evt.modules_registry, gk2a::xrit::GK2AUHRITCADUextractor);
    }
};

PLUGIN_LOADER(GK2ASupport)