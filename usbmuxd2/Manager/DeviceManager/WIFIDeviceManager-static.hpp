#ifndef WIFIDeviceManager_hpp
#define WIFIDeviceManager_hpp

#include <Muxer.hpp>
#include <Manager/DeviceManager/DeviceManager.hpp>

class WIFIDeviceManager : public DeviceManager{

    virtual void loopEvent() override;
public:
	WIFIDeviceManager(Muxer *mux);
    virtual ~WIFIDeviceManager() override;    
};


#endif /* WIFIDeviceManager_hpp */