# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.158.0/containers/cpp/.devcontainer/base.Dockerfile

# [Choice] Debian / Ubuntu version: debian-10, debian-9, ubuntu-20.04, ubuntu-18.04
ARG VARIANT="buster"
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}

# [Optional] Uncomment this section to install additional packages.
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
     && apt-get -y install --no-install-recommends libopenmpi-dev cmake python3-pip \
     libpng-dev libeigen3-dev
#RUN pip3 install sphinx jupyter_sphinx_theme

RUN usermod -aG sudo vscode
RUN echo "vscode         ALL = (ALL) NOPASSWD: ALL" >> /etc/sudoers
RUN sed -i 's/codespaces/standard/g' /home/vscode/.bashrc