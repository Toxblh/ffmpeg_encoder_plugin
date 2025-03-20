#pragma once

#include "wrapper/plugin_api.h"

namespace IOPlugin {

enum QualityMode : int32_t {
    CQP = 1 << 0,
    CRF = 1 << 1,
    VBR = 1 << 2,
};

class UISettingsController final {
   public:
    explicit UISettingsController(const EncoderInfo& encoderInfo);
    UISettingsController(const HostCodecConfigCommon& commonProps, const EncoderInfo& encoderInfo);
    void Load(IPropertyProvider* values);
    StatusCode Render(HostListRef* settingsList) const;

   private:
    void InitDefaults();
    StatusCode RenderQuality(HostListRef* settingsList) const;

   public:
    QualityMode GetQualityMode() const;
    int32_t GetQP() const;
    int32_t GetBitRate() const;

   private:
    HostCodecConfigCommon commonProps;
    EncoderInfo encoderInfo;

    QualityMode qualityMode{};
    int32_t qp{};
    int32_t bitRate{};

    std::string qualityModeId;
    std::string qpId;
    std::string bitrateId;
};

}
