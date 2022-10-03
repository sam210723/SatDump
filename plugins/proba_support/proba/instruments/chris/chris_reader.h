#pragma once

#include "common/ccsds/ccsds.h"

#include "common/image/image.h"
#include <string>
#include <map>
#include <memory>
#include "nlohmann/json.hpp"
#include "products/dataset.h"

namespace proba
{
    namespace chris
    {
        struct CHRISImagesT
        {
            int mode;
            image::Image<uint16_t> raw;
            std::vector<image::Image<uint16_t>> channels;
        };

        class CHRISImageParser
        {
        private:
            unsigned short *tempChannelBuffer;
            std::vector<int> modeMarkers;
            int mode;
            int current_width, current_height, max_value;

        public:
            CHRISImageParser();
            ~CHRISImageParser();
            void work(ccsds::CCSDSPacket &packet);
            CHRISImagesT process();

            int frame_count = 0;
        };

        std::string getModeName(int mode);

        struct CHRISFullFrameT
        {
            bool has_half_1 = false;
            bool has_half_2 = false;
            CHRISImagesT half1;
            CHRISImagesT half2;

            CHRISImagesT recompose();
            image::Image<uint16_t> interleaveCHRIS(image::Image<uint16_t> img1, image::Image<uint16_t> img2);
        };

        class CHRISReader
        {
        private:
            std::map<uint32_t, std::shared_ptr<CHRISImageParser>> imageParsers;
            std::string output_folder;
            satdump::ProductDataSet &dataset;

        public:
            CHRISReader(std::string &outputfolder, satdump::ProductDataSet &dataset);
            void work(ccsds::CCSDSPacket &packet);
            void save();
            int cnt() { return imageParsers.size(); }
        };
    } // namespace chris
} // namespace proba