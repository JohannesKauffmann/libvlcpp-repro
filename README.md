# How to reproduce:

1. `git clone https://github.com/JohannesKauffmann/libvlcpp-repo.git && cd libvlcpp-repo`
2. `git submodule update --init --recursive`
3. `mkdir build && cd build`
4. `cmake -GNinja ..`
5. `cmake --build .`
