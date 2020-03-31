FROM debian:9

RUN apt-get update && apt-get install --no-install-recommends -y \
    build-essential \
    ca-certificates \
    libusb-dev \
    unzip \
    wget && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /teensy_loader
RUN wget https://github.com/PaulStoffregen/teensy_loader_cli/archive/master.zip && \
    unzip -q master.zip && \
    mv ./teensy_loader_cli-master/* ./ && \
    mv ./teensy_loader_cli-master/.??* ./ && \
    rmdir ./teensy_loader_cli-master

RUN make && \
    mv teensy_loader_cli /usr/local/bin && \
    rm -rf /teensy_loader

WORKDIR /scripts
COPY /.docker/teensy_loader/run.sh ./

WORKDIR /qmk_firmware/.build
CMD bash /scripts/run.sh
