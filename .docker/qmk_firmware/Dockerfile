FROM debian:9

RUN apt-get update && apt-get install --no-install-recommends -y \
    avr-libc \
    avrdude \
    binutils-arm-none-eabi \
    binutils-avr \
    build-essential \
    dfu-programmer \
    dfu-util \
    gcc \
    gcc-arm-none-eabi \
    gcc-avr \
    git \
    libnewlib-arm-none-eabi \
    software-properties-common \
    unzip \
    wget && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /qmk_firmware
RUN git clone --recursive https://github.com/qmk/qmk_firmware.git .

CMD make $KEYBOARD:$KEYMAP
