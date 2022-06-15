# Ubuntu dependencies
FROM ubuntu:20.04
# FROM nvidia/cuda:11.2.0-runtime-ubuntu20.04

RUN apt-get update -y && apt-get install -y locales gnupg curl sudo \
    && rm -rf /var/lib/apt/lists/* \
    && localedef -i en_US -c -f UTF-8 -A /usr/share/locale/locale.alias en_US.UTF-8

ENV LANG en_US.utf8

# YaCos System Dependencies
RUN curl https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add - \
    && echo "deb http://apt.llvm.org/focal/ llvm-toolchain-focal-10 main" | tee -a /etc/apt/sources.list \
    && apt-get update -y

RUN DEBIAN_FRONTEND="noninteractive" TZ="America/Sao_Paulo" \
    apt-get install -y graphviz libgraphviz-dev creduce libeigen3-dev \
    clang-10 clang-format-10 libclang1-10 libclang-10-dev libclang-common-10-dev \
    wget python3 python3-dev python3-pip python3-virtualenv python3-setuptools \
    python3-ipython python-is-python3 gcc g++ cmake make binutils git tar zip unzip

RUN update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-10 100 \
    && update-alternatives --install /usr/bin/clang clang /usr/bin/clang-10 100 \
    && update-alternatives --install /usr/bin/clang-format clang-format /usr/bin/clang-format-10 100 \
    && update-alternatives --install /usr/bin/opt opt /usr/bin/opt-10 100

RUN wget https://github.com/sharkdp/hyperfine/releases/download/v1.11.0/hyperfine_1.11.0_amd64.deb \
    && dpkg -i hyperfine_1.11.0_amd64.deb && rm -f hyperfine_1.11.0_amd64.deb

RUN pip3 install tensorflow tensorboard protobuf numpy pygraphviz appdirs \
    pandas tqdm absl-py colorit pygmo scikit-learn scipy matplotlib seaborn \
    networkx gensim==3.4.0 six==1.15.0 wget python-Levenshtein nltk angr \
    spektral pyyaml stellargraph scikit-image jupyter jupyterlab ipython

# YaCos IR2VEC Dependencies
RUN git clone https://github.com/IITH-Compilers/IR2Vec.git \
    && mkdir -p IR2Vec/build && cd IR2Vec/ \
    && git checkout llvm10 \
    && cd build \
    && cmake -DLT_LLVM_INSTALL_DIR=/usr -DEigen3_DIR=/usr -DCMAKE_INSTALL_PREFIX=/usr ../src \
    && make install \
    && cd ../.. \
    && rm /usr/seedEmbeddingVocab-300-llvm10.txt \
    && rm -rf IR2Vec

RUN git clone https://github.com/ComputerSystemsLaboratory/YaCoS.git \
    && cd YaCoS \
    && pip3 install .
