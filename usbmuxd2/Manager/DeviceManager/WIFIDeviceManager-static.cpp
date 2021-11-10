#include <chrono>
#include <thread>

#include <log.h>
#include <libgeneral/macros.h>

#ifdef HAVE_WIFI_STATIC
#include "WIFIDeviceManager-static.hpp"
#include <Devices/WIFIDevice.hpp>

#pragma mark WIFIDeviceManager

WIFIDeviceManager::WIFIDeviceManager(Muxer *mux): DeviceManager(mux){
  info("WIFIDeviceManager static");
}

WIFIDeviceManager::~WIFIDeviceManager(){
    stopLoop();
}

void WIFIDeviceManager::loopEvent(){
  info("WIFIDeviceManager static adding device");

  int err = 0;
  const char* addr = std::getenv("IDEVICE_ADDRESS");
  const char* uuid = std::getenv("IDEVICE_UUID");

  WIFIDevice *dev = nullptr;
  try{
      dev = new WIFIDevice(uuid, addr, "a4:d9:31:ec:57:f3@", _mux);
  } catch (tihmstar::exception &e){
      creterror("failed to construct device with error=%d (%s)",e.code(),e.what());
  }
  _mux->add_device(dev); dev = NULL;

  while (true) {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }

  debug("WIFIDeviceManager static main loop finished");

error:
  if (err) {
      error("adding device failed with error=%d",err);
  }
}

#endif //HAVE_WIFI_SUPPORT
