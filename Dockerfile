FROM ubuntu:22.04

# Compiler, debugger, leak checker
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y \
        build-essential \
        valgrind \
        lldb \
        vim \
        python3 \
        python3-pip \
        libcriterion-dev && \
        clang \
        gdb \
        gdbserver \
        git curl ca-certificates \
        meson ninja-build cmake pkg-config \
        libssl-dev && \
        rm -rf /var/lib/apt/lists/*

ARG CRITERION_TAG=v2.4.2
RUN git clone --depth 1 --branch ${CRITERION_TAG} \
        https://github.com/Snaipe/Criterion.git /tmp/criterion \
    && cd /tmp/criterion \
    && meson setup build \
    && ninja -C build   \
    && ninja -C build install \
    && ldconfig \
    && rm -rf /tmp/criterion

# Work in a write‑able folder that we'll mount from the host
WORKDIR /workspace
CMD ["bash"]
