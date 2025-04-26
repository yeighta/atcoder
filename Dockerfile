FROM node:23.11-bookworm

# インタラクティブモードにならないようにする
ARG DEBIAN_FRONTEND=noninteractive

# タイムゾーンを日本に設定
ENV TZ=Asia/Tokyo

# install uv in global env
ENV UV_PROJECT_ENVIRONMENT /usr

# 作業ディレクトリの設定
WORKDIR /workspace

# 必要なパッケージのインストール
RUN apt-get update && apt-get install -y \
    time \
    tzdata \
    vim \
    python3 \
    tree \
    git \
    gcc \
    g++ \
    gdb \
    make \
    && rm -rf /var/lib/apt/lists/*

# uv install
COPY --from=ghcr.io/astral-sh/uv:latest /uv /uvx /bin/

COPY pyproject.toml .
RUN uv sync

# atcoder-cliのインストール
RUN npm install -g atcoder-cli

# C++でAtCoder Library(ACL)を使えるようにする
RUN git clone https://github.com/atcoder/ac-library.git /lib/ac-library
ENV CPLUS_INCLUDE_PATH /lib/ac-library

RUN acc config oj-path /usr/local/bin/oj && \
    acc config default-task-choice all && \
    acc config default-test-dirname-format test && \
    acc config default-template cpp

# シェルの設定
SHELL ["/bin/bash", "-c"]