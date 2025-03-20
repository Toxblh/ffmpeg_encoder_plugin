#pragma once

#include "ffmpeg_encoder.h"

namespace IOPlugin {

class X264Encoder final : public FFmpegEncoder {
   public:
    static const EncoderInfo encoderInfo;

    X264Encoder();

    static StatusCode RegisterCodecs(HostListRef* list);
    static StatusCode GetEncoderSettings(HostPropertyCollectionRef* values, HostListRef* settingsList);
};

}
