#include "third_party/nugget/psyqo/application.hh"
#include "third_party/nugget/psyqo/cdrom-commandbuffer.hh"
#include "third_party/nugget/psyqo/cdrom-device.hh"

namespace {

class EnterBootloader final : public psyqo::Application {
    void prepare() override;

  public:
    psyqo::CDRomDevice m_cdrom;
};

EnterBootloader enterBootloader;

}  // namespace

void EnterBootloader::prepare() {
    m_cdrom.prepare();
    m_cdrom.resetBlocking(gpu());

    psyqo::Hardware::CDRom::CDRomCommandBuffer commandBuffer;
    commandBuffer.set(0x50, 0xfa, 0xbe, 0xef);
    m_cdrom.testBlocking(gpu(), commandBuffer);
}

int main() { return enterBootloader.run(); }
