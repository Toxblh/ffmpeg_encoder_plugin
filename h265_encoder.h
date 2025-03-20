#pragma once

#include "ffmpeg_encoder.h"

namespace IOPlugin {

class H265Encoder final : public FFmpegEncoder {
   public:
    static const EncoderInfo encoderInfo;

    H265Encoder();

    static StatusCode RegisterCodecs(HostListRef* list);
    static StatusCode GetEncoderSettings(HostPropertyCollectionRef* values, HostListRef* settingsList);
};

}
