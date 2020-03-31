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
    libnewlib-arm-none-eabi \
    software-properties-common \
    unzip \
    wget && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /qmk_firmware
RUN wget https://github.com/qmk/qmk_firmware/archive/master.zip && \
    unzip -q master.zip && \
    mv ./qmk_firmware-master/* ./ && \
    mv ./qmk_firmware-master/.??* ./ && \
    rmdir ./qmk_firmware-master

CMD make $KEYBOARD:$KEYMAP
