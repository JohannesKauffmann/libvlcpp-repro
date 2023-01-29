#include <iostream>

#include <vlcpp/vlc.hpp>

#include <synchapi.h>

void onPositionChanged(float newPos)
{
    std::cout << "New pos: " << newPos << std::endl;
}

int main(int argc, char *argv[])
{
    const char *args[1] = { "-q" };
    VLC::Instance inst(sizeof(args), args);
    VLC::MediaPlayer mp(inst);
    VLC::Media video(inst, "video.mp4",
                     VLC::Media::FromPath);

    mp.setMedia(video);

    auto em = mp.eventManager();
    em.onPositionChanged(onPositionChanged);;

    mp.play();

    Sleep(3000);

    mp.stop();

    return 0;
}
