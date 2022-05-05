#pragma once

#include "core/pipeline.h"
#include "libs/ctpl/ctpl_stl.h"

namespace satdump
{
    class LivePipeline
    {
    private:
        nlohmann::json d_parameters;
        std::vector<std::future<void>> moduleFutures;

    public:
        LivePipeline(Pipeline pipeline,
                     nlohmann::json parameters,
                     std::string output_dir);
        ~LivePipeline();

        std::vector<std::shared_ptr<ProcessingModule>> modules;

        void start(std::shared_ptr<dsp::stream<complex_t>> stream, ctpl::thread_pool &threadPool);
        void stop();

        std::vector<std::string> getOutputFiles();

        nlohmann::json getModulesStats();

        void drawUIs();
    };
}