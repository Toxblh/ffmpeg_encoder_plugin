#include "svt_av1_encoder.h"

const EncoderInfo SvtAv1Encoder::encoderInfo = {
    .UUID{0x97, 0x39, 0xbb, 0x53, 0x9b, 0x97, 0xd0, 0x0e, 0x3e, 0x1c, 0x90, 0xeb, 0x70, 0x75, 0x9d, 0xcc},
    .codecGroup = "AV1",
    .codecName = "SVT-AV1 (FFmpeg)",
    .fourCC = 'av01',
    .encoder = "libsvtav1",
    .useVaapi = false,
    .pixelFormat = AV_PIX_FMT_YUV420P,
    .colorModel = clrYUVp,
    .hSubsampling = 2,
    .vSubsampling = 2,
    .qualityModes = CRF | VBR,
    .qp = {1, 35, 63},
};

SvtAv1Encoder::SvtAv1Encoder() { FFmpegEncoder::encoderInfo = encoderInfo; }

StatusCode SvtAv1Encoder::RegisterCodecs(HostListRef* list) { return FFmpegEncoder::RegisterCodecs(list, encoderInfo); }

StatusCode SvtAv1Encoder::GetEncoderSettings(HostPropertyCollectionRef* values, HostListRef* settingsList) {
    return FFmpegEncoder::GetEncoderSettings(values, settingsList, encoderInfo);
}
