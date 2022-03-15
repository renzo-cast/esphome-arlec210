#include "RCSwitch.h"
#include "esphome.h"

class ArlecSwitch : public Component, public Switch {
 public:

  ArlecSwitch(int pin, unsigned long code_on, unsigned long code_off, unsigned int bit_length, int protocol):
    pin{pin},
    code_on{code_on},
    code_off{code_off},
    bit_length{bit_length}, 
    protocol{protocol} 
  { }

  private:
    RCSwitch arlec = RCSwitch();
    int pin;
    unsigned long code_on;
    unsigned long code_off;
    unsigned long bit_length;
    int protocol;
    
  void setup() override {
    ESP_LOGD("INFO", "Setup()");
    arlec.enableTransmit(pin);
    arlec.setProtocol(protocol);
    arlec.setRepeatTransmit(20);
  }
  void write_state(bool state) override {

    if (state==true){
      ESP_LOGD("INFO", "Turning on");
      arlec.send(code_on, bit_length);
    } else {
      ESP_LOGD("INFO", "Turning off");
      arlec.send(code_off, bit_length);
    } 

    // Acknowledge new state by publishing it
    publish_state(state);
  }
};
