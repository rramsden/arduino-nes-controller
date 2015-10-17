#ifndef NESController_h
#define NESController_h

#define RIGHT    128
#define LEFT     64
#define DOWN     32
#define UP       16
#define START    8
#define SELECT   4
#define BUTTON_B 2
#define BUTTON_A 1

class NESController
{
    public:
        NESController(int pin_latch, int pin_clock, int pin_data);
        void read();
        bool pressed(byte direction);
    private:
        int NESLatch;
        int NESClock;
        int NESData;
        byte NESButtonData;
};

#endif
