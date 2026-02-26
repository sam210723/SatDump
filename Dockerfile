ARG DEBIAN_IMAGE_TAG=bookworm
FROM debian:${DEBIAN_IMAGE_TAG} AS builder

ARG DEBIAN_FRONTEND=noninteractive
ARG CMAKE_BUILD_PARALLEL_LEVEL=2
ENV TZ=Etc/UTC \
    CMAKE_BUILD_PARALLEL_LEVEL=${CMAKE_BUILD_PARALLEL_LEVEL}

WORKDIR /usr/local/src/
COPY packages.builder .
RUN apt -y update && \
    apt -y upgrade && \
    xargs -a packages.builder apt install --no-install-recommends -qy && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /usr/local/src/satdump
COPY . .

RUN cmake -B build \
          -DCMAKE_BUILD_TYPE=Release \
          -DBUILD_GUI=ON \
          -DPLUGIN_SCRIPTING=ON \
          -DBUILD_TOOLS=ON &&\
    cmake --build build --target package


ARG DEBIAN_IMAGE_TAG=bookworm
FROM debian:${DEBIAN_IMAGE_TAG} AS runner

LABEL org.opencontainers.image.title="SatDump" \
      org.opencontainers.image.description="A generic satellite data processing software" \
      org.opencontainers.image.source="https://github.com/SatDump/SatDump" \
      org.opencontainers.image.url="https://www.satdump.org" \
      org.opencontainers.image.documentation="https://docs.satdump.org"

ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=Etc/UTC

COPY packages.runner /usr/local/src/
COPY --from=builder /usr/local/src/satdump/build/satdump_*.deb /usr/local/src/
RUN apt -y update && \
    apt -y upgrade && \
    xargs -a /usr/local/src/packages.runner apt install -qy && \
    apt install -qy /usr/local/src/satdump_*.deb && \
    rm -f /usr/local/src/satdump_*.deb /usr/local/src/packages.runner && \
    rm -rf /var/lib/apt/lists/*

# Add a user, possibility to map it to a user on the host to get the same uid & gid on files
ARG HOST_UID=1000
ARG HOST_GID=1000
RUN groupadd -r -g ${HOST_GID} satdump && \
	useradd -r -u ${HOST_UID} \
            -g satdump \
            -d /srv \
            -s /bin/bash \
            -G audio,dialout,plugdev \
            -m \
            satdump && \
    chown satdump:satdump /srv
USER satdump
WORKDIR /srv

ENTRYPOINT ["satdump"]
